#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "student.h"
#include "studentList.h"
#include <vector>

using namespace std;

bool studentList::addStudent(student stu)
{  
  //cout << maxSize << endl;
  if ((stuList.size()) >= maxSize)
     return false;  
  stuList.push_back(stu);
  return true;  
}  
void studentList::writeStudent(ostream& outfile)
{
  for(unsigned int index = 0; index < stuList.size(); index++)
    {       
      (stuList.at(index)).writeStudent(outfile);
       outfile << endl;
    }
}

void studentList::processGrades()
{  
  for(unsigned int index = 0; index < stuList.size(); index++)  
    (stuList.at(index)).processGrades(); 
}

void studentList::printGrades(ostream& outfile)
{ 
  for(unsigned int index = 0; index < stuList.size(); index++)
    (stuList.at(index)).printGrades(outfile);
} 

student& studentList::getStudent(int i)
{ 
  return stuList.at(i);
}


int studentList::searchById(string Id)
{  //returns the index if there is a match;  -1 otherwise.
  for (unsigned int index = 0; index < stuList.size(); index++)
    {
      if ((stuList.at(index)).getId() == Id)
	  return index;
    }
  return -1;}

int studentList::searchByName(char name[])
{  //returns the index if there is a match;  -1 otherwise.
  for (unsigned int index = 0; index < stuList.size(); index++)    
    { 
       if (strcmp(name, (stuList.at(index)).getName()) == 0)
	  return index;    
    }
  return -1;
}
