#include<iostream>
#include <string>

using namespace std;

class Book
{
        public:
            Book(){
                price=0;
                title="math and logic";
            }
            void setprice(double a);
            double getprice();
            void settitle(string a);
            string gettitle();
            void display();
        private:
            double price;
            string title;    
            string bookno;
            string author;
};
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

void Book::settitle(string a)
{
    title = a;
}

string Book::gettitle()
{
    return title;
}


class Cplus:public Book
{
    public:
        Cplus(){
            // bookno="1234567890";
            // author="someone";
            style="programming";
        }
        // void display();
        string get_style();
    private:
        string style;
        // string author;
};

string Cplus::get_style()
{
    return this->style;
}

int main()
{
    Book cplus;
    cplus.display();
    cplus.settitle(" c++  prieme");
    cplus.setprice(3.69);
    cplus.display();
    

    Cplus plus;
    cout<<plus.get_style();

    return 0;
}
