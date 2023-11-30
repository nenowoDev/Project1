#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student {
    private :
		string id;
		string name;
		string programEnroll;
		string ic;
		string address;
		string gender;
		string phoneNo;
        string DOB;

    public:
        string getID();
		string getName();
		string getProgramEnroll();
        string getIC();
		string getAddress();
        string getGender();
        string getPhoneNo();
		string getDOB();

		void editID(string newID);
		void editName(string newName);
		void editProgramEnroll(string newProg);
        void editIC(string newIC);
		void editAddress(string newAddress);
        void editGender(string newGender);
        void editPhoneNo(string newPhone);
		void editDOB(string newDOB);

		void InsertionSort(Student[], int);
		void BubbleSort(Student[], int);
		void SelectionSort(Student[], int);

        void readFile(Student[], int&);
		void add(Student [], int&);
	    void del(Student [], int&);
		void displayRecord(Student [], int&);
		void display(Student[], int&);

};

#endif