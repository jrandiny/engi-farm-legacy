#include <gtest/gtest.h>
#include <LinkedList.h>

TEST(LinkedListTest, test1){
    LinkedList<int> a;
    a.addFirst(1);
    a.addFirst(2);
    ASSERT_EQ(a.getNeff(),2);
}
