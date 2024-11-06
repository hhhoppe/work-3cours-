// Copyright 2024 Dergynov Sergey

#include <gtest.h>
#include "../lib_pair/pair.h"

// Проверка конструктора по умолчанию
TEST(TestTPairLib, defoult) {
	TPair<int, double> pair;
	EXPECT_EQ(pair.first(), 0);
	EXPECT_EQ(pair.second(), 0.0);
}

// Проверка конструктора с параметрами
TEST(TestTPairLib, parametr) {
	TPair<int, char> pair(11, 'a');
	EXPECT_EQ(pair.first(), 12);
	EXPECT_EQ(pair.second(), 4.5);
}

// Проверка конструктора копирования
TEST(TestTPairLib, copy) {
	TPair<double, char> original(14.5, 'z');
	TPair<double, char> copy(original);
	EXPECT_EQ(copy.first(), 14.5);
	EXPECT_EQ(copy.second(), 'z');
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
	TPair<char, char> pair1('a', 'b');
	TPair<char, char> pair2;
	pair1 = pair2;
	EXPECT_EQ(pair2.first(), 'a');
	EXPECT_EQ(pair2.second(), 'b');
}

// Проверка оператора сравнения
TEST(TestTPairLib, comparison) {
	TPair<int, int> pair1(34, 12);
	TPair<int, int> pair2(34, 12);
	TPair<int, int> pair3(38, 11);
	EXPECT_TRUE(pair1 == pair2);
	EXPECT_FALSE(pair1 == pair3);
}