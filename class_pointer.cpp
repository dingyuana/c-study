#include <iostream>
using namespace std;

class Book{
private:
    std::string name;
    std::string author;
    double price;

public:
    Book(string name, string author , double price);    //构造函数 1.与类名完全一样，2，系统会自动创造，3. 实例化时，这是第一运行的函数4、无返回值
    ~Book();    // 析构函数，1、命名方式 2、最后运行，3、唯一的，不可重构 4、无返回值
    void set_author(string author){
        this->author = author;
    }

    string get_author(){
        return author;
    }

    void display();


    void set_price(double price);
    double get_price();
};

Book::~Book(){
    std::cout<<" objecet is destroyed"<<endl;
}

// Book::Book(){     
//     name = "c++ primer";
//     author = "Stanley B. Lippman";
//     price = 12.34;
// }
Book::Book(string name, string author , double price){
    this->name = name;
    this->author = author;  
    this->price = price;
}
void Book::display()
{
    cout << "name: " << name << endl;
    cout << "author: " << author << endl;
    cout << "price: " << price << endl;
}
void Book::set_price(double price){
    this->price = price;
}

double Book::get_price(){
    return price;
}

int main(){
    Book *book1 = new Book("c++ primer", "Stanley B. Lippman", 12.34);
    // Book book1("c++ primer", "Stanley B. Lippman", 12.34); //还是实例化，但是带入参，类似于函数调用
    book1->display();
    std::cout<<"=========================================================="<<endl;


    Book *book2= new Book("java primer", "Stanley B. Lippman", 12.34);
    book2->display();
    // Book book1;  //类的实例化，Book是类，book1是对象
    // int a;
    // Book book2;

    // book2.display();


    book2->set_author("qst");
    book2->set_price(100.0);
    book2->display();

    // 调用析构函数，这是必须的
    // delete book2;

    // std::cout<<book1.get_author() << endl;
    // std::cout<<book1.get_price() << endl;
    
    // book1.name = " c++ primer";
    // book.author = " qst";

    return 0;
}