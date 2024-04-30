#include <iostream>
#include <string>
#include <vector>

// 图书基类 Book
class Book {
public:
    Book(const std::string& title) : title_(title) {}

    virtual ~Book() {
        std::cout << "Book destructor called" << std::endl;
    }

    // 虚函数，用于显示图书信息
    virtual void display() const {
        std::cout << "Title: " << title_ << std::endl;
    }

public:
    std::string title_;
};

// 文学类书继承自 Book
class Literature : public Book {
public:
    Literature(const std::string& title) : Book(title) {}
};

// 编程类书继承自 Book
class Programming : public Book {
public:
    Programming(const std::string& title) : Book(title) {}
};

// 艺术类书继承自 Book
class Art : public Book {
public:
    Art(const std::string& title) : Book(title) {}
};

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
    virtual void borrowBook(const Book& book) = 0;

protected:
    std::string name_;
    std::string id_;
};

// 学生类继承自 User
class Student : public User {
public:
    Student(const std::string& name, const std::string& id, int studentId)
        : User(name, id), studentId_(studentId) {}

    void borrowBook(const Book& book) override {
        if (dynamic_cast<const Programming*>(&book)) {
            std::cout << name_ << " (Student ID: " << studentId_ << ") borrows a Programming book: " << book.title_ << std::endl;
        } else {
            std::cout << name_ << " (Student ID: " << studentId_ << ") cannot borrow this type of book." << std::endl;
        }
    }

private:
    int studentId_;
};

// 教工类继承自 User
class Faculty : public User {
public:
    Faculty(const std::string& name, const std::string& id, int facultyId)
        : User(name, id), facultyId_(facultyId) {}

    void borrowBook(const Book& book) override {
        std::cout << name_ << " (Faculty ID: " << facultyId_ << ") borrows a book: " << book.title_ << std::endl;
    }

private:
    int facultyId_;
};


int main() {
    // 创建用户对象
    User* student = new Student("Alice", "S001", 1);
    User* faculty = new Faculty("Bob", "F001", 2);

    // 创建图书对象
    Literature literature("Pride and Prejudice");
    Programming programming("Mastering C++");
    Art art("The Art of Painting");

    // 学生尝试借阅不同类型的图书
    std::cout << "Student tries to borrow books:" << std::endl;
    student->borrowBook(literature);  // 学生不能借阅文学类的书
    student->borrowBook(programming);  // 学生可以借阅编程类的书
    student->borrowBook(art);  // 学生不能借阅艺术类的书

    // 教工尝试借阅不同类型的图书
    std::cout << "\nFaculty tries to borrow books:" << std::endl;
    faculty->borrowBook(literature);  // 教工可以借阅文学类的书
    faculty->borrowBook(programming);  // 教工可以借阅编程类的书
    faculty->borrowBook(art);  // 教工可以借阅艺术类的书

    // 释放分配的内存
    delete student;
    delete faculty;

    return 0;
}