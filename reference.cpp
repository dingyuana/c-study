#include <iostream>

void modify(int value){
    value += 10;
}

// 函数使用引用传递参数
void modifyValue(int& refValue) {
    refValue += 10;
}

// 函数使用指针传递参数
void modifyValueWithPointer(int* ptrValue) {
    *ptrValue += 10;
}

int main() {
    int value = 50;

    std::cout << "origin: " << value << std::endl;

    modify(value);
    std::cout << "origined: " <<value<< std::endl;


    // 使用指针修改值
    int* ptr = &value;
    modifyValueWithPointer(ptr);
    std::cout << "pointed: " << value << std::endl;

    
    // 使用引用修改值
    modifyValue(value);
    std::cout << "referenced: " << value << std::endl;

    return 0;
}