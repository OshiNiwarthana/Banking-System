#include <iostream>
#include <string>
#include <map>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance;

public:
    BankAccount(string name = "", double initialBalance = 0) {
        owner = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << ". Balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << ". Balance: " << balance << endl;
        } else {
            cout << "Not enough money!" << endl;
        }
    }

    void transfer(BankAccount &receiver, double amount) {
        if (amount <= balance) {
            balance -= amount;
            receiver.balance += amount;
            cout << "Transferred " << amount << " to " << receiver.owner << endl;
        } else {
            cout << "Not enough money!" << endl;
        }
    }

    void checkBalance() {
        cout << owner << "'s balance: " << balance << endl;
    }

    string getOwner() { return owner; }
    double getBalance() { return balance; }
};

int main() {
    map<int, BankAccount> accounts;
    int nextAccNo = 1001; // first account number

    int choice, accNo, targetAcc;
    double amount;
    string name;

    do {
        cout << "\n--- Banking Menu ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer\n";
        cout << "5. Check Balance\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter starting balance: ";
            cin >> amount;
            accounts[nextAccNo] = BankAccount(name, amount);
            cout << "Account created! Number: " << nextAccNo << endl;
            nextAccNo++;
            break;

        case 2:
            cout << "Enter account number: ";
            cin >> accNo;
            if (accounts.find(accNo) != accounts.end()) {
                cout << "Enter deposit amount: ";
                cin >> amount;
                accounts[accNo].deposit(amount);
            } else {
                cout << "Account not found!" << endl;
            }
            break;

        case 3:
            cout << "Enter account number: ";
            cin >> accNo;
            if (accounts.find(accNo) != accounts.end()) {
                cout << "Enter withdraw amount: ";
                cin >> amount;
                accounts[accNo].withdraw(amount);
            } else {
                cout << "Account not found!" << endl;
            }
            break;

        case 4:
            cout << "Enter your account number: ";
            cin >> accNo;
            cout << "Enter target account number: ";
            cin >> targetAcc;
            if (accounts.find(accNo) != accounts.end() && accounts.find(targetAcc) != accounts.end()) {
                cout << "Enter transfer amount: ";
                cin >> amount;
                accounts[accNo].transfer(accounts[targetAcc], amount);
            } else {
                cout << "One or both accounts not found!" << endl;
            }
            break;

        case 5:
            cout << "Enter account number: ";
            cin >> accNo;
            if (accounts.find(accNo) != accounts.end()) {
                accounts[accNo].checkBalance();
            } else {
                cout << "Account not found!" << endl;
            }
            break;

        case 6:
            cout << "Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
