#include <UI.h>
#include <locale.h>
#include <ncurses.h>
#include <string>
#include <sstream>

UI::UI(){
    int parentX,parentY;

    setlocale(LC_ALL, "");

    initscr();
    noecho();

    clear();
    refresh();

    start_color();

    getmaxyx(stdscr, parentY, parentX);

    int mapWidth = parentX/2;
    int mapHeight = parentY - bottomBarHeight;
    
    mapPanel = newwin(mapHeight,mapWidth,0,0);
    drawBorders(mapPanel);
    commandPanel = newwin(bottomBarHeight,parentX,mapHeight,0);
    drawBorders(commandPanel);
    waterPanel = newwin(bottomBarHeight,parentX-mapWidth,mapHeight-bottomBarHeight,mapWidth);
    drawBorders(waterPanel);
    moneyPanel = newwin(bottomBarHeight,parentX-mapWidth,mapHeight-bottomBarHeight*2,mapWidth);
    drawBorders(moneyPanel);
    titlePanel = newwin(titleBarHeight,parentX-mapWidth,0,mapWidth);
    drawBorders(titlePanel);

    int inventoryHeight = parentY - bottomBarHeight*3 - titleBarHeight;

    inventoryPanel = newwin(inventoryHeight,parentX-mapWidth,titleBarHeight,mapWidth);
    drawBorders(inventoryPanel);

    wrefresh(commandPanel);
    wrefresh(mapPanel);
    wrefresh(titlePanel);
    wrefresh(inventoryPanel);
    wrefresh(waterPanel);
    wrefresh(moneyPanel);
}

UI::~UI(){
    endwin();
}

void UI::drawBorders(WINDOW *screen){
    int x, y, i;

    getmaxyx(screen, y, x);

    // Pojok
    mvwaddch(screen, 0, 0, ACS_ULCORNER);
    mvwaddch(screen, y - 1, 0, ACS_LLCORNER);
    mvwaddch(screen, 0, x - 1, ACS_URCORNER);
    mvwaddch(screen, y - 1, x - 1, ACS_LRCORNER);

    // Sisi
    for (i = 1; i < (y - 1); i++) {
        mvwaddch(screen, i, 0, ACS_VLINE);
        mvwaddch(screen, i, x - 1, ACS_VLINE);
    }

    // Atas bawah
    for (i = 1; i < (x - 1); i++) {
        mvwaddch(screen, 0, i, ACS_HLINE);
        mvwaddch(screen, y - 1, i, ACS_HLINE);
    }
}

void UI::drawPlayerStat(Player p){
    // Draw water
    werase(waterPanel);
    drawBorders(waterPanel);
    mvwprintw(waterPanel,1,2,"Water = %d",p.getWater());
    wrefresh(waterPanel);

    // Draw money
    werase(moneyPanel);
    drawBorders(moneyPanel);
    mvwprintw(moneyPanel,1,2,"Money = %d",p.getMoney());
    wrefresh(moneyPanel);

    // Draw inventory
    werase(inventoryPanel);
    drawBorders(inventoryPanel);
    int maxY, maxX;
    getmaxyx(inventoryPanel, maxY, maxX);

    std::map<std::shared_ptr<Product>,int,Player::cmpSharedPtrProduct> bag = p.getBag();

    int i=0;

    for(auto item: bag){
        if(i<maxY-2){
            mvwprintw(inventoryPanel,i+1,2,"%d - %s",item.second,item.first->render().c_str());
            i++;
        }else{
            mvwprintw(inventoryPanel,maxY-2,2,"~~~");
        }
    }

    wrefresh(inventoryPanel);
}

void UI::drawMap(Map in, Player P){
    int panelX;
    int panelY;
    int posy;
    int posx;

    std::vector<std::vector<std::shared_ptr<Cell>>> map = in.getMap();


    werase(mapPanel);
    drawBorders(mapPanel);

    // Draw tile
    int maxX = map[0].size();
    int maxY = map.size();

    getmaxyx(mapPanel,panelY,panelX);

    // Margin calculation
    // (total width - (table width-1(for border compensation)))/2
    int marginX = (panelX - ((maxX-1)*5))/2;
    // (total height - (table height-1(border compensation)))/2
    int marginY = (panelY - (maxY-1)*3)/2;


    for(int i=0;i<maxY;i++){
        for(int j=0;j<maxX;j++){
            posy=(i+1)*2 + marginY;
            posx=(j+1)*4 + marginX;

            // Membentuk
            //  | P |
            //  +---+
                
            // Lokasi posx dan posy berada di kanan P (kotak isi cell paling kanan)

            // Isi
            
            auto idx = mapColorPair.find(map[i][j]->render());

            int colorPairIndex = 0;
    
            if(idx==mapColorPair.end()){
                colorPairIndex = mapColorPair.size()+1;
                mapColorPair.insert(std::make_pair(map[i][j]->render(),colorPairIndex));
            }else{
                colorPairIndex = idx->second;
            }

            init_pair(colorPairIndex,map[i][j]->getFgColor(),map[i][j]->getBgColor());

            wattron(mapPanel,COLOR_PAIR(colorPairIndex));
            mvwaddch(mapPanel,posy, posx-1,map[i][j]->render()[0]);
            wattroff(mapPanel,COLOR_PAIR(colorPairIndex));
            // Garis bawah
            if(i+1!=maxY){
                mvwaddch(mapPanel, posy+1, posx, ACS_HLINE);
                mvwaddch(mapPanel, posy+1, posx-1, ACS_HLINE);
                mvwaddch(mapPanel, posy+1, posx-2, ACS_HLINE);
            }

            // Garis samping
            if(j+1!=maxX){
                mvwaddch(mapPanel,posy,posx+1,ACS_VLINE);
            }

            // Pojok (simbol +)
            if(i+1!=maxY && j+1!=maxX){
                mvwaddch(mapPanel,posy+1,posx+1,ACS_PLUS);
            }
        }
    }

    // Animal
    std::vector<std::shared_ptr<FarmAnimal>> animals = in.getAllFarmAnimal();

    for(auto animal : animals){
        posx=(animal->getX()+1)*4 + marginX;
        posy=(animal->getY()+1)*2 + marginY;
        mvwaddch(mapPanel, posy, posx-1, animal->render()[0]);
    }

    // Waiter
    posx=(P.getPosX()+1)*4 + marginX;
    posy=(P.getPosY()+1)*2 + marginY;
    mvwprintw(mapPanel, posy, posx-2, P.render().c_str());

    wrefresh(mapPanel);
}

std::vector<std::string> UI::getInput(){
    std::string output;
    int tempInput;

    bool finishReading = false;

    keypad(commandPanel,true);

    while(!finishReading){
        wclear(commandPanel);
        drawBorders(commandPanel);
        mvwprintw(commandPanel,1,2,"Command : ");
        mvwprintw(commandPanel,1,12,output.c_str());
        wrefresh(commandPanel);

        tempInput = wgetch(commandPanel);

        if((tempInput==13)||(tempInput==10)||(tempInput==KEY_ENTER)){
            finishReading =true;
        }else if(tempInput == KEY_BACKSPACE){
            if(output.length()>0){
                output.erase(output.end()-1);
            }
        }else if(tempInput == KEY_RESIZE){
            output = std::string("RESIZE");
            // refreshLayout(gs);
            finishReading = true;
        }else if(tempInput == KEY_UP){
            output = std::string("UP");
            finishReading = true;
        }else if(tempInput == KEY_DOWN){
            output = std::string("DOWN");
            finishReading = true;
        }else if(tempInput == KEY_LEFT){
            output = std::string("LEFT");
            finishReading = true;
        }else if(tempInput == KEY_RIGHT){
            output = std::string("RIGHT");
            finishReading = true;
        }else if(((tempInput>='A')&&(tempInput<='Z'))||((tempInput>='0')&&(tempInput<='9'))){
            if(output.length()<50){
                output.push_back(tempInput);
            }
        }else if((tempInput>='a')&&(tempInput<='z')){
            if(output.length()<50){
                output.push_back(tempInput-32);
            }
        }else if(tempInput==' '){
            output.push_back(' ');
        }

    }

    std::vector<std::string> outArr;

    std::string temp;

    std::istringstream split(output);

    while(std::getline(split,temp,' ')){
        outArr.push_back(temp);
    }
    
    return outArr;
}

void UI::drawTooltip(std::string input){
    werase(titlePanel);
    drawBorders(titlePanel);

    int maxX;
    int maxY;

    getmaxyx(titlePanel,maxY,maxX);


    mvwprintw(titlePanel,maxY-2,maxX - 13,"Engi's Farm");

    mvwprintw(titlePanel,1,2,input.c_str());

    wrefresh(titlePanel);
}