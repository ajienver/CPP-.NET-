#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <limits>

using namespace std;

const char FILENAME[] = "inventory.dat";

struct InventoryItem
{
    char description[50];
    int quantity;
    double wholesaleCost;
    double retailCost;
    int month, day, year;
};

void addRecord();
void displayRecord();
void modifyRecord();
bool validDate(int m, int d, int y);

int main()
{
    int choice;

    do
    {
        cout << "\nInventory Menu\n";
        cout << "1. Add new record\n";
        cout << "2. Display a record\n";
        cout << "3. Modify a record\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter again: ";
            cin >> choice;
        }

        switch (choice)
        {
            case 1: addRecord(); break;
            case 2: displayRecord(); break;
            case 3: modifyRecord(); break;
            case 4: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}

void addRecord()
{
    InventoryItem item;
    ofstream file(FILENAME, ios::binary | ios::app);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Item description: ";
    cin.getline(item.description, 50);

    do
    {
        cout << "Quantity on hand: ";
        cin >> item.quantity;
    } while (item.quantity < 0);

    do
    {
        cout << "Wholesale cost: ";
        cin >> item.wholesaleCost;
    } while (item.wholesaleCost < 0);

    do
    {
        cout << "Retail cost: ";
        cin >> item.retailCost;
    } while (item.retailCost < 0);

    do
    {
        cout << "Date added (MM DD YYYY): ";
        cin >> item.month >> item.day >> item.year;
    } while (!validDate(item.month, item.day, item.year));

    file.write(reinterpret_cast<char*>(&item), sizeof(item));
    file.close();

    cout << "Record added successfully.\n";
}

void displayRecord()
{
    InventoryItem item;
    ifstream file(FILENAME, ios::binary);

    int record;
    cout << "Enter record number to display (starting at 1): ";
    cin >> record;

    if (record < 1)
    {
        cout << "Invalid record number.\n";
        return;
    }

    file.seekg((record - 1) * sizeof(item), ios::beg);

    if (file.read(reinterpret_cast<char*>(&item), sizeof(item)))
    {
        cout << "\nDescription: " << item.description << endl;
        cout << "Quantity: " << item.quantity << endl;
        cout << "Wholesale Cost: $" << fixed << setprecision(2)
             << item.wholesaleCost << endl;
        cout << "Retail Cost: $" << item.retailCost << endl;
        cout << "Date Added: "
             << item.month << "/" << item.day << "/" << item.year << endl;
    }
    else
    {
        cout << "Record not found.\n";
    }

    file.close();
}

void modifyRecord()
{
    InventoryItem item;
    fstream file(FILENAME, ios::binary | ios::in | ios::out);

    int record;
    cout << "Enter record number to modify (starting at 1): ";
    cin >> record;

    if (record < 1)
    {
        cout << "Invalid record number.\n";
        return;
    }

    file.seekg((record - 1) * sizeof(item), ios::beg);

    if (!file.read(reinterpret_cast<char*>(&item), sizeof(item)))
    {
        cout << "Record not found.\n";
        file.close();
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "New description: ";
    cin.getline(item.description, 50);

    do
    {
        cout << "New quantity: ";
        cin >> item.quantity;
    } while (item.quantity < 0);

    do
    {
        cout << "New wholesale cost: ";
        cin >> item.wholesaleCost;
    } while (item.wholesaleCost < 0);

    do
    {
        cout << "New retail cost: ";
        cin >> item.retailCost;
    } while (item.retailCost < 0);

    do
    {
        cout << "New date (MM DD YYYY): ";
        cin >> item.month >> item.day >> item.year;
    } while (!validDate(item.month, item.day, item.year));

    file.seekp((record - 1) * sizeof(item), ios::beg);
    file.write(reinterpret_cast<char*>(&item), sizeof(item));

    file.close();
    cout << "Record updated successfully.\n";
}

bool validDate(int m, int d, int y)
{
    if (y < 2000 || y > 2100)
        return false;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;

    return true;
}
