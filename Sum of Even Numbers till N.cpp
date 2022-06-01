#include<iostream>
using namespace std;


int main(){

       	/*
		Read input as specified in the question.
		Print output as specified in the question.
	*/
    int N;
    cin>>N;
    int num=1;
    int sum=0;
    while (num<=N){
        if (num%2==0){
           sum=sum+num;
        }
        num=num+1;
    }
    cout<<sum;
}
