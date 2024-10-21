#include <iostream>
using namespace std;

using namespace std;


class Employee {
public:

	virtual double calculateSalary() const = 0;

	
	virtual ~Employee() = 0; 
};


class FullTimeEmployee : public Employee {
private:
	double fixedSalary;

public:
	
	FullTimeEmployee(double salary) : fixedSalary(salary) {}


	double calculateSalary() const override {
		return fixedSalary;
	}
};


class PartTimeEmployee : public Employee {
private:
	double hoursWorked;
	double hourlyRate;

public:
	
	PartTimeEmployee(double hours, double rate) : hoursWorked(hours), hourlyRate(rate) {}

	
	double calculateSalary() const override {
		return hoursWorked * hourlyRate;
	}
};

int main() {
	
	FullTimeEmployee fullTimeEmp(5000);
	cout << "Full-Time Employee Salary: $" << fullTimeEmp.calculateSalary() << endl;

	
	PartTimeEmployee partTimeEmp(20, 15);
	cout << "Part-Time Employee Salary: $" << partTimeEmp.calculateSalary() << endl;

	return 0;
}
