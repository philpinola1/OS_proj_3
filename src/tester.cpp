#include "../usr_includes/tester.h"
#include "../usr_includes/print_ts.h"
#include <thread>
#include <vector>

using namespace std;

vector<thread> threads;
bool doWork = true;


int main () {
	startThreads("hello world", 3, P1, 2, 500);
	joinThreads();
}


void printHelper(std::string str, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay) {
	for (int i = 0; i < numTimesToPrint; i++) {

		while (doWork) {
			switch (wp) {
			case P1:
					threads.push_back(std::thread(PRINT1, std::ref(str)));
					//cout << "in printHelper P1 case" << endl;
				break;
			case P2:
					threads.push_back(std::thread(PRINT2, std::ref(str), std::ref(str)));
					//cout << "in printHelper P2 case" << endl;
				break;
			case P3:
					threads.push_back(std::thread(PRINT3, std::ref(str), std::ref(str), std::ref(str)));
					//cout << "in printHelper P3 case" << endl;
				break;
			case P4:
					threads.push_back(std::thread(PRINT4, std::ref(str), std::ref(str), std::ref(str), std::ref(str)));
					//cout << "in printHelper P4 case" << endl;
				break;
			case P5:
					threads.push_back(std::thread(PRINT5, std::ref(str), std::ref(str), std::ref(str), std::ref(str), std::ref(str)));
					//cout << "in printHelper P5 case" << endl;
				break;
			default:
				break;
			}
			//joinThreads();
			std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
		}
		cout << USER_CHOSE_TO_CANCEL << endl;
	}
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

		for (int i = 0; i < numThreads; i++) {
			threads.push_back(std::thread(printHelper, s, wp, numTimesToPrint, millisecond_delay));
		}
		//joinThreads();
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

//	for(auto& thread : threads){
//		thread.join();
//}

	for (unsigned int i = 0; i < threads.size(); i++) {
		threads.at(i).join();
	}
	doWork = false;
}
