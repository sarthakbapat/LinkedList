#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

// Get the length of the linked list.
int getListLength(Node* head);

// Insert at the start of the list.
void insertAtStart(Node**, int);

// Insert at nth position in the list.
void insertAtPosN(Node**, int, int);

// Insert at end of the list.
void insertAtEnd(Node**, int);

// Delete at start of the list.
void deleteAtStart(Node**);

// Delete at nth position in the list.
void deleteAtPosN(Node**, int);

// Delete at the end of the list.
void deleteAtEnd(Node**);

// Reverse the linked list.
void reverseLinkedList(Node**);

// Print the contents of the list.
void printList(Node* head);


#endif