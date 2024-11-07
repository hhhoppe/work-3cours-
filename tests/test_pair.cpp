// Copyright 2024 Dergynov Sergey

#include <gtest.h>
#include "../lib_pair/pair.h"

// Проверка конструктора по умолчанию
TEST(TestTPairLib, default) {
	TPair<int, double> pair0;
	EXPECT_EQ(pair0.first(), 0);
	EXPECT_EQ(pair0.second(), 0.0);
}

// Проверка конструктора с параметрами
TEST(TestTPairLib, parametr) {
	TPair<int, int> pair(11, 45);
	EXPECT_EQ(pair.first(), 11);
	EXPECT_EQ(pair.second(), 45);
}

// Проверка конструктора копирования
TEST(TestTPairLib, copy) {
	TPair<double, int> original(14.5, 22);
	TPair<double, int> copy(original);
	EXPECT_EQ(copy.first(), 14.5);
	EXPECT_EQ(copy.second(), 22);
}

// Проверка геттеров
TEST(TestTPairLib, getters) {
	TPair<int, int> pair(11, 98);
	EXPECT_EQ(pair.first(), 11);
	EXPECT_EQ(pair.second(), 98);
}

// Проверка сеттеров
TEST(TestTPairLib, setters) {
	TPair<double, double> pair;
	pair.set_first(11.1);
	pair.set_second(22.2);
	EXPECT_EQ(pair.first(), 11.1);
	EXPECT_EQ(pair.second(), 22.2);
}

// Проверка оператора присваивания
TEST(TestTPairLib, assignment) {
	TPair<int, int> pair1(1, 3);
	TPair<int, int> pair2;
	pair2 = pair1;
	EXPECT_EQ(pair2.first(), 1);
	EXPECT_EQ(pair2.second(), 3);
}

// Проверка оператора сравнения
TEST(TestTPairLib, comparison) {
	TPair<int, int> pair1(34, 12);
	TPair<int, int> pair2(34, 12);
	TPair<int, int> pair3(38, 11);
	EXPECT_TRUE(pair1 == pair2);
	EXPECT_FALSE(pair1 == pair3);
}