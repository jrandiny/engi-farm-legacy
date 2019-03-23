#include <gtest/gtest.h>
#include <LinkedList.h>

TEST(LinkedList, basicIO){
    LinkedList<int> list;
    list.addFirst(1);
    list.addFirst(2);
    list.addFirst(5);
    list.addLast(9);

    ASSERT_EQ(4,list.getNeff());

    ASSERT_EQ(2,list.get(1));
    ASSERT_EQ(1,list.get(2));
    ASSERT_EQ(3,list.getFirst()->getInfo());
    ASSERT_EQ(9,list.get(list.getNeff()-1));

    ASSERT_FALSE(list.isEmpty());

    list.remove(5);
    list.remove(2);
    ASSERT_EQ(list.getNeff(),3);
}

TEST(LinkedList, find){
    LinkedList<int> list;
    list.addFirst(1);
    list.addFirst(2);
    list.addFirst(5);

    ASSERT_EQ(list.idxUndeff,list.find(9));
    ASSERT_EQ(0,list.find(5));
    ASSERT_EQ(2,list.find(1));
}

TEST(LinkedList, bracketOperator){
    LinkedList<int> list;
    list.addFirst(1);
    list.addFirst(2);

    ASSERT_EQ(2,list[0]);
    ASSERT_EQ(1,list[1]);

    list[0] = 9;
    ASSERT_EQ(9,list[0]);
}

TEST(LinkedList, copy){
    LinkedList<int> list;
    list.addFirst(1);
    list.addFirst(2);
    list.addFirst(3);

    LinkedList<int> list2 = list;
    ASSERT_EQ(3,list.get(0));
    ASSERT_EQ(2,list.get(1));
    ASSERT_EQ(1,list.get(2));

    LinkedList<int> list3;
    list3.addFirst(9);
    list3.addFirst(10);

    ASSERT_EQ(9, list3.get(1));
    ASSERT_EQ(10, list3.get(0));

    list3 = list;
    ASSERT_EQ(3,list.get(0));
    ASSERT_EQ(2,list.get(1));
    ASSERT_EQ(1,list.get(2));
}
