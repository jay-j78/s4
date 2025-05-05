#include<iostream>
#include<string>
#include<fstream>

using namespace std;
struct student{
    int roll;
    string div;
    string address;
    string name;

};

void add(){
    ofstream outfile("student.txt",ios::app);
    student s;
    cout<<"enter a roll number of students:";
    cin>>s.roll;
    cin.ignore();
    cout<<"enter a name of the student:";
    getline(cin,s.name);
    cout<<"enter a division of student:";
    getline(cin,s.div);
    cout<<"enter a address of the student:";
    getline(cin,s.address);
    outfile<<s.roll<<","<<s.name<<","<<s.div<<","<<s.address<<endl;
    outfile.close();
    cout<<"students data is saved!";

}
void search(int rollno){
    ifstream infile("student.txt");
    string line;
    bool found=false;
    while(getline(infile,line)){
        int i=0;
        int exact=0;
        while(i<line.length()&& line[i]!=','){
            exact=exact*10+(line[i]-'0');
            i++;
        }
        if(exact==rollno){
            cout<<"student details:"<<line<<endl;
            found=true;
            break;
        }
    }
    
infile.close();
if(!found){
    cout<<"student details are not found:";

}
}
void delet(int rollno){
    ifstream infile("student.txt");
    ofstream tempfile("temp.txt");
    string line;
    bool found=false;
    while(getline(infile,line)){
        int i=0;
        int exact=0;
        while(i<line.length()&&line[i]!=','){
            exact=exact*10+(line[i]-'0');
            i++;

        }
        if(exact!=rollno){
            tempfile<<line<<endl;
        }
        else{
            found=true;
        }
        
    
    
}
infile.close();
tempfile.close();
remove("student.txt");
rename("temp.txt","student.txt");
if(found){
    cout<<"student data is deleted :";
}
else{
    cout<<"ishowspeed op suiii:";
}
}
int main(){
    int choice,rollno;
    do{
        cout<<"1-add student:\n";
        cout<<"2-search data:\n";
        cout<<"3-delete data:\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
        add();
            break;
        case 2:
        cout<<"enter a roll number for search:";
        cin>>rollno;
        search(rollno);
        break; 
        case 3:
        cout<<"enter a roll number to delete:";
        cin>>rollno;
        delet(rollno);
        break;
        
        default:
        cout<<"msd:";
            break;
        }

    }while(choice!=3);
    return 0;
}