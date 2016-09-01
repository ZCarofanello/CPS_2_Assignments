//Person.h
#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
using namespace std;

class CPerson
{
private:
	double m_age;
	string m_name;
public:
	CPerson(void);
	CPerson(string name, int age);
	~CPerson(void);
	double getAge(void);
	void setAge(double age);
	string& Name(void);
	string ToString(void);
	void Load(ifstream& device);
	void Save(ofstream& device);
};

