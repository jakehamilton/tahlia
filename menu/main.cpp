/*
 * Import the <iostream> library which will handle input and output
 *  streams. Hence the name "i o stream". We'll use this to output
 *  text and take textual input from a user.
 */
#include <iostream>

/*
 * Like any program, we have to create a model of our data so the
 *  computer can understand it. Here, we need to find a way to
 *  model a "menu". Breaking the concept of a menu down, we understand
 *  that a menu will have an input in the form of a character. Here we
 *  will use an integer (eg. 1). To efficiently model this data, we can
 *  rename these plain numbers into more descriptive names using an
 *  enumeration. Each item in an enumeration gets a unique name and
 *  sequential value. For example:
 *    
 *    GREETING   is 0
 *    STATISTICS is 1
 *    QUIT       is 2
 *
 * This way, when a user gives us a number to use in our menu, we can
 *  compare it in a way that reads more like english. Something like:
 *
 *    if (userChoice == GREETING) { ... }
 */
enum MenuChoice {
  GREETING,
  STATISTICS,
  QUIT,
};

/*
 * Now, we'll actually define what the task of making a menu means.
 *  To break the problem down, we have three basic tasks we need to
 *  accomplish:
 *
 *  1. Print a menu out
 *  2. Get the numerical input from the user
 *  3. Make the user's input available elsewhere in our code
 *
 * As the language of c++ requires verbosity, we'll tackle these in
 *  the order: 3, 1, 2. Before reading through this (rather large)
 *  comment, take a peek at the code it is referring to. Don't worry
 *  about understanding it too well, that's what this explanation is for!
 *
 * Task #3
 *  There are two ways that we can make a valud obtained within a
 *    function available elsewhere. I'll explain these using a simple
 *    function that creates in the number four.
 *
 *    The first way:
 *      
 *      int getFour () {
 *        return 4;
 *      }
 *
 *      int four = getFour();
 *
 *    That first method of obtaining our value utilizes the `return`
 *      keyword which essentially tells the computer to replace the
 *      text `getFour()` with the following value of `4`. Were we to
 *      imagine this, the line essentially becomes:
 *
 *      int four = 4;
 *
 *    The second way:
 *
 *      int getFour (int &result) {
 *        result = 4;
 *      }
 *
 *      int four;
 *
 *      getFour(four);
 *
 *    This looks quite different but don't be alarmed! While the text
 *      may be terse, the idea behind it is actually quite simple. Here
 *      what we are doing is what's called "pass by reference". Essentially,
 *      what it means is that we are giving a function the full ability to
 *      modify a variable. Normally, when supplying a value to a function, the
 *      value is copied so that any given function can operate on it in an
 *      isolated environment. By using the special `&` character as we've done,
 *      we can opt in to this new feature. Think of it almost like a manual
 *      version of the `return` keyword. Instead of letting the computer sort
 *      things out, we tell it manually where we want our value of `4` to end up.
 *
 * Task #1
 *  This is perhaps the easiest part of our whole function. All we're required
 *    to do is print out some text, how hard can that be! Thanks to the
 *    wonderful <iostream> library that we imported earlier, we can write text
 *    to what is called the "standard output". This output is made available to
 *    every program on every computer; Don't think it is special! To access the
 *    standard output, we can use the `cout` function contained within the
 *    `std` namespace. I won't delve in to why we want to write `std::cout` as
 *    opposed to alternatives, but do understand that there are issues that could
 *    arrise were you to not write your code the same way I have here (ie. `std::cout`).
 *
 *  Outputting text is as easy as:
 *
 *    std::cout << "My Text";
 *
 *  Were we to want to add more lines, you can continue using the `<<` operator:
 *
 *     std::cout << "My Text" << "Is Awesome";
 *
 *  However, you'll notice that when printed to the screen, both bits of text are
 *    actually on the same line. Like I mentioned before, programming languages can
 *    be rather verbose. In our case, to get the text on separate lines, we must tell
 *    the computer where to end each line. Thankfully, this can easily be done
 *    using `std::endl` like so:
 *
 *     std::cout << "My Text" << std::endl << "Is Awesome";
 *    
 *  Lastly, to keep things easy for us to read, let's format our code a little:
 *
 *     std::cout
 *        << "My Text" << std::endl
 *        << "Is Awesome";
 *
 *  There we are! Now it should be understood by anyone reading this code what
 *    is happening.
 *
 * Task #2
 *  Just like each program has a standard output that it can utilize, there also
 *    exists a standard input. When we talk about getting an input from the user
 *    we are actually talking about reading text from this standard input. Just
 *    like with the standard output, the <iostream> library gives us access to
 *    this feature as `std::cin`. Our menu is going to be using integers as the
 *    input, so we'll need to devise a way to receive an integer from the user.
 *    Thankfully this is as simple as the following:
 *
 *      int input;
 *
 *      std::cin >> input;
 *
 *  Here we've created a place to store the user's input, then received a value
 *    from the program's standard input to place in our variable. We're 90% of
 *    the way there!
 *
 *  Earlier we talked about modeling our program's data. This input is exactly
 *    the data we were modeling! Now that we have the user's choice as an integer,
 *    we need to turn that into one of our `MenuChoice` options from our enum.
 *    To do this, we need to understand the operation we are trying to perform.
 *    Our goal here is to convert the user's input (an integer) into one of our
 *    menu choices (the MenuChoice enum). To convert one simple type of data to
 *    another, we can make use of the built in `static_cast` function! This function
 *    takes one type of thing and converts it into another! The syntax may look a little
 *    weird at first, but don't be afraid; this function can be very helpful:
 *
 *    int input;
 *
 *    std::cin >> input;
 *
 *    MenuChoice choice = static_cast<MenuChoice>(input);
 *
 *  The above line says that we are making a new variable named `choice` that is
 *    a `MenuChoice`. Then, we set that variable's value using the equal sign. The
 *    value we set it to is the result of turning our `input` (an integer) into
 *    a MenuChoice!
 */
void menu (MenuChoice &choice) {
  // Temporary buffer value
  int input;

  // Print a menu
  std::cout
    << "Please select an option:" << std::endl
    << "------------------------" << std::endl
    << "1) Greeting"              << std::endl
    << "2) Statistics"            << std::endl
    << "3) Quit"                  << std::endl
    << std::endl
    << "> ";

  // Get the user's selection
  std::cin >> input;

  // Set the choice as our MenuChoice data type
  choice = static_cast<MenuChoice>(input - 1);
}

/*
 * The main function. This function _is_ our program; without it,
 *  we wouldn't get anywhere. Since this is the starting point, we
 *  can be given some extra information from the outside world. This
 *  "extra information" isn't required and is not used in this program,
 *  but can be useful in many other cases. For now, just know that the
 *  `argc` and `argv` arguments are very powerful and are well worth
 *  exploring. Other than that, let's continue.
 */
int main (int argc, char** argv) {
  
  /*
   * We'll keep track of the user's choice in our program
   */
  MenuChoice choice;

  /*
   * And we'll also track whether the program _should_ keep running or not
   */
  bool running = true;

  /*
   * To continue showing the user a menu until they explicitly quit the
   *  program, we can use a while loop since while loops are really good
   *  at looping things for an indeterminate amount. What are we going
   *  to use to determine if we should loop again? Well we'll use our
   *  `running` value of course! Since `running` will control this loop,
   *  when we set it to `false` then the loop will stop so our program can
   *  come to an end.
   */
  while (running) {
    /*
     * The first order of business is to print our menu, making sure
     *  to get the user's choice.
     */
    menu(choice);

    /*
     * Next, we'll perform a specific action based on that choice
     */
    switch (choice) {
      /*
       * If the user chose option #1
       */
      case GREETING:
        std::cout
          << std::endl
          << "Hello!" << std::endl
          << std::endl;
        break;

      /*
       * If the user chose option #2
       */
      case STATISTICS:
        std::cout
          << std::endl
          << "Mathematical!" << std::endl
          << std::endl;
        break;

      /*
       * If the user chose option #3
       */
      case QUIT:
        std::cout
          << std::endl
          << "Goodbye!" << std::endl
          << std::endl;

        /*
         * The user wants to quit our program, so we need to make
         *  sure to toggle our `running` value to `false` so that
         *  our loop will end.
         */
        running = false;
        break;
      
      /*
       * If the user didn't choose any of the previous choices
       */
      default:
        std::cout
          << std::endl
          << "I'm sorry, " << (choice + 1) << " is not a valid command."
          << std::endl << std::endl;
        break;
    }
  }

  /*
   * Returns from the `main` function are a little different than others.
   *  For a `main` function, the return value is actually a numerical error
   *  code. A code of zero means that there was no error in running our program.
   *  However, returning any number other than zero tells the computer that there
   *  _was_ an error. Since our program is so simple and (thanks to me) error-free
   *  we can be confident in always returning a zero error code.
   */
  return 0;
}
