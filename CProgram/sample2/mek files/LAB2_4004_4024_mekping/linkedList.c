#include "listADT.h"
#include <stdio.h>
#include <stdlib.h>

Node * head = NULL;
int countNode = 0;

/* return 1 if the list is empty
 * return 0 if the list has nodes.
 */
int isEmptyList()
{
    return countNode == 0;
}

/* print all numbers in list.
 */
void printList()
{
    printf("The number in list: ");
    Node* currNode = head;
    while(currNode != NULL)
    {
        printf("%d -> ", currNode->value);
        currNode = currNode->next;
    }
    printf("NULL\n");
}

/* append the number to the tail of the list.
 * return 1 if the number successfully append
 * return 0 if not
 */
int appendValue(int n)
{
    /* create new node */
    Node* newNode = calloc(1, sizeof(Node));
    /* if unable to insert because the memory allocation fail. */
    if(newNode == NULL)
    {
        return 0;
    }
    /* if able to insert */
    else
    {
        newNode->value = n;
        newNode->next = NULL;
        if(isEmptyList()) /* this is an empty list */
        {
            head = newNode;
        }
        else
        {
            Node * currNode = head;
            while(currNode->next != NULL)
            {
                currNode = currNode->next;
            }
            currNode->next = newNode;
        }
        countNode = countNode + 1;
        return 1;
    }
}

/* insert the number to the list at the specific position.
 * note that: position counts from 0
 * return 1 if the number n could be inserted at the position p.
 * return 0 if the number n could not be inserted at the position p.
 */
int insertValue(int n, int p)
{
    /* create new node */
    Node* newNode = calloc(1, sizeof(Node));

    /* if unable to insert because the memory allocation fail or p is over the length of the list. */
    if(newNode == NULL || countNode < p)
    {
        return 0;
    }
    /* if able to insert */
    else
    {
        newNode->value = n;
        newNode->next = NULL;
        if(p == 0) /* insert at zeroth position */
        {
            // set the next of new node to the next of head
            newNode->next = head;
            // set the head of the list to new node
            head = newNode;
        }
        else /* insert at other position */
        {
            Node * currNode = head;
            int i;
            for(i=0; i<p-1; i++)
            {
                currNode = currNode->next;
            }
            newNode->next = currNode->next;
            currNode->next = newNode;
        }
        countNode = countNode + 1;
        return 1;
    }
}

/* delete the number n from the list
 * note that: n is the number that stores in the list.
 * return 1 if the number n is in the list and the deletion is successful.
 * return 0 if the number n is not in the list or the deletion is unsuccessful.
 */
int deleteValue(int n)
{
    /* search for a deleting node which its value equals to n.
     * currNode will store the address of the node to be deleted.
     * prevNode will store the address of the predecessor of currNode.
     */
    Node * currNode = head;
    Node * predNode;
    while(currNode != NULL && currNode->value != n)
    {
        predNode = currNode;
        currNode = currNode->next;
    }

    /* check whether the deleting node exists or not. */
    if(currNode == NULL) /* deleting node does not exist. */
    {
        return 0;
    }
    else
    {
        if(currNode == head) /* case 1: delete the first node */
        {
            Node* deleteNode = head;
            head = head->next;
            free(deleteNode);
        }
        else /* case 2: delete the node that has the predecessor node. */
        {
            predNode->next = currNode->next;
            free(currNode);
        }
		countNode = countNode-1; /* decrease the countNode */
        return 1;
    }
}

/* delete the number at position p from the list
 * note that: p is the position counts from 0.
 * return 1 if the position p is in range and successfully deleted.
 * return 0 if the position p is out of range.
 */
int deleteAt(int p)
{
    Node* newNode = calloc(1, sizeof(Node));
    /* case 1: cannot delete */
    if(p > countNode-1 || p < 0) /* p is out of range so there is no node at position p */
    {
        return 0;
    }

    /* case 2: delete the first node */
    else if(p == 0)
    {
        int value = head->value;
        head = NULL;
        free(head);
        countNode = 0;
        return 1;
    }

    /* case 3: delete the node that has predecessor */
    else
    {
        /* Search for a deleting node which its position equals to p. (starting from 0)
         * currNode will store the address of the node to be deleted.
         * prevNode will store the address of the predecessor of currNode.
         */
        Node * currNode = head;
        Node * predNode;
        int i;
        for(i=0; i<p-1; i++)
        {
            predNode = currNode;
            currNode = currNode->next;

        }
        // TODO: move the currNode to the node at position p and the predNode to the node at position (p-1)
        predNode->next=currNode->next;
        // TODO: connect the predNode to the next of deleting node.


        //int value = currNode->value;
        free(currNode);
        countNode = countNode - 1;
        return 1;
    }
}

/* delete all numbers from the list
 */
void deleteAll()
{
    while (!isEmptyList()) {
        deleteAt(0);
    }
}

/* retrieve the value at position p from the list
 * note that: p is the position counts from 0.
 * return data at position p
 * return 0 if the position p is out of range.
 */
int valueAt(int p)
{
    /* if unable to retrieve value. */
    if(head == NULL || countNode < p)
    {
        return 0;
    }
    /* retrieve value at p */
    else
    {
        Node * currNode = head;
        int i;
        for(i=0; i<p; i++)
        {
            currNode = currNode->next;
        }
        return currNode->value;
    }
}
