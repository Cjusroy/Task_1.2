#include<iostream>
using namespace std;


int main(){
  int S,E,W;
    cin>>S>>E>>W;
    while(S<=E){
       int temp= ((5.0/9) *(S-32));
       cout<<S<<" "<<temp<<endl;
           S=S+W;
    }
}
