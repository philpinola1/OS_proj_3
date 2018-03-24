#include "../usr_includes/tester.h"
#include "../usr_includes/print_ts.h"
#include <string>
#include <chrono>
#include<thread>
#include<iostream>
using namespace std;



int main() {

	string s = "some";
	string s1 = "data";
	int numThreads = 1;
	int numRepeats = 3;
	int miliDelay = 200;
	WHICH_PRINT wp = P2;

	startThreads(s, numThreads, wp, numRepeats, miliDelay);
	std::this_thread::sleep_for(std::chrono::milliseconds(400));
	//cout << "im awake!" << endl;
	setCancelThreads(true);
	//joinThreads();

	PRINT1(s1);
	PRINT2(s, s1);
	PRINT3(s, s, s);
	PRINT4(s,s,s,s);
	PRINT5(s1,s1,s1,s1,s1);


}
