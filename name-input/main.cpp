// Include libraries for io and strings
#include <iostream>
#include <string>

/**
 * @function getName
 * @brief Gets a valid full name from the user
 *
 * @return {std::string*|NULL} name A pointer to the user's name
 *
 * @example
 *  std::string myName;
 *
 *  myName = getName();
 */
std::string* getName () {
  int spaces = 0;
  std::string* name = new std::string();

  // Get user input
  std::getline(std::cin, *name);

  // Go through each character in the string to check for spaces
  for (unsigned int i = 0; i < (*name).length(); ++i) {
    // Check if there is a space
    if ((*name)[i] == ' ') {
      spaces++;
    }
  }

  // If the user gave their first, second, and/or last
  if (spaces == 1 || spaces == 2)
    return name;
  // Otherwise, the name is invalid
  else
    return NULL;
}

int main () {
  std::string* name;

  std::cout << "Enter your name: ";

  name = getName();

  if (name == NULL) {
    std::cout
      << "\r\n"
      << "Invalid Name!";
  } else {
    std::cout
      << "\r\n"
      << "Hello, " << (*name) << "!";
  }

  return 0;
}
