#include <iostream>
#include<string>
using namespace std;
// #include <map>

int main() {
    string id;
    std::cout << "����ͼ��ID: ";
    std::cin.ignore();
    std::getline(std::cin, id);

    std::cout << "����ͼ�����: ";
    std::string title;
    std::cin.ignore();
    std::getline(std::cin, title);

    std::string author;
    std::cout << "����ͼ������: ";
    std::cin.ignore();
    std::getline(std::cin, author);

    
    int quantity;
    std::cout << "����ͼ������: ";
    std::cin >> quantity;


    return 0;
}
