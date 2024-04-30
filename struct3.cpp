#include <iostream>  
#include <string>  
  
// 定义User结构体  
struct User {  
    std::string name;  
    int age;  
};  
  
// 通过传值方式打印User信息  
void printUserByValue(User p) {  
    std::cout << "Name1: " << p.name << ", Age1: " << p.age << std::endl;  
    p.age = 28;
    std::cout << "Name1: " << p.name << ", Age1: " << p.age << std::endl;  
}  
  
// 通过传引用方式打印User信息  
void printUserByReference(const User& p) {  
    std::cout << "Name2: " << p.name << ", Age2: " << p.age << std::endl;  
}  
  
// 修改User年龄的函数，需要传引用才能修改原始数据  
void changeAgeByReference(User& p, int newAge) {  
    p.age = newAge;  
}  
  
int main() {  
    // 创建一个User对象  
    User User;  
    User.name = "Alice";  
    User.age = 30;  
  
    // 通过传值方式打印User信息  
    printUserByValue(User);  
  
    // 通过传引用方式打印User信息  
    printUserByReference(User);  
  
    // 修改User的年龄，并再次打印以验证修改是否生效  
    changeAgeByReference(User, 31);  
    printUserByReference(User);  
  
    return 0;  
}