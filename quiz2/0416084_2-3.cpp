/*
***************************************************
TITLE:
***************************************************
CHECK-CODE      :
Student Name   :
Student ID      :
Student Email   :
--
Lecturer Name: Sai-Keung Wong
Computer Science
Nationa Chiao Tung University, Taiwan
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
public:
   Student( ) { }

   void showEmail() 
   {
      cout << Email << endl;
   }
   
protected:
   void setAccount(string accountName)
   {
     Email=accountName+".";
   }
   void setStudentID(string StudentID) 
   {
   	Email=Email+StudentID[0]+StudentID[1]+"@nctu.edu.tw";
   }
   void setDepartment(string Department) 
   {
      Email=Email+Department;
   }
   

private:
   string accountName;
   string Department;
   string StudentID;
   string Email;
};

class Male : public Student
{
public:
   Male( ) { }
   void ProcessData(string input) 
   {    
   		int n;
   		int fault=0;
   		int underline=0;
   		string StudentID,accountName,Department;
   		int a=0,b=0,c=0;
		for(n=0;input[n]!='\0';n++){
			if(input[n]=='_'){
			underline++;
			if(underline==1)a=n;
			if(underline==2)b=n;
			if(underline==3)c=n;
			}
		}
		StudentID.assign(input,a+1,b-a-1);
		accountName.assign(input,b+1,c-b-1);
		Department.assign(input,c+1,n-c-1); 
		if(StudentID.size()!=7||accountName.size()!=8||Department.size()!=2)fault=1;
		if(fault==1) cout<<"Invalid Format"<<endl;
		else{
    		setAccount(accountName);
  			setDepartment(Department);
  			setStudentID(StudentID);
  			showEmail();
  		}
   }
};

class Female : public Student
{
public:
   Female( ) { }
   void ProcessData(string input) 
   {
      int n;
   		int fault=0;
   		int underline=0;
   		string StudentID,accountName,Department;
   		int a=0,b=0,c=0;
		for(n=0;input[n]!='\0';n++){
			if(input[n]=='_'){
			underline++;
			if(underline==1)a=n;
			if(underline==2)b=n;
			if(underline==3)c=n;
			}
		}
		Department.assign(input,a+1,b-a-1);
		StudentID.assign(input,b+1,c-b-1);
		accountName.assign(input,c+1,n-c-1); 
		if(StudentID.size()!=7||accountName.size()!=8||Department.size()!=2)fault=1;
		if(fault==1) cout<<"Invalid Format"<<endl;
		else{
    		setAccount(accountName);
  			setDepartment(Department);
  			setStudentID(StudentID);
  			showEmail();
  		}
   }
};

int main( )
{   
	int n,num;
	cin>>num;
	for(n=0;n<num;n++){
		Male male;
		Female female;
		Student a;
		string ques;
		cin>>ques;
		if(ques[0]=='0'){
			male.ProcessData(ques);
		}
		else if(ques[0]=='1'){
			female.ProcessData(ques);
		}
		else cout<<"Invalid Format"<<endl;
	}
   
   return 0;
}
