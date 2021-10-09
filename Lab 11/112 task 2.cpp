///lab 11
#include <fstream> //for file-stream functions
#include <iostream>
#include <typeinfo> //for typeid()
#include <process.h> //for exit()

using namespace std;

const int LEN = 32; //maximum length of last names
const int MAXEM = 100; //maximum number of Furnitures

enum furniture_type {bed, sofa};

////////////////////////////////////////////////////////////////

class Furniture //Furniture class
{
private:
    char name[LEN];
    float price;
    unsigned long number;
    static int n;
    static Furniture* arrap[]; //array of ptrs to emps
public:
    virtual void getdata()
    {
        cin.ignore(10, '\n');
        cout << "Enter last name: ";
        cin >> name;
        cout << " Enter number: ";
        cin >> number;
        cout << " Enter price: ";
        cin >> price;

    }
    virtual void putdata()
    {
        cout << "\n Name: " << name;
        cout << "\n Number: " << number;
        cout << "\n price: " << price;
    }
    virtual furniture_type get_type(); //get type
    static void add(); //add an Furniture
    static void display(); //display all Furnitures
    static void read(); //read from disk file
    static void write(); //write to disk file
};

//--------------------------------------------------------------

//static variables
int Furniture::n; //current number of Furnitures

Furniture* Furniture::arrap[MAXEM]; //array of ptrs to emps

////////////////////////////////////////////////////////////////

class Bed : public Furniture
{
private:
    char bedsize[LEN]; //"vice-president" etc.
public:
    void getdata()
    {
        Furniture::getdata();
        cout << " Enter bedsize: ";
        cin >> bedsize;
        }
    void putdata()
    {
        Furniture::putdata();
        cout << "\n bedsize: " << bedsize;
    }
};

////////////////////////////////////////////////////////////////

class Sofa : public Furniture
{
private:
    string sofasize; //number of publications
public:
    void getdata()
    {
        Furniture::getdata();
        cout << " Enter size: ";
        cin >> sofasize;
    }
    void putdata()
    {
        Furniture::putdata();
        cout << "\n sofa size: " << sofasize;
    }
};

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////

//add Furniture to list in memory
void Furniture::add()
{
    char ch;
    cout << "'b' to add a bed"
            "\n's' to add a sofa"
            "\nEnter selection: ";
    cin >> ch;
    switch(ch)
    { //create specified Furniture type
        case 'm':
            arrap[n] = new Bed;
            break;
        case 's':
            arrap[n] = new Sofa;
            break;
        default: cout << "\nUnknown Furniture type\n"; return;
    }
    arrap[n++]->getdata(); //get Furniture data from user
}

//--------------------------------------------------------------

//display all Furnitures
void Furniture::display()
{
    for(int j=0; j<n; j++)
    {
        cout << (j+1); //display number
        switch( arrap[j]->get_type() ) //display type
        {
            case bed:
                cout << ". Type: Bed";
                break;
            case sofa:
                cout << ". Type: sofa";
                break;
            default: cout << ". Unknown type";
        }
        arrap[j]->putdata(); //display Furniture data
        cout << endl;
    }
}
//--------------------------------------------------------------
//return the type of this object
furniture_type Furniture::get_type()
{
    if( typeid(*this) == typeid(Bed) )
        return bed;
    else if( typeid(*this)==typeid(Bed) )
        return sofa;
    else
        { cerr << "\nBad Furniture type"; exit(1); }
    return bed;
}
//--------------------------------------------------------------
//write all current memory objects to file
void Furniture::write()
{
    int size;
    cout << "Writing " << n << " furnitures.\n";
    ofstream ouf; //open ofstream in binary
    furniture_type ftype; //type of each Furniture object
    ouf.open("furnitures.DAT", ios::trunc | ios::binary);
    if(!ouf)
    { cout << "\nCan't open file\n"; return; }
    for(int j=0; j<n; j++) //for every Furniture object
    { //get its type
        ftype = arrap[j]->get_type();
        //write type to file
        ouf.write( (char*)&ftype, sizeof(ftype) );
        switch(ftype) //find its size
        {
            case bed: size=sizeof(Bed); break;
            case sofa: size=sizeof(Sofa); break;
        } //write Furniture object to file
        ouf.write( (char*)(arrap[j]), size );
        if(!ouf)
            { cout << "\nCan't write to file\n"; return; }
    }
}
//--------------------------------------------------------------
//read data for all Furnitures from file into memory
void Furniture::read()
{
    int size; //size of Furniture object
    furniture_type ftype; //type of Furniture
    ifstream inf; //open ifstream in binary
    inf.open("furnitures.DAT", ios::binary);
    if(!inf)
        { cout << "\nCan't open file\n"; return; }
    n = 0; //no Furnitures in memory yet
    while(true)
    { //read type of next Furniture
        inf.read( (char*)&ftype, sizeof(ftype) );
        if( inf.eof() ) //quit loop on eof
            break;
        if(!inf) //error reading type
            { cout << "\nCan't read type from file\n"; return; }
        switch(ftype)
        { //make new Furniture
            case bed: //of correct type
                arrap[n] = new Bed;
                size=sizeof(Bed);
                break;
            case sofa:
                arrap[n] = new Sofa;
                size=sizeof(Sofa);
                break;
            default: cout << "\nUnknown type in file\n"; return;
        }    //read data from file into it
        inf.read( (char*)arrap[n], size );

        if(!inf) //error but not eof
                { cout << "\nCan't read data from file\n"; return; }
        n++; //count Furniture
    } //end while
    cout << "Reading " << n << " furnitures\n";
}
////////////////////////////////////////////////////////////////

int main()
{
    char ch;
    while(true)
    {
        cout << "'a' -- add data for a furnitures"
                "\n'd' -- display data for all furnitures"
                "\n'w' -- write all furnitures data to file"
                "\n'r' -- read all furnitures data from file"
                "\n'x' -- exit"
                "\nEnter selection: ";
        cin >> ch;
        switch(ch)
        {
            case 'a': //add an Furniture to list
                Furniture::add(); break;
            case 'd': //display all Furnitures
                Furniture::display(); break;
            case 'w': //write Furnitures to file
                Furniture::write(); break;
            case 'r': //read all Furnitures from file
                Furniture::read(); break;
            case 'x': exit(0); //exit program
            default: cout << "\nUnknown command";
        } //end switch
    } //end while
return 0;
} //end main()
