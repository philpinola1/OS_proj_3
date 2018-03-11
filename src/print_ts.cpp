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
	m.lock();
	cout << txt << endl;
	m.unlock();
}

void PRINT2(std::string &txt, std::string &txt1) {
	m.lock();
	cout << txt << " " << txt1 <<endl;
	m.unlock();
}

void PRINT3(std::string &txt, std::string &txt1, std::string &txt2) {
	m.lock();
	cout << txt << " " << txt1 << " " << txt2 << endl;
	m.unlock();
}

void PRINT4(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3) {
	m.lock();
	cout << txt << " " << txt1 << " " << txt2 << " " << txt3 << endl;
	m.unlock();
}

void PRINT5(std::string &txt, std::string &txt1, std::string &txt2, std::string &txt3, std::string &txt4) {
	m.lock();
	cout << txt << " " << txt1 << " " << txt2 << " " << txt3 << " " << txt4 <<endl;
	m.unlock();
}
