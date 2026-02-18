#include <iostream>
using namespace std;


class DigitalAccount {
private:
    string customerName;
    int accountID;
    double balance;

public:

    DigitalAccount(string name, int id, double initialBalance = 0) {
        customerName = name;
        accountID = id;

        if (initialBalance >= 0)
            balance = initialBalance;
        else
            balance = 0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }


    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdraw amount.\n";
        }
        else if (amount > balance) {
            cout << "Withdrawal failed! Not enough balance.\n";
        }
        else {
            balance -= amount;
            cout << "Withdrawal successful.\n";
        }
    }



    void display() {
        cout << "\n--- Account Summary ---\n";
        cout << "Customer Name : " << customerName << endl;
        cout << "Account ID    : " << accountID << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of accounts to create: ";
    cin >> n;



    DigitalAccount* accounts[100];



    for (int i = 0; i < n; i++) {
        string name;
        int id;
        double initialBalance;

        cout << "\nEnter details for Account " << i + 1 << endl;

        cout << "Customer Name: ";
        cin >> name;

        cout << "Account ID: ";
        cin >> id;

        cout << "Initial Balance: ";
        cin >> initialBalance;

        accounts[i] = new DigitalAccount(name, id, initialBalance);
    }


    int choice;
    do {
        int index;
        double amount;

        cout << "\n===== Digital Banking Menu =====\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Display Account Summary\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            cout << "Enter account number (1 to " << n << "): ";
            cin >> index;

            if (index < 1 || index > n) {
                cout << "Invalid account number.\n";
                continue;
            }
        }

        switch (choice) {
        case 1:
            cout << "Enter deposit amount: ";
            cin >> amount;
            accounts[index - 1]->deposit(amount);
            break;

        case 2:
            cout << "Enter withdraw amount: ";
            cin >> amount;
            accounts[index - 1]->withdraw(amount);
            break;

        case 3:
            accounts[index - 1]->display();
            break;

        case 4:
            cout << "Thank you for using Digital Banking System.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
