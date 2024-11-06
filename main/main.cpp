// Copyright 2024 Dergynov Sergey

#define Pair

#ifdef EASY_EXAMPLE

#include <iostream>
#include <iomanip>
#include "../lib_easy_example/easy_example.h"

int main() {
  int a, b;
  float result;

  a = 1; b = 4;

  try {
      result = division(a, b);
      std::cout << a << " / " << b << " = "
          << std::setprecision(2) << result << std::endl;
  } catch (std::exception err) {
      std::cerr << err.what() << std::endl;
  }

  a = 1; b = 0;

  try {
      result = division(a, b);
      std::cout << a << " / " << b << " = "
          << std::setprecision(2) << result << std::endl;
  } catch (std::exception err) {
      std::cerr << err.what() << std::endl;
  }

  return 0;
}

#endif  // EASY_EXAMPLE

#ifdef Pair

#include <iostream>
#include <iomanip>
#include "../lib_pair/pair.h"

int main() {

    // Создение пары с помощью конструктора по умолчанию
    TPair<int, int> pair1;
    std::cout << "Defolt constructor pair: ("
        << pair1.first() << ", " << pair1.second() << ")" << std::endl;

    // Создение пары с помощью конструктора с параметром
    TPair<int, int> pair2(12, 2);
    std::cout << "Parametr constructor pair: ("
        << pair2.first() << ", " << pair2.second() << ")" << std::endl;

    // Работа сеттеров и геттеров
    pair1.set_first(10);
    pair1.set_second(20);
    std::cout << "Using setters on pair1: ("
        << pair1.first() << ", " << pair1.second() << ")" << std::endl;

    // Работа конструктора копирования
    TPair<int, int> pair3(pair2);
    std::cout << "Copy constructor pair3 from pair2: ("
        << pair3.first() << ", " << pair3.second() << ")" << std::endl;

    // Работа оператора присваивания
    pair3 = pair1;
    std::cout << "Assigning pair1 from pair3: ("
        << pair3.first() << ", " << pair3.second() << ")" << std::endl;

    // Работа оператора сравнения
    if (pair1 == pair3) {
        std::cout << "pair1 and pair3 ==" << std::endl;
    } else {
        std::cout << "pair1 and pair3 !=" << std::endl;
    }

    if (pair1 == pair2) {
        std::cout << "pair1 and pair2 ==" << std::endl;
    } else {
        std::cout << "pair1 and pair2 !=" << std::endl;
    }

    return 0;
}

#endif  // Pair

#ifdef DMassive

#include <iostream>
#include <iomanip>
#include "../lib_Dmassive/dmassive.h"

int main() {

    ///

    return 0;
}

#endif  // DMassive

#ifdef TVector

#include <iostream>
#include <iomanip>
#include "../lib_TVector/tvector.h"

int main() {

    ///

    return 0;
}

#endif  // TVector

#ifdef Stack

#include <iostream>
#include <iomanip>
#include "../lib_Stack/stack.h"

int main() {

    ///

    return 0;
}

#endif  // Stack

#ifdef Queue

#include <iostream>
#include <iomanip>
#include "../lib_Queue/queue.h"

int main() {

    ///

    return 0;
}

#endif  // Queue

#ifdef List

#include <iostream>
#include <iomanip>
#include "../lib_List/list.h"

int main() {

    ///

    return 0;
}

#endif  // List