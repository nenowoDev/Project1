#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
#include "Student.h"
#include "Student.cpp"

//static int count = 0;

// Function to display the main menu
void menu(Student [], int &count);
// Function to handle staff operations
void Staff(Student [], int &count);
// Function to handle student operations
void Stud(Student [], int &count);

// Function to read data from a file and store it in an array of Student objects
void readFile(Student stud[], int &count) {
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
void add(Student stud[], int &count) {
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
    cout<<"\n\n\n\t\t\tSTUDENT DETAILS RECORDED\n\n\n\n\n";	
}

//Function to delete student details
void del(Student stud[], int &count) {
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
	else
    	cout<<"\n\n\n\t\tTHE RECORD WAS DELETED SUCCESSFULLY\n\n\n\n\n";
    	
}

// Function to display all record of student in an array for the staff to see
void displayRecord(Student stud[], int &count) {
    cout<<"*************************************************************************************************************************************\n";
    cout<<"                                                       DISPLAY ALL RECORD\n";
    cout<<"*************************************************************************************************************************************\n\n";
    cout<<"ID        NAME                PROGRAM ENROLL              IC NUMBER        ADDRESS           GENDER    DATE OF BIRTH     PHONE NUMBER\n";
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------\n";
    readFile(stud, count);
    for (int i = 0; i < count; i++) {
    cout<<left<<setw(10)<<stud[i].id
        <<setw(20)<<stud[i].name
        <<setw(28)<<stud[i].programEnroll
        <<setw(17)<<stud[i].ic
        <<setw(18)<<stud[i].address
        <<setw(10)<<stud[i].gender
        <<setw(18)<<stud[i].DOB               
        <<setw(15)<<stud[i].phoneNo<<endl;
    }
    cout<<endl<<endl;
}

// Function to display the main menu and handle user input
void menu(Student stud[], int &count) {
    int n;
    start:
    system("cls");
    cout<<"*******************************************\n";
    cout<<"        STUDENT MANAGEMENT SYSTEM\n";
    cout<<"*******************************************\n\n";
    cout<<"            -----------------\n";
    cout<<"                MAIN MENU\n";
    cout<<"            -----------------\n\n";
    cout<<"              SELECT OPTION\n";
    cout<<"-------------------------------------------\n";
    cout<<"         1. STAFF \t2. STUDENT\n";
    cout<<"-------------------------------------------\n";
    cout<<"            (PRESS 3 TO EXIT)\n\n";
    cout<<"         ENTER AN OPTION -> ";
    cin>>n;
    system("cls");
    switch(n)
    {
        case 1: Staff(stud, count);
                break;
        case 2: Stud(stud, count);
                break;
        case 3: exit(0);
                break;
        default:cout<<"\n\n\nWRONG OPTION!\n";
               system("PAUSE");
    }
    goto start;
}

// Function to handle staff operations
void Staff(Student stud[], int &count) {
    int n;
    start:
    system("cls");
    cout<<"******************************\n";
    cout<<"            STAFF\n";
    cout<<"******************************\n\n";
    cout<<"       ------------\n";
    cout<<"           MENU\n";
    cout<<"       ------------\n\n";
    cout<<"  1. Create new Record\n";
    cout<<"  2. Edit Existing Record\n";
    cout<<"  3. Remove a Record"<<"\n";
    cout<<"  4. Display All Records\n";
    cout<<"  5. Back to Main Menu\n\n";
    cout<<"   ENTER YOUR OPTION -> ";
    cin>>n;
    system("cls");
    switch(n)
    {
    	case 1: add(stud, count);
            break;
        // case 2: edit(stud, count);
        //     break;
        case 3: del(stud, count);
        	break;
        case 4: displayRecord(stud, count);
            break;
        case 5: menu(stud, count);
            break;
        default:cout<<"\n\n\n\nWRONG OPTION!\n";
    }
    system("PAUSE");
    goto start;
}

// Function to handle student operations
void Stud(Student stud[], int &count) {
    int n;
    start:
    system("cls");
    cout<<"******************************\n";
    cout<<"           STUDENT\n";
    cout<<"******************************\n\n";
    cout<<"        ------------"<<"\n";
    cout<<"            MENU"<<"\n";
    cout<<"        ------------"<<"\n\n";
    cout<<"  1. View Student Detail"<<"\n";
    cout<<"  2. Back to Main Menu"<<"\n\n";
    cout<<"   ENTER YOUR OPTION -> ";
    cin>>n;
    system("cls");
    switch(n)
    {
        // case 1:search(stud);
        //     break;
        case 2:menu(stud, count);
            break;
        default:cout<<"\n\n\nWRONG OPTION!!\n";
    }
    system("PAUSE");
    goto start;
}

int main() {
    int count = 0;
    Student stud[50];

    readFile(stud, count);
    
    menu(stud, count);
   
    return 0;
}

