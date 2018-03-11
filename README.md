Project 2 for CMP SCI 2250 at University of Missouri Saint Louis 2/23/18 by Bryan Fisk

Project Stipulations:

Overview: This project is for testing the use of structures, arrays and string handling functions. In this assignment you will be prompting the user to enter an english sentence. The program will then convert it to the code Pig Latin . Your program will then output this Pig Latin to the screen.

Note: While there are many ways to do conversions to pig latin, I will require that you follow the procedures below, all of which will use the following structure: 

struct Word {
 string english;
 string piglatin;
};

Part 1. Write a function that takes in an English sentence as one string. This function should first calculate how many “words” are in the sentence (words being substrings separated by whitespace). It should then allocate a dynamic array of size equal to the number of words. The array contains Word structures (i.e. array of type Word).  The function would then store each word of that sentence to the english field of the corresponding structure. The function should then return this array to the calling function using the return statement, along with the array size using a reference parameter.

This function should also remove all capitalization and special characters other than letters. Implement the function with the following prototype

Word * splitSentence(const string words, int &size);
Part 2. Write a function that takes in an array of Word structures and the size of the array and converts each english field to the corresponding piglatin field.

void convertToPigLatin(Word [] wordArr, int size);
To do this conversion, if a word starts with a consonant, the piglatin conversion of the word involves moving the first letter of the word to the end of the string and then adding “ay” to the end.

pig -> igpay

cat -> atcay

dog -> ogday

If the word starts with a vowel, simply add “way” to the end of the word

apple -> appleway

are -> areway

Part 3. Write a function that takes in an array of Word structures and outputs the pig latin part of it to the screen, with each word separated by a space.

void displayPigLatin(const Word [] wordArr, int size);
Example:

Please enter a string to convert to PigLatin:
Casino is nothing but a Goodfellas knockoff
Output:
oodfellasgay isway othingnay utbay away oodfellasgay nockoffkay 
Error conditions: Your program should get rid of all punctuation and special characters other than letters. Your program should be able to deal with there being two or more spaces between words.

Note: Make sure to follow proper programming style, as per the style supplement.
