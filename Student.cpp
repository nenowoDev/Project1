#include <string>
#include "Student.h"
using namespace std;

// Student :: Student(string _id, string _name, string _programEnroll, string _ic, string _address, string _gender, string _DOB, string _phoneNo) {
//     id = _id;
//     name = _name;
//     programEnroll = _programEnroll;
//     ic = _ic;
//     address = _address;
//     gender = _gender;
//     DOB = _DOB;
//     phoneNo = _phoneNo;
// }

string Student :: getID()            { return id; }
string Student :: getName()          { return name; }
string Student :: getProgramEnroll() { return programEnroll; }
string Student :: getIC()            { return ic; }
string Student :: getAddress()       { return address; }
string Student :: getGender()        { return gender; }
string Student :: getDOB()           { return DOB; }
string Student :: getPhoneNo()       { return phoneNo; }
