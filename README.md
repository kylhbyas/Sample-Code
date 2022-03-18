# hw-08-actual-dynamic-starter
Readme goes here!

Please use the requirements from the previous assignment as a template for content.

# HW08 -confMAKER: The conference management tool 
Name: <your name here> Kyle Byassee
Date: <date of last update> 2022-03-18

## Required Files
* list
* files
* here
* (along with a brief description of the purpose of each)

* Makefile
  controls compilation and cleans temporary and extraneous files.
* Attendees.h
  Declares the base class.
* Attendees.cpp
  Contains the definitions of the methods for the base class.
* main.cpp
  Contains the main function.


## Compilation Instructions
How do we compile your program?
    To compile type <make> which calls the Makefile.

## Program usage
How do we run your program?  Does it expect any inputs?
    To run the program type <make> to compile and make the executable then type <./confmaker> to run the executable.
    It prompts the user for a filename.

## Notes
Any extra notes, such as:
* What is working?
  The entire program is working as intended.

* What are the limitations of your program?
  The input file must be properly formatted.

* What design decisions did you make?
  Consistency was the primary consideration at the time of writing.

* Is there anything you wish to draw our attention to? (cool trick, extra credit, strange logic, problem area, etc)
  The while loop in the readAttendeeData method requires no priming read to be performed due to the structure of the loop causing a segmentation fault.


You may want to check out a [GitHub Markdown Guide](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax).  Also, emojis! :tada: :unicorn: :octocat:
