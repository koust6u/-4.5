#ifndef COURSEREGISTRATION
#define COURSEREGISTRATION
#include <iostream>
#include <vector>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

class course {
public:
	char* courseName;
	int id;
	char* strId;
	int length;
	int credit;
	char* strCredit;
	char* grade;
	float Fgrade;
	course();
	course(const course& c);
	~course();
	course& operator =(const course& c);
};
course::course() {
	courseName = new char[20];
	id = 0;
	strId = new char[10];
	strCredit = new char[5];
	length = 0;
	credit = 0;
	grade = new char[5];
	Fgrade = 0.0;
}
course::course(const course& c) {
	courseName = new char[strlen(c.courseName) + 1];
	strcpy(courseName, c.courseName);
	length = c.length;
	credit = c.credit;
	strId = new char[strlen(c.strId) + 1];
	strcpy(strId, c.strId);
	strCredit = new char[strlen(c.strCredit) + 1];
	strcpy(strCredit, c.strCredit);
	grade = new char[strlen(c.grade) + 1];
	strcpy(grade, c.grade);
	id = c.id;
	Fgrade = c.Fgrade;
	//cout << endl << "copy constructor of Course class is called" << endl;

}
course::~course() {
	if (courseName != 0) delete courseName;
	length = 0;
	credit = 0;
	delete strId;
	delete strCredit;
	id = 0;
	delete grade;
}
course& course::operator =(const course& c) {
	if (strlen(c.courseName) >= length) {
		delete courseName;
		courseName = new char[strlen(c.courseName) + 1];
		strcpy(courseName, c.courseName);
		strcpy(strCredit, c.strCredit);
		length = strlen(courseName);
		strcpy(grade, c.grade);
		strcpy(strId, c.strId);
		id = c.id;
		Fgrade = c.Fgrade;
	}
	cout << "assignment::operator=() is called" << "::Course" << courseName << endl;
	strcpy(courseName, c.courseName);
	strcpy(strCredit, c.strCredit);
	strcpy(grade, c.grade);
	strcpy(strId, c.strId);
	return *this;
}

class courseRegistration {
public:
	vector<course> courses;
	int studentId;
	//멤버
	courseRegistration();
	void addCourse(course& c);
	void deleteCourse(int id);
	int totalCredit();
};
//
courseRegistration::courseRegistration() {
	courses.clear();
	studentId = 0;
}
void courseRegistration::addCourse(course& c) {
	for (auto iter = courses.begin(); iter != courses.end(); iter++) { //중복 과목 이수 예외처리
		if ((*iter).id == c.id)return;
	}
	courses.push_back(c);
}
void courseRegistration::deleteCourse(int id) {
	for (auto iter = courses.begin(); iter != courses.end(); iter++) {
		if ((*iter).id == id) {
			courses.erase(iter);
		}
	}
}
int courseRegistration::totalCredit() {
	int temp = 0;
	for (auto iter = courses.begin(); iter != courses.end(); iter++) {
		temp += (*iter).credit;
	}
	return temp;

}

#endif