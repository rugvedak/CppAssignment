#include <iostream>
using namespace std;

class Employee
{
protected:
    int id;
    float salary;

public:
    Employee() : id(0), salary(0.0) {}
    Employee(int empId, float empSalary) : id(empId), salary(empSalary) {}

    int getId() const { return id; }
    float getSalary() const { return salary; }


    void setId(int id) {
	    this->id = id;
    }


    void setSalary(float salary) {
    	this->salary = salary;
    }

    virtual void accept()
    {
        cout << "Enter employee ID: ";
        cin >> id;
        cout << "Enter employee salary: ";
        cin >> salary;
    }

    virtual void display() 
    {
        cout << "Employee ID: " << id << "\n";
        cout << "Employee Salary: " << salary << "\n";
    }
};
class Manager : virtual public Employee
{
private:
    float bonus;

public:
    Manager() : bonus(0.0) {}
    Manager(int empId, float empSalary, float empBonus) : Employee(empId, empSalary), bonus(empBonus) {}

    float getBonus() const { return bonus; }


    void setBonus(float bonus) {
	    this->bonus = bonus;
    }

    void accept() override{
        Employee::accept();
        accept_manager();

    }
    void display() override{
        Employee::display();
        display_manager();
    }
    void accept_manager()
    {
        cout << "Enter manager bonus: ";
        cin >> bonus;
    }

    void display_manager() const
    {
       
        cout << "Manager Bonus: " << bonus << "\n";
    }
};

class Salesman : virtual public Employee
{
private:
    float comm;

public:
    Salesman() : comm(0.0) {}
    Salesman(int empId, float empSalary, float empComm) : Employee(empId, empSalary), comm(empComm) {}

    float getComm() const { return comm; }


    void setComm(float comm) {
	    this->comm = comm;
    }
    void accept()override{
        Employee::accept();
        accept_salesman();
    }
    void display()override
    {
        Employee::display();
        display_salesman();
    }

    void accept_salesman()
    {
     
        cout << "Enter salesman commission: ";
        cin >> comm;
    }

    void display_salesman() const
    {
        
        cout << "Salesman Commission: " << comm << "\n";
    }
};
class SalesManager : public Manager, public Salesman {
public:
    SalesManager(int id, double salary, double bonus, double commission)
        : Manager(id, salary, bonus), Salesman(id, salary, commission) {}

   void accept() override{
     Employee::accept();
     Manager::accept();
     Salesman::accept();
   }

   void display() override{
    Employee::display();
    Manager::display();
    Salesman::display();
   }
};

int MenuChoice()
{
        std::cout << "\nMenu:\n";
        std::cout << "1. Accept Employee\n";
        std::cout << "2. Display Employee Counts by Designation\n";
        std::cout << "3. Display Employees by Designation\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";
        int choice;
        std::cin >> choice;

        return choice;
}
int main()
{
    const int MAX_EMPLOYEES = 10;
    Employee* employees[MAX_EMPLOYEES] = {nullptr};

    int numEmployees = 0;

 while (true) {
        
        int choice = MenuChoice();
     
        if (choice == 4) {
            break;
        }

        switch (choice) {
            case 1: {
                if (numEmployees >= MAX_EMPLOYEES) {
                    std::cout << "Maximum employees reached." << std::endl;
                    break;
                }

                std::cout << "Select Employee Type (1 for Manager, 2 for Salesman, 3 for SalesManager): ";
                int empType;
                std::cin >> empType;

                if (empType == 1) {
                    int id;
                    double salary, bonus;
                    std::cout << "Enter ID: ";
                    std::cin >> id;
                    std::cout << "Enter Salary: ";
                    std::cin >> salary;
                    std::cout << "Enter Bonus: ";
                    std::cin >> bonus;
                    employees[numEmployees++] = new Manager(id, salary, bonus);
                } else if (empType == 2) {
                    int id;
                    double salary, commission;
                    std::cout << "Enter ID: ";
                    std::cin >> id;
                    std::cout << "Enter Salary: ";
                    std::cin >> salary;
                    std::cout << "Enter Commission: ";
                    std::cin >> commission;
                    employees[numEmployees++] = new Salesman(id, salary, commission);
                } else if (empType == 3) {
                    int id;
                    double salary, bonus, commission;
                    std::cout << "Enter ID: ";
                    std::cin >> id;
                    std::cout << "Enter Salary: ";
                    std::cin >> salary;
                    std::cout << "Enter Bonus: ";
                    std::cin >> bonus;
                    std::cout << "Enter Commission: ";
                    std::cin >> commission;
                    employees[numEmployees++] = new SalesManager(id, salary, bonus, commission);
                } else {
                    std::cout << "Invalid Employee Type" << std::endl;
                }
                break;
            }
            case 2: {
                int managerCount = 0, salesmanCount = 0, salesManagerCount = 0;
                for (int i = 0; i < numEmployees; i++) {
                    if (dynamic_cast<Manager*>(employees[i])) {
                        managerCount++;
                    } else if (dynamic_cast<Salesman*>(employees[i])) {
                        salesmanCount++;
                    } else if (dynamic_cast<SalesManager*>(employees[i])) {
                        salesManagerCount++;
                    }
                }
                std::cout << "Manager Count: " << managerCount << std::endl;
                std::cout << "Salesman Count: " << salesmanCount << std::endl;
                std::cout << "SalesManager Count: " << salesManagerCount << std::endl;
                break;
            }
            case 3: {
                std::cout << "Select Designation (1 for Manager, 2 for Salesman, 3 for SalesManager): ";
                int empType;
                std::cin >> empType;

                for (int i = 0; i < numEmployees; i++) {
                    if ((empType == 1 && dynamic_cast<Manager*>(employees[i])) ||
                        (empType == 2 && dynamic_cast<Salesman*>(employees[i])) ||
                        (empType == 3 && dynamic_cast<SalesManager*>(employees[i]))) {
                        employees[i]->display();
                    }
                }
                break;
            }
            default:
                std::cout << "Invalid choice." << std::endl;
        }
    }

    // Clean up allocated memory
    for (int i = 0; i < numEmployees; i++) {
        delete employees[i];
    }

    return 0;
}
