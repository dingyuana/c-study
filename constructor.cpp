#include<iostream>
using namespace std;

class Book
{
        public:
            // Book(){
            //     price=0;
            //     title="Book name ";
            // }
            Book(string a, double p  = 50.0);
            void setprice(double a);
            double getprice();
            void settitle(char* a);
            string gettitle();
            void display();
        private:
            double price;
            string title;
            string bookno;
            string author;
};

Book::Book(string a, double p)
{
    title = a;
    price = p;
}

void Book::display()
{
    cout<<"The price of "<<title<<" is $"<<price<<endl;
}

void Book::setprice(double a)
{
    price = a;
}

double Book::getprice()
{
    return price;
}

void Book::settitle(char* a)
{
    title = a;
}

string Book::gettitle()
{
    return title;
}

int main()
{
    // Book cplus;
    // cplus.display();

    Book Alice("adsfa", 12.3);
    Alice.display();
    Alice.settitle("Alice in Wonderland");
    Alice.setprice(29.9);
    Alice.display();
    Book Harry("Harry Potter", 49.9);
    Harry.display();

    Book Gone("Gone with the Wind");
    Gone.display();
    return 0;
}
