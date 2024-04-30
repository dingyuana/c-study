
#include <iostream>
using namespace std;

class Book {
private:
    std::string title;  // 书名
    std::string isbn;   // 书号
    std::string author; // 作者
    double price;       // 单价
    int quantity;      // 数量
// };

// class Book {
public:
    // 构造函数
    Book(std::string title, std::string isbn, std::string author, double price, int quantity);

    // 获取书名的函数
    std::string getTitle();
    // 设置书名的函数
    void setTitle(std::string title);

    // 获取书号的函数
    std::string getIsbn();
    // 设置书号的函数
    void setIsbn(std::string isbn);

    // 获取作者的函数
    std::string getAuthor();
    // 设置作者的函数
    void setAuthor(std::string author);

    // 获取单价的函数
    double getPrice();
    // 设置单价的函数
    void setPrice(double price);

    // 获取数量的函数
    int getQuantity();
    // 设置数量的函数
    void setQuantity(int quantity);

    // 输出图书信息的函数
    void printInfo();
};



Book::Book(std::string title, std::string isbn, std::string author, double price, int quantity) {
    this->title = title;
    this->isbn = isbn;
    this->author = author;
    this->price = price;
    this->quantity = quantity;
}

std::string Book::getTitle() {
    return title;
}

void Book::setTitle(std::string title) {
    this->title = title;
}

std::string Book::getIsbn() {
    return isbn;
}

void Book::setIsbn(std::string isbn) {
    this->isbn = isbn;
}

std::string Book::getAuthor() {
    return author;
}

void Book::setAuthor(std::string author) {
    this->author = author;
}

double Book::getPrice() {
    return price;
}

void Book::setPrice(double price) {
    this->price = price;
}

int Book::getQuantity() {
    return quantity;
}

void Book::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Book::printInfo() {
    std::cout << "title: " << title << std::endl;
    std::cout << "isbn: " << isbn << std::endl;
    std::cout << "isbn: " << author << std::endl;
    std::cout << "price: " << price << std::endl;
    std::cout << "quantity: " << quantity << std::endl;
}