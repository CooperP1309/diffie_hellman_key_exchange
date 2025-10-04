// standard libaries
#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <limits>
#include <cstdlib>		// use: srand() and exit()
#include <ctime>		// use: time() in srand()
#include <unistd.h>
#include <iterator>		// for choosing a random element in a set

// header files
#include "primitiveRoot.h"
#include "squareAndMultiply.h"
#include "generateKey.h"
#include "argSetter.h"

using namespace std;

int main(int argc, char* argv[]) {

	int p, xA, xB;

	ArgSetter args;
	args.setArgs(p, xA, xB);

	PrimitiveRoot pm;
	int g = pm.getPrimitiveRoot(p);

	GenerateKey key(p, g, xA, xB);

	return 0;
}