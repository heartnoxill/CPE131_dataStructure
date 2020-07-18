#include "polish.h"
#include "stack_str_float_ADT.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Convert the infix notation to postfix
 * infix - the string that contains infix expression
 * postfix - the pointer to a variable for containing postfix
 */
void convertInfixToPostfix(char * infix, char * postfix)
{
    initStack();
    strcpy(postfix, "");            /* Initialize postfix to empty string */
    char * token = strtok(infix, " ");
    char * topToken;
    while(token != NULL)
    {
        if (isOpenParenthesis(token))
        {
            pushString(token);
            // TODO
        }
        else if (isCloseParenthesis(token))
        {
            token = popString();
            while (!isOpenParenthesis(token))
            {
                strcat(postfix, token);
                strcat(postfix, " ");
                token = popString();
            }
            // TODO
        }
        else if (isOperator(token))
        {
            topToken = topString(token);
            while (!stackEmpty(token) && priority(token) <= priority(topToken))
            {
                strcat(postfix, popString());
                strcat(postfix, " ");
                topToken = topString();
            }
            pushString(token);
            // TODO
        }
        else
        {
            strcat(postfix, token);
            strcat(postfix, " ");
        }

        token = strtok(NULL, " ");  /* next token */
    }
    while (stackSize() != 0)
    {
        // TODO
        strcat(postfix, popString());
        strcat(postfix, " ");
    }
}

/**
 * Arithematically evaluate the value of the postfix expression
 */
float evaluatePostfix(char * postfix) {
    initStack();
    float result = 0.0;
    float operand2;
    float operand1;
    char * token = strtok(postfix, " ");
    while(token != NULL)
    {
        if(isOperand(token))
        {
            float number = atof(token);
            pushFloat(number);
            // TODO
        }
        else
        {
            operand2 = popFloat();
            operand1 = popFloat();
            if (strcmp(token, "*") == 0)
                result = operand1 * operand2;
            if (strcmp(token, "/") == 0)
                result = operand1 / operand2;
            if (strcmp(token, "+") == 0)
                result = operand1 + operand2;
            if (strcmp(token, "-") == 0)
                result = operand1 - operand2;
            pushFloat(result);
            // TODO
        }

        token = strtok(NULL, " ");  /* next token */
    }
    // TODO
    popFloat();
    return result;
}

/**
 * Get the priority of the operator (more value is high priority)
 * return 2: (*) and (/)
 *        1: (+) and (-)
 *        0: Otherwise
 */
int priority(char * oper)
{
    if(strcmp(oper, "*") == 0 || strcmp(oper, "/") == 0)
        return 2;
    if(strcmp(oper, "+") == 0 || strcmp(oper, "-") == 0)
        return 1;
    return 0;
}

/**
 * Check whether the given string is operator or not
 * return 1: if the given string is (+), (-), (*) or (/)
 *        0: not the operator
 */
int isOperator(char * token)
{
    return strcmp(token, "+") == 0
            || strcmp(token, "-") == 0
            || strcmp(token, "*") == 0
            || strcmp(token, "/") == 0;
}

/**
 * Check whether the given string is operand or not
 * return 1: if the given string is operand
 *        0: not the operand
 */
int isOperand(char * token)
{
    return isOperator(token) ? 0 : 1;
}

/**
 * Check whether the given string is open parenthesis or not
 * return 1: if the given string is an open parenthesis
 *        0: not the operator
 */
int isOpenParenthesis(char * token)
{
    return strcmp(token, "(") == 0;
}

/**
 * Check whether the given string is close parenthesis or not
 * return 1: if the given string is an close parenthesis
 *        0: not the operator
 */
int isCloseParenthesis(char * token)
{
    return strcmp(token, ")") == 0;
}

/**
 * Check whether the opening-closing parentheses are all paired.
 * return 1: if all the parentheses are paired
 *        0: if not
 */
int isAllParenthesesPaired(char * str)
{
    int i;
    int len = strlen(str);
    for(i=0; i<len; i++)
    {
        if(str[i] == '(')
        {
            pushString("(");
        }
        else if(str[i] == ')' && !stackEmpty())
        {
            popString();
        }
        else if(str[i] == ')' && stackEmpty())
        {
            return 0;
        }
    }
    if(!stackEmpty())
    {
        initStack();
        return 0;
    }
    return 1;
}

/**
 * Add the space between operator, operand and parenthesis
 */
void addSpace(char * str)
{
    char buffer[200] = {0};
    char tmp[2] = {0};
    int len = strlen(str);
    int i;
    for(i=0; i<len; i++)
    {
        tmp[0] = str[i];
        if(isOperator(tmp) || isOpenParenthesis(tmp) || isCloseParenthesis(tmp))
        {
            strcat(buffer, " ");
            strcat(buffer, tmp);
            strcat(buffer, " ");
        }
        else if(str[i] != ' ')
        {
            strcat(buffer, tmp);
        }
    }
    strcpy(str, buffer);
}
