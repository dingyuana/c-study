#include <iostream>
#include <string>
// #include "book.h"

#pragma once
// 用户基类
class User {
protected:
    std::string name;
    int userID;

public:
    User(std::string n, int id) : name(n), userID(id) {}

    void borrowBook(Book* book){
                if (canBorrowBook(book)) {
            // 借书的具体实现...
            std::cout << name << " 正在借阅 " << book->getTitle() << std::endl;
        } else {
            std::cout << name << " 没有权限借阅这本书。" << std::endl;
        }
    }; // 纯虚函数，确保User是一个抽象基类
    virtual void returnBook(Book& book) = 0;
    virtual bool canBorrowBook(Book* book) const = 0; // 检查用户是否有权借阅图书

    void display() const {
        std::cout << "User name: " << name << ", User ID: " << userID << std::endl;
    }
};

// 教师子类
class Teacher : public User {
public:
    Teacher(std::string n, int id) : User(n, id) {}

    void borrowBook(Book& book) override {
        std::cout << "Teacher " << name << " is borrowing book." << std::endl;
        // 借书的具体实现...
    }

    void returnBook(Book& book) override {
        std::cout << "Teacher " << name << " is returning book " << std::endl;
        // 还书的具体实现...
    }
};

// 学生子类
class Student : public User {
public:
    Student(std::string n, int id) : User(n, id) {}

    void borrowBook(Book& book) override {
        std::cout << "Student " << name << " is borrowing book" << std::endl;
        // 借书的具体实现...
    }

    void returnBook(Book& book) override {
        std::cout << "Student " << name << " is returning book " << std::endl;
        // 还书的具体实现...
    }
};

// 员工子类
class Employee : public User {
public:
    Employee(std::string n, int id) : User(n, id) {}

    void borrowBook(Book& book) override {
        std::cout << "Employee " << name << " is borrowing book" << std::endl;
        // 借书的具体实现...
    }

    void returnBook(Book& book) override {
        std::cout << "Employee " << name << " is returning book " << std::endl;
        // 还书的具体实现...
    }
};

