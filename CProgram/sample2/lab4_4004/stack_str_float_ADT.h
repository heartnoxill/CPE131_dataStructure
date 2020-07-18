/**
 *  stack_str_float.h
 *
 *  Header file defining the operations that one can
 *  do on a generic or abstract stack. The elements of
 *  the list can be pointers to anything.
 *
 *  This can be implemented in a variety of ways.
 *
 *  Created by Sally Goldin, 21 December 2011 for CPE113
 *  Edited by Chattriya Jariyavajee, 27 January 2016 for CPE113(AE)
 *  Edited by Chattriya Jariyavajee, 8 February 2017 for CPE131(AE)
 *  Edited by Chattriya Jariyavajee, 12 February 2018 for CPE131(AE) / CPE113(CPE)
 */

#ifndef STACK_STR_FLOAT_H
#define STACK_STR_FLOAT_H

/**
 * Push a string data item onto the stack
 * Arguments:
 *   str   -  String we want to add to stack
 * Returns 1 if successful, 0 if we have an overflow.
 */
int pushString(char* str);

/**
 * Removes and returns the top string item on the stack.
 * Returns NULL if the stack is empty.
 */
char * popString();

/**
 * Returns the top item on the stack without remove it.
 * Returns NULL if the queue is empty (that is, underflow).
 */
char * topString();

/**
 * Push a float data item onto the stack
 * Arguments:
 *   number  -  number we want to add to stack
 * Returns 1 if successful, 0 if we have an overflow.
 */
int pushFloat(float number);

/**
 * Removes and returns the top item on the stack.
 */
float popFloat();

/**
 * Returns the top item on the stack without remove it.
 */
float topFloat();

/**
 * Find out how many items are currently in the stack.
 * Returns 0 if the stack is empty.
 */
int stackSize();

/**
 * Check whether stack is empty or not
 * Returns 1 - stack is empty
 *         0 - stack is not empty
 */
int stackEmpty();

/**
 * Initialize the stack
 */
void initStack();

#endif
