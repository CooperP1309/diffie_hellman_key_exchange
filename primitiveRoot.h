#ifndef PRIMITIVEROOT_H
#define PRIMITIVEROOT_H

#include "squareAndMultiply.h"

using namespace std;

class PrimitiveRoot {
public:
	int getPrimitiveRoot(int);
	int getAutoPrimitiveRoot(int);

private:
	SqreAndMult snm;

	bool isPrimitive(int,int, vector<int>);
	vector<int> getFactors(int);
	int choosePrimitiveRoot(set<int>);
};

int PrimitiveRoot::getPrimitiveRoot(int p) {

	// get the factors of p-1
	vector<int> possibleOrders = getFactors(p-1);
	set<int> primitiveRoots;

	// iterate throguh each possible primitive root
	for (int g=1; g<p; g++) {

		if (isPrimitive(g, p, possibleOrders)) {
			primitiveRoots.insert(g);
		}
	}

	// allow user to select their desired primitive root
	return choosePrimitiveRoot(primitiveRoots);
}

int PrimitiveRoot::getAutoPrimitiveRoot(int p) {
	
	// get the factors of p-1
	vector<int> possibleOrders = getFactors(p-1);
	set<int> primitiveRoots;

	// iterate throguh each possible primitive root
	for (int g=1; g<p; g++) {

		if (isPrimitive(g, p, possibleOrders)) {
			primitiveRoots.insert(g);
		}
	}

	// choose a random primitive root in the vector
	srand(time(0));
	int randomIndex = (rand() % (primitiveRoots.size()-1));

	auto it = primitiveRoots.begin();
    std::advance(it, randomIndex);

	return *it;
}

vector<int> PrimitiveRoot::getFactors(int n) {

	vector<int> factors;

	// getting factors
	for (int i=1; i<n; i++) {

		if (n%i == 0) {		// case for a factor
			factors.push_back(i);
		}
	}

	return factors;
}

bool PrimitiveRoot::isPrimitive(int g, int p, vector<int> possibleOrders) {

	int product;

	for (int k : possibleOrders) {
        //product = static_cast<long int>(pow(g,k));	// must cast to int due to return val from pow()
		product = product%p;	

		product = snm.squareAndMultiply(g, k, p);

        if (product == 1) {
        	return false;
        }
    }

	return true;
}

int PrimitiveRoot::choosePrimitiveRoot(set<int> primitiveRoots) {

	cout << "Please choose from one of the following primitive roots:\n\n";

	for (int i : primitiveRoots) {
		cout << i << " ";
	}
	cout << "\n\n";

	string ans;
	while(1) {

		getline(cin, ans);

		if (primitiveRoots.count(stoi(ans))) {
			cout << "\n";
			return stoi(ans);
		}

		cout << ans << " is not a valid primitive root, please try again\n\n";
	}

	return -1;
}

#endif // PRIMITIVEROOT_H