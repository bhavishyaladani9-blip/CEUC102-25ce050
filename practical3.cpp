#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
public:
    string name;
    double basicSalary;
    double bonus;

    Employee(string n, double basic, double bon = 500) {
        name = n;
        basicSalary = basic;
        bonus = bon;
    }


    inline double totalSalary() {
        return basicSalary + bonus;
    }

    void display() {
        cout << "\nName        : " << name;
        cout << "\nBasic Salary: Rs." << basicSalary;
        cout << "\nBonus       : Rs." << bonus;
        cout << "\nTotal Salary: Rs." << totalSalary();
        cout << "\n---------------------------";
    }
};

int main() {
    int n;
    cout << "=== Payroll System ===\n";
    cout << "How many employees? ";
    cin >> n;


    vector<Employee*> employees;

    for (int i = 0; i < n; i++) {
        string name;
        double basic, bonus;
        char choice;

        cout << "\n--- Employee " << i + 1 << " ---";
        cout << "\nEnter Name        : ";
        cin >> name;
        cout << "Enter Basic Salary : Rs.";
        cin >> basic;
        cout << "Custom bonus? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Enter Bonus Amount : Rs.";
            cin >> bonus;
            employees.push_back(new Employee(name, basic, bonus));
        } else {

            employees.push_back(new Employee(name, basic));
        }
    }

    cout << "\n\n=== Employee Salary Report ===";
    for (int i = 0; i < employees.size(); i++) {
        employees[i]->display();
    }


    for (int i = 0; i < employees.size(); i++) {
        delete employees[i];
    }

    return 0;
}
