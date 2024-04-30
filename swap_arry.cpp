#include <iostream>

void swapWithArray(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main() {
    int arr[2] = {10, 20};  //数组的初始化
    // arr[0]=12;
    // arr[1]=13;
    // arr[2]=14;   //错误的语句

    std::cout << "before: arr[0] = " << arr[0] << ", arr[1] = " << arr[1] << std::endl;
    swapWithArray(arr, 0, 1);
    std::cout << "after: arr[0] = " << arr[0] << ", arr[1] = " << arr[1] << std::endl;

    return 0;
}