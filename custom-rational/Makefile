#
# Makefile for Homework 10 - Custom Rationals
# Typing 'make' or 'make rational' will create an executable file for testing
#

# Start by defining variables for the compiler and compiler flags (makes it easy to change later)
# We can then use the variables later with $()

CC = g++
CFLAGS = -g -Wall

# Simply calling 'make' will invoke whatever entry comes first in the file
# We've set it up to be the default entry (a good habit)

default: rational

# List the object files needed to create the executable file.
# Rational.o, main.o

rational: Rational.o main.o
	$(CC) $(CFlags) -o rational Rational.o main.o

# First, the rule to create Rational.o

Rational.o: Rational.cpp Rational.h
	$(CC) $(CFLAGS) -c Rational.cpp

# Then, the rule to create main.o

main.o: main.cpp Rational.h
	$(CC) $(CFLAGS) -c main.cpp

# Now the logic to clean things up! (invoked with 'make clean')

clean:
	$(RM) rational *.o *~
