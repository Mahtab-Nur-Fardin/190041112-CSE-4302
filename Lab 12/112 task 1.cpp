///lab 12
#include<iostream>
#include<process.h> // for exit 1
using namespace std;
const int MAX = 5;

template <class T>
class My_Stack
{
protected:
    T st[MAX];
    int top;
public:
    class Empty
    {   };
    class Full
    {   };
    Stack()
    {   top = -1;   }
    void push(T var)
    {   if (top >= MAX -1)
            throw Full();

        st[++top] = var;
    }
    T pop()
    {
        if (top<0)
            throw Empty();
        return st[--top];
    }
    T peek()
    {
        if (top < 0)
            throw Empty();
        return st[0];
    }
};

int main()
{
    try
    {

        My_Stack<int> s1;
        s1.push(10);
        s1.push(20);
        s1.push(30);
        //s1.push(40);
        cout << "1:" << s1.pop() <<  endl;
        cout << "2:" << s1.pop() <<  endl;
        cout << "3:" << s1.pop() <<  endl;
        cout << "4:" << s1.pop() <<  endl;
    }
    catch(My_Stack<int>::Empty)
    {
        cout << "Exception : Stack empty " << endl;
    }
    catch (My_Stack<int>::Full)
    {
        cout << "Exception: Stack full " << endl;
    }
    cout << "Arrived here after catch or (normal exit)" << endl;
}
