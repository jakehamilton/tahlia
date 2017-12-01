#include <iostream>
#include <fstream>
#include <string>

#include "functions.hpp"

using std::string;

const int MAX_NAMES = 20;

int main () {
  int size;
  string names[MAX_NAMES];

  readFile("names.txt", MAX_NAMES, names, size);
  alphabetize(names, size);

  bool x = names[0] > names[1];

  std::cout << x << std::endl;

  for (int i = 0; i < size; i++) {
    std::cout << names[i] << std::endl;
  }

  return 0;
}
