#include <iostream>
#include <string>
using namespace std;


class User{
public:
    string name;
    string no;
public:
    //构造函数
    User(){}  

    // User(string name, string no){
    //     this->name = name;
    //     this->no = no;
    // }

// 函数名相同，但入参数量不同，是重载，并不是真正的多态
    User(string name, string no):name(name),no(no) {
    }      

    void display(){
        cout << "name:" << name << "  no:" << no << endl;
    }

    ~User(){
        std::cout << "this User destructor" << std::endl;
    }  
};

class Student:public User{
private:
    string college;
    string grade;
public:
    Student(){};
    Student(string name, string no,string college,string grade):User(name,no),college(college),grade(grade){};
    void borrow(){};

    void set_name(string name){
        this->name = name;
    }

    // 与基类函数名相同，是覆盖，也不算真正的多态
    void display()
    {
        cout << "name:" << name << "  no:" << no ;
        cout << "college:" << college << "  grade:" << grade << endl;
    }
    ~Student(){
        std::cout << "this Student destructor" << std::endl;
    };
  
};

class Teacher:public  User{
private:
    string college;
    string subject;
public:
    Teacher(){};
    void borrow(){};

};

class Client:public  User{
private:
    string college;
    string password;
public:
    Client(){};
};

int main(){
    User p2;
    // User p3("1321","2432");
    User *p1 = new User("wang","2432");
    p1->display();
    Student *s1 = new Student("wang","2432","qwe","ew32");
    s1->set_name("qst");
    s1->display();
    // Teacher t1;
    // t1.display();
    // Client c1;
    // c1.display();

    delete p1;
    delete s1;   
    // delete t1;
    // delete c1;


    return 0;
}