#include "../../bin/include/gameObject.h"
#include <stddio.h>
#include <iostream>

using namespace std;

int main() {
	GameObject go(4, 4);

	cout << go.getDataLenght();

	return 0;
}
