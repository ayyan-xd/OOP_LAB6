#include <iostream>
#include <string>
using namespace std;

class Person {
    protected :
    string name;
    string CNIC;
    Person(string n, string cnic) {
        name = n;
        CNIC = cnic;
    }
    Person() {}
    virtual void displayInfo(){
        cout << "Name of Person : " << name << endl;
        cout << "CNIC Number of Person : " << CNIC << endl; 
    }
};

class Student : public Person {
    private :
    string rollNo;
    double GPA;
    public :
    Student(string name, string cnic, string roll, double gpa) : Person(name, cnic) {
        rollNo = roll;
        GPA = gpa;
        }
    void displayInfo() override {
        Person :: displayInfo();
        cout << "Roll no. of Student : " << rollNo << endl;
        cout << "GPA of Student : " << GPA << endl;
    }
};

class Lecturer : public Person {
    private : 
    string empID;
    string dept;
    public :
    Lecturer(string name, string cnic, string ID, string depart) : Person(name, cnic) {
        empID = ID;
        dept = depart;
    }
    void displayInfo() override {
        Person :: displayInfo();
        cout << "Emplpoyee ID of Lecturer : " << empID << endl;
        cout << "Department of Lecturer : " << dept << endl;
    }
};

int  main() {
    Student std("Ali", "1234567890", "123", 3.0);
    std.displayInfo();
    cout << endl;
    Lecturer lct("Mujahid", "0987654321", "321", "Physics");
    lct.displayInfo();
    return 0;
}