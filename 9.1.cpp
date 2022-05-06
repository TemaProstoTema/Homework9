#include <iostream>
class Property
{
public:
    Property(double a) { worth = a; }
    virtual double tax() { return 0; }
    virtual ~Property() {}
protected:
    double worth;
};

class Apartment : public Property{
public:
    double tax() { return worth / 1000; }
    Apartment(double a) : Property(a){ };
private:
};
class Car :public Property {
public:
    double tax() { return worth / 200; }
    Car(double a) : Property(a) { };
private:
};
class CountryHouse :public Property {
public:
    double tax() { return worth / 500; }
    CountryHouse(double a) : Property(a) { };
private:
};


int main()
{
    Property* Tax[7];

    Tax[0] = new Apartment(1000);
    Tax[1] = new Apartment(2000);
    Tax[2] = new Apartment(3000);
    Tax[3] = new Car(200);
    Tax[4] = new Car(400);
    Tax[5] = new CountryHouse(500);
    Tax[6] = new CountryHouse(1000);
    for (int i = 0; i < 7; i++) {
        std::cout << Tax[i]->tax() << std::endl;
    }
    for (int i = 0; i < 7; i++) {
        delete Tax[i];
    }
}







