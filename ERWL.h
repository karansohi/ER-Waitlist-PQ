/*Author: Karanbir Singh
This h file includes both h and cpp for the patient class, node class and ERWL class.
The patient class will contain basic information about the patient

ERWL is our queue for the patient. The difference between a normal queue and our ERWL is that in the ERWL we store the patients according to their priority, hence we use a priority queue */
#include <iostream>
#include <string>

#ifndef ERWL_H
#define ERWL_H

using namespace std;

//Class that will contain the details of the patient, name and priority... it can be amplified according to our needs

class Patient{
	private:
		string name;
		int priority;
	public:
		Patient();
		Patient(string n, int pr);
		int getPriority();
		string getName();
};
Patient::Patient(){
	name = "no name";
	priority = 0;
}
Patient::Patient(string n, int pr){
			name = n;
			priority = pr;
		}
int Patient::getPriority(){
			return priority;
		}
string Patient::getName(){
			return name;
		}
//Class ndode will let use the object created from the parents class along side pointers that will link them, making a prority list and therefore creating our waitlist

class Node{
	
	private:	
		Patient p;
		Node *next;
	public:
		Node(){
			next = nullptr;
		}	
		Node(Patient& p1, Node* link){
			p = p1;
			next = link;
		}
	friend class ERWL;
};
//emergency room: it will use a user made priority queue that will help the user in placing the patients according to their needs
// FILO PQ
class ERWL{
	private:
		int size = 0;
		Node *front,*rear;
	public:
		ERWL();
		~ERWL();
		void enqueuePatient(Patient p1);
		void dequeuePatient();
		int getSize();
		bool empty();
		void waitList();
};
		ERWL::ERWL(){
			front = rear = nullptr;
		}
		ERWL::~ERWL(){
			for(Node* temp; front !=nullptr;){
				temp = front;
				front = front->next;
				delete temp;
				temp = nullptr;
			}
		}
		void ERWL::enqueuePatient(Patient p1){
			Node* current;
            //base case : if the PQ is empty both rear and front will point to the same element
			if(front == nullptr && rear == nullptr)
			{
				current = new Node( p1 , nullptr);
				front = rear = current;
				size++;
			}
            //if the new patient has a lower priority he gets inserted at the front making sure that he stays back and gets treated after the critical patients
			else if( p1.getPriority() < front->p.getPriority())
			{
				current = new Node( p1, front->next);
				front->next = current;
				size++;
			}
            //means that the Priority is higher and the patients needs to to get treated earlier than the mild ones
            //current will create a new node pointing its next to the front of the PQ but the front will point to PQ making sure that the PQ rules remain integrated
			else {
				current = new Node(p1 , front);
				front = current;
				size++;
			}
		}
		int ERWL::getSize(){
			return size;
		}
		bool ERWL::empty(){
			if( front == nullptr && rear == nullptr)
				return true;
			else
				return false;
		}
		//patients with higher priority are classified at the rear of the queue so that the integrity of the queue remains intact ( FILO or LIFO ) and also we can treat the patients with the highest priority first
		void ERWL::dequeuePatient(){
			Node* temp;
			temp = front;
			for( int i = 0; i < size-1; i++){
				temp = temp -> next;
			}
			rear = temp;
			size--;
			delete temp;
		}
		//For now our waitlist can containt only patients with either mild or critical priority ( 2 or 1 ) and that will be displayed alongside the patient name
		void ERWL::waitList(){
			int waitNo = size;
			Node* temp = front;
			while(waitNo > 0)
			{
				cout << "Patient Name: " << temp->p.getName();
				if( temp -> p.getPriority () == 1)
					cout << "-Condition: Critical-";
				else
					cout << "-Condition: Mild-";
				cout << " ServiceNumber:" << waitNo;
				cout << endl;
				waitNo--;
				temp = temp->next;
			}
		}
#endif
