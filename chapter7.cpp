#include "chapter7.h"
#include <random>

void problem33() {
	const int arraySize = 4;
	string magic8BallResponds[arraySize] = { "Yes", "No", "Maybe", "AskLater" };
	cout << "What's your question? ";
	string answer;
	cin >> answer;
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, arraySize - 1);
	int respondNum = dist(mt);
	cout << magic8BallResponds[respondNum] << "\n";
}
