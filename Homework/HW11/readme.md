# Homework 11 Description

## Problem Description
You have collected a file of movie ratings where each movie is rated from 1 (bad) to 5 (excellent). The first line of the file is a number that identifies how many ratings are in the file. Each rating then consists of two lines: the name of the movie followed by the numeric rating from 1 to 5.

### Sample Input
Here is a sample rating file with four unique movies and seven ratings:
```
7
Harry Potter and the Order of the Phoenix
4
Harry Potter and the Order of the Phoenix
5
The Bourne Ultimatum
3
Harry Potter and the Order of the Phoenix
4
The Bourne Ultimatum
4
Wall-E
4
Glitter
1
```

### Program Requirements
Write a program that reads a file in this format, calculates the average rating for each movie, and outputs the average along with the number of reviews.

### Desired Output
Here is the desired output for the sample data:
```
Glitter: 1 review, average of 1 / 5
Harry Potter and the Order of the Phoenix: 3 reviews, average of 4.3 / 5
The Bourne Ultimatum: 2 reviews, average of 3.5 / 5
Wall-E: 1 review, average of 4 / 5
```

### Implementation Details
- Use a map or multiple maps to calculate the output.
- Your map(s) should index from a string representing each movie’s name to integers that store the number of reviews for the movie and the sum of the ratings for the movie.