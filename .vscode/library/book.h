#include <string>
#include <iostream>
#include "user.h"
#include <fstream>
using namespace std;

#pragma once


// 图书基类
class Book {
protected:
    std::string title_;
    std::string author_;
    int publicationYear_;
    bool isBorrowed_;
    std::string type_; // 新增属性，表示书籍类型

public:
    Book(std::string t, std::string a, int year, std::string typ) : title_(t), author_(a), publicationYear_(year), isBorrowed_(false), type_(typ) {}

    virtual ~Book() {};
    virtual void display() const{
        std::cout << "title_: " << title_ << ", author_: " << author_ << ", Year: " << publicationYear_;
        if (isBorrowed_) {
            std::cout << " (Borrowed)";
        }
        std::cout << ", type_: " << type_ << std::endl;
    }

    bool borrowBook(User *user) {
        if (!isBorrowed_ && (user->canBorrow(this) ) {
            isBorrowed_ = true;
            return true;
        }
        return false;
    }

    string get_title() {
        return this->title_;
    }
    
    void saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << title << " " << author << " " << publicationYear << " " << type;
        file.close();
    } else {
        std::cerr << "Unable to open file " << filename << std::endl;
    }



    bool returnBook() {
        if (isBorrowed_) {
            isBorrowed_ = false;
            return true;
        }
        return false;
    }
};

class Journal : public Book {
public:
    Journal(std::string t, std::string a, int year, string type) : Book(t, a, year,type) {}

    void display() const override {
        std::cout << "Journal: " << title << std::endl;
        Book::display();
    }
    ~Journal() override{};
};

class Paper : public Book {
public:
    Paper(std::string t, std::string a, int year, string type) : Book(t, a, year,type) {}

    void display() const override {
        std::cout << "Journal: " << title << std::endl;
        Book::display();
    }

    ~Paper() override{};
};

class EResource : public Book {
public:
    EResource(std::string t, std::string a, int year) : Book(t, a, year,type) {}

    void display() const override {
        std::cout << "E-Resource: " << title << std::endl;
        Book::display();
    }
    ~EResource() override{};
};
// // 电子书籍子类
// class EBook : public Book {
// public:
//     EBook(std::string t, std::string a, int id) : Book(t, a, id) {}

//     void display() const override {
//         std::cout << "This is a EBOOK:";
//         Book::display();
//     }
// };

// // 纸质书籍子类
// class PaperBook : public Book {
// public:
//     PaperBook(std::string t, std::string a, int id) : Book(t, a, id) {}

//     void display() const override {
//         std::cout << "This is a PaperBookPaperBook ";
//         Book::display();
//     }
// };