#include <stdio.h>
#include <stdlib.h>
struct Node {
    int val; 
    struct Node * next; 
} * head; 
void isEmpty() {
    if (head == NULL) { 
        printf("Stack is empty: Underflow State\n");
    } else {
        printf("Stack is not empty\n");
    }
}
void push() {
    struct Node *ptr = (struct Node *) malloc(sizeof(struct Node)); 
    int data;
    printf("Enter Value To Push: ");
    scanf("%d", & data); 
    if (head == NULL) { 
        ptr -> val = data;
        ptr -> next = NULL;
        head = ptr;
    } else { 
        ptr -> val = data;
        ptr -> next = head;
        head = ptr;
    }
}
void pop() {
    int item;
    struct Node * ptr;
    if (head == NULL) { 
        printf("Underflow State: can't remove any item\n");
    } else { 
        item = head -> val;
        ptr = head;
        head = head -> next;
        free(ptr);
        printf("Popped Element: %d\n", item);
    }
}
void peek() {
    if (head != NULL) 
        printf("Topmost Element: %d\n", head -> val);
    else 
        printf("Stack is empty: Underflow State\n");
}
int main() {
    int ch;
    printf("1. Push\n2. Pop\n3. Peek\n4. is Empty?\n5. Exit");
    do {
        printf("\nEnter Your Choice: ");
        scanf("%d", & ch); 
        if (ch == 1) { 
            push();
        } else if (ch == 2) { 
            pop();
        } else if (ch == 3) { 
            peek();
        } else if (ch == 4) { 
            isEmpty();
        } else if (ch == 5) { 
            exit(0);
        } else { 
            printf("Invalid Choice\n");
        }
    } while (ch != 7); 
    return 0;
}

