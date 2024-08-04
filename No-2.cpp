#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Employee 
{
private:
    int id;
    string name;
    double salary;

public:
    Employee(int emp_id, const string &emp_name, double emp_salary)
        : id(emp_id), name(emp_name), salary(emp_salary) {}

    double getSalary() const {
        return salary;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary <<endl;
    }
};

void inputEmployeeData(vector<Employee> &employees) {
    int id;
    string name;
    double salary;
    char choice;

    do {
        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore(); // to ignore the newline character left by std::cin
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Employee Salary: ";
        cin >> salary;

        employees.emplace_back(id, name, salary);

       cout << "Do you want to add another employee? (y/n): ";
       cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}

void displayEmployeesWithSalaryGreaterThan(const vector<Employee> &employees, double amount) {
    for (const auto &employee : employees) {
        if (employee.getSalary() > amount) {
            employee.display();
        }
    }
}

int main() {
    vector<Employee> employees;
    inputEmployeeData(employees);

    double amount;
    cout << "Enter the salary amount to filter employees: ";
    cin >> amount;

    cout << "Employees with salary greater than " << amount << ":\n";
    displayEmployeesWithSalaryGreaterThan(employees, amount);

    return 0;
}
