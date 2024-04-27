#include "memoryDB.cpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    memoryDB db;  // Update this with your actual class name
    string command, key;
    int value;
    bool showMenu = true;

    cout << "Hello! Welcome to the Data Processing and Storage Assignment!" << endl;

    while (true) {
        cout << "\nPlease enter a command (begin, put, get, commit, rollback, exit):" << endl;
        cin >> command;

        try {
            if (command == "begin") {
                db.begin_transaction();
                cout << "Transaction started." << endl;
            } else if (command == "put") {
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value (integer): ";
                cin >> value;
                db.put(key, value);
                cout << "Key " << key << " set to " << value << "." << endl;
            } else if (command == "get") {
                cout << "Enter key: ";
                cin >> key;
                cout << "Value at '" << key << "' is " << db.get(key) << endl;
            } else if (command == "commit") {
                db.commit();
                cout << "Transaction committed." << endl;
            } else if (command == "rollback") {
                db.rollback();
                cout << "Transaction rolled back." << endl;
            } else if (command == "exit") {
                cout << "Exiting program." << endl;
                break;
            } else {
                cout << "Unknown command! Please try again." << endl;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
