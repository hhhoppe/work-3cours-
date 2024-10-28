// Copyright 2024 Dergynov Sergey

#define EASY_EXAMPLE

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

    ///

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