// LinkedListTest.cpp
#include "gtest/gtest.h"
#include "DoublyLinkedList.h"

TEST(DoublyLinkedListTest, AddingElements) {
    DoublyLinkedList<int> list;
    ASSERT_TRUE(list.isEmpty());

    list.add(10);
    list.add(20);
    list.add(30);

    ASSERT_EQ(list.getSize(), 3);
    ASSERT_FALSE(list.isEmpty());
}

TEST(DoublyLinkedListTest, RemovingElements) {
    DoublyLinkedList<int> list;
    list.add(10);
    list.add(20);
    list.add(30);

    ASSERT_EQ(list.getSize(), 3);

    ASSERT_TRUE(list.remove(20));
    ASSERT_EQ(list.getSize(), 2);

    ASSERT_FALSE(list.remove(40));
    ASSERT_EQ(list.getSize(), 2);

    ASSERT_TRUE(list.remove(10));
    ASSERT_EQ(list.getSize(), 1);

    ASSERT_TRUE(list.remove(30));
    ASSERT_TRUE(list.isEmpty());
}

TEST(DoublyLinkedListTest, AddingAndRemovingElements) {
    DoublyLinkedList<int> list;
    ASSERT_TRUE(list.isEmpty());

    list.add(10);
    list.add(20);
    list.add(30);

    ASSERT_EQ(list.getSize(), 3);
    ASSERT_FALSE(list.isEmpty());

    ASSERT_EQ(list.getHead()->data, 10);

    ASSERT_TRUE(list.remove(20));
    ASSERT_EQ(list.getSize(), 2);

    ASSERT_FALSE(list.remove(40));
    ASSERT_EQ(list.getSize(), 2);

    ASSERT_TRUE(list.remove(10));
    ASSERT_EQ(list.getSize(), 1);

    ASSERT_EQ(list.getHead()->data, 30);

    ASSERT_TRUE(list.remove(30));
    ASSERT_TRUE(list.isEmpty());
}
