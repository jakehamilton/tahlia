#include <iostream>
#include <fstream>
#include <string>

#include "functions.hpp"

using std::string;
using std::fstream;

void readFile (string name, int max, string output[], int &size) {
  size = 0;

  string line;
  fstream file;

  file.open(name.c_str());

  while (size < max && std::getline(file, line)) {
    output[size++] = line;
  }

  file.close();
}

void alphabetize (string text[], int length) {
  bool sorted = false;

  while (!sorted) {
    sorted = true;

    for (int i = 0; i < length - 1; i++) {
      if (text[i] > text[i + 1]) {
        sorted = false;

        text[i].swap(text[i + 1]);
      }
    }
  }
}
