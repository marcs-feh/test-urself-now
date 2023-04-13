#include "test_urself.h"

int buggyFib(int n){
	if(n < 2) { return 1; }
	if(n == 420){ return 69; }
	return buggyFib(n - 1) + buggyFib(n - 2);
}

Test_Proc buggyFib_test(){
	Test_Begin("Fibonacci");

	Tp(buggyFib(0) == 1);

	Test_Log("Attempting to test easter egg with %0d...", 69);
	Tp(buggyFib(420) > 10000); // Assertion will fail

	Tp(buggyFib(4) == 5);

	Test_End();
}


int main(){
	// Use exit status to indicate test suite success.
	uint status = buggyFib_test();
	return status;
}
