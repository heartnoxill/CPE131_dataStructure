#include <stdio.h>
#include <stdlib.h>

long factorial(long n);
int fibonacci(int n);
int gcd(int x, int y);
int pascal(int i,int n);

long factorial(long n)
{
    if(n<=1)
    {
        return 1;
    }
    return n*factorial(n-1);
}

int fibonacci(int n)
{
    if (n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int gcd(int x, int y)
{
    if (x==0)
        return y;
    if (y==0)
        return x;
    else
        return gcd(y,x%y);
}
int pascal(int i,int n)
{
    if (n==0)
    {
        return 0;
    }
    else
        return factorial(n)/factorial(i)/factorial(n-i);
}

int main()
{
    int menu, m, n;
    do
    {
        printf("Tester program for recursive function.\n");
        printf("1 - factorial\n");
        printf("2 - fibonacci\n");
        printf("3 - greatest common divisor\n");
        printf("4 - pascal\n");
        do
        {
            menu = 0;
            printf("Enter your choice (0 to exit): ");
            scanf("%d", &menu);
            fflush(stdin);
        }
        while(menu < 0 || menu > 4);
        if(menu == 0)
            exit(0);
        else if(menu == 1)
        {
            printf("Enter number: ");
            scanf("%d", &n);
            fflush(stdin);
            printf("factorial(%d) = %ld\n", n, factorial(n));
        }
        else if(menu == 2)
        {
            printf("Enter number: ");
            scanf("%d", &n);
            fflush(stdin);
            printf("fibonacci(%d) = %d\n", n, fibonacci(n));
        }
        else if(menu == 3)
        {
            printf("Enter number 1: ");
            scanf("%d", &m);
            fflush(stdin);
            printf("Enter number 2: ");
            scanf("%d", &n);
            fflush(stdin);
            printf("gcd(%d, %d) = %d\n", m, n, gcd(m, n));
        }
        else if (menu == 4)
        {
            int i,n;
            printf("Enter row:");
            scanf("%d",&n);
            fflush(stdin);
            printf("pascal(%d) is ",n);
            for (i=0; i<n+1; i++)
            {
                printf("%d ",pascal(i,n));
            }

        }
        printf("\nPress enter to continue...\n");
        getc(stdin);
    }
    while(menu != 0);
    return 0;
}
