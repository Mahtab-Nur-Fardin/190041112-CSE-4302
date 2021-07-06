#include<iostream>

using namespace std;

class StudentResult
{
private:
    static int passingMark;
    int subjectMark[6];
    bool fail;

public:
    void displayMarks()
    {
        for(int i=0; i<6; i++)
        {
            cout <<  subjectMark[i] << " ";
        }
        cout << endl;
    }
    void setMarks()
    {
        fail = false;

        for(int i=0; i<6; i++)
        {
            cin>> subjectMark[i];
            if(subjectMark[i] < passingMark)
            {
                fail = true;
            }
        }
    }
    void checkPassing()
    {
        if(fail == true)
        {
            cout << "Sorry you have failed!" << endl;
        }
        else{
            cout << "Congrats you have passed!" << endl;
        }
    }


};
int StudentResult :: passingMark = 40;
int main()
{
    StudentResult s1;
    s1.setMarks();
    s1.displayMarks();
    s1.checkPassing();
}
