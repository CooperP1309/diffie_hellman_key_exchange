#ifndef SQUAREANDMULTIPLY_H
#define SQUAREANDMULTIPLY_H

using namespace std;

class SqreAndMult {
public:
	int squareAndMultiply(int, int, int);

private:
	int findLargestSetBit(bitset<32>);
};

int SqreAndMult::squareAndMultiply(int g, int exponent, int n) {

	// layout the exponent into binary and get number of bits used
	bitset<32> exponentBits(exponent);		
	int k = findLargestSetBit(exponentBits);

	int c = 0, d = 1;

	// for each binary bit
	for (int i=k; i>=0; i--) {

	 	c = 2*c;

	 	d = d*d % n;

		// multiply g if bit is 1
		if (exponentBits[i] == 1) {
			c++;
			d = d*g % n;
		}
	}

	return d;
}

int SqreAndMult::findLargestSetBit(bitset<32> set) {

	for (int i = 31; i >=0; i--) {
		if (set[i]) {
			return i;
		}
	}

	return 0;
}

#endif // SQUAREANDMULTIPLY_H