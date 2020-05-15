/*Author: Karanbir Singh
TestCode for an Emergency Room waitlist, the patients will be placed according to their priorities*/
#include <iostream>
#include <string>
#include "ERWL.h"

using namespace std;

int main(){
	
	Patient p1("Anthony" , 2);
	Patient p2("Peter" , 1);
	Patient p3("Charlie", 1);
	Patient p4("Julio",1);
	Patient p5("Victor",2);
	
	ERWL Er;
	Er.enqueuePatient(p1);
	Er.enqueuePatient(p2);
	Er.enqueuePatient(p3);
	Er.enqueuePatient(p4);
	Er.enqueuePatient(p5);
	Er.waitList();
	cout << "After treating one patient..."<<endl;
	Er.dequeuePatient();
	Er.waitList();
	cout << "After treating two patients..."<<endl;
	Er.dequeuePatient();
	Er.waitList();
	return 0;
}


//running code: g++ -pedantic -Wall -Wextra -std=c++14 TestER.cpp -o TestER
