#include "LinkedList.h"


Node* _createNewNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;

}

// Passing headPointer by reference to the func, hence using double pointer.
void insertAtStart(Node** headPointer, int data)
{
    // Create a new node to insert at the begnning.
    Node* newNode = _createNewNode(data);

    // if the list is empty, headpointer points to NULL.
    if (*headPointer == NULL)
    {
        // Just make the headpointer point to the first node (newly created).
        *headPointer = newNode;
    }
    else
    {
        // Make newNode point to current first node.
        newNode->next = *headPointer;
        *headPointer = newNode;
    }
    // Print the list on adding new element.
    printList(*headPointer);
}

void insertAtPosN(Node** headPointer, int data, int position)
{
    // Scenario 1: List is empty
    // Scenario 2: List not empty but position = 0 or position = 1, insert at start.
    // Basically, we are treating position 0 as position 1.
    if (*headPointer == NULL || position == 0 || position == 1)
    {
        // Call func to insert at the start if list is empty.
        insertAtStart(headPointer, data);
        // print the list.
        printList(*headPointer);
        return;
    }
    // Scenario 2: List not empty but position is out of range.
    int len = 0;
    len = getListLength(*headPointer);
    if (position > len)
    {
        // Insert at the end of the list.
        insertAtEnd(headPointer, data);
        // print the list.
        printList(*headPointer);
    }
    else
    {
        // Handles the cases where position is not 0,1 and is within the range of len.
        Node *newNode = _createNewNode(data);
        // Create a temp to hold headPointer address.
        Node* temp = *headPointer;
        // traverse to the previous node to get the addr of next node.
        for (int i=0; i<(position - 2); i++)
        {
            temp = temp->next;
        }
        // Create a link between newNode and next node.
        newNode->next = temp->next;
        // Create a link between prev node (temp) and newNode.
        temp->next = newNode;

        printList(*headPointer);
    }
    
}

void insertAtEnd(Node** headPointer, int data)
{
    // Scenario 1: List is empty.
    if (*headPointer == NULL)
    {
        // Insert at the start and return.
        insertAtStart(headPointer, data);
        // print the list.
        printList(*headPointer);
        return;
    }
    else
    {
        // Scenario 2: List not empty.
        // Create a new node
        Node* newNode = _createNewNode(data);
        // Treverse till the end and insert.
        Node* temp = *headPointer;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // Establish link between last node and newNode.
        temp->next = newNode;
        newNode->next = NULL;

        printList(*headPointer);
    }
}

void deleteAtStart(Node** headPointer)
{
    // Create a temp node that points to head node.
    Node* temp = *headPointer;
    // Make headPointer point to the next node (2nd node).
    *headPointer = temp->next;
    // delete the temp.
    free(temp);

    // Print the list.
    printList(*headPointer);
}

void deleteAtPosN(Node** headPointer, int position)
{
    // Scenario 1: delete at pos 0 or 1.
    if (position == 0 || position == 1)
    {
        // Call the deleteAtStart() function
        deleteAtStart(headPointer);
        return;
    }

    // Scenario 2: delete at the end of the list, pos > len of list.
    int len = 0;
    len = getListLength(*headPointer);
    if (position > len)
    {
        // Call deleteAtEnd() func, always delete the last node.
        deleteAtEnd(headPointer);
    }
    else
    {
        // Normal case where the position is in a valid range.
        Node* traverse = *headPointer;
        Node* temp = traverse->next;
        for(int i=0; i<(position - 2); i++)
        {
            traverse = traverse->next;
            temp = temp->next;
        }
        // traverse is now at (postion -1) node, fix the link.
        traverse->next = temp->next;
        // temp is now at position, delete it.
        free(temp);

        // print the list.
        printList(*headPointer);

    }
}

void deleteAtEnd(Node** headPointer)
{
    // traverse points to the head node.
    Node* traverse = *headPointer;
    // temp points to head+1 node.
    Node* temp = traverse->next;

    while (temp->next != NULL)
    {
        temp = temp->next;
        traverse = traverse->next;
    }
    // traverse is now at last-1 node. Set its next to NULL.
    traverse->next = NULL;
    // Now temp is the last Node, delete it.
    free(temp);

    // Print the list.
    printList(*headPointer);
}

void reverseLinkedList(Node** headPointer)
{
    Node* current = *headPointer;
    Node* prev = NULL;
    Node* next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // Update the headPointer finally.
    *headPointer = prev;

    // print the list.
    printList(*headPointer);
} 

void printList(Node* head)
{
    printf("List is: ");
    while (head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
    
}

int getListLength(Node* head)
{
    int len = 0;
    if (head == NULL)
    {
        return len;
    }
    else
    {
        while (head != NULL)
        {
            head = head->next;
            len++;
        }
        
    }
    return len;
}