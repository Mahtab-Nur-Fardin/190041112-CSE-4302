/// lab 13
#include<iostream>
using namespace std;

namespace my_namespace
{
     double pi = 3.14;
     double circumCircle(int r)
     {
         return 2 * pi * r;
     }
}

int main()
{
    double c;
    c = my_namespace::circumCircle(5);
    cout << c << endl;

    double c2;
    double pi = 6.28;
    cout << pi << endl;
}

