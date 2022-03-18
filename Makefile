#
# Starter makefile for Assignment 8: confMAKER: The conference management tool
# Typing 'make' or 'make confmaker' will create an executable file for testing
#

# Start by defining variables for the compiler and compiler flags (makes it easy to change later)
# We can then use the variables later with $()

CC = g++
CFLAGS = -g -Wall -Wextra

# Simply calling 'make' will invoke whatever entry comes first in the file
# We've set it up to be the default entry (a good habit)

default: confmaker

# List the object files needed to create the executable file.  For this assignment:
# Attendees.o, main.o

confmaker: Attendees.o main.o
	$(CC) $(CFlags) -o confmaker Attendees.o main.o

# First, the rule to create Attendees.o

Attendees.o: Attendees.cpp Attendees.h
	$(CC) $(CFLAGS) -c Attendees.cpp

# Then, the rule to create main.o

main.o:	main.cpp Attendees.h
	$(CC) $(CFLAGS) -c main.cpp

# Now the logic to clean things up! (invoked with 'make clean')

clean:
	$(RM) confmaker *.o *~
