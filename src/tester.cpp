/*
 * tester.cpp
 *
 *  Created on: Mar 11, 2018
 *      Author: host001
 */

#include "../usr_includes/tester.h"
#include "../usr_includes/print_ts.h"
#include <thread>
#include <vector>

using namespace std;

vector<thread> threads;
bool doWork = true;


int main () {

	startThreads("hello world", 3, P1, 7, 750);

}

/*
 * starts cancelable threads
 * string s			-the string to print
 * numThreads 		-the number of threads to start
 * wp 				-which print statement should be used
 * numTimesToPrint 	-the number of PRINT statements each thread will call
 * millisecond_delay- how long (in milliseconds) to wait between prints
 *
 * if user chooses to cancel then this function should print USER_CHOSE_TO_CANCEL before exit
 */
void startThreads(std::string s, int numThreads, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay) {

	//unsigned num_cpus = thread::hardware_concurrency();

	while (doWork) {
		switch (wp) {
		case P1:
			for (int i = 0; i < numThreads; i++) {

				int k = numTimesToPrint;
				threads.push_back(std::thread(PRINT1, std::ref(s)));

				while (k > 0) {
					threads.at(i)=thread(PRINT1, std::ref(s));
					std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
					k--;
				}

				//if numTimesToPrint > 1, call PRINT1 again inside THIS thread
			}
			break;

		case P2:
			for (int i = 0; i < numThreads; i++) {
				threads.push_back(std::thread(PRINT2, std::ref(s), std::ref(s)));
				std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
			}
			break;

		case P3:
			for (int i = 0; i < numThreads; i++) {
				threads.push_back(std::thread(PRINT3, std::ref(s), std::ref(s), std::ref(s)));
				std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
			}
			break;

		case P4:
			for (int i = 0; i < numThreads; i++) {
				threads.push_back(std::thread(PRINT4, std::ref(s), std::ref(s), std::ref(s), std::ref(s)));
				std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
			}
			break;

		case P5:
			for (int i = 0; i < numThreads; i++) {
				threads.push_back(std::thread(PRINT5, std::ref(s), std::ref(s), std::ref(s), std::ref(s), std::ref(s)));
				std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
			}
			break;

		default:
			break;
		}
		joinThreads();
	}
}

/*
 * if bCanceled== true then causes all running threads to exit
 * if false then just reset logic used to cancel threads
 */
void setCancelThreads(bool bCancel) {
	if (bCancel) {
		doWork = false;
		joinThreads();
	}
	else {
		doWork = true;
	}
}

/*
 * waits for all threads to complete
 */
void joinThreads() {

	for(auto& thread : threads){
		thread.join();
}
	doWork = false;
//	for (unsigned int i = 0; i < threads.size(); i++) {
//		threads.at(i).join();
//	}
}
