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



void Student::search(Student stud[],int &count){

    system("cls");
    cout<<"***********************************************************************\n";
    cout<<"                        SEARCH STUDENT RECORD\n";
    cout<<"***********************************************************************\n\n";
    cout<<"\t\t"<<setw(25)<<left<<"[1] ALL"           <<"\n";
    cout<<"\t\t"<<setw(25)<<left<<"[2] ID"            <<"\n";
    cout<<"\t\t"<<setw(25)<<left<<"[3] NAME"          <<"\n";
    cout<<"\t\t"<<setw(25)<<left<<"[4] PROGRAMME"     <<"\n";
    cout<<"\t\t"<<setw(25)<<left<<"[5] IC NUMBER"     <<"\n";
    cout<<"\t\t"<<setw(25)<<left<<"[6] ADDRESS"       <<"\n";
    cout<<"\t\t"<<setw(25)<<left<<"[7] GENDER"        <<"\n";
    cout<<"\t\t"<<setw(25)<<left<<"[8] DATE OF BIRTH" <<"\n";
    cout<<"\t\t"<<setw(25)<<left<<"[9] PHONE NUMBER"  <<"\n";

    cout<<"\n\n\t\tSELECT ATTRIBUTE TO SEARCH (1-9) <<" ;
    int searchwhere;
    cin>>searchwhere;
    int tempc=0;

    if(searchwhere<1||searchwhere>9){
            search(stud,count);
    }

    
    else{

        cout<<"\n\t\tVALUES TO SEARCH:";
        cin.ignore();
        string searchwhat;
        getline(cin,searchwhat);
        Student temp[count];
        if(searchwhere==1){
            for(int i=0;i<count;i++){
                
                if(stud[i].getID().find(searchwhat)!=string::npos){
                    temp[tempc]=stud[i];
                    tempc++;
                }
                else if(stud[i].getName().find(searchwhat)!=string::npos){
                    temp[tempc]=stud[i];
                    tempc++;
                }
                else if(stud[i].getProgramEnroll().find(searchwhat)!=string::npos){
                    temp[tempc]=stud[i];
                    tempc++;
                }
                else if(stud[i].getIC().find(searchwhat)!=string::npos){
                    temp[tempc]=stud[i];
                    tempc++;
                }
                else if(stud[i].getAddress().find(searchwhat)!=string::npos){
                    temp[tempc]=stud[i];
                    tempc++;
                }
                else if(stud[i].getGender().find(searchwhat)!=string::npos){
                    temp[tempc]=stud[i];
                    tempc++;
                }
                else if(stud[i].getDOB().find(searchwhat)!=string::npos){
                    temp[tempc]=stud[i];
                    tempc++;
                }
                else if(stud[i].getPhoneNo().find(searchwhat)!=string::npos){
                    temp[tempc]=stud[i];
                    tempc++;
                }
            }

        }

        else if(searchwhere==2){
            for(int i=0;i<count;i++){
                
                if(stud[i].getID().find(searchwhat)!=string::npos){
                    temp[tempc]=stud[i];
                    tempc++;
                }
            }
        }

        else if(searchwhere==3){
            for(int i=0;i<count;i++){
                
                if(stud[i].getName().find(searchwhat)!=string::npos){
                    temp[tempc]=stud[i];
                    tempc++;
                }
            }
        }


        else if(searchwhere==4){
            for(int i=0;i<count;i++){
                
                if(stud[i].getProgramEnroll().find(searchwhat)!=string::npos){
                    temp[tempc]=stud[i];
                    tempc++;
                }
            }
        }

        else if(searchwhere==5){
            for(int i=0;i<count;i++){
                
                if(stud[i].getIC().find(searchwhat)!=string::npos){
                    temp[tempc]=stud[i];
                    tempc++;
                }
            }
        }

        else if(searchwhere==6){
            for(int i=0;i<count;i++){
                
                if(stud[i].getAddress().find(searchwhat)!=string::npos){
                    temp[tempc]=stud[i];
                    tempc++;
                }
            }
        }

        else if(searchwhere==7){
            for(int i=0;i<count;i++){
                
                if(stud[i].getGender().find(searchwhat)!=string::npos){
                    temp[tempc]=stud[i];
                    tempc++;
                }
            }
        }

        else if(searchwhere==8){
            for(int i=0;i<count;i++){
                
                if(stud[i].getDOB().find(searchwhat)!=string::npos){
                    temp[tempc]=stud[i];
                    tempc++;
                }
            }
        }

        else if(searchwhere==9){
            for(int i=0;i<count;i++){
                
                if(stud[i].getPhoneNo().find(searchwhat)!=string::npos){
                    temp[tempc]=stud[i];
                    tempc++;
                }
            }
        }


        


        system("cls");
        cout<<"\n\n\t\tOCCURENCE OF \""<<searchwhat<<"\"\n";
        cout<<"*************************************************************************************************************************************\n";
        cout<<"                                                       DISPLAY ALL RECORD\n";
        cout<<"*************************************************************************************************************************************\n\n";
        cout<<"ID        NAME                PROGRAM ENROLL              IC NUMBER        ADDRESS           GENDER    DATE OF BIRTH     PHONE NUMBER\n";
        cout<<"-------------------------------------------------------------------------------------------------------------------------------------\n";
        for (int i = 0; i < tempc; i++) {
        cout<<left<<setw(10)<<temp[i].getID()
            <<setw(20)<<temp[i].getName()
            <<setw(28)<<temp[i].getProgramEnroll()
            <<setw(17)<<temp[i].getIC()
            <<setw(18)<<temp[i].getAddress()
            <<setw(10)<<temp[i].getGender()
            <<setw(18)<<temp[i].getDOB()               
            <<setw(15)<<temp[i].getPhoneNo()<<endl;
    }
    cout<<endl<<endl;


    }   


}
