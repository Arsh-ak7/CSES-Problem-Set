#include <iostream>
#include <math.h>

using namespace std;

int main(){
    long long n;
    cin>>n;
    long long pow_of_five = 0;
    int i = 1;
    long long div;
    while((div=pow(5,i))<=n){
        pow_of_five+=floor(n/div);
        i++;
    }
    cout<<pow_of_five;
}