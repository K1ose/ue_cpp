#pragma once
#include "BullCowGame.h"
#include <map>
using namespace std;
using int32 = int;

BullCowGame::BullCowGame() {
	/* TODO BullCowGame.cpp, to reset the game*/
	Reset();
}

int32 BullCowGame::GetMaxTries() const
{
	/* TODO BullCowGame.cpp, get max tries with length of word */
	map<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,16},{7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int32 BullCowGame::GetCurrentTry() const {
	return MyCurrentTry;
}

int32 BullCowGame::GetHiddenWordLength() const {
	return MyHiddenWord.length();
}

bool BullCowGame::IsGameWon() const
{
	return GameIsWon;
}

GuessStatus BullCowGame::CheckGuessValidity(string guess) const
{
	if (!IsIsogram(guess))
		return GuessStatus::Not_Isogram;
	else if (!IsLowercase(guess))
		return GuessStatus::Not_Lowercase;
	else if (guess.length() != GetHiddenWordLength())
		return GuessStatus::Wrong_length;
	else
		return GuessStatus::OK;
}

void BullCowGame::Reset()
{
	/* TODO Reset() define a hidden word and init other values*/
	const string hidden_word = "phone";
	MyHiddenWord = hidden_word;
	MyCurrentTry = 1;
	GameIsWon = false;
	return;
}

BullCowCount BullCowGame::SubmitValidGuess(string guess)
{
	MyCurrentTry++;
	BullCowCount count;
	int32 wordlength = MyHiddenWord.length();

	for (int32 i = 0; i < wordlength; i++) {
		for (int32 j = 0; j < wordlength; j++) {
			if (guess[j] == MyHiddenWord[i]) {
				if (i == j)
					count.Bulls++;
				else
					count.Cows++;
			}
		}
	}
	if (count.Bulls == wordlength)
		GameIsWon = true;
	else
		GameIsWon = false;
	return count;
}

string BullCowGame::GetWord()
{
	return MyHiddenWord;
}

bool BullCowGame::IsIsogram(string word) const
{
	if (word.length() <= 1)
		return true;
	map<char, bool> letterSeen;
	for (auto letter : word) {
		letter = tolower(letter);
		if (letterSeen[letter])
			return false;
		else
			letterSeen[letter] = true;
	}
	return true;
}

bool BullCowGame::IsLowercase(string word) const
{
	for (auto letter : word) {
		if (!islower(letter)) {
			return false;
		}
	}
	/*
	for(int i = 0;i < word.length();i++)
		if(!islower(word[i])
			return false;
	return true;
	*/
	return true;
}

