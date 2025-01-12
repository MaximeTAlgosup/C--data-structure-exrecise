#include <iostream>
#include <string>

using namespace std;

class Fruits
{
private:
    int ID;
    string Name;
    int Quantity;
    float Price;
    string Origin;
public:
    Fruits(int ID, string name, int quantity, float price, string origin);
    ~Fruits();
    void Display();

    int GetID();
    string GetName();
    int GetQuantity();
    float GetPrice();
    string GetOrigin();

    void SetID(int identifier);
    void SetName(string Name);
    void SetQuantity(int quantity);
    void SetPrice(float price);
    void SetOrigin(string origin);
};

Fruits::Fruits(int identifier, string name, int quantity, float price, string origin)
{
    ID = identifier;
    Name = name;
    Quantity = quantity;
    Price = price;
    Origin = origin;
}

Fruits::~Fruits()
{
}

void Fruits::Display()
{
    cout << "ID: " << ID << " Name: " << Name << " Quantity: " << Quantity << " Price: " << Price << " Origin: " << Origin << endl;
}

int Fruits::GetID()
{
    return ID;
}

string Fruits::GetName()
{
    return Name;
}

int Fruits::GetQuantity()
{
    return Quantity;
}

float Fruits::GetPrice()
{
    return Price;
}

string Fruits::GetOrigin()
{
    return Origin;
}

void Fruits::SetID(int identifier)
{
    ID = identifier;
}

void Fruits::SetName(string name)
{
    Name = name;
}

void Fruits::SetQuantity(int quantity)
{
    Quantity = quantity;
}

void Fruits::SetPrice(float price)
{
    Price = price;
}

void Fruits::SetOrigin(string origin)
{
    Origin = origin;
}