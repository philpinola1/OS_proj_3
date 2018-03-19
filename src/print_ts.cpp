/*
 * print_ts.cpp
 *
 *  Created on: Mar 11, 2018
 *      Author: host001
 */

#include "../usr_includes/print_ts.h"
#include <mutex>
#include <iostream>
#include <thread>

using namespace std;

mutex m;
//maybe one mutex per function?

void PRINT1(std::string &txt) {

	std::thread::id this_id = std::this_thread::get_id();
	std::lock_guard<mutex> lock(m);
	cout << txt << this_id <<endl;
}

void PRINT2(std::string &txt, std::string &txt1) {
	std::lock_guard<mutex> lock(m);
	cout << txt << " " << txt1 <<endl;
}

void PRINT3(std::string &txt, std::string &txt1, std::string &txt2) {
	std::lock_guard<mutex> lock(m);
	cout << txt << " " << txt1 << " " << txt2 << endl;
}

void PRINT4(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3) {
	std::lock_guard<mutex> lock(m);
	cout << txt << " " << txt1 << " " << txt2 << " " << txt3 << endl;
}

void PRINT5(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3, std::string &txt4) {
	std::lock_guard<mutex> lock(m);
	cout << txt << " " << txt1 << " " << txt2 << " " << txt3 << " " << txt4 <<endl;
}
