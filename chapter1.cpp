#include "chapter1.h"

void TipCalculator() {


	float billAmount = AskNumber("What is the bill amount? ");
	float tipRate = AskNumber("What is the tip percentage? ");

	Calculate(billAmount, tipRate);

	//Challenge 1 - done
	//Challenge 2 - done
	//Challenge 3 - done
	//Challenge 4 - done?
	//Challenge 5 - need to find GUI library?
	//Challenge 6 - need to find GUI library?
}

void Calculate(float _billAmount, float _tipRate) {
	float tip = 0;
	float total = 0;
	tip = _billAmount * (_tipRate / 100);
	tip = ceilf(tip * 100) / 100;

	total = _billAmount + tip;

	cout << "Tip: " << tip << endl;
	cout << "Total: " << total << endl;
}