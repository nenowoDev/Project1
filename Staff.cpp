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

void Staff::selectionSort(int Data[], int n){
    for (int last = n-1; last >= 1; --last){
        int largestIndex = 0;
        for (int p=1;p <= last; ++p){
            if (Data[p]>Data[largestIndex])
                largestIndex = p;
        } 
        swap(Data[largestIndex],Data[last]);
    }  
} 


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



void Staff::search(Student stud[],int &count){

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
        stud->displayRecord(temp,tempc);


    }   


}