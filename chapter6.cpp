#include "chapter6.h"
#include <random>

void problem28() {
	int counter = static_cast<int>(AskNumber("How many numbers to add? "));
	string input = string();
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int total = 0;
	for (int i = 0; i < counter; i++)
	{
		input = AskString("Enter a number: ");
		if (all_of(input.begin(),input.end(),isdigit))
		{
			total += stoi(input);
		}
	}
	cout << "The total is " << total << '\n';

	//challenge 1 - done
	//challenge 2 - done
}

void problem29() {
	int answer = 0;
	string question = "What is the rate of return? ";
	cout << question;	cin >> answer;
	while (cin.fail() || answer <= 0)
	{
		if (cin.fail())
		{
			cout << "Sorry. That's not a valid input.\n";
		}
		else if (answer == 0)
		{
			cout << "Rate of return can't be 0.\n";
		}
		else if (answer < 0) {
			cout << "Please enter a positive number.\n";
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << question;	cin >> answer;
	}
	cout << "It will take " << 72 / answer << " years to double your initial investment.\n";

	//challenge done
}

void problem30(){
	for (int i = 0; i < 13; i++)
	{	
		for (int j = 0; j < 13; j++)
		{
			cout << i << " X  " << j << " = " << i * j << "\n";
		}
	}

	cout << "|\t";
	for (size_t i = 0; i < 13; i++)
	{
		cout << "|  " << i << "\t";
	}
	cout << "|\n";

	for (int i = 0; i < 13; i++)
	{
		cout <<"|  " << i << "\t";
		for (int j = 0; j < 13; j++)
		{
			cout << "|  " << i *  j << "\t";
		}
		cout << "|\n";
	}
	//challenge 1 - not yet
	//challenge 2 -done
}

void problem31() {
	int resting_pulse = static_cast<int>(AskNumber("What is your resting pulse? "));
	int age = static_cast<int>(AskNumber("What is your age? "));
	
	cout << "Resting Pulse: " << resting_pulse << "\tAge: " << age << "\n\n";

	cout << "Intensity\t| Rate\n";
	cout << "----------------|--------\n";
	for (int intensity = 55; intensity < 100; intensity+=5)
	{
		cout << intensity << "%\t\t| " << roundf((((220 - age) - resting_pulse) * (intensity / 100.0f)) + resting_pulse) << " bpm\n";
	}

	//challenge - not yet
}

void problem32() {
	cout << "Let's play Guess the Number.";
	bool play = true; 
	std::vector<int> guesses;
	while (play) {
		int difficulty = 0;
		do
		{
			difficulty = AskNumber("Pick a difficulty level\n1 ( 1-10 )\n2 ( 1-100 )\n3 ( 1-1000)\n ");
			if (difficulty < 1 || difficulty > 3)
			{
				cout << "invalid choice.\n";
			}
		} while (difficulty < 1 || difficulty > 3);

		int upper_limit = 0;
		switch (difficulty)
		{
		case 1:
			upper_limit = 10;
			break;
		case 2:
			upper_limit = 100;
			break;
		case 3:
			upper_limit = 1000;
			break;
		default:
			break;
		}

		random_device rd;
		mt19937 mt(rd());
		uniform_int_distribution<int> dist(1, upper_limit);
		int number = dist(mt);
		int guess = static_cast<int>(AskNumber("I have my number. What's your guess? "));;
		auto it = find(guesses.begin(), guesses.end(), guess);
		bool bAlreadyGuessed = (it != guesses.end());
		guesses.push_back(guess);
		while (guess != number)
		{
			if (guess < number)
			{
				cout << "Too low.\t";
			}
			else if (guess > number) {
				cout << "Too high.\t";
			}
			if (bAlreadyGuessed) {
				cout << "You have already guessed that number.\n";
			}
			guess = static_cast<int>(AskNumber("Guess again: "));
			it = find(guesses.begin(), guesses.end(), guess);
			bAlreadyGuessed = (it != guesses.end());
			guesses.push_back(guess);

		}
		string unit = string();
		if (guesses.size() > 1)
		{
			unit = "guesses";
		}
		else {
			unit = "guess";
		}
		cout << "You got it in " << guesses.size() << " " << unit << "!\n";

		switch (guesses.size())
		{
		case 1:
			cout << "You're a mind reader!\n";
			break;
		case 2:
		case 3:
		case 4:
			cout << "Most impressive.\n";
			break;
		case 5:
		case 6:
			cout << "You can do better than that.\n";
			break;
		default:
			cout << "Better luck next time.\n";
			break;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		guesses.clear(); 

		play = AskYesNo("Play again? ");
	}
	cout << "Goodbye!\n";

	//Challenge 1 - done
	//Challenge 2 - done
	//Challenge 3 - not yet
}