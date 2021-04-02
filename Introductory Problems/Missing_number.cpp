#include <stdio.h>

int main(void)
{
    long long int n, t;
    long long int sum = 0;
    scanf("%lld", &n);

    for (long long int i = 0; i < n - 1; i++)
    {
        scanf("%lld", &t);
        sum += t;
    }
    printf("%lld", (-sum + (n * (n + 1) / 2)));
}