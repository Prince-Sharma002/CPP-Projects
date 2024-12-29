#include <iostream>
#include <fstream>
using namespace std;

class temp {
    string phoneNo, name, address, description;
    fstream file;

public:
    void addContact();
    void showContact();
    void searchContact();
};

int main() {
    temp obj;
    char choice;

    while (true) {
        cout << "1 ----> Add Contact" << endl;
        cout << "2 ----> Show Contact" << endl;
        cout << "3 ----> Search Contact" << endl;
        cout << "4 ----> Exit" << endl;

        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) {
            case '1':
                obj.addContact();
                break;
            case '2':
                obj.showContact();
                break;
            case '3':
                obj.searchContact();
                break;
            case '4':
                exit(0);
                break;
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
    }

    return 0;
}

void temp::addContact() {
    cout << "Enter your phone number: ";
    getline(cin, phoneNo);
    cout << "Enter your Name: ";
    getline(cin, name);
    cout << "Enter your Address: ";
    getline(cin, address);
    cout << "Enter Description: ";
    getline(cin, description);

    try {
        file.open("contact.csv", ios::out | ios::app);
        file << phoneNo << "," << name << "," << address << "," << description << endl;
        file.close();
        cout << "Contact saved successfully" << endl;
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}

void temp::showContact() {
    file.open("contact.csv", ios::in);

    getline(file, phoneNo, ',');
    getline(file, name, ',');
    getline(file, address, ',');
    getline(file, description, '\n');

    while (!file.eof()) {
        cout << "Phone no: " << phoneNo << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Description: " << description << endl << endl;

        getline(file, phoneNo, ',');
        getline(file, name, ',');
        getline(file, address, ',');
        getline(file, description, '\n');
    }

    file.close();
}

void temp::searchContact() {
    string search;
    cout << "Enter the phone number to search: ";
    getline(cin, search);

    file.open("contact.csv", ios::in);

    getline(file, phoneNo, ',');
    getline(file, name, ',');
    getline(file, address, ',');
    getline(file, description, '\n');

    while (!file.eof()) {
        if (phoneNo == search) {
            cout << "Phone no: " << phoneNo << endl;
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Description: " << description << endl << endl;
        }

        getline(file, phoneNo, ',');
        getline(file, name, ',');
        getline(file, address, ',');
        getline(file, description, '\n');
    }

    file.close();
}
