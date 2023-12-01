#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Staff.h"
#include "Student.h"
using namespace std;

void Staff::merge(Student theArray[], int first, int mid, int last){
    Student tempArray[100]; 
    int first1 = first;  
    int last1 = mid;  
    int first2 = mid + 1; 
    int last2 = last; 
    int index = first1;

    for (; (first1 <= last1) && (first2 <= last2); ++index){
        if (theArray[first1].getID() < theArray[first2].getID()){
            tempArray[index] = theArray[first1];
            ++first1;
        }
        else{
            tempArray[index] = theArray[first2];
            ++first2;
        }
    } 
    for (; first1 <= last1; ++first1, ++index)
        tempArray[index] = theArray[first1];
    for (; first2 <= last2; ++first2, ++index)
        tempArray[index] = theArray[first2];

    for (index = first; index <= last; ++index)
        theArray[index] = tempArray[index];
}

void Staff::mergeSort(Student theArray[],int first,int last){
        if (first < last){

            int mid = (first + last)/2; 
            mergeSort(theArray, first, mid);
            mergeSort(theArray, mid+1, last);
            merge(theArray, first, mid, last);
        } 
} 

//Bubble Sort
void Staff :: BubbleSort(Student data[], int n)
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
void Staff :: InsertionSort(Student stud[], int n) {
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

//Selection Sort
void Staff :: SelectionSort(Student Data[], int n) 
{
    for (int last = n-1; last >= 1; --last)
    {
        int largestIndex = 0;
        for (int p = 1; p <= last; ++p)
        {
            if (Data[p].getID() > Data[largestIndex].getID())
                largestIndex = p;
        }
        swap(Data[largestIndex], Data[last]);
    }
}
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

// Function to edit student record
void Staff::edit(Student stud[],int &count,int index=-1){

    if(index==-1){

        cout<<"***********************************************************************\n";
        cout<<"                        EDIT STUDENT RECORD\n";
        cout<<"***********************************************************************\n\n";
        string studID;
        cout<<"\n\n\n\t\t ENTER STUDENT ID : ";
        cin>>studID;
        system("cls");
        int value=0,c=0;
        int tempindex[50];
        for(int i=0;i<count;i++){
            if(stud[i].getID() == studID){
                tempindex[c]=i;
                value=1;
                c+=1;
                index=i;
            }
        }

        system("cls");
        cout<<"***********************************************************************\n";
        cout<<"                        EDIT STUDENT RECORD\n";
        cout<<"***********************************************************************\n\n";
        if(value==0){
        	cout<<"\n\n\n\t\t\tRECORD NOT FOUND!\n\n\n\n\n";
        } 
    	else{
        	cout<<"\n\n\n\t\tTHE RECORD WAS FOUND SUCCESSFULLY\n\n\n\n\n";
            if(c>1){
                system("cls");
                cout<<"*************************************************************************************************************************************\n";
                cout<<"                                                       AMBIGIOUS  RECORD\n";
                cout<<"*************************************************************************************************************************************\n\n";
                cout<<" INDEX ID        NAME                PROGRAM ENROLL              IC NUMBER        ADDRESS           GENDER    DATE OF BIRTH     PHONE NUMBER\n";
                cout<<"-------------------------------------------------------------------------------------------------------------------------------------\n";
                
                for (int i=0;i<c;i++){
                    cout<<left
                    <<setw(6)<<tempindex[i]
                    <<setw(10)<<stud[tempindex[i]].getID()
                    <<setw(20)<<stud[tempindex[i]].getName()
                    <<setw(28)<<stud[tempindex[i]].getProgramEnroll()
                    <<setw(17)<<stud[tempindex[i]].getIC()
                    <<setw(18)<<stud[tempindex[i]].getAddress()
                    <<setw(10)<<stud[tempindex[i]].getGender()
                    <<setw(18)<<stud[tempindex[i]].getDOB()               
                    <<setw(15)<<stud[tempindex[i]].getPhoneNo()<<endl;
                }
                cout<<"\t\t\nCHOOSE INDEX :";
                cin>>index;
            }
        }
    }

    if(index!=-1){

        system("cls");
        cout<<"***********************************************************************\n";
        cout<<"                        EDIT STUDENT RECORD\n";
        cout<<"***********************************************************************\n\n";
        cout<<setw(25)<<left<<"[1] ID"                <<stud[index].getID()<<"\n";
        cout<<setw(25)<<left<<"[2] NAME"              <<stud[index].getName()<<"\n";
        cout<<setw(25)<<left<<"[3] PROGRAMME"         <<stud[index].getProgramEnroll()<<"\n";
        cout<<setw(25)<<left<<"[4] IC NUMBER"         <<stud[index].getIC()<<"\n";
        cout<<setw(25)<<left<<"[5] ADDRESS"           <<stud[index].getAddress()<<"\n";
        cout<<setw(25)<<left<<"[6] GENDER"            <<stud[index].getGender()<<"\n";
        cout<<setw(25)<<left<<"[7] DATE OF BIRTH"     <<stud[index].getDOB()<<"\n";
        cout<<setw(25)<<left<<"[8] PHONE NUMBER"      <<stud[index].getPhoneNo()<<"\n";
        cout<<setw(25)<<left<<"[9] EXIT\n";

        cout<<"\n\n\n\t\t CHOOSE ATTRIBUTES TO EDIT (1-8) : ";
        int choice;
        cin>>choice;

        if(choice<1||choice>9){
            edit(stud,count,index);
        }
        else if(choice==1){
            cout<<"\n\n\t\t OLD ID       -> "<<stud[index].getID()<<"\n";
            cout<<"\t\t ENTER NEW ID -> ";
            string newvalue;
            cin.ignore();
            getline(cin,newvalue);
            stud[index].editID(newvalue);
        }
        else if(choice==2){
            cout<<"\n\n\t\t OLD NAME       -> "<<stud[index].getName()<<"\n";
            cout<<"\t\t ENTER NEW NAME -> ";
            string newvalue;
            cin.ignore();
            getline(cin,newvalue);
            stud[index].editName(newvalue);
        }
        else if(choice==3){
            cout<<"\n\n\t\t OLD PROGRAMME       -> "<<stud[index].getProgramEnroll()<<"\n";
            cout<<"\t\t ENTER NEW PROGRAMME -> ";
            string newvalue;
            cin.ignore();
            getline(cin,newvalue);
            stud[index].editProgramEnroll(newvalue);
        }
        else if(choice==4){
            cout<<"\n\n\t\t OLD IC       -> "<<stud[index].getIC()<<"\n";
            cout<<"\t\t ENTER NEW IC -> ";
            string newvalue;
            cin.ignore();
            getline(cin,newvalue);
            stud[index].editIC(newvalue);
        }
        else if(choice==5){
            cout<<"\n\n\t\t OLD ADDRESS       -> "<<stud[index].getAddress()<<"\n";
            cout<<"\t\t ENTER NEW ID -> ";
            string newvalue;
            cin.ignore();
            getline(cin,newvalue);
            stud[index].editID(newvalue);
        }
        else if(choice==6){
            cout<<"\n\n\t\t OLD GENDER       -> "<<stud[index].getGender()<<"\n";
            cout<<"\t\t ENTER NEW GENDER -> ";
            string newvalue;
            cin.ignore();
            getline(cin,newvalue);
            stud[index].editGender(newvalue);
        }
        else if(choice==7){
            cout<<"\n\n\t\t OLD DATE OF BIRTH       -> "<<stud[index].getDOB()<<"\n";
            cout<<"\t\t ENTER NEW DATE OF BIRTH -> ";
            string newvalue;
            cin.ignore();
            getline(cin,newvalue);
            stud[index].editDOB(newvalue);
        }
        else if(choice==8){
            cout<<"\n\n\t\t OLD PHONE No       -> "<<stud[index].getPhoneNo()<<"\n";
            cout<<"\t\t ENTER NEW PHONE No -> ";
            string newvalue;
            cin.ignore();
            getline(cin,newvalue);
            stud[index].editPhoneNo(newvalue);
        }
        
        if(choice>=1&&choice<=8){
            cout<<"\n\n\t\t EDIT SUCCESSFUL\n";

            Staff::mergeSort(stud,0,count-1);

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
        }
    }
}

// Function to read data from a file
void Staff :: readFile(Student stud[], int &count) {
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
        }
        count = n;
    }
    inp.close();
}

// Function to add student details
void Staff :: add(Student stud[], int &count) {
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

    InsertionSort(stud, count);

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
    
    system("PAUSE");
    system("cls");
    cout<<"*************************************************************************************************************************************\n";
    cout<<"                                                       DISPLAY ALL RECORD\n";
    cout<<"*************************************************************************************************************************************\n\n";
    cout<<"ID        NAME                PROGRAM ENROLL              IC NUMBER        ADDRESS           GENDER    DATE OF BIRTH     PHONE NUMBER\n";
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------\n";
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

//Function to delete student details
void Staff :: del(Student stud[], int &count) {
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
        readFile(stud, count);
        BubbleSort(stud, count);

        system("PAUSE");
        system("cls");
        cout<<"*************************************************************************************************************************************\n";
        cout<<"                                                       DISPLAY ALL RECORD\n";
        cout<<"*************************************************************************************************************************************\n\n";
        cout<<"ID        NAME                PROGRAM ENROLL              IC NUMBER        ADDRESS           GENDER    DATE OF BIRTH     PHONE NUMBER\n";
        cout<<"-------------------------------------------------------------------------------------------------------------------------------------\n";
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
}

// Function to display sorted student record
void Staff :: display(Student stud[], int &count) {
    SelectionSort(stud, count);

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
    
    cout<<"*************************************************************************************************************************************\n";
    cout<<"                                                       DISPLAY ALL RECORD\n";
    cout<<"*************************************************************************************************************************************\n\n";
    cout<<"ID        NAME                PROGRAM ENROLL              IC NUMBER        ADDRESS           GENDER    DATE OF BIRTH     PHONE NUMBER\n";
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------\n";
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


