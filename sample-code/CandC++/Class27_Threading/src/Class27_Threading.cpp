//============================================================================
// Name        : Class27_Threading.cpp
// Author      : Biplav
// Version     :
// Copyright   : Your copyright notice
// Description : Samples for class on Threading -  C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>

using namespace std;

/**
 * Credit: Based on code at: https://www.geeksforgeeks.org/multithreading-in-cpp/
 *
 */

// -------------------------------------------------------

// Example of a task to do
void aTaskFunction(int upperLimit) {

	int sum = 0;
	for (int i = 1; i < upperLimit; i++) {
		sum += i;
	}

	cout << "INFO: sum of " << (upperLimit-1) << " numbers = " << sum << endl;

}

// -------------------------------------------------------

// Example of a task to do
class AClassWithOpertorForTask {
public:
	void operator()(int upperLimit) {
		int sum = 0;
		for (int i = 1; i < upperLimit; i++) {
			sum += i;
		}

		cout << "INFO: sum of " << (upperLimit-1)  << " numbers = " << sum << endl;

	}
};

// -------------------------------------------------------

// Demonstrate threading - simple
void demoThreading() {

	cout << "DEMO: Simple multi threading usage" << endl;

	// This thread is launched by using function pointer
	// as callable
	thread t1(aTaskFunction, 5);

	// This thread is launched by using function object
	// as callable
	thread t2(AClassWithOpertorForTask(), 11);

	// Wait for thread t1 to finish
	t1.join();

	// Wait for thread t2 to finish
	t2.join();

	// Print when both threads are done
	cout << "INFO: both threads are done." << endl;
}

// -------------------------------------------------------

// -------------------------------------------------------
// The main

int main(int argc, char *argv[]) {
	cout << "Class on Multi Threading" << endl; // for Class 27

	char command = 0;
	string str = "";

	// First argument is program name
	cout << "Program name : " << argv[0] << endl;

	if (argc == 1) {
		printf("\nNo command passed. By default, running with option 0. \n");
		command = '0';
	} else {
		// argc >= 2
		command = *argv[1];

		cout << "Command to run is - " << command << endl;
	}

	// Now execute based on command

	if (command == '0') {
		// Show simple threading
		demoThreading();
	} else if (command == '1') {
		// Do something else
		;
	} else {
		// future option
		;
	}

	return 0;
}
