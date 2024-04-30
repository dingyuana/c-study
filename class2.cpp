#include <iostream>
using namespace std;

class Book{
private:
    std::string name;
    std::string author;
    double price;

public:
    Book();   //构造函数 1.与类名完全一样，2，系统会自动创造，3. 实例化时，这是第一运行的函数 4.没有返回值
    Book(string name, string author , double price); 
    ~Book();

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
// 1.默认构造函数
// Book::Book(){};

// 2.初始化列表成员函数：
Book::Book(){     
    name = "c++ primer";
    author = "Stanley B. Lippman";
    price = 55552.34;
};
Book::~Book(){
    std::cout << "this destroy fun" << std::endl;
 }
// 3. 带参数的构造函数：
// Book::Book(string name, string author , double price){
//     this->name = name;
//     this->author = author;  
//     this->price = price;
// };

// 4.使用初始化列表的构造函数：c++11鼓励这样的使用
Book::Book(string name, string author , double price)
    :name(name),author(author),price(price){};

// 5.带参数的构造函数
// Book::Book(string name, string author , double price):name("c++ primer"),author("Stanley B. Lippman"),price(12.34){};


void Book::display()
{
    cout << "name: " << this->name << endl;
    cout << "author: " << this->author << endl;
    cout << "price: " << this->price << endl;
}
void Book::set_price(double price){
    this->price = price;
}

double Book::get_price(){
    return price;
}

int main(){
    // Book book1("c++ primer", "Stanley B. Lippman", 12.34); //还是实例化，但是带入参，类似于函数调用
    // book1.display();
    // std::cout<<"=========================================================="<<endl;
    Book book2("java primer", "Stanley B. Lippman", 33.33);
    std::cout<<book2.get_author()<<endl;
    book2.display();
// Book book1;  //类的实例化，Book是类，book1是对象
    // int a;
    // Book book2;

    // book2.display();


    // book2.set_author("qst");
    // book2.set_price(100.0);
    // book2.display();

    // std::cout<<book1.get_author() << endl;
    // std::cout<<book1.get_price() << endl;
    
    // book1.name = " c++ primer";
    // book.author = " qst";

    // Book book3("c++ primer", "Stanley B. Lippman", 22.34); 
    // book3.display();

    // Book book4;
    // book4.display();
    // book4.set_author("qst");
    // book4.set_price(100.0);
    // book4.display();
    return 0;
}