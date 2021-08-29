#include<iostream>

using namespace std;

class Counter
{
private:
    int _count;
    int step;
public:
    Counter():_count(0), step(1)
    {   }
    Counter(int c, int s): _count(c), step(s)
    {
    }
    Counter(int c1): _count(c1)
    {
    }
    void setIncrementStep(int step_val)
    {
        if(step_val >= 0){
            step = step_val;
        }
        else    cout << "Cant't assign negative value!" << endl;
    }
    int getCount()
    {   return _count;  }

    void increment()
    {
        _count += step;
    }
    void resetCount()
    {
        _count = 0;
    }

    Counter operator ++ ()
    {
        return Counter(++_count);
    }
    Counter operator ++ (int)
    {
        return Counter(_count++);
    }

    Counter operator + (Counter c)
    {
        int ac = _count + c._count;
        int as = min(step, c.step);
        return Counter(ac, as);
    }

    Counter operator + (int var)
    {
        int av = _count + var;
        return Counter(av, step);
    }

    friend Counter operator + (int var, Counter c);

    Counter operator += (Counter c)
    {
        _count += c._count;
    }
};

Counter operator + (int var, Counter c)
{
        int va =  var + c._count;
        return Counter(va, c.step);
}

int main()
{
    Counter c1, c2, c3;
    c2.setIncrementStep(4);
    c2.increment();
    c3.setIncrementStep(2);
    c3.increment();
    cout << c1.getCount() << endl;
    c1 = ++c2;
    cout << c1.getCount() << endl;
    c1 = c2 + c3;
    cout << c1.getCount() << endl;
    int varr = 10;
    c1 = c2 + varr;
    cout << c1.getCount() << endl;
    c1 += c2;
    cout << c1.getCount() << endl;
    c1 =  varr + c2;
    cout << c1.getCount() << endl;

}
