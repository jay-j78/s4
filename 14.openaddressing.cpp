#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

struct Node {
    int key;
    string value;
    Node* next;
    
    Node(int k, string v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class Dictionary {
    Node* table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    Dictionary() {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = nullptr;
    }

    void insert(int key, string value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);

        
        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->key == key) {
                cout << "Key already exists. Updating value.\n";
                temp->value = value;
                delete newNode;
                return;
            }
            temp = temp->next;
        }

       
        newNode->next = table[index];
        table[index] = newNode;
        cout << "Inserted (" << key << ", " << value << ")\n";
    }

    void find(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];

        while (temp != nullptr) {
            if (temp->key == key) {
                cout << "Found: " << temp->value << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Key not found.\n";
    }

    void remove(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->key == key) {
                if (prev == nullptr)
                    table[index] = temp->next;
                else
                    prev->next = temp->next;

                delete temp;
                cout << "Key deleted.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Key not found.\n";
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "[" << i << "]: ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << "(" << temp->key << ", " << temp->value << ") -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    Dictionary dict;
    int choice;
    int key;
    string value;

    do {
        
        cout << "1. Insert\n2. Find\n3. Delete\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
    cout << "Enter key (integer): ";
    cin >> key;
    cout << "Enter value: ";
    cin.ignore();
    getline(cin, value);
    dict.insert(key, value);
    break;


            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                dict.find(key);
                break;

            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                dict.remove(key);
                break;

            case 4:
                dict.display();
                break;

            case 5:
                cout << "end";
                break;

            default:
                cout << "csk eleminated";
        }

    } while (choice != 5);

    return 0;
}
