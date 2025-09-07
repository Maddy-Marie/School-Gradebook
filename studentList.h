#include <fstream>
using namespace std;
#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include "student.h"

#ifndef STUDENTLIST
#define STUDENTLIST

//studentList class
class studentList 
{

private:

 unsigned int maxSize; 

 int  nameLength, idLength; 

vector<student> stuList;


public: 
//constructor
studentList(unsigned int size=0)//default

{
   maxSize = size;
   nameLength = student::nameLength; 

}


bool addStudent(student ); 


void writeStudent(ostream& outfile);
void processGrades();
void printGrades(ostream& outfile);
student& getStudent(int i);


int searchById(string Id);

int searchByName(char name[]);



};
#endif
