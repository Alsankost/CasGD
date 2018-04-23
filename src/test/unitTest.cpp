#include "unitTest.h"

UnitTest::UnitTest(char* n) {
	name = n;
}

void UnitTest::testCase(char* n, bool (*func)()) {
	if (this -> first) {
		//cout << "<stype type='text/css'>table td tr { border: solid 2px black } </style>";
		//cout << "<h2>" << this -> name << "</h2>\n<table style='border-collapse: collapse;'>";
		cout << "<tr><td>Name</td><td>Discription</td><td>State</td></tr>";
		first = false;
	}
	cout << "<tr><td>" << n << "</td><td>";
	bool st = func();
	this -> testCount++;
	this -> testPassed += (st)?1:0;
	cout << "</td>" << ((st)?"<td style='color: blue;'>pass</td>":"<td style='color: red;'>fail</td></tr>");
}

void UnitTest::result() {
	float prc = ((this -> testPassed * 1.0F) / this -> testCount) * 100;
	char* color = "blue";
	if (prc < 75) color = "green";
	if (prc < 50) color = "#EFC206";
	if (prc < 25) color = "red";
	
	cout << "</table><h3>Test passed: <font style='color: " << color << ";'>" << prc << "%</font></h3><br>";
}
