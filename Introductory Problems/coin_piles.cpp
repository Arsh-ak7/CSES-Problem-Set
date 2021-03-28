#include <iostream>

using namespace std;

void swap(long long *a,long long *b){
    long long temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
       if(b>a)
       swap(a,b);
       if(a>2*b)
       cout<<"NO"<<endl;
       else {
        if((a+b)%3==0)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
       }
    }
}