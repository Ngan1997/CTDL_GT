#include<iostream>
using namespace std;
int main()
{
	int n;
    cin>>n;
  //  int temp=n;
    int dem=0;
    if(n==0)
    {
    	cout<<"do dai la 1";
    	return 0;
	}
    while(n!=0)
    {
    	n=n/10;
    	dem++;
    	
	}
	cout<<"do dai la "<<dem;
    
}
