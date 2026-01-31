
#include <iostream>
using namespace std;

struct HourlyPaid
{
    double hoursWorked;
    double hourlyRate;
};

struct Salaried
{
    double salary;
    double bonus;
};

union Worker
{
    HourlyPaid hourly;
    Salaried salaried;
};

int main()
{
    Worker worker;
    int choice;
    double pay = 0.0;

    cout << "Select worker type:\n";
    cout << "1. Hourly Paid Worker\n";
    cout << "2. Salaried Worker\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    if (choice == 1)
    {
        do
        {
            cout << "Enter hours worked (0–80): ";
            cin >> worker.hourly.hoursWorked;
        } while (worker.hourly.hoursWorked < 0 || worker.hourly.hoursWorked > 80);

        // Input validation for hourly rate
        do
        {
            cout << "Enter hourly rate: ";
            cin >> worker.hourly.hourlyRate;
        } while (worker.hourly.hourlyRate < 0);

        pay = worker.hourly.hoursWorked * worker.hourly.hourlyRate;
    }
    else if (choice == 2)
    {
        do
        {
            cout << "Enter salary: ";
            cin >> worker.salaried.salary;
        } while (worker.salaried.salary < 0);

        do
        {
            cout << "Enter bonus: ";
            cin >> worker.salaried.bonus;
        } while (worker.salaried.bonus < 0);

        pay = worker.salaried.salary + worker.salaried.bonus;
    }
    else
    {
        cout << "Invalid choice.\n";
        return 1;
    }

    cout << "\nTotal Pay: $" << pay << endl;

    return 0;
}
