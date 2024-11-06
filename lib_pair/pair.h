// Copyright 2024 Dergynov Sergey

#ifndef LIB_PAIR_PAIR_H_
#define LIB_PAIR_PAIR_H_

#include <iostream>

// Объявление шаблонного класса
template <class T1, class T2>
class TPair {
    T1 _first;
    T2 _second;
public:
    TPair();                                    // Конструктор по умолчанию
    TPair(const T1& first, const T2& second);   // Конструктор с параметрами
    TPair(const TPair& pair);                   // Конструктор копирования
    ~TPair();                                   // Деструктор

    inline T1 first() const noexcept;                   // Getter для 1ого и 2ого элемента
    inline T2 second() const noexcept;
    inline void set_first(const T1& value) noexcept;    // Setter для 1ого и 2ого элемента
    inline void set_second(const T2& value) noexcept;

    TPair& operator=(const TPair& pair) noexcept;       // Оператор присваивания

    bool operator==(const TPair& pair) const noexcept;  // Оператор сравнения
};

// Конструктор по умолчанию
template <class T1, class T2>
TPair<T1, T2>::TPair() : _first(), _second() {}

// Конструктор с параметрами
template <class T1, class T2>
TPair<T1, T2>::TPair(const T1& first, const T2& second) : _first(first), _second(second) {}

// Конструктор копирования
template <class T1, class T2>
TPair<T1, T2>::TPair(const TPair& pair) : _first(pair._first), _second(pair._second) {}

// Деструктор
template <class T1, class T2>
TPair<T1, T2>::~TPair() {}

// Getter для 1ого и 2ого элемента
template <class T1, class T2>
T1 TPair<T1, T2>::first() const noexcept { return _first; }

template <class T1, class T2>
T2 TPair<T1, T2>::second() const noexcept { return _second; }

// Setter для 1ого и 2ого элемента
template <class T1, class T2>
void TPair<T1, T2>::set_first(const T1& value) noexcept { _first = value; }

template <class T1, class T2>
void TPair<T1, T2>::set_second(const T2& value) noexcept { _second = value; }

// Оператор присваивания
template <class T1, class T2>
TPair<T1, T2>& TPair<T1, T2>::operator=(const TPair& pair) noexcept {
    if (this != &pair) {
        _first = pair._first;
        _second = pair._second;
    }
    return *this;
}

// Оператор сравнения
template <class T1, class T2>
bool TPair<T1, T2>::operator==(const TPair& pair) const noexcept {
    return (_first == pair._first) && (_second == pair._second);
}

#endif  // LIB_PAIR_PAIR_H_