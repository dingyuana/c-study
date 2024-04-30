#include <iostream>
#include <string>

using namespace std;

struct Books
{
    string bookname;
    string  bookno;
    string author;
};


class Book
{
    // 相比结构体，增加了数据私有的概念
private:
    string bookname;
    string  bookno;
    string author;

    // 相比结构体，增加了成员函数的概念，更符合对对象的理解
public:
    void set_bookno(string bookno);
    string get_bookno() const;

public:
    void set_name(string bookname)
    {
        bookname = bookname;
    }

    string get_name()
    {
        cout<<"bookname is :"<<bookname<<endl;
        return bookname;
    }
};

// 两种成员函数的实现方法
void Book::set_bookno(string bookno){
    bookno = bookno;
}

string Book::get_bookno() const
{
    return bookno;
}

int main(){

    // 1.面向过程编程思想
    // Books book1;
    // book1.bookname = "C++";
    // book1.bookno = "123456";
    // book1.author = "Li Lei";

    // cout<<book1.bookname<<endl;
    // cout<<book1.bookno<<endl;
    // cout<<book1.author<<endl;

    // 2. 面向对象的编程思想
    // 对象的实例化
    // 静态内存的定义方法
    Book book1;
    // 对于对象的数据操作，不再直接读写，而是通过开放的接口函数开实现
    book1.set_name("c primer");
    book1.get_name();

    // 错误语法，数据成员是私有的，不能访问
    // book1.bookname = "C++";
    // book1.bookno = "123456";

    // 动态内存，指针的方式定义，一定要回收
    Book *book2 = new Book;
    book2->set_name("math");
    book2->get_name();

    delete book2;

}