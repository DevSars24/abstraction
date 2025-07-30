# 🔒 C++ Abstraction-Based Company Employee System

This project demonstrates the concept of **Abstraction** in C++ using abstract classes and virtual functions. It simulates a simple company employee system where different types of employees share a common interface but implement their details differently.

---

## 📌 What is Abstraction?

> **Abstraction** means hiding internal implementation and showing only essential features.

In C++, abstraction is implemented using:
- **Abstract classes** (classes that contain at least one pure virtual function)
- **Pure virtual functions** (`= 0`) that force derived classes to define their own behavior

**Real-life example**:  
A "remote control" has buttons to turn the TV on/off — you don’t need to know how circuits inside work. You just use the interface.

---

## 🧠 How This Project Uses Abstraction

- `Employee` is an **abstract base class** with a pure virtual method `displayInfo()`.
- `Developer` and `Manager` are **derived classes** that implement their version of `displayInfo()`.
- We use `Employee*` (base class pointer) to refer to both `Developer` and `Manager` — this hides the implementation and uses only the abstract interface.

---

---

## 🧾 Code Overview

```cpp
class Employee {
public:
    virtual void displayInfo() = 0; // Pure virtual function
};

class Developer : public Employee {
    void displayInfo() override {
        // Developer-specific info
    }
};

class Manager : public Employee {
    void displayInfo() override {
        // Manager-specific info
    }
};


Employee* dev = new Developer(...);
Employee* mgr = new Manager(...);
dev->displayInfo();
mgr->displayInfo();


💻 Sample Output
yaml
Copy
Edit
--- Abstract Employee System ---

[Developer] Name: Alice, ID: 101
Programming Language: C++
------------------------------
[Manager] Name: Bob, ID: 201
Team Size: 5


