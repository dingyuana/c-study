#include <iostream>
#include <string>
#include "book.h"
#include "user.h"
using namespace std;

int main() {
    // 创建图书对象
    Book novel("3 body", "liu cixing", 1);
    EBook ebook("C++ Primer", "Stanley B. Lippman", 2);

    // 创建用户对象
    Teacher teacher("Mr Ding", 1001);
    Student student("Student he", 2001);
    Employee employee("Employee wang", 3001);

    // 借书操作
    teacher.borrowBook(novel);
    student.borrowBook(ebook);

    // 还书操作
    teacher.returnBook(novel);
    student.returnBook(ebook);

    return 0;
}

// int main()
// {
//     string title = "book";
//     string author = "qst";
//     string type = "c++";
//     // Book *p = new Book();
//     Book *p = new Book(title);
//     p->display();
//     Literature test(title, author, type);
//     test.display();
//     p = &test;
//     p->display();
//     delete p;
//     return 0;
// }