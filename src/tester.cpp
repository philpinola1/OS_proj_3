#include "../usr_includes/tester.h"
#include "../usr_includes/print_ts.h"
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

mutex doWorkChanged, exiting;
vector<thread> threads;
bool doWork = true;

//
//int main() {
//	startThreads("hello world", 5, P1, 6, 100);
//	std::this_thread::sleep_for(std::chrono::milliseconds(400));
//	cout << "im awake!" << endl;
//	setCancelThreads(true);
//	//joinThreads();
//}


void printHelper(std::string str, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay) {

	WHICH_PRINT unInitwp;										//a garbage/unint WHICH_PRINT object
	WHICH_PRINT *wpPointer = &wp;								//a pointer to wp

	std::thread::id this_id = std::this_thread::get_id();		//id the current thread

		for (int i = 0; i < numTimesToPrint; i++) {

			if (!doWork) {										//checks if setCancelThread changed doWork to false
				std::lock_guard<mutex> lock(doWorkChanged);		//lockguard this bc we are writing to i (to escape the for loop)
				i = numTimesToPrint;
				wpPointer = &unInitwp; //sets wp to an uninitalized WHICH_PRINT object so that we don't get to any of the print statements.
			}

			if (wpPointer != &unInitwp) {						//if the above if statement was hit, this will be true

				switch (wp) {
					case P1:
						PRINT1(str);
						break;
					case P2:
						PRINT2(str, str);
						break;
					case P3:
						PRINT3(str, str, str);
						break;
					case P4:
						PRINT4(str, str, str, str);
						break;
					case P5:
						PRINT5(str, str, str, str, str);
						break;
					default:
						break;
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(millisecond_delay));
			}
			else {
				std::lock_guard<mutex> lock(exiting);
				cout << "exiting on " << this_id << endl;
			}
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
}

/*
 * if bCanceled== true then causes all running threads to exit
 * if false then just reset logic used to cancel threads
 */
void setCancelThreads(bool bCancel) {
	if (bCancel) {
		doWork = false;										//inform printHelper that threads were canceled
		joinThreads();										//cause all thread to exit
	}
	else {
		doWork = true;										//reset logic
	}
}

/*
 * waits for all threads to complete
 */
void joinThreads() {
	for(auto& t: threads){
		t.join();
	}
	doWork = false;
}
