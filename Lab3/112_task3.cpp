
#include<iostream>
#include<string>
using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;
public:
    int hours()
    {
        return hour;
    }
    int minutes()
    {
        return minute;
    }
    int seconds()
    {
        return second;
    }
    void reset(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }
    void advance(int h, int  m,int s)
    {
        second = second+s;
        if(second > 60 )
        {
            minute = minute + (second/60);
            second = (second%60);
        }
        minute = minute+ m;
        if(minute > 60 )
        {
            hour = hour + (minute/60) ;
            minute = minute%60;
        }
        hour = hour + h;
        if(hour > 24)
        {
            hour = hour%24;
        }

    }
    void print()
    {
        int h =  hours();
        int m = minutes();
        int s = seconds();
        cout << h << ":" << m << ":"<<s<< endl ;
    }

};

int main()
{
    Time t1;
    t1.reset(11,20,45);
    t1.print();
    t1.advance(14,50,25);
    t1.print();
}
