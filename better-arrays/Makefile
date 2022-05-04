#
# Makefile for Homework 11 - Better Arrays
# Typing 'make' or 'make arrayTest' will create an executable file for testing
#

# Start by defining variables for the compiler and compiler flags (makes it easy to change later)
# We can then use the variables later with $()

CC = g++
CFLAGS = -g -Wall -Wextra

# Simply calling 'make' will invoke whatever entry comes first in the file
# We've set it up to be the default entry (a good habit)

default: arrayTest

# List the object files needed to create the executable file.
# main.o

arrayTest:  main.o
	$(CC) $(CFlags) -o arrayTest main.o

# Then, the rule to create main.o

main.o: main.cpp Array.h
	$(CC) $(CFLAGS) -c main.cpp

# Now the logic to clean things up! (invoked with 'make clean')

clean:
	$(RM) arrayTest *.o *~
