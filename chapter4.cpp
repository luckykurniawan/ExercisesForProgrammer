#include "chapter4.h"


void Problem14() {
	float amount = AskNumber("What is the order amount? ");
	float total = roundf(amount * 100) / 100;
	bool isWinconsin = false;
	string answer;
	cout << "What is the state? ";
	cin >> answer;
	transform(answer.begin(), answer.end(), answer.begin(), tolower);
	isWinconsin = ((answer == "wi") || (answer == "wisconsin"));
	if (isWinconsin) {
		float subtotal = total;
		cout << "The subtotal is $" << fixed << setprecision(2) << subtotal << ".\n";
		float tax = 5.5f / 100 * subtotal;
		tax = roundf(tax * 100) / 100;
		cout << "The tax is $" << fixed << setprecision(2) << tax << ".\n";
		total += tax;
	}
	cout << "The total is $" << fixed << setprecision(2) << total << ".\n";
	//Challenge 1 - done
	//Challenge 2 - done
}

void Problem15() {
	const string PASSWORD = "abc$123";
	string input = "";
	cout << "What is the password?\n";
	cin >> input;
	if (input.compare(PASSWORD) == 0)
	{
		cout << "Welcome!\n";
	}
	else {
		cout << "I don't know you.\n";
	}
	//Challenge 1 - not yet;
	//Challenge 2 - not yet;
	//Challenge 3 - not yet;
}

void Problem16() {
	int age = 0;
	cout << "What is your age? ";	cin >> age;
	while (cin.fail() || age < 0)
	{
		cout << "Please enter a valid age.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "What is your age?";	cin >> age;
	}
	string result = (age > 15) ? "old" : "not old";
	cout << "You are " << result << " enough to legally drive.\n";
	//Challenge 1 - done
	//Challenge 2 - not yet
}

void Problem17() {
	/*float weight;
	string gender;
	float alcoholConsumed;



	do
	{
		answer = Ask(question);
		transform(answer.begin(), answer.end(), answer.begin(), tolower);
		accepted = ((answer == "m") || (answer == METER)) || ((answer == "f") || (answer == FEET));
	} while (!accepted);*/
	//https://www.teamdui.com/bac-calculator-widmark-formula-blood-alcohol-content-dui/
	//https://en.wikipedia.org/wiki/Blood_alcohol_content

}

void Problem18() {
	const string CELSIUS = "Celsius";
	const string FAHRENHEIT = "Fahrenheit";
	const string KELVIN = "Kelvin";

	cout << "Press C to convert from Celsius.\n";
	cout << "Press F to convert from Fahrenheit.\n";
	cout << "Press K to convert from Kelvin.\n";
	string answer = "";
	bool isAnswerAccepted = false;
	do
	{
		answer = AskString("Your choice: ");
		transform(answer.begin(), answer.end(), answer.begin(), tolower);
		isAnswerAccepted = ((answer == "f") || (answer == "c") || (answer == "k"));
		if (!isAnswerAccepted)
			cout << "Invalid choice.\n";
	} while (!isAnswerAccepted);

	string instruction = "Please enter the temperature in ";
	float srcTemp = 0;
	float dstTemp1 = 0;
	float dstTemp2 = 0;
	string otherTemp1 = "";
	string otherTemp2 = "";

	if (answer == "c") {
		srcTemp = AskNumber(instruction + CELSIUS + ": ");
		dstTemp1 = CelsiusToFahrenheit(srcTemp);
		dstTemp2 = CelsiusToKelvin(srcTemp);
		otherTemp1 = FAHRENHEIT;
		otherTemp2 = KELVIN;
	}
	else if (answer == "f") {
		srcTemp = AskNumber(instruction + FAHRENHEIT + ": ");
		dstTemp1 = FahrenheitToCelsius(srcTemp);
		dstTemp2 = FahrenheitToKelvin(srcTemp);
		otherTemp1 = CELSIUS;
		otherTemp2 = KELVIN;
	}
	else if (answer == "k") {
		srcTemp = AskNumber(instruction + KELVIN + ": ");
		dstTemp1 = KelvinToCelsius(srcTemp);
		dstTemp2 = KelvinToFahrenheit(srcTemp);
		otherTemp1 = CELSIUS;
		otherTemp2 = FAHRENHEIT;
	}

	cout << "The temperature in " << otherTemp1 << " is " << dstTemp1 << ".\n";
	cout << "The temperature in " << otherTemp2 << " is " << dstTemp2 << ".\n";

	//Challenge 1 - done
	//Challenge 2 
	//Challenge 3 - not yet
	//Challenge 4 - done
}

float CelsiusToFahrenheit(float cels) {
	return (cels * 9 / 5) + 32;
}

float FahrenheitToCelsius(float fahr) {
	return (fahr - 32) * 5 / 9;
}

float CelsiusToKelvin(float cels) {
	return cels + 273.15f;
}

float KelvinToCelsius(float kelv) {
	return kelv - 273.15f;
}

float FahrenheitToKelvin(float fahr) {
	float temp = FahrenheitToCelsius(fahr);
	return CelsiusToKelvin(temp);
}

float KelvinToFahrenheit(float kelv) {
	float temp = KelvinToCelsius(kelv);
	return CelsiusToFahrenheit(temp);
}

void Problem19() {

}

void Problem21() {
	int in = 0;
	const string a[] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	cout << "Please enter the number of the month: ";
	cin >> in;
	if (in < 1 || in > 12)
	{
		cout << "Please only input number between 1 and 12";
	}
	else {
		cout << "The name of the month is " << a[in - 1] << endl;
	}
	//Challenge 1 & 2 - not yet
}

void Problem22() {
	vector<int> inputs;
	vector<int>::iterator it;
	int input;
	int result = INT_MIN;
	//get unlimited input
	for (int i = 1; ; i++)
	{
		cout << "Enter the " << i << GetOrdinalSuffix(i) << " number:";
		cin >> input;
		it = find(inputs.begin(), inputs.end(), input);
		//stop loop if you enter anything other than integer
		if (cin.fail())
		{
			break;
		}
		//ask user for another number if number is already inputted
		while (it != inputs.end()) {
			cout << "Number is already inputted.\n";
			cout << "Enter the " << i << GetOrdinalSuffix(i) << " number:";
			cin >> input;
			it = find(inputs.begin(), inputs.end(), input);
		}
		//saving the inputted number
		inputs.push_back(input);
	}

	for (size_t i = 0; i < inputs.size(); i++)
	{
		cout << inputs[i] << " ";
		if (inputs[i] > result)
			result = inputs[i];
	}
	cout << '\n';
	cout << "The largest number is " << result << endl;

	//Challenge 1 2 3 - done
}


string GetOrdinalSuffix(int num) {
	string suffix = "th";
	if ((1 <= num % 10) && (num % 10 <= 3))
	{
		if ((num % 100 < 10) || (num % 100 > 20))
		{
			suffix = (num % 10 == 1) ? "st" : (num % 10 == 2) ? "nd" : "rd";
		}
	}
	return suffix;
}

void Problem23() {
	cout << "Answer with yes/y or no/n\n";
	if (AskYesNo("Is the car silent when you turn the key? ")) {
		if (AskYesNo("Are the battery terminals corroded? "))
		{
			cout << "Clean terminals and try starting again.\n";
		}
		else {
			cout << "Replace cables and try again.\n";
		}
	}
	else {
		if (AskYesNo("Does the car make a clicking noise? "))
		{
			cout << "Replace the battery.\n";
		}
		else {
			if (AskYesNo("Does the car crank up but fail to start? "))
			{
				cout << "Check spark plug connections.\n";
			}
			else {
				if (AskYesNo("Does the engine start and then die? "))
				{
					if (AskYesNo("Does your car have fuel injection? "))
					{
						cout << "Get it in for service.\n";
					}
					else {
						cout << "Check to ensure the choke is opening and closing.\n";
					}
				}
			}	
		}
	}
}