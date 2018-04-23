#include "unitTest.h"

int a = 0;

bool test() {
	cout << "Test #" << a;
	a++;
	return a % 3 == 0;
}

int main() {
	UnitTest ut = UnitTest("This is unit test!");

	for (int i = 0; i < 10; i++) {
		ut.testCase("Test", test);
	}
	
	ut.result();

	return 0;
}
