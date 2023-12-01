#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
#include "Student.h"
#include "Student.cpp"
#include "Staff.h"
#include "Staff.cpp"

// Function to display the main menu
void menu(Student [], int &count,Staff admin);
// Function to handle staff operations
void Staffmenu(Student [], int &count,Staff admin);
// Function to handle student operations
void Stud(Student [], int &count,Staff admin);


// Function to display the main menu and handle user input
void menu(Student stud[], int &count,Staff admin) {
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
        case 1: Staffmenu(stud, count,admin);
                break;
        case 2: Stud(stud, count,admin);
                break;
        case 3: exit(0);
                break;
        default:cout<<"\n\n\nWRONG OPTION!\n";
               system("PAUSE");
    }
    goto start;
}

// Function to handle staff operations
void Staffmenu(Student stud[], int &count,Staff admin) {
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
    	case 1: admin.add(stud, count);
            break;
        case 2: admin.edit(stud, count);
             break;
        case 3: admin.del(stud, count);
        	break;
        case 4: admin.display(stud, count);
            break;
        case 5: menu(stud, count,admin);
            break;
        default:cout<<"\n\n\n\nWRONG OPTION!\n";
    }
    system("PAUSE");
    goto start;
}

// Function to handle student operations
void Stud(Student stud[], int &count,Staff admin) {
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
        case 1:stud->search(stud,count);
           break;
        case 2:menu(stud, count,admin);
            break;
        default:cout<<"\n\n\nWRONG OPTION!!\n";
    }
    system("PAUSE");
    goto start;
}

int main() {
    int count = 0;
    Student stud[50];
    Staff admin;

    admin.readFile(stud, count);
    
    menu(stud, count,admin);
   
    return 0;
}

