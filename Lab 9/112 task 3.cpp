#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
    string product_name;
public:

    Furniture(double p,double d,Material m, string n):price(0),discount(0),madeof(Material::Wood), product_name(n)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setName(string n)
    {
        product_name = n;
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }

    virtual void productDetails()=0;
};



enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{
private:
    BedSize bed_size;
public:

    Bed(double p,double d,Material m,BedSize bs, string n):Furniture(p,d,m,n)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        setName(n);
        setBedSize(bs);
    }
    void setBedSize(BedSize val)
    {
        bed_size=val;
    }
    string getBedSize()
    {
        if(bed_size==BedSize::Single)
            return string("Single");
        else if(bed_size==BedSize::SemiDouble)
            return string("Semi Double");
        else if(bed_size==BedSize::Double)
            return string("Double");
        else
            return string("");
    }

    void productDetails()
    {
        for(int i=0; i<20 ; i++)    cout << "-";
        cout << "\nRegular price: " << price << endl;
        cout << "Discounted price: " << discount << endl;
        cout << "Material: " << getMadeof() << endl;
        cout << "Bed Size: " << getBedSize() << endl;
        cout << "Product name: " << product_name << endl;
        for(int i=0; i<20 ; i++)    cout << "#";
    }

};
enum class SofaSize {One,Two,Three, Four, Five};
class Sofa:public Furniture
{
private:
    SofaSize    sofa_size;
public:

    Sofa(double p,double d,Material m, SofaSize ss, string n):Furniture(p,d,m,n)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        setName(n);
        setSofaSize(ss);
    }
    void setSofaSize(SofaSize val)
    {
        sofa_size=val;
    }
    string getSofaSize()
    {
        if(sofa_size==SofaSize::One)
            return string("One");
        else if(sofa_size==SofaSize::Two)
            return string("Two");
        else if(sofa_size==SofaSize::Three)
            return string("Three");
        else if(sofa_size==SofaSize::Four)
            return string("Four");
        else if(sofa_size==SofaSize::Five)
            return string("Five");
        else
            return string("");
    }
    void productDetails()
    {
        for(int i=0; i<20 ; i++)    cout << "-";
        cout << "\nRegular price: " << price << endl;
        cout << "Discounted price: " << discount << endl;
        cout << "Material: " << getMadeof() << endl;
        cout << "Sofa Size: " << getSofaSize() << endl;
        cout << "Product name: " << product_name << endl;
        for(int i=0; i<20 ; i++)    cout << "#";
    }
//    Furniture *f;
//    void a()
//    {
//        f = new Sofa();
//    }
//
//    ~Sofa
//    {
//        delete f;
//    }
};

enum class ChairCount {Two,Four, Six};

class DiningTable:public Furniture
{
private:
    ChairCount chair_no;
public:
    DiningTable(double p,double d,Material m, ChairCount cc, string n):Furniture(p,d,m,n)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        setName(n);
        setChairCount(cc);
    }
    void setChairCount(ChairCount val)
    {
        chair_no=val;
    }
    string getChairCount()
    {
        if(chair_no==ChairCount::Two)
            return string("Two");
        else if(chair_no==ChairCount::Four)
            return string("Four");
        else if(chair_no==ChairCount::Six)
            return string("Six");
        else
            return string("");
    }
    void productDetails()
    {
        for(int i=0; i<20 ; i++)    cout << "-";
        cout << "\nRegular price: " << price << endl;
        cout << "Discounted price: " << discount << endl;
        cout << "Material: " << getMadeof() << endl;
        cout << "Chair count: " << getChairCount() << endl;
        cout << "Product name: " << product_name << endl;
        for(int i=0; i<20 ; i++)    cout << "#";
    }
};

int main()
{
    Furniture* f_list[100];
    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single, "BD101");
    f_list[1] = new Sofa(11000,234,Material::Steel,SofaSize::Five, "S112");
    f_list[2] = new DiningTable(13000,345,Material::Wood,ChairCount::Four, "DT008");
    f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single, "BD978");

    f_list[0]->productDetails();
     /**
        task 3 (Modify productDetails)
    */

    f_list[2]->setDiscount(30);
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }

}

