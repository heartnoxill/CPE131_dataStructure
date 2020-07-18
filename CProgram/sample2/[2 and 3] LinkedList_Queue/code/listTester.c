#include <stdio.h>
#include <stdlib.h>
#include "listADT.h"

int main()
{
    int menu;
    int n, p;
    do
    {
        printf("Linked list tester program: \n");
        printf("(1) append\n");
        printf("(2) insert\n");
        printf("(3) delete\n");
        printf("(4) deleteAt\n");
        do
        {
            menu = 0;
            printf("Enter your choice (0 to exit): ");
            scanf("%d", &menu);
            fflush(stdin);
        } while(menu < 0 || menu > 4);
        if(menu == 0){
            exit(0);
        }
        else if(menu == 1)
        {
            printf("Enter number: ");
            scanf("%d", &n);
            fflush(stdin);
            if(appendValue(n) == 1)
            {
                printf("\n  [%d] is appended.\n", n);
            }
            else
            {
                printf("\n  Cannot append.\n");
            }
        }
        else if(menu == 2) {
            printf("Enter number: ");
            scanf("%d", &n);
            fflush(stdin);
            printf("Enter position: ");
            scanf("%d", &p);
            fflush(stdin);
            if(insertValue(n, p) == 1)
            {
                printf("\n  [%d] is inserted.\n", n);
            }
            else
            {
                printf("\n  Cannot insert.\n");
            }
        }
        else if(menu == 3) {
            printf("Enter number: ");
            scanf("%d", &n);
            fflush(stdin);
            if(deleteValue(n) == 1)
            {
                printf("\n  [%d] is deleted.\n", n);
            }
            else
            {
                printf("\n  Cannot delete.\n");
            }
        }
        else if(menu == 4) {
            printf("Enter position: ");
            scanf("%d", &p);
            fflush(stdin);
            if(deleteAt(p) == 1)
            {
                printf("\n  Number at %d is deleted.\n", p);
            }
            else
            {
                printf("\n  Cannot delete.\n");
            }
        }
        printf("  ");
        printList();
        printf("\n");
    } while(menu != 0);

    return 0;
}
