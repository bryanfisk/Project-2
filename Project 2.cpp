#include "stdafx.h"
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

struct Word {
	string english;
	string piglatin;
};

Word * splitSentence(const string words, int &size);
int findNthChar(string s, char c, int nth);
void convertToPigLatin(Word wordArr[], int size);
void displayPigLatin(const Word wordArr[], int size);

int main()
{
	string phrase;
	int size;
	cout << "Please enter a string to convert to PigLatin:" << endl;
	getline(cin, phrase);
	Word * outputWord = new Word;
	outputWord = splitSentence(phrase, size);
	convertToPigLatin(outputWord, size);
	displayPigLatin(outputWord, size);
	return 0;
}

Word * splitSentence(const string words, int &size) {	//Splits the input sentence into individual words
	size = 1;
	for (int i = 0; i < words.length(); i++) {	//counts spaces and adds 1 to get the number of words
		if (isspace(words.at(i))) size++;
	}

	Word * outputWords = new Word[size];

	if (size != 1) {	//if size == 1 then there's no spaces to count so the else statement down there somewhere accounts for that
		for (int i = 0; i < size; i++) {	//for loop does the actual splitting
			outputWords[i].english = words.substr(findNthChar(words, ' ', i), findNthChar(words, ' ', i + 1) - findNthChar(words, ' ', i));
		}
	}
	else {
		outputWords[0].english = words;
	}

	for (int i = 0; i < size; i++) {	//lowercases capitals and removes non-alphabetical characters
		for (int j = 0; j < outputWords[i].english.size(); j++) {
			outputWords[i].english[j] = tolower(outputWords[i].english[j]);
			if (isalpha(outputWords[i].english[j]) == 0) {
				outputWords[i].english.erase(j,1);
				j--;	//accounts for erasing an element in a string, the string adjusts for the missing space and this line adjusts the value of j to account for that
			}
		}
	}
	return outputWords;
}

void convertToPigLatin(Word wordArr[], int size) {
	for (int i = 0; i < size; i++) {	//accounts for if the input has two consecutive spaces; if two consecutive spaces were to be entered it'd create empty strings and cause problems
		if (wordArr[i].english.empty()) {
			wordArr[i].english = " ";
		}
		else if (wordArr[i].english[0] == 'a' || wordArr[i].english[0] == 'e' || wordArr[i].english[0] == 'i' || wordArr[i].english[0] == 'o' || wordArr[i].english[0] == 'u') {	//what to do if word starts with a vowel
			wordArr[i].piglatin = wordArr[i].english;
			wordArr[i].piglatin.append("way");
		}
		else if (wordArr[i].english != " ") {		//what to do if the word starts with a consonant
			wordArr[i].piglatin.append(wordArr[i].english, 1, wordArr[i].english.length() - 1);
			wordArr[i].piglatin.append(wordArr[i].english, 0, 1);
			wordArr[i].piglatin.append("ay");
		}
	}
}

void displayPigLatin(const Word wordArr[], int size) {		//displays piglatin sentence to message buffer
	for (int i = 0; i < size; i++) {
		cout << wordArr[i].piglatin << ' ';
	}
	cout << endl;
}

int findNthChar(string s, char c, int nth) {		//finds the position of the nth instance of a character c; returns position + 1 so that spaces aren't stored with the word
	int count = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == c) {
			count++;
			if (count == nth) {
				return i+1;
			}
		}
	}
	return 0;
}