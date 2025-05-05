#include <iostream>
#include <string>
using namespace std;

const int c = 100;

class treenode {
public:
    string name;
    treenode* chil[c];
    int children;

    treenode(string namec) {
        name = namec;
        children = 0;
        for (int i = 0; i < c; i++)
            chil[i] = nullptr;
    }

    void addname(treenode* child) {
        if (children < c) {
            chil[children++] = child;
        } else {
            cout << "Node has reached maximum number of children." << endl;
        }
    }
};


void printtree(treenode* node, int level = 0) {
    for (int i = 0; i < level; i++)
        cout << "  "; 
    cout << node->name << endl;

    for (int i = 0; i < node->children; i++) {
        printtree(node->chil[i], level + 1);
    }
}

int main() {
    string bookname;
    cout << "Enter the name of the book: ";
    getline(cin, bookname);

    treenode* book = new treenode(bookname);

    int numchap;
    cout << "Enter the number of chapters in the book: ";
    cin >> numchap;
    cin.ignore();

    for (int i = 0; i < numchap; i++) {
        string chapname;
        cout << "Enter name of chapter " << i + 1 << ": ";
        getline(cin, chapname);

        treenode* chapter = new treenode(chapname);
        book->addname(chapter);

        int numsec;
        cout << "Enter number of sections in chapter \"" << chapname << "\": ";
        cin >> numsec;
        cin.ignore();

        for (int j = 0; j < numsec; j++) {
            string secname;
            cout << "  Enter name of section " << j + 1 << ": ";
            getline(cin, secname);

            treenode* section = new treenode(secname);
            chapter->addname(section);

            int numsub;
            cout << "  Enter number of subsections in section \"" << secname << "\": ";
            cin >> numsub;
            cin.ignore();

            for (int k = 0; k < numsub; k++) {
                string subname;
                cout << "    Enter name of subsection " << k + 1 << ": ";
                getline(cin, subname);

                treenode* subsection = new treenode(subname);
                section->addname(subsection);
            }
        }
    }

    cout << "Book Structure:";
    printtree(book);

    return 0;
}
