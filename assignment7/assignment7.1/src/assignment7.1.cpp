#include<iostream>
using namespace std;
#include <iostream>
using namespace std;

class Employee {
protected:
	int id;
	float salary;

public:
	Employee() :
			id(0), salary(0.0) {
	}
	Employee(int empId, float empSalary) :
			id(empId), salary(empSalary) {
	}

	int getId() const {
		return id;
	}
	float getSalary() const {
		return salary;
	}

	void setId(int id) {
		this->id = id;
	}

	void setSalary(float salary) {
		this->salary = salary;
	}

	virtual void accept() {
		cout << "Enter employee ID: ";
		cin >> id;
		cout << "Enter employee salary: ";
		cin >> salary;
	}

	virtual void display() {
		cout << "Employee ID: " << id << "\n";
		cout << "Employee Salary: " << salary << "\n";
	}
};
class Manager: virtual public Employee {
protected:
	float bonus;

public:
	Manager() :
			bonus(0.0) {
	}
	Manager(int empId, float empSalary, float empBonus) :
			Employee(empId, empSalary), bonus(empBonus) {
	}

	float getBonus() const {
		return bonus;
	}

	void setBonus(float bonus) {
		this->bonus = bonus;
	}

	void accept() 
	{
		Employee::accept();
	}
	void display() {
		cout << "Manager Information:\n";
		cout << "ID: " << Employee::getId() << " , Salary: "
				<< Employee::getSalary()<<" , ";
		
	}
protected:
	void accept_manager() {
		cout << "Enter manager bonus: ";
		cin >> bonus;
	}
	void display_manager() {
		cout << "Bonus: " << bonus << "\n";
	}
	
};

class Salesman: virtual public Employee {
protected:
	float comm;

public:
	Salesman() :
			comm(0.0) {
	}
	Salesman(int empId, float empSalary, float empComm) :
			Employee(empId, empSalary), comm(empComm) {
	}

	float getComm() const {
		return comm;
	}

	void setComm(float comm) {
		this->comm = comm;
	}

	void accept() 
	{
		Employee::accept();
	}

	void display()  {
		cout << "Salesman Information:\n";
		cout << "ID: " << Employee::getId() << " , Salary: "
				<< Employee::getSalary() << " , ";
				}
protected:
	void accept_salesman() {
		cout << "Enter salesman commission: ";
		cin >> comm;
	}

	void display_salesman() const {

		cout << "Commission: " << comm << "\n";
	}
};
class SalesManager: public Manager, public Salesman {
public:
	SalesManager() {
	}
	SalesManager(int empId, float empSalary, float empBonus, float empComm) :
			Manager(empId, empSalary, empBonus), Salesman(empId, empSalary,
					empComm) {
	}

	void accept()  {
		Employee::accept();
		Manager::accept_manager();
		Salesman::accept_salesman();
	}

	void display() override {
		Employee::display();
		Manager::display_manager();
		Salesman::display_salesman();	}
};
int main() {
	
	SalesManager salesManager;
	salesManager.accept();
	salesManager.display();

}
