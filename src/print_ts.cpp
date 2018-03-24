#include "../usr_includes/print_ts.h"
#include <mutex>
#include <iostream>

using namespace std;

mutex m;

void PRINT1(std::string &txt) {
	std::lock_guard<mutex> lock(m);
	cout << txt <<endl;
}

void PRINT2(std::string &txt, std::string &txt1) {
	std::lock_guard<mutex> lock(m);
	cout << txt << txt1 <<endl;
}

void PRINT3(std::string &txt, std::string &txt1, std::string &txt2) {
//	std::lock_guard<mutex> lock(m);
	cout << txt << txt1 << txt2 << endl;
}

void PRINT4(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3) {
//	std::lock_guard<mutex> lock(m);
	cout << txt << txt1 << txt2 << txt3 << endl;
}

void PRINT5(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3, std::string &txt4) {
//	std::lock_guard<mutex> lock(m);
	cout << txt << txt1 << txt2 << txt3 << txt4 <<endl;
}
