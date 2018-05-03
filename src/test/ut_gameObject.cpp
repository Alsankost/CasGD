#include "include/gameObject.h"
#include "unitTest.h"
#include <stdio.h>
#include <iostream>

using namespace std;

struct data {
	int a;
};

GameObject testObject;
Listeners* lst = new Listeners;

void func1(GameObject*) {
	cout << "Func1 is call!";
}

void func2(GameObject*) {
	cout << "Func2 is call!";
}

void func3(GameObject*) {
	cout << "Func3 is call!";
}

bool TC_const() {
	lst -> e_create = func1;
	lst -> e_step   = func2;
	lst -> e_dead   = func3;
	
	testObject = GameObject(lst, 4, 4);
	return true;
}

bool TC_getListeners() {
	Listeners* l = testObject.getListeners();
	if (l == 0) {
		cout << "getListeners return is 0";
		return false;
	}
	l -> e_create(&testObject);
	l -> e_step(&testObject);
	l -> e_dead(&testObject);
	return true;
}

bool TC_data() {
	int oc = testObject.getDataLenght();
	if (oc != 4) {
		cout << oc << " != 4";
		return false;
	}

	int d1 = 100;
	testObject.setData(0, &d1);
	data d2 = {200};
	testObject.setData(2, &d2);
	/*
	int* pd1 = (long int) testObject.getData(0);
	if (pd1 == 0) {
		cout << "Data1 return 0";
		return false;
	}
	if (*pd1 != d1) {
		cout << "Data1 != " << d1;
	}

	data* pd2 = (long int) testObject.getData(2);
	if (pd2 == 0) {
		cout << "Data2 return 0";
		return false;
	}
	if (*pd2 != d2) {
		cout << "Data2 != " << d2;
	}
	*/
	return false;
}

int main() {
	UnitTest ut = UnitTest("GameObject test");
	
	ut.testCase("Constructor test", TC_const);
	ut.testCase("Listeners test", TC_getListeners);
	ut.testCase("Data test", TC_data);

	ut.result();
	return 0;
}
