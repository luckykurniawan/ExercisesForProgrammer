#include "chapter3.h"

void Problem7() {
	const double  CONVERSION_FACTOR = 0.09290304;
	const string METER = "meters";
	const string FEET = "feet";

	string question = "Do you want to calculate in meters or feet?\n(Please answer with meters/m or feet/f) : ";
	string answer = "";
	string unit = "";
	string unit2 = "";

	bool accepted = false;

	do
	{
		answer = AskString(question);
		transform(answer.begin(), answer.end(), answer.begin(), tolower);
		accepted = ((answer == "m") || (answer == METER)) || ((answer == "f") || (answer == FEET));
	} while (!accepted);

	string questionLength = "What is the length of the room in ";
	string questionWidth = "What is the length of the room in ";

	if ((answer == "m") || (answer == METER)) {
		unit = METER;
		unit2 = FEET;
	}
	else {
		unit = FEET;
		unit2 = METER;
	}

	questionLength += unit + "? ";
	questionWidth += unit + "? ";

	float length = AskNumber(questionLength);
	float width = AskNumber(questionWidth);

	cout << "You entered dimensions of " << length << " " << unit
		<< " by " << width << " " << unit << ".\n";

	float area = length * width;

	cout << "The area is\n" << area << " square " << unit << "\n";

	float area2 = 0;

	if ((answer == "m") || (answer == METER)) {
		area2 = static_cast<float> (area / CONVERSION_FACTOR);
	}
	else {
		area2 = static_cast<float> (area * CONVERSION_FACTOR);
	}

	cout << area2 << " " << unit2;
	//Challenge 1 - done 
	//Challenge 2 - done 
	//Challenge 3 - need to find GUI library?
}

void Problem8() {
	int people = static_cast<int> (AskNumber("How many people? "));
	int pizza = static_cast<int> (AskNumber("How many pizzas do you have? "));
	int allPizzaPieces = pizza * 8;
	int piecePerPerson = 0;
	if (people != 0)
		piecePerPerson = allPizzaPieces / people;
	int leftover = allPizzaPieces - piecePerPerson * people;

	string pizzaUnit = DecideSingleorPluralUnit(pizza, "pizzas");
	string piecePerPersonUnit = DecideSingleorPluralUnit(piecePerPerson, "pieces");
	string leftoverUnit = DecideSingleorPluralUnit(leftover, "pieces");

	cout << people << " people with " << pizza << " " << pizzaUnit << "\n";
	cout << "Each person gets " << piecePerPerson << " " << piecePerPersonUnit << " of pizza.\n";
	cout << "There are " << leftover << " leftover " << leftoverUnit << "\n";

	//Challenge 1 - done
	//Challenge 2 - done
}

string DecideSingleorPluralUnit(int amount, string unit) {
	if (amount < 2) {
		unit.erase(unit.end() - 1);
		return unit;
	}
	else
		return unit;
}

void Problem8_C3() {
	float people = AskNumber("How many people? ");
	float piecePerPerson = AskNumber("How many pieces do you want for each person? ");
	int pizza = static_cast<int> (ceilf(piecePerPerson * people / 8));
	string pizzaUnit = DecideSingleorPluralUnit(pizza, "pizzas");
	cout << "You will need to buy " << pizza << " " << pizzaUnit << "\n";
	//Challenge 3 - done
}

void Problem9() {
	const float AREA_PER_GALLON = 350.0f;

	enum roomShape { Rectangle = 1, Round, LShaped };

	int shape = static_cast<int>(AskNumber("What's the shape of the room?\n1-Rectangle\n2-Round\n3-LShaped\n"));
	float area = 0.0f;
	switch (shape)
	{
	case Rectangle:
	{
		float length = AskNumber("What's the length of the room? ");
		float width = AskNumber("What's the width of the room? ");
		area = length * width;
		break;
	}
	case Round:
	{
		float radius = AskNumber("What's the radius of the room? ");
		area = static_cast<float> (M_PI * radius * radius);
		break;
	}

	case LShaped:
	{
		float length = AskNumber("What's the length of the room? ");
		float innerLength = AskNumber("What's the inner length of the room? ");
		float width = AskNumber("What's the width of the room? ");
		float innerWidth = AskNumber("What's the inner width of the room? ");
		float side1 = length - innerLength;
		float side2 = width - innerWidth;
		area = length * side2 + innerWidth * side1;
		break;
	}
	default:
		cout << "Invalid Choice\n";
		break;
	}

	int gallonOfPaint = static_cast<int> (ceilf(area / AREA_PER_GALLON));

	cout << "You will need to purchase " << gallonOfPaint << " gallons of paint to cover " <<
		area << " square feet\n";
}

void Problem10() {
	const float TAX_RATE = 0.055f;
	vector<float> prices;
	vector <int> quantities;
	int index = 1;
	float price = 0;
	float quantity = 0;
	bool proceed = true;

	do {
		proceed = AskNumber_P10("Enter the price of item " + to_string(index) + " : ", price);
		if (proceed) {
			proceed = AskNumber_P10("Enter the quantity of item " + to_string(index) + " : ", quantity);
			if (proceed) {
				prices.push_back(price);
				quantities.push_back(static_cast<int>(quantity));
				index++;
			}
		}
	} while (proceed);

	float sum = 0;

	for (int i = 0; i < index - 1; i++)
	{
		sum += prices.at(i) * quantities.at(i);
	}
	cout << "Subtotal: $" << fixed << setprecision(2) << sum << '\n';
	float tax = sum * TAX_RATE;
	cout << "Tax: $" << fixed << setprecision(2) << tax << '\n';
	cout << "Total: $" << fixed << setprecision(2) << sum + tax << '\n';

	//Challenge 1 - done
	//Challenge 2 - done
}

bool AskNumber_P10(string question, float& price) {
	string input = "";
	float output = 0;
	cout << question;
	getline(cin, input);
	bool inputWasParsed = false;
	while (!input.empty())
	{
		inputWasParsed = CanParseFloat(input, output);
		if (inputWasParsed) {
			if (output <= 0)
				cout << "Please input only number bigger than 0\n";
			else {
				price = output;
				return inputWasParsed;
			}
		}
		else {
			cout << "Please input a valid number.\n";
		}
		cout << question;
		getline(cin, input);
	}
	cout << "No Input\n";
	price = 0;
	inputWasParsed = false;
	return inputWasParsed;
}

bool CanParseFloat(string input, float& out) {
	try {
		size_t st = 0;
		out = stof(input, &st);
		if (input.size() != st) {
			return false;
		}
	}
	catch (invalid_argument) {
		return false;
	}
	return true;
}

void Problem11() {
	float euro = AskNumber("How many euros are you exchanging? ");
	float rate = AskNumber("What is the exchange rate? ");
	float dollar = euro * rate;
	dollar = ceilf(dollar * 100) / 100;
	cout << euro << " euros at an exchange rate of " << rate <<
		" is " << dollar << " U.S. dollars.\n";

	//Challenge - not yet
}

void Problem12() {
	float principal = AskNumber("Enter the principal: ");
	float rateOfInterest = AskNumber("Enter the rate of interest: ");
	float years = AskNumber("Enter the number of years: ");
	for (int year = 1; year <= static_cast<int>(years); year++)
	{
		cout << "After " << year << " at " << rateOfInterest <<
			"%, the investment will be worth $" <<
			calculateSimpleInterest(principal, rateOfInterest, static_cast<float>(year)) << '\n';
	}
	//Challenge 1 - done
	//Challenge 2 - done
	//Challenge 3 - done
}

float calculateSimpleInterest(const float& principal, const float& rate, const float& years) {
	float result = principal * (1 + rate / 100 * years);
	result = ceilf(result * 100) / 100;
	return result;
}

void Problem13() {
	float principal = AskNumber("What is the principal amount? ");
	float rateOfInterest = AskNumber("What is the rate? ");
	float years = AskNumber("What is the number of years? ");
	float compoundYear = AskNumber("What is the number of times the interest is compounded per year? ");

	float result = principal * pow((1 + rateOfInterest / 100 / compoundYear), compoundYear * years);
	result = ceilf(result * 100) / 100;
	cout << "$" << principal << " invested at " << rateOfInterest << "% for " <<
		years << " years compounded " << compoundYear << " times per year is $" <<
		result << '\n';
	//Challenge 1 - done;
	//Challenge 2 - done;
	//Challenge 3 - not yet;
}

void Problem13_C2() {
	float goal = AskNumber("What is the goal amount? ");
	float rateOfInterest = AskNumber("What is the rate? ");
	float years = AskNumber("What is the number of years? ");
	float compoundYear = AskNumber("What is the number of times the interest is compounded per year? ");
	float result = goal / pow((1 + rateOfInterest / 100 / compoundYear), compoundYear * years);
	result = ceilf(result * 100) / 100;
	cout << "To get $" << goal << " amount at " << rateOfInterest << "% for " <<
		years << " years compounded " << compoundYear << " times per year, you need to invest $" <<
		result << '\n';
}
