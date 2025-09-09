# Makefile - blank placeholder
# Makefile for the Banking System Demo

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Executable name
TARGET = banking_demo

# Source files
SOURCES = main.cpp Account.cpp SavingsAccount.cpp CheckingAccount.cpp FD.cpp Transaction.cpp Deposit.cpp Withdrawal.cpp Transfer.cpp Customer.cpp Branch.cpp Bank.cpp

# Object files are derived from source files
OBJECTS = $(SOURCES:.cpp=.o)

# Default rule
all: $(TARGET)

# Rule to link the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Phony targets
.PHONY: all clean

*/