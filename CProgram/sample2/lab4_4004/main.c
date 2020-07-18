#include "polish.h"
#include "stack_str_float_ADT.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main () {
    char postfix[80] = {0};
    char infix[80] = {0};
    printf("Enter an infix notation: ");
    scanf("%[^\n]", infix);
    if(!isAllParenthesesPaired(infix))
    {
        printf("The opening-closing parentheses of the given infix are not paired.\n");
        return -1;
    }
    
    /* add space between operator, parenthesis and operand for simpler string tokenizing */
    addSpace(infix);
    printf("infix with space: %s\n", infix);

    convertInfixToPostfix(infix, postfix);
    printf("The postfix notation: %s\n", postfix);

    float result = evaluatePostfix(postfix);
    printf("The result is %g\n", result);

    return 0;
}
