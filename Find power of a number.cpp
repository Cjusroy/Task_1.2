#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int a,b;
    cin>>a>>b;
    int n=1;
    int sum=1;
    if (b==0){
     cout<<1;
    }
    else{
      while(n<=b){
        int ans=sum*a;
            sum=ans;
        n=n+1;
       }
       cout<<sum;
    }
}
