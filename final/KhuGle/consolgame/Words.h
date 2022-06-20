#pragma once
#include <string>
#include <vector>
using namespace std;

const int WIDTH = 30;
const int HEIGHT = 30;

class Letters {
	//private:
	char letter;
	int location[2];

public:
	void setLetterSpelling(char letter) {
		this->letter = letter;
	}
	void setLetterLocation(int row, int col) {
		location[0] = row;
		location[1] = col;
	}

	void getLetterSpelling(char& letter) {
		letter = this->letter;
	}
	void getLetterLocation(int& row, int& col) {
		row = location[0];
		col = location[1];
	}

	void operator=(Letters item) {
		letter = item.letter;
		location[0] = item.location[0];
		location[1] = item.location[1];
	}
};


class Word {

public:
	Letters spell[16];
	string info;
	int length;
	bool answer;

	Word(string name = "..." , string info = "...");
	void getWordLocation(int row, int col, int direction);
	void operator=(Word item);
	void getWordInfo(string info);
};
