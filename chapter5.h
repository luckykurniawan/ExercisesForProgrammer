#pragma once
#include "includes.h"
#include "sharedfunctions.h"


void Problem24();
bool isAnagram(string s1, string s2);
void qSort(string& str, int start, int end);
void Problem25();
enum class PasswordStrength {
	very_weak, weak, strong, very_strong
};
PasswordStrength passwordValidator(string password);

void Problem27();
string askInput();
string validateInput(string first, string last, string zipCode, string id);
string validateName(string desc, string input);
string validateZIPCode(string zipCode);
string validateID(string id);