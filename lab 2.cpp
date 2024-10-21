#include <iostream>
using namespace std;
class Shape {
public:
	
	virtual double area() const = 0;

	
		virtual ~Shape() = 0;
};


class Circle : public Shape {
private:
	double radius;

public:
	
	Circle(double r) : radius(r) {}

	
	double area() const override {
		return area * radius * radius; 
	}
};


class Rectangle : public Shape {
private:
	double length;
	double width;

public:
	
	Rectangle(double l, double w) : length(l), width(w) {}

	
	double area() const override {
		return length * width; 
	}
};

int main() {
	
	Circle circle(5.0);
	cout << "Area of Circle: " << circle.area() << endl;

	
	Rectangle rectangle(4.0, 6.0);
	cout << "Area of Rectangle: " << rectangle.area() << endl;

	return 0;
}
