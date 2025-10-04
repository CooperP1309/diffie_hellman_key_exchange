#ifndef GENERATEKEY_H
#define GENERATEKEY_H

#include "squareAndMultiply.h"

using namespace std;

class GenerateKey {
public:
	GenerateKey(int, int, int, int);

private:
	SqreAndMult snm;
};

GenerateKey::GenerateKey(int p, int g, int xA, int xB) {

	cout << "Generating Encryption Key via the following arguements:\n"
		 << "p = " << p << ", g = " << g << ", xA = " << xA << ", xB = " << xB << "\n\n";

	// start by generating both public key A and B
	cout << "Getting public Key A...\n";
	int yA = snm.squareAndMultiply(g, xA, p);
	cout << "yA = g^xA mod p\n";
	cout << "   = " << g << "^" << xA << " mod" << p << "\n";
	cout << "   = " << yA << "\n\n";

	cout << "Getting public Key B...\n";
	int yB = snm.squareAndMultiply(g, xB, p);
	cout << "yB = g^xB mod p\n";
	cout << "   = " << g << "^" << xB << " mod" << p << "\n";
	cout << "   = " << yB << "\n\n";

	// now to generate the actual key
	cout << "Generating Encryption Key Via yA...\n";
	int key1 = snm.squareAndMultiply(yA, xB, p);
	cout << "K = yA^xB mod p\n";
	cout << "  = " << yA << "^" << xB << " mod " << p << "\n";
	cout << "  = " << key1 << "\n\n";

	cout << "Generating Encryption Key Via yB...\n";
	int key2 = snm.squareAndMultiply(yB, xA, p);
	cout << "K = yB^xA mod p\n";
	cout << "  = " << yB << "^" << xA << " mod " << p << "\n";
	cout << "  = " << key2 << "\n\n";

	// comparing of encryption keys
	if (key1 == key2) {
		cout << "Matching key produced by both public keys. Success!\n"
			 << "Your key: " << key1 << "\n\n";
	}
	else {
		cout << "Varying keys produced by both public keys. Fail!\n\n";
	}
}

#endif // GENERATEKEY_H