#include <string>
#include "Student.h"
using namespace std;

string Student :: getID()            { return id; }
string Student :: getName()          { return name; }
string Student :: getProgramEnroll() { return programEnroll; }
string Student :: getIC()            { return ic; }
string Student :: getAddress()       { return address; }
string Student :: getGender()        { return gender; }
string Student :: getDOB()           { return DOB; }
string Student :: getPhoneNo()       { return phoneNo; }


void Student::editID(string newID)                    {id=newID;}
void Student::editName(string newName)                {name=newName;}
void Student::editProgramEnroll(string newProg)       {programEnroll=newProg;}
void Student::editIC(string newIC)                    {ic=newIC;}
void Student::editAddress(string newAddress)          {address=newAddress;}
void Student::editGender(string newGender)            {gender=newGender;}
void Student::editPhoneNo(string newPhone)            {phoneNo=newPhone;}
void Student::editDOB(string newDOB)                  {DOB=newDOB;}

//Bubble Sort
void Student :: BubbleSort(Student data[], int n)
{
    Student tempValue;
    bool sorted = false;
    for(int pass = 1; (pass < n) && !sorted; ++pass) 
    {   
        sorted = true;
        for(int x = 0; x < n - pass; x++)
        {
            if(data[x].getID() > data[x+1].getID())
            {
                tempValue = data[x];
                data[x] = data[x+1];
                data[x+1] = tempValue;
                sorted = false;
            }
        }
    }
}

//Insertion Sort
void Student :: InsertionSort(Student stud[], int n) {
    Student temp;
    int X, last;
    for (last = n-1; last >= 1; last--)
    {
        X = 0;
        for (int p = 1; p <= last; ++p) 
        {
            if (stud[p].getID() > stud[X].getID())
                X = p;
        }
        temp = stud[last];
        stud[last] = stud[X];
        stud[X] = temp;
    }
}

// Function to read data from a file and store it in an array of Student objects
void Student :: readFile(Student stud[], int &count) {
    int n = 0;
    ifstream inp("Record.csv");
    if (!inp) {
         cout<<"\t\t\tFILE NOT FOUND!";
         cout<<"\n\n";
    }
    else {
        while(getline(inp, stud[n].id, ',')) {
         	getline(inp, stud[n].name, ',');
         	getline(inp, stud[n].programEnroll, ',');
         	getline(inp, stud[n].ic, ',');
         	getline(inp, stud[n].address, ',');
			getline(inp, stud[n].gender, ',');
            getline(inp, stud[n].DOB, ',');
			getline(inp, stud[n].phoneNo);
            n++;
            //count++;
        }
        count = n;
    }
    inp.close();
}

// Function to add student details
void Student :: add(Student stud[], int &count) {
	cout<<"***********************************************************************\n";
    cout<<"                          CREATE NEW RECORD\n";
    cout<<"***********************************************************************\n\n";
	cout<<"\n\t\t  -------------------------------\n";
    cout<<"\t\t     ENTER THE STUDENT DETAILS\n";
    cout<<"\t\t  -------------------------------\n\n";
    cin.ignore();
    cout<<"\t	ID NUMBER        -> "; getline(cin, stud[count].id); 
    cout<<"\t	NAME             -> "; getline(cin, stud[count].name);  
	cout<<"\t	PROGRAM ENROLL   -> "; getline(cin, stud[count].programEnroll); 
	cout<<"\t	IC NUMBER        -> "; getline(cin, stud[count].ic); 
	cout<<"\t	ADDRESS          -> "; getline(cin, stud[count].address); 
	cout<<"\t	GENDER           -> "; getline(cin, stud[count].gender); 
	cout<<"\t	DATE OF BIRTH    -> "; getline(cin, stud[count].DOB); 
    cout<<"\t	PHONE NUMBER     -> "; getline(cin, stud[count].phoneNo);
    cout<<endl<<endl;
    count++;

    ofstream f("Record.csv");
    for(int i = 0; i < count; i++) {
    	f << stud[i].getID() << "," 
          << stud[i].getName() << "," 
          << stud[i].getProgramEnroll() << "," 
          << stud[i].getIC() << "," 
          << stud[i].getAddress() << "," 
          << stud[i].getGender() << "," 
          << stud[i].getDOB() << ","   
          << stud[i].getPhoneNo() << endl;     
	}
    f.close();

    system("cls");
    cout<<"***********************************************************************\n";
    cout<<"                          CREATE NEW RECORD\n";
    cout<<"***********************************************************************\n\n";
    cout<<"\n\n\n\t\t\tSTUDENT DETAILS RECORDED\n\n\n";	
    char y;
    cout<<"\t\tDo you want to sort the student list (Y/N) : ";
    cin>>y;
    if (y=='Y' || y=='y') {
        InsertionSort(stud, count);
        cout<<"\n\n\t\tThe student list is sorted\n\n\n";
    } 
    else 
        cout<<"\n\n\t\t\tThe list is not sorted\n\n\n";
}

//Function to delete student details
void Student :: del(Student stud[], int &count) {
    string id; int value = 0;
	cout<<"***********************************************************************\n";
    cout<<"                        DELETE STUDENT RECORD\n";
    cout<<"***********************************************************************\n\n";
    readFile(stud, count);
    cout<<"\n\n\n\t\t ENTER STUDENT ID : ";
    cin>>id;
    system("cls");
    int x=0;
    for(int n = 0; n < count; n++)
    	if(id == stud[n].getID()) {
        	value=1;
        	x=n;	
        }
	
    if (value == 1) {
		ofstream f("Record.csv");
		for(int i = 0; i < count; i++) {
    		if(i == x) 
    			continue;		
    		else{
    		f << stud[i].getID() << "," 
              << stud[i].getName() << "," 
              << stud[i].getProgramEnroll() << "," 
              << stud[i].getIC() << "," 
              << stud[i].getAddress() << "," 
              << stud[i].getGender() << "," 
              << stud[i].getDOB() << ","   
              << stud[i].getPhoneNo() << endl;  	
			}		
		}
    	f.close();	
	}

    system("cls");
    cout<<"***********************************************************************\n";
    cout<<"                        DELETE STUDENT RECORD\n";
    cout<<"***********************************************************************\n\n";
    if(value==0)
    	cout<<"\n\n\n\t\t\tRECORD NOT FOUND!\n\n\n\n\n"; 
	else {
        cout<<"\n\n\n\t\tTHE RECORD WAS DELETED SUCCESSFULLY\n\n\n";
        char y;
        cout<<"\tDo you want to sort the student list (Y/N) : ";
        cin>>y;
        if (y=='Y' || y=='y') {
            readFile(stud, count);
            BubbleSort(stud, count); 
            cout<<"\n\n\t\tThe student list is sorted\n\n\n";
        } 
        else 
            cout<<"\n\n\t\t\tThe list is not sorted\n\n\n";	
    }
}

// Function to display all record of student in an array for the staff to see
void Student :: displayRecord(Student stud[], int &count) {
    cout<<"*************************************************************************************************************************************\n";
    cout<<"                                                       DISPLAY ALL RECORD\n";
    cout<<"*************************************************************************************************************************************\n\n";
    cout<<"ID        NAME                PROGRAM ENROLL              IC NUMBER        ADDRESS           GENDER    DATE OF BIRTH     PHONE NUMBER\n";
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------\n";
    //readFile(stud, count);
    for (int i = 0; i < count; i++) {
    cout<<left<<setw(10)<<stud[i].getID()
        <<setw(20)<<stud[i].getName()
        <<setw(28)<<stud[i].getProgramEnroll()
        <<setw(17)<<stud[i].getIC()
        <<setw(18)<<stud[i].getAddress()
        <<setw(10)<<stud[i].getGender()
        <<setw(18)<<stud[i].getDOB()               
        <<setw(15)<<stud[i].getPhoneNo()<<endl;
    }
    cout<<endl<<endl;
}