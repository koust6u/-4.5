//Student.cc
#include "teststudent.h"

Student::Student() { Clear(); }

void Student::Clear()
{
	// set each field to an empty string
	sname[0] = 0;
	SID[0] = 0;
	age = 0;
	weight = 0;
	Address[0] = 0;
}

Student::Student(Student& s) {
	strcpy(sname, s.sname);
	strcpy(SID, s.SID);
	age = s.age;
	weight = s.weight;
	strcpy(Address, s.Address);

}

int Student::Pack(IOBuffer& Buffer) const
{// pack the fields into a FixedFieldBuffer, 
 // return TRUE if all succeed, FALSE o/w
	int numBytes;
	int result;
	Buffer.Clear();
	result = Buffer.Pack(&(this->SID), strlen(SID));
	if (result == -1)return FALSE;
	result = Buffer.Pack(&(this->sname), strlen(sname));
	if (result == -1)return FALSE;
	result = Buffer.Pack(&(this->age), 2);
	if (result == -1)return FALSE;
	result = Buffer.Pack(&(this->weight), 4);
	if (result == -1)return FALSE;
	result = Buffer.Pack(&(this->Address),strlen(Address));
	if (result == -1)return FALSE;

	return TRUE;
}

int Student::Unpack(IOBuffer& Buffer)
{
	Clear();
	int numBytes = 0;
	int result;
	char temp[20];
	char temp2[20];
	result = Buffer.Unpack(&(this->SID),40);
	if (result == -1)return FALSE;
	cout << "ID ok" << endl;
	result = Buffer.Unpack(&(this->sname), 10);
	if (result == -1)return FALSE;
	cout << "Name ok" << endl;
	result = Buffer.Unpack(&(this->age), 4);
	if (result == -1)return FALSE;
	cout << "age ok" << endl;
	result = Buffer.Pack(&(this->weight), 4);
	if (result == -1)return FALSE;
	cout << "weight ok" << endl;
	result = Buffer.Pack(&(this->Address), 40);
	if (result == -1)return FALSE;
	cout << "anything is okay" << endl;

	return TRUE;
}


void Student::Print(ostream& stream, char* label) const
{
	//수정 필요
	if (label == 0) stream << "Student:";
	else stream << label;
	stream << "\n\t SID '" << SID << "'\n";
	stream << "\n\t SNAME '" << sname << "'\n";
	stream << "\n\t age '" << age << "'\n";
	stream << "\n\t weight '" << weight << "'\n";
	stream << "\n\t address '" << Address << "'\n";

}

istream& operator>>(istream& stream, Student& s) //입력 받아올때 string -> int 
{
	char temp[30];
	cout << "Enter SID : " << flush;
	stream.getline(s.SID, 30);
	cout << "Enter student name : " << flush;
	stream.getline(s.sname, 30);
	cout << "Enter age : " << flush;
	stream.getline(temp, 30);
	s.age = atoi(temp);
	cout << "Enter weight : " << flush;
	stream.getline(temp, 30);
	s.weight = atof(temp);
	cout << "Enter address : " << flush;
	stream.getline(s.Address, 30);
	
	return stream;
}
ostream& operator<<(ostream& stream, Student& s)
{
	char temp[30];
	snprintf(temp, 3, "%d", s.age);
	char temp2[30];
	snprintf(temp2, 5, "%f", s.weight);
	stream << "Student ID : " << s.SID << endl;
	stream << "Student name : " << s.sname << endl;
	stream << "Student age : " << temp << endl;
	stream << "Student weight : " << temp2 << endl;
	stream << "Student Address : " << s.Address << endl;

	return stream; 
}