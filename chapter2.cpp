#include "chapter1.h"
#include "chapter2.h"

void Problem1() {
	string name = "";
	cout << "What is your name? "; cin >> name;
	string output = "Hello " + name + ", nice to meet you!\n";
	cout << output;
	//Challenge 1 - done, maybe? (still using a variable in the procedure) (Problem1_C1())
	//Challenge 2 - not yet
}

void Problem1_C1() {
	cout << "Hello " << AskString("What is your name?") << ", nice to meet you!\n";
}

void Problem2() {
	string input = "";
	do
	{
		cout << "What is the input string? ";
		getline(cin, input);
		if (input.empty())
		{
			cout << "Input can't be empty\n";
		}
	} while (input.empty());
	cout << input << " has " << input.length() << " characters.\n";
	//Challenge 1 - done
	//Challenge 2 - need to find GUI library?
}

void Problem3() {
	string quote = AskString("What is the quote? ");
	string name = AskString("Who said it ? ");
	cout << name + " says, \"" + quote + "\"\n";
	//Challenge 1 - not yet
}

void Problem4() {
	string answer = "";
	answer = AskString("Enter a noun: ");
	char* noun = new char[answer.length() + 1];
	strcpy_s(noun, answer.length() + 1, answer.c_str()); //NOTE: _s function only works on microsoft platform 

	answer = AskString("Enter a verb: ");
	char* verb = new char[answer.length() + 1];
	strcpy_s(verb, answer.length() + 1, answer.c_str());

	answer = AskString("Enter an adjective: ");
	char* adjective = new char[answer.length() + 1];
	strcpy_s(adjective, answer.length() + 1, answer.c_str());

	answer = AskString("Enter an adverb: ");
	char* adverb = new char[answer.length() + 1];
	strcpy_s(adverb, answer.length() + 1, answer.c_str());

	printf("Do you %s your %s %s %s? That's hilarious!\n", noun, verb, adjective, adverb);

	delete[] noun;
	delete[] verb;
	delete[] adjective;
	delete[] adverb;

	//Challenge 1 - not yet
	//Challenge 2 - not yet
}

void Problem5() {
	int a = static_cast<int>(AskNumber("What is the first number? "));
	int b = static_cast<int>(AskNumber("What is the second number? "));
	
	CalculateNumber(a,b);
	//Challenge 1 - done
	//Challenge 2 - done
	//Challenge 3 - done
	//Challenge 4 - need to find GUI library?
}

void CalculateNumber(int a, int b) {
	cout << a << " + " << b << " = " << a + b << "\n"
		<< a << " - " << b << " = " << a - b << "\n"
		<< a << " * " << b << " = " << a * b << "\n"
		<< a << " / " << b << " = " << a / b << "\n";
}

void Problem6() {
	string sAge = AskString("What is your current age? ");
	string swishToRetireAge = AskString("At what age would you like to retire? ");
	int age = stoi(sAge);
	int wishToRetireAge = stoi(swishToRetireAge);
	int difference = wishToRetireAge - age;
	if (difference < 0)
	{
		cout << "You can already retire.\n";
	}
	else
	{
		cout << "You have " << difference << " years left until you can retire.\n";
		time_t now = time(0);
		tm ltime;
		localtime_s(&ltime, &now);
		int currentYear = 1900 + ltime.tm_year;
		cout << "It's " << currentYear << ", so you can retire in " << currentYear + difference << ".\n";
	}
	//Challenge 1 - done
}