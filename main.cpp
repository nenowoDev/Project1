#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
#include "Student.h"
#include "Student.cpp"

static int count = 0;

// Function to display the main menu
void menu(Student []);

// Function to handle staff operations
void Staff(Student []);

// Function to handle student operations
void Stud(Student []);

// Function to read data from a file and store it in an array of Student objects
void readFile(Student stud[]) {
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
		    //inp.ignore();
        }
        count = n;
    }
    inp.close();
}

// Function to display all record of student in an array for the staff to see
void displayRecord(Student stud[]) {
    cout<<"*************************************************************************************************************************************\n";
    cout<<"                                                       DISPLAY ALL RECORD\n";
    cout<<"*************************************************************************************************************************************\n\n";
    cout<<"ID        NAME                PROGRAM ENROLL              IC NUMBER      ADDRESS             GENDER    DATE OF BIRTH     PHONE NUMBER\n";
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < count; i++) {
    cout<<left<<setw(10)<<stud[i].id
        <<setw(20)<<stud[i].name
        <<setw(28)<<stud[i].programEnroll
        <<setw(15)<<stud[i].ic
        <<setw(20)<<stud[i].address
        <<setw(10)<<stud[i].gender
        <<setw(18)<<stud[i].DOB               
        <<setw(15)<<stud[i].phoneNo<<endl;
    }
    cout<<endl<<endl;
}

// Function to display the main menu and handle user input
void menu(Student stud[]) {
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
        case 1: Staff(stud);
                break;
        case 2: Stud(stud);
                break;
        case 3: exit(0);
                break;
        default:cout<<"\n\n\nWRONG OPTION!";
               system("PAUSE");
    }
    goto start;
}

// Function to handle staff operations
void Staff(Student stud[]) {
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
    cout<<"  2. Search Existing Record\n";
    cout<<"  3. Remove a Record"<<"\n";
    cout<<"  4. Display All Records\n";
    cout<<"  5. Back to Main Menu\n\n";
    cout<<"   ENTER YOUR OPTION -> ";
    cin>>n;
    system("cls");
    switch(n)
    {
    	// case 1: add(stud);
        //     break;
        // case 2: search(stud);
        //     break;
        // case 3: del(stud);
        // 	break;
        case 4: displayRecord(stud);
            break;
        case 5: menu(stud);
            break;
        default:cout<<"\n\n\n\nWRONG OPTION!";
    }
    system("PAUSE");
    goto start;
}

// Function to handle student operations
void Stud(Student stud[]) {
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
        // case 1:viewStudent(stud);
        //     break;
        case 2:menu(stud);
            break;
        default:cout<<"\n\n\nWRONG OPTION!!";
    }
    system("PAUSE");
    goto start;
}

int main() {
    Student stud[50];

    readFile(stud);
    //displayRecord(stud);
    
    menu(stud);
   
    return 0;
}

