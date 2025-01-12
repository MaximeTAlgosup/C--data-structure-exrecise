#include <iostream>
#include <cstdlib>
#include <vector>
#include "class.hpp"

using namespace std;

Fruits Apples(80, "apples", 2, 1.20, "France");
Fruits Bananas(3, "bananas", 10, 3.50, "Brazil");
Fruits Strawberries(60, "strawberries", 5, 4, "Portugal");

vector<Fruits> section;

void displayMenu(int* choice);
void clearTerminal();
Fruits addNewElement();
void wait();
void merge(vector<Fruits>* section, int lowerB, int middle, int upperB);
void mergeSort(vector<Fruits>* section, int lowerB, int upperB);
bool containsBS(int num, vector<Fruits>* section, int lowerB, int upperB);
int displaySection(int size, vector<Fruits> section);

int main()
{
    section.push_back(Apples);
    section.push_back(Bananas);
    section.push_back(Strawberries);
    int choice;
    int elementSelected = 0;
    int size = 3;
    int updateChoice;
    int newID;
    string newName;
    int newQuantity;
    float newPrice;
    string newOrigin;

    while (true)
    {
        clearTerminal();
        displayMenu(&choice);

        switch (choice)
        {
        case 0:
            clearTerminal();
            cout << "You have quit!" << endl;
            return 0;

        case 1:
            section.push_back(addNewElement());
            cout << "You have chosed 1!" << endl;
            size++;
            break;

        case 2:
            cout << "Select the element you want to look at: " << endl;
            cin >> elementSelected;
            section[elementSelected-1].Display();
            wait();
            break;

        case 3:
            cout << "You currently have " << size << " elements in your section." << endl;
            cout << "Which of those do you want to update?" << endl;
            cin >> elementSelected;
            cout << "Which part do you want to update?" << endl;
            cout << "1: ID." << endl;
            cout << "2: Name." << endl;
            cout << "3: Quantity." << endl;
            cout << "4: Price." << endl;
            cout << "5: Origin." << endl;
            cin >> updateChoice;
            switch (updateChoice)
            {
            case 1:
                cout << "Their current ID are " << section[elementSelected-1].GetID() << "!" << endl;
                cout << "What ID do you want them to have?" << endl;
                cin >> newID;
                section[elementSelected-1].SetID(newID);
                break;
            
            case 2:
                cout << "Their current name are " << section[elementSelected-1].GetName() << "!" << endl;
                cout << "What name do you want them to have?" << endl;
                cin >> newName;
                section[elementSelected-1].SetName(newName);
                break;

            case 3:
                cout << "There are " << section[elementSelected-1].GetQuantity() << " of them!" << endl;
                cout << "How many of them do you want to have?" << endl;
                cin >> newQuantity;
                section[elementSelected-1].SetQuantity(newQuantity);
                break;

            case 4:
                cout << "Their current price are " << section[elementSelected-1].GetPrice() << "!" << endl;
                cout << "Which Price do you want them to be?" << endl;
                cin >> newPrice;
                section[elementSelected-1].SetPrice(newPrice);
                break;

            case 5:
                cout << "Their current origin are " << section[elementSelected-1].GetOrigin() << "!" << endl;
                cout << "What origin do you want them to have?" << endl;
                cin >> newOrigin;
                section[elementSelected-1].SetOrigin(newOrigin);
                break;
            
            default:
                cout << "Not a possible value" << endl;
                break;
            }
            break;

        case 4:
            cout << "Which element do you want to remove from the section?" << endl;
            cin >> elementSelected;
            section.erase(section.begin() + (elementSelected - 1));
            size--;
            break;
        
        case 5:
            mergeSort(&section, 0, size-1);
            break;

        case 6:
            cout << "What element (ID) do you want to search?" << endl;
            cin >> elementSelected;
            if(containsBS(elementSelected, &section, 0, size-1))
            {
                cout << "This element is in your section!" << endl;
            }
            else
            {
                cout << "This element is not in your section!" << endl;
            }
            wait();
            break;

        case 7:
            displaySection(size, section);
            break;

        default:
            cout << "This choice isn't handle. Please, chose an option between 0 and 4." << endl;
            break;
        }
    }
}

void displayMenu(int* choice)
{
    cout << "What do you want to do in your section?" << endl;
    cout << "1: add a new element." << endl;
    cout << "2: retrieve an element." << endl;
    cout << "3: update an element." << endl;
    cout << "4: remove an element." << endl;
    cout << "5: sort elements." << endl;
    cout << "6: search for an element." << endl;
    cout << "7: see all elements." << endl;
    cout << "0: quit." << endl;
    cin >> *choice;
}

void clearTerminal()
{
    cout << "\033[2J\033[1;1H";
}

Fruits addNewElement()
{
    int ID;
    string Name;
    int Quantity;
    float Price;
    string Origin;

    cout << "What is the ID of your product?" << endl;
    cin >> ID;
    cout << "What is the name of your product?" << endl;
    cin >> Name;
    cout << "How many of them do you have?" << endl;
    cin >> Quantity;
    cout << "How much do they cost?" << endl;
    cin >> Price;
    cout << "Where do they come from?" << endl;
    cin >> Origin;

    return Fruits(ID, Name, Quantity, Price, Origin);
}

void wait()
{
    string wait;
    cin >> wait;
}

void merge(vector<Fruits>* section, int lowerB, int middle, int upperB)
{
    int sizeLeft = middle - lowerB + 1;
    int sizeRight = upperB - middle;

    vector<Fruits> leftVector;
    vector<Fruits> rightVector;

    for (int i = 0; i < sizeLeft; i++)
    {
        leftVector.push_back((*section)[lowerB + i]);
    }

    for (int i = 0; i < sizeRight; i++)
    {
        rightVector.push_back((*section)[middle + 1 + i]);
    }
    
    int i, j, k;
    i = 0; //left array index
    j = 0; //right array index
    k = lowerB; //main array index

    while ((i < sizeLeft) && (j < sizeRight))
    {
        int a = leftVector.at(i).GetID();
        int b = rightVector.at(j).GetID();
        if (a <= b)
        {
            (*section)[k] = leftVector[i];
            i++;
        }
        else
        {
            (*section)[k] = rightVector[j];
            j++;
        }
        k++;
    }
    
    while(i < sizeLeft)
    {
        (*section)[k] = leftVector[i];
        i++;
        k++;
    }

    while(j < sizeRight)
    {
        (*section)[k] = rightVector[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Fruits>* section, int lowerB, int upperB)
{
    if (lowerB >= upperB)
    {
        return;
    }
    
    int middle = lowerB + (upperB - lowerB) / 2;
    mergeSort(section, lowerB, middle);
    mergeSort(section, middle + 1, upperB);
    merge(section, lowerB, middle, upperB);
}

bool containsBS(int num, vector<Fruits>* section, int lowerB, int upperB)
{
    if (upperB >= lowerB)
    {
        int middleElementIndex = lowerB + (upperB - lowerB)/2;
        int a = section->at(middleElementIndex).GetID();
        if (num == a)
        {
            return true;
        }
        else if (num < a)
        {
            return containsBS(num, section, lowerB, middleElementIndex-1);
        }
        else
        {
            return containsBS(num, section, middleElementIndex+1, upperB);
        }
    }
    return false;
}

int displaySection(int size, vector<Fruits> section)
{
    cout << "Here is your section!" << endl;
    for (int i = 0; i < size; i++)
    {
        section.at(i).Display();
    }
    wait();
    return 0;
}