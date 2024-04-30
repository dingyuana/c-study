#include <iostream>
#include <string>

using namespace std;

int main()
{
    //声明字符串 
    string s1 ;  

    //初始化字符串
    s1 = "1234567890";   

    //遍历字符串
    for(int i=0; i<s1.length(); i++)   
        cout<<s1[i]<<" ";
    cout<<endl;

    //修改字符串中某个值
    s1[5] = '*';            
    cout<<s1<<endl;

    //截取字符串
    string s3;
    s3 = s1.substr(6, 6);
    cout<< s1 <<endl;
    cout<< s3 <<endl;
    
    //查找字符串
    string s4 = "789";
    int index = s1.find(s4,5);
    //length取字符串长度
    if(index < s1.length())
        cout<<"Found at index : "<< index <<endl;
    else
        cout<<"Not found"<<endl;
    return 0;
}