#include<iostream>

using namespace std;

class alpha
{
private:
    int data1;
    int data2;
public:
    alpha(): data1(0), data2(0)
    {

    }
    alpha(int d1, int d2) : data1(d1), data2(d2)
    {

    }
private:

    alpha operator = (alpha&    a)
    {
        data1 = a.data1;
        cout << "Assignment operator invoked" << endl;
        return *this;
    }
    alpha(alpha& a )
    {
        data1 = a.data1;
        cout << "Copy constructor" << endl;
     }
public:
    void display()
    {
         cout << data1 <<  " "<< data2 << endl;
    }
};

class dalpha
{
private:
    int ddata1;
    int ddata2;
public:
    dalpha(): ddata1(0), ddata2(0)
    {

    }
    dalpha(int d1, int d2) : ddata1(d1), ddata2(d2)
    {

    }

    void display()
    {
         cout << ddata1 << " " << ddata2 << endl;
    }
};

int main()
{
    alpha a1(37, 50);
    a1.display();
    alpha a2 = a1; //copy constructor
    cout << "a2 = ";
    a2.display();
    alpha a3 ;
    a3 = a1; // assigment operator
    cout << "a3 = ";
    a3.display();
    cout << "\n";

    dalpha da1(37, 50);
    cout << "da1 = ";
    da1.display();
    dalpha da2 = da1;
    cout << "da2 = ";
    da2.display();

}
