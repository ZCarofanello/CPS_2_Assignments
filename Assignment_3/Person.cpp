//Person.cpp
#include "Person.h"

//Defines the getter and setter methods for the CPerson object
CPerson::CPerson(void)
	: m_age(0)
{
}

//Constructor for Person Object
CPerson::CPerson(string name, int age)
	:m_name(name),
	m_age(age)
{
}

//Deconstructor to "delete" the object
CPerson::~CPerson(void)
{
}

//Returns Age of Selected Person
double CPerson::getAge(void)
{
	return m_age;
}

//Sets age of selected person
void CPerson::setAge(double age)
{
	m_age = age;
}

//Returns Name of Person
string& CPerson::Name(void)
{
	return m_name;
}

//Outputs the pertinent fields of the CPerson in string format
string CPerson::ToString(void)
{
	stringstream result;
	result << "Name: " << left << setw(17) << m_name;
	result << "Age: " << m_age;
	return result.str();
}

//Reads and creates a CPerson object created by Save() in the expected syntax
//The device parameter is infile which tells it where to load from
void CPerson::Load(ifstream& device)
{
	if (!device.eof())
	{
		getline(device,m_name);	
	}
	if (!device.eof())
	{
		string age;
		getline(device,age);
		m_age = stoi(age);
	}
}

//Exports the CPerson
void CPerson::Save(ofstream& device)
{
	device << m_name << endl;
	device << m_age << endl;
}
