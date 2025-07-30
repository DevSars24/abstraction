#include <iostream>
using namespace std;

// Abstract Base Class
class Employee {
protected:
    string name;
    int id;

public:
    // Constructor to initialize employee name and ID
    Employee(string empName, int empId) : name(empName), id(empId) {}

    // Pure virtual function - makes this class abstract
    // Every derived class must implement this
    virtual void displayInfo() = 0;
};

// Developer class inherits from Employee
class Developer : public Employee {
private:
    string programmingLanguage;

public:
    // Constructor to initialize Developer with name, id, and programming language
    Developer(string empName, int empId, string lang)
        : Employee(empName, empId), programmingLanguage(lang) {}

    // Overriding the abstract function from Employee class
    void displayInfo() override {
        cout << "[Developer] Name: " << name << ", ID: " << id << endl;
        cout << "Programming Language: " << programmingLanguage << endl;
    }
};

// Manager class inherits from Employee
class Manager : public Employee {
private:
    int teamSize;

public:
    // Constructor to initialize Manager with name, id, and team size
    Manager(string empName, int empId, int size)
        : Employee(empName, empId), teamSize(size) {}

    // Overriding the abstract function from Employee class
    void displayInfo() override {
        cout << "[Manager] Name: " << name << ", ID: " << id << endl;
        cout << "Team Size: " << teamSize << endl;
    }
};

int main() {
    cout << "--- Abstract Employee System ---" << endl << endl;

    // Creating objects of Developer and Manager using base class pointers
    // This is abstraction + polymorphism in action
    Employee* dev = new Developer("Alice", 101, "C++"); // dev points to a Developer object
    Employee* mgr = new Manager("Bob", 201, 5);         // mgr points to a Manager object

    // Call overridden methods - actual implementation is decided at runtime
    dev->displayInfo(); // Calls Developer::displayInfo()
    cout << "------------------------------" << endl;
    mgr->displayInfo(); // Calls Manager::displayInfo()

    // Clean up memory (important when using new)
    delete dev;
    delete mgr;

    return 0;
}
