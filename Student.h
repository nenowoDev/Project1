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
		


		// string editID(string newID);
		// string editName(string newName);
		// string editProgramEnroll(string newProg);
        // string editIC(string newIC);
		// string editAddress(string newAddress);
        // string editGender(string newGender);
        // string editPhoneNo(string newPhone);
		// string editDOB(string newDOB);


		void editID(string newID);
		void editName(string newName);
		void editProgramEnroll(string newProg);
        void editIC(string newIC);
		void editAddress(string newAddress);
        void editGender(string newGender);
        void editPhoneNo(string newPhone);
		void editDOB(string newDOB);


        friend void readFile(Student[], int&);
		friend void add(Student [], int&);
		void displayRecord(Student [], int &);
	    friend void del(Student [], int&);

};


#endif