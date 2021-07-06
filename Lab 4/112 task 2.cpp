
#include<iostream>
#include<string>

using namespace std;

class Employee
{
private:
    string EmpName;
    int ID;
    int Age;
    float Salary;
    string status;

    string getStatus()
    {
      if (Salary > 20000 && Age <= 25){
        status = "Moderate";
      }
      if (Salary <= 20000 && Age <= 25){
        status = "Low";
      }
      if (Salary <= 21000 && Age >25){
        status = "Low";
      }
      if (Salary > 21000 && Salary <= 60000 && Age >25){
        status = "Moderate";
      }
      if (Salary >60000 && Age >25){
        status = "High";
      }
      return status;
    }
public:
    void FeedInfo()
    {
        cout << "Enter name: ";
        cin >> EmpName;
        cout << "Enter Id: ";
        cin >> ID;
        cout << "Enter Salary: ";
        cin >> Salary;
        cout << "Enter age: ";
        cin >> Age;
    }
    void ShowInfo()
    {
        cout << "Employee name: " << EmpName << endl;
        cout << "Employee Id: " << ID << endl;
        cout << "Employee Salary: " << Salary << endl;
        cout << "Employee Salary: " << Age << endl;
        cout << "Employee Status: " << getStatus() << endl;
    }

};

int main()
{
    Employee e1;
    e1.FeedInfo();
    e1.ShowInfo();
}
