#
# Makefile for HW 9 - Chess 3: With a Vengeance
# Typing 'make' or 'make knight' will create an executable file for testing
#

# Start by defining variables for the compiler and compiler flags (makes it easy to change later)
# We can then use the variables later with $()

CC = g++
CFLAGS = -g -Wall -Wextra

# Simply calling 'make' will invoke whatever entry comes first in the file
# We've set it up to be the default entry (a good habit)

default: knight

# List the object files needed to create the executable file.
# Knight.o, main.o

knight:	Knight.o main.o
	$(CC) $(CFlags) -o knight Knight.o main.o

# First, the rule to create Knight.o

Knight.o: Knight.cpp Knight.h
	$(CC) $(CFLAGS) -c Knight.cpp

# Then, the rule to create main.o

main.o: main.cpp Knight.h
	$(CC) $(CFLAGS) -c main.cpp

# Now the logic to clean things up! (invoked with 'make clean')

clean:
	$(RM) knight *.o *~
