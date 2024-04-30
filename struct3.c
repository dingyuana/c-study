#include <iostream>
using namespace std;
struct P1{
	int i;
	char c;
	int j;
	char d;
}p1;

struct P2{
	int i;
	char c;
	char d;
	int j;
}p2;

struct P3{
	short w[3];
	char c[3];
}p3;

struct P4{
	short w[3];
	char *c[3];
}p4;

struct P5{
	struct P1 a[2];
	struct P2 *p;
}p5;

int main(){
	cout<<sizeof(p1)<<endl;
	cout<<sizeof(p2)<<endl;
	cout<<sizeof(p3)<<endl;
	cout<<sizeof(p4)<<endl;
	cout<<sizeof(p5)<<endl;
	
}