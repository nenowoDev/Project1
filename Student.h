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

		void search(Student stud[],int &count);

		friend class Staff;

};

#endif