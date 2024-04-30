#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    cout << "vector example:" << endl;
    
    // 创建一个int类型向量 x
    vector<int> x; 

    // 创建一个包含100个元素的int类型向量 y
    vector<int> y(100);
    
    // 输出vector x的初始大小
    cout << "vector x size = " << x.size() <<endl;

    // 输出vector y的初始大小
    cout << "vector y size = " << y.size() <<endl;
    
    // 为向量x的前10个元素赋值
    for (int a = 0; a < 10; a++)
        x.push_back(a); // 在vector最后插入元素
    
    // 输出vector y扩展后的大小
    cout << "vector x size = " << x.size() <<endl;
 
    vector<int>::iterator p; // 使用迭代器访问 x 的值 
    cout << "all elements in x: ";
    for (p = x.begin(); p < x.end(); p++)
        cout << *p << " "; //依次输出每一个元素的值
    cout << endl;
    
    // 删除vector中第4个元素
    vector<int>::iterator pp = (x.begin()+3);
    cout << "before erase ";
    cout << "vector x[4] = " << *pp << endl; 
    x.erase(pp);
    cout << "after  erase ";
    cout << "vector x[4] = " << *pp << endl; 
    return 0;
}