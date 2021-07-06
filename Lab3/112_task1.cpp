
#include<iostream>

using namespace std;

class RationalNumber
{
private:
    int numerator;
    int denominator;
public:
    void Assign(int num, int denom)
    {
        if(denom == 0 )
        {
            cout << "ERROR! Mathemitacally undefined." << endl;
            return;
        }
        numerator = num ;
        denominator = denom;
    }
    double convert()
    {
        double d_num;
        double d_den;

        d_num = (double)numerator;
        d_den = (double)denominator;
        return (d_num/d_den);
    }
    void invert()
    {
        int In_Num = denominator;
        int In_Denom = numerator;

        if(In_Denom == 0 )
        {
            cout << "ERROR! Mathemitacally undefined." << endl;
            return;
        }
        cout << "The Inverted Rational Number is " << In_Num << "/" << In_Denom << endl;
    }
    void print()
    {
        cout << "The Rational Number is " << numerator << "/" << denominator << endl;
    }

};

int main()
{
    RationalNumber r1;
    r1.Assign(3,2);
    r1.print();
    r1.invert();
    double fr;
    fr = r1.convert();
    cout << "The fraction: " << fr << endl;
}
