#include "chapter5.h"

void Problem24() {
	string s1, s2;
	cout << "Enter 2 strings and I'll tell you if they are anagrams:\n";
	cout << "Enter the first string: ";
	cin >> s1;
	cout << "Enter the second string: ";
	cin >> s2;
	if (isAnagram(s1, s2))
	{
		cout << "\"" << s1 << "\" and \"" << s2 << "\" are anagrams";
	}
	else {
		cout << "\"" << s1 << "\" and \"" << s2 << "\" are not anagrams";
	}

	//Challenge - done(?)
}

bool isAnagram(string s1, string s2) {
	int n1 = s1.length();
	int n2 = s2.length();
	if (n1 != n2)
		return false;

	/*sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());*/
	qSort(s1, 0, n1-1);
	qSort(s2, 0, n2-1);
	for (int i = 0; i < n1; i++)
	{
		if (s1[i] != s2[i])
		{
			return false;
		}
	}

	return true;
}

void qSort(string& str, int start, int end) {
	int i = start;
	int j = end;
	char pivot = str[(start + end) / 2];

	//partition
	while (i <= j)
	{
		while (str[i] < pivot)
		{
			i++;
		}
		while (str[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			char temp = str[i];
			str[i] = str[j];
			str[j] = temp;
			i++;
			j--;
		}
	};

	//recursion
	if (start < j) qSort(str, start, j);
	if (i < end) qSort(str, i, end);

}

void Problem25() {
	string input = AskString("Input password: ");
	PasswordStrength result = passwordValidator(input);
	string sResult;
	switch (result)
	{
	case PasswordStrength::very_weak:
		sResult = "very weak";
		break;
	case PasswordStrength::weak:
		sResult = "weak";
		break;
	case PasswordStrength::strong:
		sResult = "strong";
		break;
	case PasswordStrength::very_strong:
		sResult = "very strong";
		break;
	default:
		break;
	}

	cout << "The password '" << input << "' is a " << sResult << " password.\n";
	//challenge - not yet
}

PasswordStrength passwordValidator(string password) {
	bool hasNumber = any_of(password.begin(), password.end(), isdigit);
	bool hasLetter = any_of(password.begin(), password.end(), isalpha);
	bool passwordAtLeast8Chars = password.length() >= 8;
	bool hasSpecialChars = (find_if_not(password.begin(), password.end(), isalnum) != password.end());

	if (hasSpecialChars && passwordAtLeast8Chars && hasLetter && hasNumber) {
		return PasswordStrength::very_strong;
	}
	else if (passwordAtLeast8Chars && hasLetter && hasNumber) {
		return PasswordStrength::strong;
	}
	else if (!passwordAtLeast8Chars && hasLetter) {
		return PasswordStrength::weak;
	}
	return PasswordStrength::very_weak;
}

void Problem27() {
	string result = string();
	do
	{
		result = askInput();
		cout << (result.empty() ? "There were no errors\n" : result) ;
	} while (!result.empty());

	//challenge 1 - not yet
	//challenge 2 - not yet
	//challenge 3 - done
}

string askInput() {
	string firstName = AskString("Enter the first name: ");
	string lastName = AskString("Enter the last name: ");
	string zipCode = AskString("Enter the ZIP code: ");
	string id = AskString("Enter an employee ID: ");
	string warning = validateInput(firstName, lastName, zipCode, id);
	return warning;
}
string validateInput(string first, string last, string zipCode, string id) {
	return validateName("first", first) + validateName("last", last) +
	validateZIPCode(zipCode) +	validateID(id);
}

string validateName(string desc, string input) {
	if (input.empty())
	{
		return "The " + desc + " name must be filled.\n";
	}
	else if (input.length() < 2 )
	{
		return "\"" + input + "\" is not a valid " + desc + " name. It's too short.\n";

	}
	return string();
}

string validateZIPCode(string zipCode) {
	if (!all_of(zipCode.begin(), zipCode.end(), isdigit) || (zipCode.length() != 5))
	{
		return "The ZIP code must be numeric\n";
	}
	return string();
}

string validateID(string id) {
	bool valid = true;

	if (id.length() == 7)
	{
		int i = 0;
		while (valid && i < 2)
		{
			if (!isalpha(id.at(i))) {
				valid = false; 
			}
			else
				i++;
		}

		if (valid) {
			if (id.at(i) != '-') {
				valid = false; 
			}else 
				i++;
		}

		while (valid && i < id.length()) {
			if (!isdigit(id.at(i))) {
				valid = false; 
			}
			else 
				i++;
		}
	}
	else
		valid = false;
	if (valid)
		return string();
	else
		return id + " is not a valid ID.\n";
}