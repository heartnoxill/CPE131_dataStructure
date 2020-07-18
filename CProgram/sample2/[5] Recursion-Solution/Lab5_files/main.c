#include <stdio.h>
#include <stdlib.h>

long factorial(long n);
int fibonacci(int n);
int gcd(int x, int y);

long factorial(long n) {
    if (n == 0)
        return 1;
    return n * factorial(n-1);
}

int fibonacci(int n) {
    if (n == 0 || n == 1) 
        return 1;
    return fibonacci(n-1) + fibonacci(n);
}

int gcd(int x, int y){
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

int main() {
    int menu, m, n;
    do
    {
        printf("Tester program for recursive function.\n");
        printf("1 - factorial\n");
        printf("2 - fibonacci\n");
        printf("3 - greatest common divisor\n");
        do
        {
            menu = 0;
            printf("Enter your choice (0 to exit): ");
            scanf("%d", &menu);
            fflush(stdin);
        } while(menu < 0 || menu > 3);
        if(menu == 0) exit(0);
        else if(menu == 1) {
            printf("Enter number: ");
            scanf("%d", &n);
            fflush(stdin);
            printf("factorial(%d) = %ld\n", n, factorial(n));
        }
        else if(menu == 2) {
            printf("Enter number: ");
            scanf("%d", &n);
            fflush(stdin);
            printf("fibonacci(%d) = %d\n", n, fibonacci(n));
        }
        else if(menu == 3) {
            printf("Enter number 1: ");
            scanf("%d", &m);
            fflush(stdin);
            printf("Enter number 2: ");
            scanf("%d", &n);
            fflush(stdin);
            printf("gcd(%d, %d) = %d\n", m, n, gcd(m, n));
        }
        printf("\nPress enter to continue...\n");
        getc(stdin);
    } while(menu != 0);
    return 0;
}
