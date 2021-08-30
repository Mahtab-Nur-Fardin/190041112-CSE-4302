#include<iostream>
#include<string>
using namespace std;

class Animal
{
private:
    string nameofAnimal;
    string habitat_area;
    string sound;
    int weight;
    int height;
    int birthyear;
public:
    Animal():sound("sound"), birthyear(2021)
    {    }
    Animal(string s, int y):sound(s), birthyear(y)
    {    }
    void setName(string name)
    {   nameofAnimal = name;    }
    void setHabitat(string habitat)
    {   habitat_area = habitat;     }
    void setSound()
    {   sound = "sound";     }
    void setWeight(int w)
    {   weight=w ;     }
    void setHeight(int h)
    {   height = h;     }
    string getName()
    {   return nameofAnimal;    }
    string getHabitat()
    {   return habitat_area;     }
    string getSound()
    {   return sound;     }

    int getWeight()
    {   return  weight;     }
    int getHeight()
    {   return  height;     }
    void setBirthYear(int y)
    {
        if (y <2022){
            birthyear = y;
        }
        else{
            cout << "Birthyear can not be greater than 2021!" << endl;
        }
    }
    int getBirthYear()
    {   return  birthyear;     }

    int getAge()
    {   return  2021 - birthyear;     }

    void getInformation()
    {
        cout << "Name: " << nameofAnimal << "\n";
        cout << "Habitat area: " << habitat_area << "\n";
        cout << "Weight: " << weight << "\n";
        cout << "Height: " << height << "\n";
        cout << "Birth year: " << birthyear << "\n";
        cout << "Age: " << getAge() << "\n";
        cout << "Sound: " << sound << "\n";
    }
    void changeWeight(int pounds)
    {
        weight = pounds;
    }
    void Vocalize()
    {
        cout << getSound() << " ";
    }

};

class Cow : public Animal
{
public:
    Cow() : Animal("moo",2021)
    {   }
};

class Cat : public Animal
{
public:
    Cat() : Animal("meow",2021)
    {   }

};

class Chicken : public Animal
{
public:
    Chicken() : Animal("buck buck",2021)
    {   }
};
int main()
{
    Cow cow1;
    cow1.setName("Manik");
    cow1.setBirthYear(2010);
    cow1.setHabitat("Bangladesh");
    cow1.setWeight(200);
    cow1.setHeight(100);

    cow1.Vocalize();

    cow1.getInformation();

    return 0;
}
