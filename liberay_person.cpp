#include <iostream>
#include <string>
#include <vector>

// 抽象基类 User
class User {
public:
    User(const std::string& name, const std::string& id) : name_(name), id_(id) {}

    virtual ~User() {
        std::cout << "User destructor called" << std::endl;
    }

    // 虚函数，用于显示个人信息
    virtual void display() const {
        std::cout << "Name: " << name_ << ", ID: " << id_ << std::endl;
    }

    // 纯虚函数，子类需要实现
    virtual void borrowBook() = 0;

protected:
    std::string name_;
    std::string id_;
};

// 学生类继承自 User
class Student : public User {
public:
    Student(const std::string& name, const std::string& id, int studentId)
        : User(name, id), studentId_(studentId) {}

    void borrowBook() override {
        std::cout << name_ << " (Student ID: " << studentId_ << ") borrows a book." << std::endl;
    }

    ~ Student(){
        std::cout << "Student destructor called" << std::endl;
    }

private:
    int studentId_;
};

// 教工类继承自 User
class Faculty : public User {
public:
    Faculty(const std::string& name, const std::string& id, int facultyId)
        : User(name, id), facultyId_(facultyId) {}

    void borrowBook() override {
        std::cout << name_ << " (Faculty ID: " << facultyId_ << ") borrows a book." << std::endl;
    }

private:
    int facultyId_;
};

// 工作人员类继承自 User
class Staff : public User {
public:
    Staff(const std::string& name, const std::string& id, int staffId)
        : User(name, id), staffId_(staffId) {}

    void borrowBook() override {
        std::cout << name_ << " (Staff ID: " << staffId_ << ") borrows a book." << std::endl;
    }

private:
    int staffId_;
};


int main() {
    // 使用动态指针创建Student对象
    User* student = new Student("Alice", "S001", 1);
    student->display();
    student->borrowBook();

    // 使用动态指针创建Faculty对象
    User* faculty = new Faculty("Bob", "F001", 2);
    faculty->display();
    faculty->borrowBook();

    // 使用动态指针创建Staff对象
    User* staff = new Staff("Charlie", "W001", 3);
    staff->display();
    staff->borrowBook();

    // 释放分配的内存
    delete student;
    delete faculty;
    delete staff;

    return 0;
}