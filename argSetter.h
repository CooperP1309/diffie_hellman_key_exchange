#ifndef ARGSETTER_H
#define ARGSETTER_H

using namespace std;

class ArgSetter {
public:
void setArgs(int&, int&, int&);

private:
PrimitiveRoot pm;

bool chooseInputMethod();
void getManualInput(int&, int&, int&);
void setInputP(int&);
bool isPrime(int);
void setInputX(int&, int);
void getAutoInput(int&, int&, int&);
};

void ArgSetter::setArgs(int& p, int& xA, int& xB) {

	if (chooseInputMethod()) {
		cout << "Using manual input\n\n";
		getManualInput(p, xA, xB);
	}
	else {
		cout << "Auto generating inputs\n\n";
		getAutoInput(p, xA, xB);
		exit(0);
	}
}

bool ArgSetter::chooseInputMethod() {

	cout << "Choose your input method\n\n1.Manual\n2.Automatic\n\n";

	char ans;
	while(1) {

		cin >> ans;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	// clear "\n" after using >>

		if ((ans-'0') == 1) {

			return true;
		}
		else if ((ans-'0') == 2) {
			return false;
		}

		cout << "Please choose a valid method\n\n";
	}
}

void ArgSetter::getManualInput(int& p, int& xA, int& xB) {

	// set the prime value of P
	setInputP(p);

	// set value of xA
	cout << "\nPlease set a value for xA that's within the range (1-" << p-1 << ")\n";
	setInputX(xA, p); 

	cout << "\nPlease set a value for xB that's within the range (1-" << p-1 << ")\n";
	setInputX(xB, p); 
	cout << endl;
}

void ArgSetter::setInputP(int& p) {

	cout << "Please set a prime value for p that's less than 100:\n\n";

	string ans;

	while (1) {

		getline(cin, ans);

		if (isPrime(stoi(ans)) && stoi(ans) < 100) {
			break;
		}
		else if (stoi(ans) > 100) {
			cout << "Input is greater than 100, please try again...\n";
		}
		else {
			cout << "Input was not a prime number, please try again...\n";
		}
	}

	p = stoi(ans);
}

bool ArgSetter::isPrime(int p) {

    if (p == 1) {
        return false;
    }
    else if (p == 2) {
        return true;
    }
	else if (p % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= p; i += 2) { 
        if (p % i == 0) {
            return false; 
        }
    }

    return true;
}

void ArgSetter::setInputX(int& x, int p) {

	string ans;

	while (1) {

		getline(cin, ans);

		if (stoi(ans) < p && stoi(ans) > 0 ) {
			break;
		}

		cout << "Given value is out of range 1 <-> p-1, please try again...\n";
	}

	x = stoi(ans);
}

void ArgSetter::getAutoInput(int& p, int& xA, int& xB) {

	int randomNumber;
	
	// generating p
	do {
		// Generate a random number between 2 and 97 (the range of prime numbers allowed)
		srand(time(0));
	    randomNumber = (rand() % 97) + 5;

	} while (!isPrime(randomNumber));
	p = randomNumber;
	cout << "Generated p: " << p << "\n";

	// getting the primitive root
	int g = pm.getAutoPrimitiveRoot(p);
	cout << "Generated g (primitive root): " << g << "\n"; 

	// generating xA
	srand(time(0));
	randomNumber = (rand() % (p-1)) + 1;
	xA = randomNumber;
	cout << "Generated xA: " << xA << "\n";

	// generating xB
	sleep(1);				// sleep to ensure xB gets a different time() seed
	srand(time(0));
	randomNumber = (rand() % (p-1)) + 1;
	xB = randomNumber;
	cout << "Generated xB: " << xB << "\n\n";

	// using inputs to get the generated key
	GenerateKey key(p, g, xA, xB);
}

#endif // ARGSETTER_H