#include<iostream>
#include<string>
using namespace std;

class Shape
{
public:
     virtual    void Draw()
     {
         cout << "SHAPE" << endl;
     }
};

class Circle : public Shape
{
public:
    void Draw()
    {   cout << "\t\t CIRCLE \t\t" << endl;    }
};

class Rectangle : public Shape
{
public:
    void Draw()
    {   cout << "\t\t RECTANGLE \t\t" << endl;   }
};

class Triangle : public Shape
{
public:
    void Draw ()
    {   cout << "\t\tTRIANGLE\t\t" << endl;  }
};

class Person
{
protected:
    string name;
public:
    void getName()
    {
        cout << "Enter name: ";
        cin >> name;
    }
    void putName()
    {   cout << "Name: " << name << endl;   }
    virtual void getData() = 0;
    virtual void putData() = 0;
};

class Student : public Person
{
private:
    int sid;
    float cgpa;
public:
    void getData()
    {
        Person::getName();
        cout << "Enter you student id: ";
        cin >> sid;
        cout << "Enter cgpa: ";
        cin >> cgpa;
    }
    void putData()
    {
        Person::putName();
        cout << "ID: " << sid << endl;
        cout << "Cgpa : " << cgpa << endl;
    }
};

class Teacher : public Person
{
private:
    int id;
    float salary;
public:
    void getData()
    {
        Person::getName();
        cout << "Enter your id: ";
        cin >> id;
        cout << "Enter salary: ";
        cin >> salary;
    }
    void putData()
    {
        Person::putName();
        cout << "ID: " << id << endl;
        cout << "Salary : " << salary << endl;
    }
};

int main()
{
    Shape* sptr;
    Circle cobj;

    sptr = &cobj;
    sptr->Draw();

    Person* pptr1;
    Person* pptr2;
    Student s1;
    pptr1 = &s1;
    pptr1->getData();
    pptr1->putData();


}
