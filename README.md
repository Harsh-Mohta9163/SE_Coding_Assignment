# C++ Banking System Demo

This project is a C++ implementation of a banking system based on a UML class diagram.

## Prerequisites

- A C++ compiler that supports C++17 or later (e.g., g++, clang++).
- `make` utility (optional, but recommended for easy compilation).

## File Structure

The project is organized into header (.hpp) and source (.cpp) files for each class, along with a `main.cpp` for the demonstration.

- `*.hpp`: Header files with class declarations.
- `*.cpp`: Source files with class implementations.
- `main.cpp`: The main entry point and demo logic.

## Compilation and Execution

You can compile the files and run the demo using the g++ compiler.

### Method 1: Using g++ directly

1.  Navigate to the directory containing all the `.cpp` and `.hpp` files.
2.  Run the following command in your terminal to compile all source files into a single executable named `banking_demo`:

    ```sh
    g++ -std=c++17 -o banking_demo main.cpp Account.cpp SavingsAccount.cpp CheckingAccount.cpp FD.cpp Transaction.cpp Deposit.cpp Withdrawal.cpp Transfer.cpp Customer.cpp Branch.cpp Bank.cpp
    ```

3.  Execute the compiled program:

    ```sh
    ./banking_demo
    ```

### Method 2: Using a Makefile

For a more convenient build process, you can use the provided `Makefile`.

1.  Save the `Makefile` content into a file named `Makefile` in the same directory as your source code.

2.  Run `make` in your terminal to compile the project.
    ```sh
    make
    ```

3.  Execute the program:
    ```sh
    ./banking_demo
    ```

4. To clean up the compiled files, run:
    ```sh
    make clean
    ```

*/