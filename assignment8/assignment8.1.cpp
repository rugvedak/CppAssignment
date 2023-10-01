#include <iostream>
using namespace std;

class Employee
{
private:
	int id;
	float salary;

protected:
	string designation;

public:
	Employee() : id(0), salary(0.0)
	{
	}
	Employee(int empId, float empSalary) : id(empId), salary(empSalary)
	{
	}

	int getId() const
	{
		return id;
	}
	float getSalary() const
	{
		return salary;
	}

	void setId(int id)
	{
		this->id = id;
	}

	void setSalary(float salary)
	{
		this->salary = salary;
	}

	string getDesignation()
	{
		return this->designation;
	}
	void setDesignation(string designation)
	{
		this->designation = designation;
	}
	virtual void accept()
	{
		cout << "Enter employee ID: ";
		cin >> id;
		cout << "Enter employee salary: ";
		cin >> salary;
	}

	virtual void display() = 0;
};
class Manager : virtual public Employee
{
protected:
	float bonus;

public:
	Manager() : bonus(0.0)
	{
		this->designation = "Manager";
	}
	Manager(int empId, float empSalary, float empBonus) : Employee(empId, empSalary), bonus(empBonus)
	{
		this->designation = "Manager";
	}

	float getBonus() const
	{
		return bonus;
	}

	void setBonus(float bonus)
	{
		this->bonus = bonus;
	}

	string getDesignation()
	{
		return this->designation;
	}

	void accept()
	{
		Employee::accept();
	}
	void display()
	{
		cout << "Manager Information:\n";
		cout << "ID :" << getId() << endl;
		cout << "Salary :" << getSalary() << endl;
		cout << "Bonus = " << this->bonus << endl;
	}

protected:
	void accept_manager()
	{
		cout << "Enter manager bonus: ";
		cin >> bonus;
	}
	void display_manager()
	{
		cout << "Bonus: " << bonus << "\n";
	}
};

class Salesman : virtual public Employee
{
protected:
	float comm;

public:
	Salesman() : comm(0.0)
	{
		this->designation = "Salesman";
	}
	Salesman(int empId, float empSalary, float empComm) : Employee(empId, empSalary), comm(empComm)
	{
		this->designation = "Salesman";
	}

	float getComm() const
	{
		return comm;
	}

	void setComm(float comm)
	{
		this->comm = comm;
	}

	string getDesignation()
	{
		return this->designation;
	}

	void accept()
	{
		Employee::accept();
	}

	void display()
	{
		cout << "Salesman Information:\n";
		cout << "ID :" << getId() << endl;
		cout << "Salary :" << getSalary() << endl;
		cout << "Commission: " << this->comm << "\n";
	}

protected:
	void accept_salesman()
	{
		cout << "Enter salesman commission: ";
		cin >> comm;
	}

	void display_salesman() const
	{

		cout << "Commission: " << comm << "\n";
	}
};
class SalesManager : public Manager, public Salesman
{
public:
	SalesManager()
	{
		this->designation = "SalesManager";
	}
	SalesManager(int empId, float empSalary, float empBonus, float empComm) : Manager(empId, empSalary, empBonus), Salesman(empId, empSalary, empComm)
	{
		this->designation = "SalesManager";
	}
	string getDesignation()
	{
		return this->designation;
	}

	void accept()
	{
		Employee::accept();
		Manager::accept_manager();
		Salesman::accept_salesman();
	}

	void display()
	{
		Manager::display_manager();
		Salesman::display_salesman();
	}
};
int MenuChoice()
{
	cout << "\nMenu:\n";
	cout << "1. Accept Employee\n";
	cout << "2. Display Employee Counts by Designation\n";
	cout << "3. Display Employees by Designation\n";
	cout << "4. Exit\n";
	cout << "Enter choice: ";
	int choice;
	cin >> choice;

	return choice;
}
int main()
{
	const int MAX_EMPLOYEES = 10;
	Employee *employees[MAX_EMPLOYEES] = {nullptr};

	int numEmployees = 0;

	while (true)
	{

		int choice = MenuChoice();

		if (choice == 4)
		{
			break;
		}

		switch (choice)
		{
		case 1:
		{
			if (numEmployees >= MAX_EMPLOYEES)
			{
				cout << "Maximum employees reached." << endl;
				break;
			}

			cout << "Select Employee Type (1 for Manager, 2 for Salesman, 3 for SalesManager): ";
			int empType;
			cin >> empType;

			if (empType == 1)
			{
				int id;
				double salary, bonus;
				cout << "Enter ID: ";
				cin >> id;
				cout << "Enter Salary: ";
				cin >> salary;
				cout << "Enter Bonus: ";
				cin >> bonus;
				employees[numEmployees++] = new Manager(id, salary, bonus);
			}
			else if (empType == 2)
			{
				int id;
				double salary, commission;
				cout << "Enter ID: ";
				cin >> id;
				cout << "Enter Salary: ";
				cin >> salary;
				cout << "Enter Commission: ";
				cin >> commission;
				employees[numEmployees++] = new Salesman(id, salary, commission);
			}
			else if (empType == 3)
			{
				int id;
				double salary, bonus, commission;
				cout << "Enter ID: ";
				cin >> id;
				cout << "Enter Salary: ";
				cin >> salary;
				cout << "Enter Bonus: ";
				cin >> bonus;
				cout << "Enter Commission: ";
				cin >> commission;
				employees[numEmployees++] = new SalesManager(id, salary, bonus, commission);
			}
			else
			{
				cout << "Invalid Employee Type" << endl;
			}
			break;
		}
		case 2:
		{
			int managerCount = 0, salesmanCount = 0, salesManagerCount = 0;
			for (int i = 0; i < numEmployees; i++)
			{
				if (typeid(*employees[i]) == typeid(Manager))
				{
					managerCount++;
				}
				else if (typeid(*employees[i]) == typeid(Salesman))
				{
					salesmanCount++;
				}
				else if (typeid(*employees[i]) == typeid(SalesManager))
				{
					salesManagerCount++;
				}
			}
			cout << "Manager Count: " << managerCount << endl;
			cout << "Salesman Count: " << salesmanCount << endl;
			cout << "SalesManager Count: " << salesManagerCount << endl;
			break;
		}
		case 3:
		{
			for (int i = 0; i < numEmployees; i++)
			{
				if(employees[i]->getDesignation() == "Manager" )
					employees[i]->display();
				if(employees[i]->getDesignation() == "Salesman")
					employees[i]->display();
				if(employees[i]->getDesignation()== "SalesManager")	
					employees[i]->display();
			}
			break;
		}
		default:
			cout << "Invalid choice." << endl;
		}
	}

	// Clean up allocated memory
	for (int i = 0; i < numEmployees; i++)
	{
		delete employees[i];
	}

	return 0;
}
