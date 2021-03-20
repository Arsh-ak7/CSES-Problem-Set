#include <iostream>
#include <math.h>

using namespace std;

int main(){
    long n;
    cin>>n;
    if(n==2 || n ==3)
    cout<<"NO SOLUTION";
    else {
        int odd =1,even = 2;
        if(n%2!=0){
            for(int i =0;i<=floor(n/2);i++){
            cout<<odd<<" ";
            odd+=2;
        }
         for(int i =0;i<floor(n/2);i++){
            cout<<even<<" ";
            even+=2;
        }
        } else {
            for(int i =0;i<floor(n/2);i++){
            cout<<even<<" ";
            even+=2;
        }
            for(int i =0;i<floor(n/2);i++){
            cout<<odd<<" ";
            odd+=2;
        }
        }
    }
}