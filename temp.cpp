#include <iostream>
#include<string>
using namespace std;
// #include <map>

int main() {
    string id;
    std::cout << "输入图书ID: ";
    std::cin.ignore();
    std::getline(std::cin, id);

    std::cout << "输入图书标题: ";
    std::string title;
    std::cin.ignore();
    std::getline(std::cin, title);

    std::string author;
    std::cout << "输入图书作者: ";
    std::cin.ignore();
    std::getline(std::cin, author);

    
    int quantity;
    std::cout << "输入图书数量: ";
    std::cin >> quantity;


    return 0;
}
