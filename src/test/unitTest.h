#include <stdio.h>
#include <iostream>

using namespace std;

class UnitTest {
	private:
		int testCount = 0;
		int testPassed = 0;
		bool first = true;
		char* name;

	public:
		UnitTest(char* n);
		void testCase(char* n, bool (*func)());
		void result();
};
