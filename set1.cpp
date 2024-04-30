#include <iostream>
#include <set>
#include <vector>

std::vector<int> findMissingNumbers(const std::vector<int>& nums) {
    // 创建一个set来存储数组中的数字
    std::set<int> numSet;
    for (int num : nums) {
        numSet.insert(num);
    }

    // 创建一个vector来存储缺失的数字
    std::vector<int> missingNumbers;

    // 遍历从1到n的整数，检查是否在set中
    for (int i = 1; i <= nums.size(); ++i) {
        // 如果数字不在set中，说明是缺失的数字
        if (numSet.find(i) == numSet.end()) {
            missingNumbers.push_back(i);
        }
    }

    return missingNumbers;
}

int main() {
    // 示例1
    std::vector<int> nums1 = {4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> result1 = findMissingNumbers(nums1);
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 示例2
    std::vector<int> nums2 = {1, 1};
    std::vector<int> result2 = findMissingNumbers(nums2);
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}