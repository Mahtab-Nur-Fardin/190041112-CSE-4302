
#include<iostream>
#include<string>
using namespace std;

class Medicine
{
private:
    string name;
    string genericName;
    double discountPercent;
    double unitPrice;
public:
    Medicine() : discountPercent(5), unitPrice(0)
    {

    }
    void assignName(string a_name, string genName)
    {
        name = a_name;
        genericName = genName;
    }
    void assignPrice(double price)
    {
        if(price > 0)
        {
            unitPrice = price;
        }
    }
    void setDiscountPrice(double percent)
    {
        if (percent > 0 && percent <= 45)
        {
            discountPercent = percent;
        }
    }
    double getSellingPrice(int nos)
    {
        return ( (nos*unitPrice) - (discountPercent/100) );
    }
    void display()
    {
        cout << genericName << "(" << name << ") has a unit price BDT" << unitPrice << ". Current discount "<< discountPercent <<endl;
    }
};

int main()
{
    Medicine m1;
    m1.assignName("Paracetamol" , "Napa");

    m1.assignPrice(0.80);
    m1.setDiscountPrice(10);
    m1.display();
    double res;
    res = m1.getSellingPrice(1);
    cout << "res: " << res << endl;
}
