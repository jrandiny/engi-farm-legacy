/**
 * @file Product.cpp
 * @author Back End K3
 * @brief file berisi implementasi kelas Well
 * @version 0.1
 * @date 2019-03-01
 */

#include <Cell/Facility/Well.h>
#include <Cell/Cell.h>

Well::Well(int _x, int _y):Facility(_x,_y,CellType::WellType){
    usable = true;
}
std::string Well::render(){
    return "W";
}