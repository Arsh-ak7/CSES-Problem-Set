#include <iostream>
#include <math.h>

const long long MOD = 1000000007;

using namespace std;

long long power(long long x, long long y, long long p){
    long long res =1;
    x%=p;
    while (y)
    {
        if (y & 1)
            res = (res * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    scanf("%lld",&n);
    cout<<power(2,n,MOD);
}