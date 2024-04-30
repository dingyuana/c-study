#include <iostream>
#include <set>

int main() {
    std::set<int> uniqueNumbers;
    int arr[] = {1, 2, 3, 2, 1, 5, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 插入数组中的元素到 set，自动去除重复项
    for (int i = 0; i < n; i++) {
        uniqueNumbers.insert(arr[i]);
        uniqueNumbers.insert(arr[i]);
    }

    // 输出唯一数字
    std::cout << "Unique numbers in the array: ";
    for (int num : uniqueNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
