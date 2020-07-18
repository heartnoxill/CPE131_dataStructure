#ifndef POLISH_H
#define POLISH_H

/**
 * Convert the infix notation to postfix
 * infix - the string that contains infix expression
 * postfix - the pointer to a variable for containing postfix
 */
void convertInfixToPostfix(char * infix, char * postfix);

/**
 * Arithematically evaluate the value of the postfix expression
 */
float evaluatePostfix(char * postfix);

/**
 * Get the priority of the operator (more value is high priority)
 * return 2: (*) and (/)
 *        1: (+) and (-)
 *        0: Otherwise
 */
int priority(char * oper);

/**
 * Check whether the given string is operator or not
 * return 1: if the given string is (+), (-), (*) or (/)
 *        0: not the operator
 */
int isOperator(char * token);

/**
 * Check whether the given string is operand or not
 * return 1: if the given string is operand
 *        0: not the operand
 */
int isOperand(char * token);

/**
 * Check whether the given string is open parenthesis or not
 * return 1: if the given string is an open parenthesis
 *        0: not the operator
 */
int isOpenParenthesis(char * token);

/**
 * Check whether the given string is close parenthesis or not
 * return 1: if the given string is an close parenthesis
 *        0: not the operator
 */
int isCloseParenthesis(char * token);

/**
 * Check whether the opening-closing parentheses are all paired.
 * return 1: if all the parentheses are paired
 *        0: if not
 */
int isAllParenthesesPaired(char * str);

/**
 * Add the space between operator, operand and parenthesis
 */
void addSpace(char * string);

#endif // POLISH_H
