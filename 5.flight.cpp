#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class flight {
    int m[20][20], n;
    string v[20];
    bool visited[20];

public:
    void getgraph();
    void displaym();
    void dfs(int);
    bool isConnected();
};

void flight::getgraph() {
    cout << "\nEnter number of cities (max 20): ";
    cin >> n;

    cout << "Enter name of cities:\n";
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // Initialize matrix to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m[i][j] = 0;

    // Input edges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "\nIs there a path between " << v[i] << " and " << v[j] << "? (y/n): ";
            char ch;
            cin >> ch;
            if (ch == 'y' || ch == 'Y') {
                cout << "Enter time in minutes from " << v[i] << " to " << v[j] << ": ";
                cin >> m[i][j];
            } else {
                m[i][j] = 0;
            }
        }
    }
}

void flight::displaym() {
    cout << "\nAdjacency Matrix:\n\t";
    for (int j = 0; j < n; j++)
        cout << v[j] << "\t";
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << v[i] << "\t";
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

// DFS traversal to check connectivity
void flight::dfs(int u) {
    visited[u] = true;
    for (int i = 0; i < n; i++) {
        if (m[u][i] != 0 && !visited[i])
            dfs(i);
    }
}

// Check if all cities are reachable
bool flight::isConnected() {
    for (int i = 0; i < n; i++)
        visited[i] = false;

    dfs(0);  // start from first city

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            return false;
    }
    return true;
}

int main() {
    int choice;
    flight f;

    while (1) {
        cout << "\n\nMenu:";
        cout << "\n1. Enter Graph";
        cout << "\n2. Display Adjacency Matrix";
        cout << "\n3. Check if Flight Network is Connected";
        cout << "\n4. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            f.getgraph();
            break;
        case 2:
            f.displaym();
            break;
        case 3:
            if (f.isConnected())
                cout << "\nThe flight network is CONNECTED.\n";
            else
                cout << "\nThe flight network is NOT CONNECTED.\n";
            break;
        case 4:
            exit(0);
        default:
            cout << "\nInvalid choice.";
        }
    }
    return 0;
}
