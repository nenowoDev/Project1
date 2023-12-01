#ifndef STAFF_H
#define STAFF_H
#include <string>
#include "Student.h"

class Staff {
    private :

    public:
        void merge(Student theArray[], int first, int mid, int last);
        void mergeSort(Student theArray[],int first,int last);
        void selectionSort(int Data[], int n);
        void edit(Student stud[],int &count,int index);
        void search(Student stud[],int &count);
};


#endif