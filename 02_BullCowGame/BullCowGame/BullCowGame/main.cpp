#pragma

#include <iostream>
#include <string>
#include "BullCowGame.h"
using namespace std;

using int32 = int;

void PrintIntro();
void PlayGame();
string GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

BullCowGame BCGame;

int main() {
	bool PlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		PlayAgain = AskToPlayAgain();
	} while (PlayAgain);
	return 0;
}

void PrintIntro()
{
	/* TODO print the game introduction */
	cout << "Hello, welcome to BullCowGame -- word game" << endl;
	cout << "Please guess the " << BCGame.GetHiddenWordLength() << " letter isogram" << endl;
	return;
}

void PlayGame()
{
	/* TODO start to play game */
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		string guess = GetValidGuess();
		BullCowCount count = BCGame.SubmitValidGuess(guess);
		cout << "Bulls = " << count.Bulls << endl;
		cout << "Cows = " << count.Cows << endl;
	}
	PrintGameSummary();
	return;
}

string GetValidGuess()
{
	string guess = "";
	GuessStatus status = GuessStatus::Invalid_Status;
	do {
		// get a guess from the player
		int32 currentTry = BCGame.GetCurrentTry();
		cout << "Try " << currentTry << " of " << BCGame.GetMaxTries() << endl;
		cout << "Enter your guess: ";
		getline(cin, guess);

		// check the guess and give feedback
		status = BCGame.CheckGuessValidity(guess);
		switch (status) {
		case GuessStatus::Wrong_length:
			cout << "please enter a" << BCGame.GetHiddenWordLength() << " word please" << endl;
			break;
		case GuessStatus::Not_Isogram:
			cout << "please enter a word without repeating letters" << endl;
			break;
		case GuessStatus::Not_Lowercase:
			cout << "Please enter all lowercase letters" << endl;
			break;
		default:
			break;
		}
	} while (status != GuessStatus::OK);
	return guess;
}

bool AskToPlayAgain()
{
	/* TODO ask to play again*/
	string isPlayAgain = "";
	cout << "Play again? input yes or no." << endl;
	getline(cin, isPlayAgain);
	if (isPlayAgain == "yes")
		return true;
	else if (isPlayAgain == "no")
		return false;
}

void PrintGameSummary()
{
	/* TODO game summary */
	if (BCGame.IsGameWon()) {
		cout << "well done!" << endl;
		cout << "the word is " << BCGame.GetWord() << endl;
	}
	else {
		cout << "Sorry, maybe better luck next time" << endl;
	}
}
