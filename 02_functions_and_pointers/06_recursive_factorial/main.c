#include <stdio.h>

long long factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("%d! = %lld\n", n, factorial(n));

    return 0;
}
