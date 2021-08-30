#include<iostream>

using namespace std;


class Seat
{
private:
    string  comfortability;
    string  presence_of_seat_warmer;
public:
    void setSeatInfo()
    {
        cout << "Comfortability of seats?: ";
        cin >> comfortability;
        cout << "Presence of seats warmer?: ";
        cin >> presence_of_seat_warmer;
    }
    void getSeatInfo()
    {
        cout << "Comfortability of seats: " <<  comfortability << "\n";
        cout << "Presence of seats warmer?: " << presence_of_seat_warmer << "\n";
    }
};
class Wheel
{
private:
    float   radius;
public:
    void setWheelInfo()
    {
        cout << "Radius of wheel: ";
        cin >> radius;
    }
    void getWheelInfo()
    {
        cout << "Circumference of wheel: " <<  radius*2*3.1416 << endl;
    }
};
class Engine
{
private:
    float   max_fuel_consumption_rate;
    float   max_energy_production_rate;
    float   averageRPM;
public:
    void setEngineInfo()
    {
        cout << "Maximum fuel consumption rate of engine: ";
        cin >> max_fuel_consumption_rate;
        cout << "Maximum energy production rate: ";
        cin >> max_energy_production_rate;
        cout << "Average RPM: ";
        cin >> averageRPM;
    }
    void getEngineInfo()
    {
        cout << "Maximum fuel consumption rate of engine: " <<  max_fuel_consumption_rate << "\n";
        cout << "Maximum energy production rate: " << max_energy_production_rate << "\n";
        cout << "Average RPM: " << averageRPM << "\n";

    }
};
class Door
{
private:
    string opening_mode;
public:
    void setDoorInfo()
    {
        cout<< "Door opening mode: ";
        cin>> opening_mode;
    }
    void getDoorInfo()
    {
        cout<< "Door opening mode: " << opening_mode << endl;
    }
};

class Car
{
private:
    Seat carSeat[4];
    Wheel carWheel[4];
    Engine carEngine;
    Door carDoor[4];
    float max_acceleration;
    float fuel_capacity;
public:
    void setCarInfo()
    {
        cout << "Car acceleration: ";
        cin >> max_acceleration;
        cout << "Fuel capacity: ";
        cin>> fuel_capacity;
        for(int i=0; i<4; i++)
        {
            carSeat[i].setSeatInfo();
            carWheel[i].setWheelInfo();
            carDoor[i].setDoorInfo();

        }
        carEngine.setEngineInfo();
    }
    void getCarInfo()
    {
        cout << "Car acceleration: " << max_acceleration << endl;
        cout << "Fuel capacity: " << fuel_capacity << endl;
        for(int i=0; i<4; i++)
        {
            carSeat[i].getSeatInfo();
            carWheel[i].getWheelInfo();
            carDoor[i].getDoorInfo();

        }
        carEngine.getEngineInfo();
    }

};
int main()
{
    Car c1;
    c1.setCarInfo();
    c1.getCarInfo();


}
