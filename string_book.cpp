#include <iostream>
#include <string>

using namespace std;

struct Book
{
    string title;
    string author;
    string no;
    /* data */
};

int find(string s1, string s2)
{
    // s1 = "first second third";
    // s2 = "second";
    std::cout<<s1<<s2<<endl;
    int index = s1.find(s2,2);
    if(index < s1.length()){
        cout<<"Found at index : "<< index <<endl;
        return index;
    }
    else{
        cout<<"Not found"<<endl;
        return 0;

    }

}
int main() {
    Book book1;
    book1.author = "guo";
    book1.title = "math";
    book1.no = "12345678";
    // ("math","guo","1234567");
    Book book2;
    
    book2.author = "liu";
    book2.title = "c++ primier";
    book2.no = "7654321";
    // ("c++ primier","liu","7654321");

    string sub_no = "234";
    int index = find(book1.no, sub_no);
    if (index != -1)
    {
        cout << "Found at index : " << index << endl;
    }else{
        cout << "Not found" << index << endl;
    }

    

    return 0;
}