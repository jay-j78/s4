#include <iostream>
#include <fstream>
using namespace std;

class student {
public:
    int roll;
    char div;
    char name[10];

    void take() {
        cout << "\nEnter name: ";
        cin >> name;
        cout << "Enter roll no: ";
        cin >> roll;
        cout << "Enter div: ";
        cin >> div;
    }

    void put() {
        cout << "Name: " << name << endl;
        cout << "Roll no: " << roll << endl;
        cout << "Div: " << div << endl;
    }
};

int main() {
    int ch, n;

    do {
        cout << "\nMenu:\n1. Create and Write\n2. Read\n3. Search\n4. Append\n5. Delete\n0. Exit\n";
        cout << "Choose option: ";
        cin >> ch;

        switch (ch) {
        case 1: {
            cout << "Enter number of students: ";
            cin >> n;
            student s;
            fstream fp("student.txt", ios::out | ios::binary);
            for (int i = 0; i < n; i++) {
                s.take();
                fp.write((char*)&s, sizeof(s));
            }
            fp.close();
            break;
        }

        case 2: {
            fstream fr("student.txt", ios::in | ios::binary);
            student s;
            while (fr.read((char*)&s, sizeof(s))) {
                s.put();
                cout << endl;
            }
            fr.close();
            break;
        }

        case 3: {
            int r, flag = 0;
            cout << "Enter roll no to search: ";
            cin >> r;
            student s;
            fstream fs("student.txt", ios::in | ios::binary);
            while (fs.read((char*)&s, sizeof(s))) {
                if (s.roll == r) {
                    cout << "Record found:\n";
                    s.put();
                    flag = 1;
                    break;
                }
            }
            fs.close();
            if (!flag)
                cout << "Record not found.\n";
            break;
        }

        case 4: {
            int n1;
            cout << "Enter number of students to append: ";
            cin >> n1;
            student s;
            fstream fa("student.txt", ios::app | ios::binary);
            for (int i = 0; i < n1; i++) {
                s.take();
                fa.write((char*)&s, sizeof(s));
            }
            fa.close();
            break;
        }

        case 5: {
            int delroll, flag = 0;
            cout << "Enter roll number to delete: ";
            cin >> delroll;
            student s;
            fstream fp("student.txt", ios::in | ios::binary);
            fstream fp1("temp.txt", ios::out | ios::binary);

            while (fp.read((char*)&s, sizeof(s))) {
                if (s.roll == delroll) {
                    cout << "Record found and deleted:\n";
                    s.put();
                    flag = 1;
                } else {
                    fp1.write((char*)&s, sizeof(s));
                }
            }

            fp.close();
            fp1.close();

            remove("student.txt");
            rename("temp.txt", "student.txt");

            if (!flag)
                cout << "Record not found.\n";
            break;
        }

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid option.\n";
        }
    } while (ch != 0);

    return 0;
}
