
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node * next;
    struct Node * prev;
};
struct Node * head = NULL;
void insertStart(int data) {
    struct Node * newNode = (struct Node * ) malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = head;
    newNode -> prev = NULL;
    if (head != NULL)
        head -> prev = newNode;
    head = newNode;
}
void insertEnd(int data) {
    struct Node * newNode = (struct Node * ) malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    if (head == NULL) {
        head = newNode;
        newNode -> prev = NULL;
        return;
    }
    struct Node * temp = head;
    while (temp -> next != NULL)
        temp = temp -> next;
    temp -> next = newNode;
    newNode -> prev = temp;
}
void deleteStart() {
    struct Node * tempNode = head;
    if (head == NULL) {
        printf("Linked List Empty\n");
        return;
    }
    if (tempNode -> next == NULL) {
        printf("Node Deleted\n");
        head = NULL;
        return;
    }
    head = head -> next;
    head -> prev = NULL;
    free(tempNode);
    printf("Node Deleted\n");
}
void deleteEnd() {
    struct Node * tempNode = head;
    if (head == NULL) {
        printf("Linked List Empty\n");
        return;
    }
    if (tempNode -> next == NULL) {
        printf("Node Deleted\n");
        head = NULL;
        free(tempNode);
        return;
    }
    while (tempNode -> next != NULL)
        tempNode = tempNode -> next;
    tempNode -> prev -> next = NULL;
    free(tempNode);
    printf("Node Deleted\n");
}
void display() {
    struct Node * end, * node = head;
    if (node == NULL) {
        printf("List is Empty\n");
        return;
    }
    printf("\nList in Forward direction: ");
    while (node != NULL) {
        printf(" %d ", node -> data);
        end = node;
        node = node -> next;
    }
    printf("\nList in backward direction: ");
    while (end != NULL) {
        printf(" %d ", end -> data);
        end = end -> prev;
    }
    printf("\n");
}
void search(int data) {
    struct Node * node = head;
    int count = 1, flag = 0;
    if (node == NULL) {
        printf("List is Empty\n");
    } else {
        while (node != NULL) {
            if (node -> data == data) {
                printf("[[Node->Data: %d]] Found at %d Position in List\n", node -> data, count);
                flag = 1;
            }
            node = node -> next;
            count++;
        }
        if (flag == 0) {
            printf("Node not found");
        }
        printf("\n");
    }
}
int getData() {
    int data;
    printf("Enter Element: ");
    scanf("%d", & data);
    return data;
}
int main() {
    int ch;
    printf("**Doubly Linked List**\n\n");
    printf("1. Insert Start\n2. Insert End\n3. Delete Start\n4. Delete End\n5. Search\n6. Display\n7. Exit");
    do {
        printf("\nEnter Your Choice: ");
        scanf("%d", & ch);
        if (ch == 1) {
            insertStart(getData());
        } else if (ch == 2) {
            insertEnd(getData());
        } else if (ch == 3) {
            deleteStart();
        } else if (ch == 4) {
            deleteEnd();
        } else if (ch == 5) {
            search(getData());
        } else if (ch == 6) {
            display();
        } else if (ch == 7) {
            exit(0);
        } else {
            printf("Invalid Choice");
        }
    } while (ch != 7);
    return 0;
}
