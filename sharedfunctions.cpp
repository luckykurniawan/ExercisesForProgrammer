#include "sharedfunctions.h"

float AskNumber(string question) {
	float answer = 0;
	cout << question;	cin >> answer;
	while (cin.fail() || answer < 0)
	{
		if (cin.fail())
		{
			cout << "Please enter a valid number.\n";
		}
		else if (answer < 0) {
			cout << "Please enter a positive number.\n";
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << question;	cin >> answer;
	}
	return answer;
}

string AskString(string question) {
	string answer = string();
	cout << question; getline(cin, answer);
	return answer;
}

bool AskYesNo(string question) {
	string input = string();
	bool answer = true;
	do
	{
		input = AskString(question);
		transform(input.begin(), input.end(), input.begin(), tolower);
	} while ((input != "y") && (input != "yes") && (input != "n") && (input != "no"));

	if ((input == "n") || (input == "no"))
	{
		answer = false;
	}

	return answer;
}