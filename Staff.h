#ifndef STAFF_H
#define STAFF_H
#include <string>
#include "Student.h"

class Staff {
    public:
        void merge(Student theArray[], int first, int mid, int last);
        void mergeSort(Student theArray[],int first,int last);
        void InsertionSort(Student[], int);
		void BubbleSort(Student[], int);
		void SelectionSort(Student[], int);

        void edit(Student stud[],int &count,int index);
        void readFile(Student[], int&);
		void add(Student [], int&);
	    void del(Student [], int&);
		//void displayRecord(Student [], int&);
		void display(Student[], int&);

        friend class Student;
};


#endif