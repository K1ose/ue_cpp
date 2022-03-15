#pragma once
#include <string>
using namespace std;

using int32 = int;

struct BullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class GuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_length,
	Not_Lowercase
};

class BullCowGame {
public:
	BullCowGame();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	GuessStatus CheckGuessValidity(string) const;
	void Reset();
	BullCowCount SubmitValidGuess(string);
	string GetWord();

private:
	int32 MyCurrentTry;
	string MyHiddenWord;
	bool GameIsWon;
	bool IsIsogram(string) const;
	bool IsLowercase(string) const;
};