// Copyright 2024 Dergynov Sergey

#define DMassive

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
#include "../main/utilities.h"

enum Actions { EXIT, INSERT, FIND, REMOVE, CLEAN };

int main() {
    TDmassive<int> massive;
    size_t n, pos;
    int* values = nullptr;
    int user;

    std::exception err;
    bool exit = false;
    bool success;
    InputSystem::InsertMode mode;

    while (!exit) {
        system("cls");
        OutputSystem::show(massive);
        std::cout << "Menu:\n 1. insert,\n 2. find,\n 3. delete,\n 4. clean,\n 0. exit.\nYour choose: ";
        std::cin >> user;
        switch (user) {
        case Actions::EXIT:
            exit = true;
            break;
        case Actions::INSERT:
            if (values != nullptr) { delete[] values; values = nullptr; }
            values = InputSystem::insert<int>(&n, &pos, &mode);
            success = false;
            if (mode == InputSystem::InsertMode::OneValue) {
                try {
                    massive.insert(values[0], pos);
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << std::endl;
                }
            }
            else {
                std::cout << "TBD" << std::endl;
            }
            if (success) {
                OutputSystem::insert();
            }
            system("pause");
            break;
        case Actions::FIND:
        {
            int value = InputSystem::get_value<int>();
            try {
                size_t index = massive.find_first(value);
                std::cout << "First occurrence at index: " <<
                    index << std::endl;
                size_t* _index = massive.find_all(value);
                size_t count = _index[0] + 1;
                if (_index != nullptr) {
                    std::cout << "All occurrences at index: ";
                    for (size_t i = 1; i < count; ++i) {
                        std::cout << _index[i] << " ";
                    }
                    std::cout << std::endl;
                    delete[] _index;
                }
                else {
                    std::cout << "Not found." << std::endl;
                }
            }
            catch (std::exception& err) {
                std::cerr << err.what() << std::endl;
            }
            system("pause");
            break;
        }
        case Actions::REMOVE:
        {
            std::cout << "Choose remove mode:\n";
            std::cout << "1 - Remove by index,\n";
            std::cout << "2 - Remove first index,\n";
            std::cout << "3 - Remove last ixdex,\n";
            std::cout << "4 - Remove all.\n";
            std::cout << "Your choice: ";
            std::cin >> user;
            try {
                if (user == 1) {
                    size_t pos = InputSystem::get_pos<int>();
                    massive.remove_by_index(pos);
                }
                else if (user == 2) {
                    int value = InputSystem::get_value<int>();
                    massive.remove_first(value);
                }
                else if (user == 3) {
                    int value = InputSystem::get_value<int>();
                    massive.remove_last(value);
                }
                else if (user == 4) {
                    int value = InputSystem::get_value<int>();
                    massive.remove_all(value);
                }
                std::cout << "Removal completed." << std::endl;
            }
            catch (std::exception& err) {
                std::cerr << err.what() << std::endl;
            }
            system("pause");
            break;
        }
        case Actions::CLEAN:
            massive.clear();
            std::cout << "Massive clear." << std::endl;
            system("pause");
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            system("pause");
            break;
        }
    }

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