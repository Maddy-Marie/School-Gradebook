#include <iostream>
#include <fstream> 
using namespace std;
#include <cstring>  

#include <string>  
#include <iomanip>  
#include "studentList.h"
  
  
  

  
const int maxSize = 20;  
const int nameLength = student::nameLength;   
const int idLength = student::idLength;
  
 

studentList stuList(20);    
ofstream outfile;  
ifstream infile;    
char input_file_name[21], output_file_name[21], name[nameLength+1]; 
string id;  
  

void showMenu()  
{  
  cout<< "Please type in  one of the following options: \n";  
  cout<< "L or l  to load the student list \n";  
  cout<< "D or d  to display  the student data \n";  
  cout<< "P or p to process grades\n";  
  cout<< "C or c to change a student's grade \n";  
  cout<< "A or a to add a new student \n";  
  cout<< "S or s to search for a particular student's information \n";  
  cout<< "R or r to print the grade results \n";  
  cout<< "M or m to display this menu \n";  
  cout<< "E or e to save and exit \n";  
}  
 
void loadStudents()  
{  
    student s_temp;  
    float hw_score[10];
    float participation_score[1];
    float mt_score[3];
    float fi_score[1];
   
    int i;


    cout << "Please enter the name of the data file:  ";  
    cin >> input_file_name;  
    infile.open(input_file_name);  

    if (!infile)  
    {  
        cout << "Could not open input file \n";  
        infile.close();  
        infile.clear();  
        return;  
    }  
  infile >> name;
  s_temp.setName(name);
    while (!infile.eof())
    {
       
        infile >> id;
        s_temp.setId(id);
        
        //get homework scores 
        i = 0;
        while (i < 10 && infile >> hw_score[i])
        {
            i++;
        }
        //set homework scores
        s_temp.setHW(hw_score, i);

        i = 0;
        //get participation score
        while (i < 1 && infile >> participation_score[i])
        {
          i++;
        }

        //set participation score
        s_temp.setParticipation(participation_score, i);

        //get midterm scores
        i = 0;
        while (i < 3 && infile >> mt_score[i])
        {
          i++;
        }

        //set midterm scores
        s_temp.setMT(mt_score, i);

        //get final scores
        i = 0;
        while (i < 1 && infile >> fi_score[i])
        {
          i++;
        }

        //set final score
        s_temp.setFI(fi_score, i);


        stuList.addStudent(s_temp);
        infile >> name;
        s_temp.setName(name);
    }

    infile.close();  
    infile.clear();  
}    

 

  
void displayData()
{
  stuList.writeStudent(cout);
}

void processGrades()  
{  
  cout << "Processing grades \n";
  stuList.processGrades();

}  
  
  
void changeGrades()  
{  
    int i; 
    float new_final[1];

    cout << "Please enter the id of the student: ";
    cin >> id;
    i = stuList.searchById(id);

    if (i != -1)
    {
      cout << "Please enter the new final exam score: ";
      cin >> new_final[0];
      (stuList.getStudent(i)).setFI(new_final, 1);
    }

    else
    {
      cout << "Could not change the exam score." << endl;
    }
    

}  
  
void addNewStudent()  
{  
  student s_temp;
  float homework_scores[10];
  float participation_score[1];
  float midterm_scores[3];
  float final_score[1];

  cout << "Please enter the name of the student: ";
  cin >> name; s_temp.setName(name);

  cout << "Please enter the id of the student: ";
  cin >> id; s_temp.setId(id);

  cout << "Please enter the 10 homework scores: ";
  cin >> homework_scores[0] >> homework_scores[1]
      >> homework_scores[2] >> homework_scores[3]
      >> homework_scores[4] >> homework_scores[5]
      >> homework_scores[6] >> homework_scores[7] 
      >> homework_scores[8] >> homework_scores[9];
  s_temp.setHW(homework_scores, 10);

  cout << "Please enter the participation grade (1 score): ";
  cin >> participation_score[0];
  s_temp.setParticipation(participation_score, 1);

  cout << "Please enter the 3 midterm grades: ";
  cin >> midterm_scores[0] >> midterm_scores[1] >> midterm_scores[2];
  s_temp.setMT(midterm_scores, 3);

  cout << "Please enter the final exam score (1 score): ";
  cin >> final_score[0];
  s_temp.setFI(final_score, 1);

  if (stuList.addStudent(s_temp))
  {
    cout << "Successfully added the student!" << endl;
  }
  else
  {
    cout << "Was not able to add student." << endl;
  }
}  
  
  
void searchAStudent()  
{  
  cout << "Searching student \n"; 
  char c; int j;
  cout << "Please enter n/N to search by name and anything else to search by id:  ";
  cin >> c;
  if((c == 'n') || (c == 'N'))
    {
      cout << "Please enter name of the student:  ";
      cin >> name;
      j = stuList.searchByName(name);
    }
  else
    {
      cout << "Please enter id of the student:  ";
      cin >> id;
      j = stuList.searchById(id);
    }
  if (j!= -1)
    stuList.getStudent(j).printPersonalInfo(cout);
  else
    cout << "Sorry, the students could not be found \n";     
}  
  
void printGrades()  
{  
  cout << "Please enter name of output  file:  ";
  cin >> output_file_name;
  outfile.open(output_file_name);
  stuList.printGrades(outfile);
  outfile.close();
  outfile.clear();
}  
  
void saveInfo()  
{ 
  cout << "Please enter the name of the new output file: ";
  cin >> output_file_name;
  outfile.open(output_file_name);

  if (!outfile)
  {
    cout << "Could not open the file." << endl;
    outfile.close();
    outfile.clear();
    return;
  }

  stuList.writeStudent(outfile);
  outfile.close();
  outfile.clear();
}  
  
  
/* ---------------------- start of Main Program -----------------------------*/  
  
  
int main()  
{  
  
  char choice;  
    
  showMenu();  
  cout << "Please indicate your choice of operation (m for menu): ";  
  cin >> choice;  
  
  while ((choice != 'e')&& (choice != 'E'))  
    {  
      switch(choice)  
	{  
	case 'l':  
	case 'L': loadStudents(); break;  
  case 'd':
	case 'D': displayData(); break;
	case 'p':  
	case 'P': processGrades();break;  
	case 'c':  
	case 'C': changeGrades();break;  
	case 'a':  
	case 'A': addNewStudent();break;  
	case 's':  
	case 'S': searchAStudent();break;  
	case 'r':  
	case 'R': printGrades();break;  
	case 'm':  
	case 'M': showMenu();break;  
	default : cout << "Not a valid choice" << endl;  
	}  
      cin.ignore(200, '\n'); cin.clear(); //clear out all input  
      cout << "Please indicate your choice of operation (m for menu): ";  
      cin >> choice;  
    }  
  saveInfo();  
  cout << "Thank-you, good bye! \n";  
}  
  
