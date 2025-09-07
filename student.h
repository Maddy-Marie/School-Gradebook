#include <iostream>  
#include <fstream> 
using namespace std; 
#include <cstring>  
#include <string> 
#include <iomanip> 
#ifndef STUDENT
#define STUDENT
  


class student{

 public:
  
  const static int nameLength = 20;   
  const static int idLength = 9; 
  const static int maxAssignments = 10;
  const static int maxParticipation = 1;
  const static int maxMidterms = 3;
  const static int maxFinals = 1;
  
 private:
  char name[nameLength];  // name is stored as an array of char 
  string id;  // id stored as string
  int assignments;
  int participation;
  int midterms;
  int finals;
  float hwAssignments[maxAssignments];
  float participationGrade[maxParticipation];
  float mtTests[maxMidterms];
  float fiTests[maxFinals];
  int i;
  float hwGrade;
  float testGrade;
  char letterGrade;
  float finalGrade;



 void computeHW()
 {
  //compute hw score
    int i;
    float total = 0, partGrade;
    float min = hwAssignments[0];
    for (i = 0; i < maxAssignments; i++)
        {
          total += hwAssignments[i];

          if (hwAssignments[i] < min) 
          {
              min = hwAssignments[i];
          }
        }

      //access participation grade
      for (i = 0; i < maxParticipation; i++)
      {
        partGrade = participationGrade[i];

        if (participationGrade[i] < min)
        {
          min = participationGrade[i];
        }
      }


      //get total without the min
      total = total - min;
      hwGrade = (total * 50) / 1000;
 }





void computeTests()
{
  int i;
  float total = 0;

  for (i = 0; i < maxMidterms; i++)
  {
    total += mtTests[i];
  }

  for (i = 0; i < maxFinals; i++)
  {
    total += (fiTests[i] * 2);
  }

  testGrade = (total * 50) / 500;


}

void computeFinalGrade()
{
  finalGrade = hwGrade + testGrade;

}

 void calculateLetterGrade() {

    if (finalGrade >= 90) {
        letterGrade = 'A';
    } else if (finalGrade >= 80) {
        letterGrade = 'B';
    } else if (finalGrade >= 70) {
        letterGrade = 'C';
    } else if (finalGrade >= 60) {
        letterGrade = 'D';
    } else {
        letterGrade = 'F';
    }
}
  



 public:


        
 void setName(char n[]) // parameter is array of char, to match name
    {
      strcpy(name, n); // need this function; cannot assign arrays
    }
  
  void setId(string n ) // parameter is a string object
    {
      id =  n; // can be assigned
    }
  
  void setHW(float hw[], int size)
    {
      assignments = (size < maxAssignments) ? size : maxAssignments; 
      for (int i = 0; i < assignments; i++)
	        hwAssignments[i] = hw[i];
    }

  void setParticipation(float pt[], int size)
    {
      participation = (size < maxParticipation) ? size : maxParticipation; 
      for (int i = 0; i < participation; i++)
	        participationGrade[i] = pt[i];
    }

  void setMT(float mt[], int size)
    {
      midterms = (size < maxMidterms) ? size : maxMidterms; 
      for (int i = 0; i < midterms; i++)
	        mtTests[i] = mt[i];
    }

  void setFI(float fi[], int size)
    {
      finals = (size < maxFinals) ? size : maxFinals; 
      for (int i = 0; i < finals; i++)
	        fiTests[i] = fi[i];
    }

  string getId() // returns a string
    {
      return id;
    }
  
 

  char* getName() // returns an array of char
    {
      return name;
    }

  //process student method

void processGrades() {
    bool error = false;

    // Error handling: Check if grades are within valid range
    for (int i = 0; i < maxAssignments; i++) {
        if (hwAssignments[i] < 0 || hwAssignments[i] > 100) {
            error = true;
            break; 
        }
    }
    for (int i = 0; i < maxParticipation; i++) {
        if (participationGrade[i] < 0 || participationGrade[i] > 100) {
            error = true;
            break; 
        }
    }
    for (int i = 0; i < maxMidterms; i++) {
        if (mtTests[i] < 0 || mtTests[i] > 100) {
            error = true;
            break; 
        }
    }
    for (int i = 0; i < maxFinals; i++) {
        if (fiTests[i] < 0 || fiTests[i] > 100) {
            error = true;
            break;
        }
    }

    if (error) {
        // If there's an error in grades, set grades to -1.0 and letterGrade to 'Z'
        hwGrade = -1.0;
        testGrade = -1.0;
        finalGrade = -1.0;
        letterGrade = 'Z';
    } else {
        // If no error, compute grades
        computeHW();
        computeTests();
        computeFinalGrade();
        calculateLetterGrade();
    }
}


void printGrades(ostream& outfile) {
    outfile << setw(nameLength + 2) << name
            << setw(idLength + 2) << id 
            << setw(10) << hwGrade
            << setw(10) << testGrade 
            << setw(10) << finalGrade
            << setw(10) << letterGrade << endl;
}

 void printPersonalInfo(ostream& outfile)  
    {  
      
      outfile <<  "Name:   "<<  name << endl  
	      <<  "Id:   "<<  id << endl   
	      << "Homework Grade:  " << hwGrade << endl  
	      << "Test Grade:   " << testGrade << endl  
        << "Final Grade: " << finalGrade << endl
        << "Letter Grade: " << letterGrade << endl
	      <<"-------------------------------------------------"<<endl 
	      << endl;  
    }

  void writeStudent(ostream& outfile)  
    {
      // saves the raw data to the specified stream
      
      char space = ' ';
      outfile << name << space << id << space;
      for (int i = 0; i < assignments; i++)
        outfile << hwAssignments[i] << space;
      for (int i = 0; i < participation; i++)
        outfile << participationGrade[i] << space;
      for (int i = 0; i < midterms; i++)
        outfile << mtTests[i] << space;
      for (int i = 0; i < finals; i++)
        outfile << fiTests[i] << space;
    } 
};
#endif
