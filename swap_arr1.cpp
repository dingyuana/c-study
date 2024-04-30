#include <iostream>
using namespace std;
 
#include <iomanip>
using std::setw;
int main ()
{
   int n[2]; 
   
   std::cout << "pls input first arr:"<< std::endl;
   cin>>n[0];
   std::cout << "pls input second arr:"<< std::endl;
   cin>>n[1];
    
    int s=0;
    s=n[0];
    n[0]=n[1];    
    n[1]=s;    
 
   // 输出数组中每个元素的值                     
   for ( int j = 0; j < 2; j++ )
   {
      cout << setw( 7 )<< j << setw( 13 ) << n[ j ] << endl;
   }
 
   return 0;
}