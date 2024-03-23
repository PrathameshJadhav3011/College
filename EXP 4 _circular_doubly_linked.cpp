#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node * next;
    struct Node * prev;
};
struct Node * head = NULL;
struct Node * create(int data) {
    struct Node * new_node = (struct Node * ) malloc(sizeof(struct Node));
    new_node -> data = data;
    new_node -> next = NULL;
    new_node -> prev = NULL;
    return new_node;
}
void insertStart(int data) {
    struct Node * new_node = create(data);
    if (head == NULL) {
        new_node -> next = new_node;
        new_node -> prev = new_node;
        head = new_node;
    } else {
        head -> prev -> next = new_node;
        new_node -> prev = head -> prev;
        new_node -> next = head;
        head -> prev = new_node;
        head = new_node;
    }
}
void insertEnd(int data) {
    struct Node * new_node = create(data); 
    if (head == NULL) { 
        new_node -> next = new_node;
        new_node -> prev = new_node;
        head = new_node;
    } else {
        head -> prev -> next = new_node;
        new_node -> prev = head -> prev;
        new_node -> next = head;
        head -> prev = new_node;
    }
}
void deleteStart() {
    struct Node * temp = head; 
    if (temp == NULL) {
        printf("List is Empty\n");
        return;
    }
    if (temp -> next == temp) { 
        temp -> next = NULL;
        temp -> prev = NULL;
        free(temp);
        head = NULL;
        printf("Node Deleted\n");
        return;
    }
    head = head -> next;
    head -> prev = temp -> prev;
    temp -> prev -> next = head;
    free(temp); 
    printf("Node Deleted\n"); 
}
void deleteEnd() { 
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    struct Node * last = head -> prev;
    struct Node * secondToLast = last -> prev; 
    if (last == head) {
        free(last); 
        head = NULL;
    } else {
        secondToLast -> next = head;
        head -> prev = secondToLast;
        free(last);
    }
    printf("Node Deleted\n"); 
}
void display() { 
    struct Node * temp = head; 
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    printf("\nList in Forward Direction: ");
    do {
        printf(" %d ", temp -> data);
        temp = temp -> next;
    } while (temp != head);
    printf("\nList in Backward Direction: ");
    do {
        temp = temp -> prev;
        printf(" %d ", temp -> data);
    } while (temp != head);
    printf("\n");
}
void search(int data) {
    struct Node * temp = head;  
    int count = 1, flag = 0;  
    if (head == NULL) {  
        printf("List is Empty\n");
        return;
    }
    do {
        if (temp -> data == data) {  
            printf("[[Node->Data: %d]] Found at %d Position in List\n", temp -> data, count);  
            flag = 1;  
        }
        temp = temp -> next;  
        count++;  
    } while (temp != head);  
    if (flag == 0)
        printf("Node not found");
}
int getData() {  
    int data;
    printf("Enter Element: ");
    scanf("%d", & data);  
    return data;
}
int main() {
    int ch;  
    printf("**Circular Doubly Linked List**\n\n");  
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
