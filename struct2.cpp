#include <iostream>  
#include <string>  
  
// 定义Student结构体  
struct Student {  
    std::string name;  
    int age;  
    float score;  
};  
  
int main() {  
    int a=1;
    int *p=&a;
    // 创建一个Student对象并初始化  
    Student student = {"张三", 20, 90.5};  
  
    // 使用指针指向Student对象  
    Student* studentPtr = &student;  
  
    // 使用指针访问成员变量并显示信息  
    std::cout << "姓名: " << studentPtr->name << std::endl;  
    std::cout << "年龄: " << studentPtr->age << std::endl;  
    std::cout << "成绩: " << studentPtr->score << std::endl;  
  
    return 0;  
}