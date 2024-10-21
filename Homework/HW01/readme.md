# Homework 1 Description

## Programming Project 6

## Project Description
Write a program that allows the user to type in any one-line question and then answers that question. The program will not actually pay any attention to the question, but will simply read the question line and discard all that it reads. It always gives one of the following answers:
1. "I'm not sure, but I think you will find the answer in Chapter #N."
2. "That's a good question."
3. "If I were you, I would not worry about such things."
4. "That question has puzzled philosophers for centuries."
5. "I don't know. I'm just a machine."
6. "Think about it and the answer will come to you."
7. "I used to know the answer to that question, but I've forgotten it."
8. "The answer can be found in a secret place in the woods."

These answers are stored in a file (one answer per line), and your program simply reads the next answer from the file and writes it out as the answer to the question. After your program has read the entire file, it simply closes the file, reopens the file, and starts down the list of answers again.

## Additional Requirements
Whenever your program outputs the first answer, it should replace the two symbols `#N` with a number between 1 and 18 (including the possibility of 1 and 18). In order to choose a number between 1 and 18, your program should initialize a variable to 18 and decrease the variable’s value by 1 each time it outputs a number so that the chapter numbers count backward from 18 to 1. When the variable reaches the value 0, your program should change its value back to 18. Give the number 17 the name `NUMBER_OF_CHAPTERS` with a global named constant declaration using the `const` modifier.

**Hint**: Use the function `newLine` defined in this chapter.

## Programming Project 7
This project is the same as Programming Project 6, except that in this project, your program will use a more sophisticated method for choosing the answer to a question. When your program reads a question, it counts the number of characters in the question and stores the number in a variable named `count`. It then responds with answer number `count % ANSWERS`. The first answer in the file is answer number 0, the next is answer number 1, then 2, and so forth.

`ANSWERS` is defined in a constant declaration, as shown next, so that it is equal to the number of answers in the answer file:
```cpp
const int ANSWERS = 8;
```

This way, you can change the answer file so that it contains more or fewer answers, and you need to change only the constant declaration to make your program work correctly for a different number of possible answers.

### Example Output
Assume that the answer listed first in the file will always be the following, even if the answer file is changed:
```
I'm not sure, but I think you will find the answer in Chapter #N.
```

When replacing the two characters `#N` with a number, use the number `(count % NUMBER_OF_CHAPTERS + 1)`, where `count` is the variable discussed above, and `NUMBER_OF_CHAPTERS` is a global named constant defined to be equal to the number of chapters in this book.
