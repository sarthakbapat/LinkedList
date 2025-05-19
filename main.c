#include "LinkedList.h"

int main()
{
    printf("Adding 5 elements to the list at the start ....\n");

    Node* head = NULL;
    int i;
    for (i=0; i<5; i++)
    {
        insertAtStart(&head, i);
    }

    printf("Length of list: %d\n", getListLength(head));

    insertAtPosN(&head, 23, 4);

    printf("Length of list: %d\n", getListLength(head));

    insertAtPosN(&head, 12, 5);

    printf("Length of list: %d\n", getListLength(head));

    insertAtPosN(&head, 32, 7);

    printf("Length of list: %d\n", getListLength(head));

    insertAtPosN(&head, 79, 1);

    printf("Length of list: %d\n", getListLength(head));

    insertAtEnd(&head, 91);

    printf("Length of list: %d\n", getListLength(head));

    insertAtPosN(&head, 121, 15);

    printf("Length of list: %d\n", getListLength(head));

    deleteAtStart(&head);

    printf("Length of list: %d\n", getListLength(head));

    deleteAtEnd(&head);

    printf("Length of list: %d\n", getListLength(head));

    deleteAtPosN(&head, 5);

    printf("Length of list: %d\n", getListLength(head));

    reverseLinkedList(&head);

    return 0;
}