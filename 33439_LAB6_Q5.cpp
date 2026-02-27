#include <iostream>
using namespace std;

class Employee {
    protected :
    int employeeID;
    double baseSalary;
    public :
    Employee(int empID, double salary) {
        employeeID = empID;
        baseSalary = salary;
    }
    virtual void display(){
        cout << "Employee ID : " << employeeID << endl;
        cout << "Base Salary : " << baseSalary << endl;
        cout << "Bonus : " << 0.05 * baseSalary << endl;
    }
};

class Manager : public Employee {
    private :
    string dept;
    public :
    Manager(int empID, double salary, string dpt) : Employee(empID, salary) {
        dept = dpt;
    }
    void display() override {
        Employee :: display();
        cout << "Department : " << dept << endl;
    cout << "Bonus : " << 0.1 * baseSalary << endl;
    }
};

class RegionalDirector : public Manager {
    private :
    string region;
    public :
    RegionalDirector (int empID, double salary, string dept, string rgn) : Manager(empID, salary, dept) { 
        region = rgn;
    }   
    void display() override {
        Manager :: display();
        cout << "Region  : " << region << endl;
    cout << "Bonus : " << 0.15 * baseSalary << endl;
    }
};

int main() {
    Employee emp1(123, 450.0);
    emp1.display();
    cout << endl;
    Manager manager1(456, 678, "Sales");
    manager1.display();
    cout << endl;
    RegionalDirector rgd1(789, 875, "Marketing", "Karachi");
    rgd1.display();
    return 0;
}