// Copyright 2024 Dergynov Sergey

#include <gtest.h>
#include "../lib_Dmassive/dmassive.h"

// Проверка конструктора по умолчанию
TEST(TestTDmassiveLib, default) {
    TDmassive<int> massive;
    EXPECT_EQ(massive.size(), 0);
    EXPECT_EQ(massive.capacity(), STEP_CAPACITY);
    EXPECT_TRUE(massive.empty());
}

// Проверка конструктора копирования
TEST(TestTDmassiveLib, copy) {
    TDmassive<int> massive1;
    massive1.push_back(5);
    massive1.push_back(10);

    TDmassive<int> massive2(massive1);
    EXPECT_EQ(massive2.size(), massive1.size());
    EXPECT_EQ(massive2.data()[0], 5);
    EXPECT_EQ(massive2.data()[1], 10);
}

// Проверка конструктора инициализации массивом
TEST(TestTDmassiveLib, init_mass) {
    int mass[] = { 1, 2, 3, 4 };
    TDmassive<int> massive(mass, 4);
    EXPECT_EQ(massive.size(), 4);
    EXPECT_EQ(massive.data()[0], 1);
    EXPECT_EQ(massive.data()[3], 4);
}

// Проверка конструктора c размером и значением по умолчанию
TEST(TestTDmassiveLib, init_size_value) {
    TDmassive<int> massive(3, 7);
    EXPECT_EQ(massive.size(), 3);
    EXPECT_EQ(massive.data()[0], 7);
    EXPECT_EQ(massive.data()[2], 7);
}

// Проверка метода push_back
TEST(TestTDmassiveLib, push_back) {
    TDmassive<int> massive;
    massive.push_back(5);
    EXPECT_EQ(massive.size(), 1);
    EXPECT_EQ(massive.data()[0], 5);
}

// Проверка метода pop_back
TEST(TestTDmassiveLib, pop_back) {
    TDmassive<int> massive;
    massive.push_back(5);
    massive.push_back(10);
    massive.pop_back();
    EXPECT_EQ(massive.size(), 1);
    EXPECT_EQ(massive.data()[0], 5);
}

// Проверка метода push_front
TEST(TestTDmassiveLib, push_front) {
    TDmassive<int> massive;
    massive.push_front(5);
    EXPECT_EQ(massive.size(), 1);
    EXPECT_EQ(massive.data()[0], 5);
}

// Проверка метода pop_front
TEST(TestTDmassiveLib, pop_front) {
    TDmassive<int> massive;
    massive.push_back(5);
    massive.push_back(10);
    massive.pop_front();
    EXPECT_EQ(massive.size(), 1);
    EXPECT_EQ(massive.data()[0], 10);
}

// Проверка метода insert с массивом
TEST(TestTDmassiveLib, insert_mass) {
    TDmassive<int> massive;
    int arr[] = { 1, 2, 3 };
    massive.insert(arr, 3, 0);
    EXPECT_EQ(massive.size(), 3);
    EXPECT_EQ(massive.data()[0], 1);
    EXPECT_EQ(massive.data()[2], 3);
}

// Проверка метода insert с значением
TEST(TestTDmassiveLib, insert_value) {
    TDmassive<int> massive;
    massive.push_back(5);
    massive.push_back(10);
    massive.insert(7, 1);
    EXPECT_EQ(massive.size(), 3);
    EXPECT_EQ(massive.data()[1], 7);
}

// Проверка метода replace
TEST(TestTDmassiveLib, replace) {
    TDmassive<int> massive;
    massive.push_back(5);
    massive.replace(0, 10);
    EXPECT_EQ(massive.data()[0], 10);
}

// Проверка метода erase
TEST(TestTDmassiveLib, erase) {
    TDmassive<int> massive;
    massive.push_back(5);
    massive.push_back(10);
    massive.push_back(15);
    massive.erase(1, 1);
    EXPECT_EQ(massive.size(), 2);
    EXPECT_EQ(massive.data()[1], 15);
}

// Проверка метода remove_all
TEST(TestTDmassiveLib, remove_all) {
    TDmassive<int> massive;
    massive.push_back(5);
    massive.push_back(10);
    massive.push_back(5);
    massive.remove_all(5);
    EXPECT_EQ(massive.size(), 1);
    EXPECT_EQ(massive.data()[0], 10);
}

// Проверка метода find_first
TEST(TestTDmassiveLib, find_first) {
    TDmassive<int> massive;
    massive.push_back(5);
    massive.push_back(10);
    EXPECT_EQ(massive.find_first(10), 1);
}

// Проверка метода find_last
TEST(TestTDmassiveLib, find_last) {
    TDmassive<int> massive;
    massive.push_back(5);
    massive.push_back(10);
    massive.push_back(5);
    EXPECT_EQ(massive.find_last(5), 2);
}

// Проверка метода find_all
TEST(TestTDmassiveLib, find_all) {
    TDmassive<int> massive;
    massive.push_back(5);
    massive.push_back(10);
    massive.push_back(5);
    size_t* tmp = massive.find_all(5);
    EXPECT_EQ(tmp[0], 2);
    EXPECT_EQ(tmp[1], 0);
    EXPECT_EQ(tmp[2], 2);
    delete[] tmp;
}

// Проверка метода swap
TEST(TestTDmassiveLib, swap) {
    TDmassive<int> massive1;
    TDmassive<int> massive2;
    massive1.push_back(5);
    massive2.push_back(10);
    massive1.swap(massive2);
    EXPECT_EQ(massive1.data()[0], 10);
    EXPECT_EQ(massive2.data()[0], 5);
}