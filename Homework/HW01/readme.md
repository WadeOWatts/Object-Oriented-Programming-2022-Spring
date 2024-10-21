# Homework 1 Description

### Programming Project 6

Write a program that allows the user to type in any one-line question and then answers that question. The program will not really pay any att ntion to the question, but will simply read the question line and discard all that it reads. It always gives one of the following answers:

I'm not sure, but I think you will find the answer in Chapter #N.
That's a good question.

If I were you, I would not worry about such things.

That question has puzzled philosophers for centuries.

I don't know. I'm just a machine.

Think about it and the answer will come to you.

I used to know the answer to that question, but I've forgotten it.
The answer can be found in a secret place in the woods.

These answers are stored in a file (one answer per line), and your program simply reads the next answer from the file and writes it out as the answer to the question. After your program has read the entire file, it simply closes the file, reopens the file, and starts down the list of answers again.

Whenever your program outputs the first answer, it should replace the two symbols #N with a number between 1 and 18 (including the possibility of 1 and 18). In order to choose a number between 1 and 18, your program should initialize a variable to 18 and decrease the variable’s value by 1 each time it outputs a number so that the chapter numbers count backward from 18 to 1. When the variable reaches the value 0, your program should change lue back to 18. Give the number 17 the name NUMBER_OF_CHAPTERS with a global named constant declaration using the *const* modifier.

*(Hint: Use the function newLine defined in this chapter.)*

### Programming Project 7

This project is the same as Programming Project 6, except that int this project your program will use a more sophisticated method for choosing the answer to a question. When your program reads a question, it counts the number of characters in the question and stores the number in a variable named *count*. It then responds with answer number count % ANSWERS. The first answer in the file is answer number 0, the next is answer number 1, then 2, and so forth. ANSWERS is defined in a constant declaration, as shown next, so that it is equal to the number of answers in the answer file:

const int ANSWERS = 8;

This way you can change the answer file so that it contains more or fewer answers and you need change only the constant declaration to make your program work correctly for a different number of possible answers. Assume that the answer listed first in the file will always be the following, even if the answer file is changed:

I'm not sure, but I think you will find the answer in Chapter #N.

When replacing the two characters #N with a number, use the number (count % NUMBER_OF_CHAPTERS + 1), where count is the variable discussed above, and NUMBER_OF_CHAPTERS is a global named constant defined to be equal to the number of chapters in this book.
