#ifndef LIST_H
#define LIST_H

typedef struct _node
{
    int value;
    struct _node * next;
} Node;

/* return 1 if the list is empty
 * return 0 if the list has nodes.
 */
int isEmptyList();

/* print all numbers in list.
 */
void printList();

/* append the number to the tail of the list.
 * return 1 if the number successfully append
 * return 0 if not
 */
int appendValue(int n);

/* insert the number to the list at the specific position.
 * note that: p is the position counts from 0
 * return 1 if the number n successfully inserted at the position p.
 * return 0 if the number n could not be inserted or the position p is out of range.
 */
int insertValue(int n, int p);

/* delete the number n from the list
 * note that: n is the number that stores in the list.
 * return 1 if the number n is in the list and the deletion is successful.
 * return 0 if the number n is not in the list or the deletion is unsuccessful.
 */
int deleteValue(int n);

/* delete the number at position p from the list
 * note that: p is the position counts from 0.
 * return 1 if the position p is in range and successfully deleted.
 * return 0 if the position p is out of range.
 */
int deleteAt(int p);

/* delete all numbers from the list
 */
void deleteAll();

/* retrieve the value at position p from the list
 * note that: p is the position counts from 0.
 * return data at position p
 * return 0 if the position p is out of range.
 */
int valueAt(int p);

#endif // LIST_H
