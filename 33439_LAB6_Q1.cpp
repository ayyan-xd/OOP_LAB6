#include <iostream>
using namespace std;

class Shape {
    protected : //Protected data members, accessible only in derived class.
    string color; 
    public : //Public data members, accessible everywhere even outside class.
    Shape() {}
    virtual void displayColor() {
        cout << "Color of circle : " << color << endl;
    }
};

class Circle : public Shape {
    private : //Private data members, not accessible outside class.
    double radius;
    public : //Public data members, accessible everywhere even outside class.
    Circle(double r, string c) {
        radius = r;
        color = c;
    }
    double area() {
        return 3.15159 * radius * radius;
    }
};

int main () {
    Circle shape1(2.00, "yellow");
    shape1.displayColor();
    cout << "The area of circle : " << shape1.area();
    return 0;
}