
#include<iostream>

using namespace std;

class RationalNumber
{
private:
    int numerator;
    int denominator;
public:
    RationalNumber() : numerator(0), denominator(0)
    {
    }
    RationalNumber(int n, int d): numerator(n)
    {
        if(d == 0)
        {
            ErrorF();
        }
        else
        {
            denominator = d;
        }
    }
    void setDenominator(int denom)
    {
        if(denom == 0 )
        {
            ErrorF();
            return;
        }
        else
        {
            denominator = denom;
        }

    }
    void setNumerator(int num)
    {
        numerator = num;

    }
    int getNumerator()
    {
        return numerator;
    }
    int getDenominator()
    {
        return denominator;
    }


    double convert()
    {
        double d_num;
        double d_den;

        d_num = (double)numerator;
        d_den = (double)denominator;
        return (d_num/d_den);
    }

    RationalNumber operator + (RationalNumber r)
    {
        double an = (numerator*r.denominator) + (r.numerator*denominator);
        double ad = (numerator*denominator);
        return RationalNumber(an,ad);
    }
    RationalNumber operator - (RationalNumber r)
    {
        double sn = (numerator*r.denominator) - (r.numerator*denominator);
        double sd = (numerator*denominator);
        return RationalNumber(sn,sd);
    }
    RationalNumber operator * (RationalNumber r)
    {
        double mn = (numerator*r.numerator);
        double md = denominator*r.denominator;
        return RationalNumber(mn,md);
    }
    RationalNumber operator / (RationalNumber r)
    {
        double dn = (numerator*r.denominator);
        double dd = denominator*r.numerator;
        return RationalNumber(dn,dd);
    }

    void ErrorF()
    {
        cout << "ERROR! Mathemitacally undefined." << endl;
        numerator = 0;
        denominator = 0;

    }
    void print()
    {
        cout << "The Rational Number is " << numerator << "/" << denominator << endl;
    }

};

int main()
{
    RationalNumber r1(5,2);
    RationalNumber r2;
    r2.setNumerator(5);
    r2.setDenominator(2);
    r1.print();
    double fr;
    fr = r1.convert();
    cout << "The fraction: " << fr << endl;
    cout << "The Rational Number r2 is " << r2.getNumerator() << "/" << r2.getDenominator() << endl;
    RationalNumber r3, r4,r5,r6;
    r3 = r1 + r2;
    r3.print();
    cout << "r3 converted: " << r3.convert() << endl;
    r4 = r1 - r2;
    r4.print();
    r5 = r1 * r2;
    r5.print();
    r6 = r1 / r2;
    r6.print();

}

