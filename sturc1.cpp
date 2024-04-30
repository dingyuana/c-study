#include <iostream>  
#include <string>  
  
// 定义Student结构体  
struct Student {  
    std::string name;  
    int age;  
    float score;  
};  
  
int main() {  
    // 创建一个Student对象并初始化  
    Student student = {"zhangsan", 20, 90.5};  
  
    // 显示学生信息  
    std::cout << "name: " << student.name << std::endl;  
    std::cout << "age: " << student.age << std::endl;  
    std::cout << "score: " << student.score << std::endl;  
  
    return 0;  
}