#include <iostream>
#define MAX 10
using namespace std;

class Hash {
    long int arr[MAX];
    int comparisons[MAX]; // Stores number of comparisons for each key

public:
    // Constructor: Initialize table with -1 (empty) and 0 comparisons
    Hash() {
        for (int i = 0; i < MAX; i++) {
            arr[i] = -1;          // -1 indicates empty slot
            comparisons[i] = 0;
        }
    }

    // Simple modulo hash function
    int hashFun(long int num) {
        return num % MAX;
    }

    // Insert a number using linear probing and count comparisons
    void insert() {
        long int num;
        cout << "Enter the number: ";
        cin >> num;

        int index = hashFun(num);
        int start = index;
        int comp = 1;

        // If the hashed slot is empty, insert directly
        if (arr[index] == -1) {
            arr[index] = num;
            comparisons[index] = comp;
            cout << "Number " << num << " inserted at index " << index
                 << " with " << comp << " comparisons.\n";
            return;
        }

        // Linear probing for collision resolution
        while (arr[index] != -1) {
            index = (index + 1) % MAX;
            comp++;
            if (index == start) {
                cout << "Hash table is full. Unable to insert " << num << endl;
                return;
            }
        }

        // Insert into the found empty spot
        arr[index] = num;
        comparisons[index] = comp;
        cout << "Number " << num << " inserted at index " << index
             << " with " << comp << " comparisons.\n";
    }

    // Display hash table contents
    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < MAX; i++) {
            if (arr[i] == -1)
                cout << i << " ------> NULL\n";
            else
                cout << i << " ------> " << arr[i] << "\n";
        }
    }

    // Display number of comparisons for each key
    void displayComparisons() {
        int totalComparisons = 0;
        cout << "\nComparisons for each key:\n";
        for (int i = 0; i < MAX; i++) {
            if (arr[i] != -1) {
                cout << "Key " << arr[i] << " required "
                     << comparisons[i] << " comparisons.\n";
                totalComparisons += comparisons[i];
            }
        }
        cout << "Total comparisons: " << totalComparisons << "\n";
    }
};

// Main driver function
int main() {
    int choice;
    Hash h;

    do {
        cout << "\nMenu:\n1. Insert\n2. Display Hashtable\n3. Display Comparisons\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                h.insert();
                break;
            case 2:
                h.display();
                break;
            case 3:
                h.displayComparisons();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
