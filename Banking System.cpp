#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Bank {
protected:
    struct Person {
        string name, ID, address;
        long long contact, cash;
    } person[100];
    int total;

public:
    Bank() : total(0) {}
    virtual void personData() = 0;
    virtual void showData() = 0;
    virtual void updateData() = 0;
    virtual void searchData() = 0;
    virtual void transactions() = 0;
    virtual void deleteData() = 0;
    virtual ~Bank() {} // Virtual destructor
};

// Derived Class implementing Bank functionality
class BankOperations : public Bank {
public:
    void personData() override;
    void showData() override;
    void updateData() override;
    void searchData() override;
    void transactions() override;
    void deleteData() override;
    void menu(); // UI interaction
};



// ---------- Menu ----------
void BankOperations::menu() {
    while (true) {
        cout << "\nMenu:\n"
             << "1. Create Account\n"
             << "2. View All Accounts\n"
             << "3. Update Account\n"
             << "4. Search Account\n"
             << "5. Transactions\n"
             << "6. Delete Account\n"
             << "7. Exit\n"
             << "Enter Choice: ";
        char ch;
        cin >> ch;

        switch (ch) {
            case '1': personData(); break;
            case '2': showData(); break;
            case '3': updateData(); break;
            case '4': searchData(); break;
            case '5': transactions(); break;
            case '6': deleteData(); break;
            case '7': cout << "Thanks for using.\n"; return;
            default: cout << "Invalid choice.\n";
        }
    }
}

// ---------- Functional Definitions ----------

void BankOperations::personData() {
    cout << "Enter person " << total + 1 << " data:\n";
    cin.ignore();
    cout << "Name: ";
    getline(cin, person[total].name);
    cout << "ID: ";
    cin >> person[total].ID;
    cin.ignore();
    cout << "Address: ";
    getline(cin, person[total].address);
    cout << "Contact: ";
    cin >> person[total].contact;
    cout << "Cash: ";
    cin >> person[total].cash;
    total++;
    cout << "Account Created.\n";
}

void BankOperations::showData() {
    if (total == 0) {
        cout << "No data.\n";
        return;
    }
    for (int i = 0; i < total; i++) {
        cout << "\nAccount " << i + 1 << ":\n";
        cout << "Name: " << person[i].name << "\nID: " << person[i].ID
             << "\nAddress: " << person[i].address << "\nContact: " << person[i].contact
             << "\nCash: " << person[i].cash << "\n";
    }
}

void BankOperations::updateData() {
    if (total == 0) {
        cout << "No data.\n";
        return;
    }
    string id;
    cout << "Enter ID to update: ";
    cin >> id;
    for (int i = 0; i < total; i++) {
        if (person[i].ID == id) {
            cout << "Updating data...\n";
            cin.ignore();
            cout << "New Name: ";
            getline(cin, person[i].name);
            cout << "New ID: ";
            cin >> person[i].ID;
            cin.ignore();
            cout << "New Address: ";
            getline(cin, person[i].address);
            cout << "New Contact: ";
            cin >> person[i].contact;
            cout << "New Cash: ";
            cin >> person[i].cash;
            cout << "Updated.\n";
            return;
        }
    }
    cout << "ID not found.\n";
}

void BankOperations::searchData() {
    if (total == 0) {
        cout << "No data.\n";
        return;
    }
    string id;
    cout << "Enter ID to search: ";
    cin >> id;
    for (int i = 0; i < total; i++) {
        if (person[i].ID == id) {
            cout << "\nFound:\n";
            cout << "Name: " << person[i].name << "\nID: " << person[i].ID
                 << "\nAddress: " << person[i].address << "\nContact: " << person[i].contact
                 << "\nCash: " << person[i].cash << "\n";
            return;
        }
    }
    cout << "ID not found.\n";
}

void BankOperations::transactions() {
    if (total == 0) {
        cout << "No data.\n";
        return;
    }
    string id;
    cout << "Enter ID for transaction: ";
    cin >> id;
    for (int i = 0; i < total; i++) {
        if (person[i].ID == id) {
            cout << "1. Deposit\n2. Withdraw\nChoice: ";
            char ch;
            cin >> ch;
            long long amount;
            if (ch == '1') {
                cout << "Amount to deposit: ";
                cin >> amount;
                person[i].cash += amount;
                cout << "New balance: " << person[i].cash << "\n";
            } else if (ch == '2') {
                cout << "Amount to withdraw: ";
                cin >> amount;
                if (amount > person[i].cash)
                    cout << "Insufficient funds.\n";
                else {
                    person[i].cash -= amount;
                    cout << "New balance: " << person[i].cash << "\n";
                }
            } else {
                cout << "Invalid choice.\n";
            }
            return;
        }
    }
    cout << "ID not found.\n";
}

void BankOperations::deleteData() {
    if (total == 0) {
        cout << "No data.\n";
        return;
    }
    cout << "1. Delete one account\n2. Delete all\nChoice: ";
    char ch;
    cin >> ch;
    if (ch == '1') {
        string id;
        cout << "Enter ID to delete: ";
        cin >> id;
        for (int i = 0; i < total; i++) {
            if (person[i].ID == id) {
                for (int j = i; j < total - 1; j++)
                    person[j] = person[j + 1];
                total--;
                cout << "Account deleted.\n";
                return;
            }
        }
        cout << "ID not found.\n";
    } else if (ch == '2') {
        total = 0;
        cout << "All accounts deleted.\n";
    } else {
        cout << "Invalid choice.\n";
    }
}
// ---------- Main ----------
int main() {
    cout << "\n*     Bank Management System     *\n\n";
    Bank* bank = new BankOperations();
    static_cast<BankOperations*>(bank)->menu(); // UI part
    delete bank;
    return 0;
}

