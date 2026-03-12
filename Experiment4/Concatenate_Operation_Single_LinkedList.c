#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node* NODE;

int main() {

    NODE t1 = NULL;
    NODE t2 = NULL;
    NODE newNode, temp;
    int n1, n2, x;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);

    printf("Enter elements of List 1:\n");
    for(int i = 0; i < n1; i++) {
        scanf("%d", &x);

        newNode = (NODE)malloc(sizeof(struct node));
        if(newNode == NULL){
            printf("Memory allocation failed\n");
            exit(1);
        }

        newNode->data = x;
        newNode->next = NULL;

        if(t1 == NULL)
            t1 = newNode;
        else {
            temp = t1;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);

    printf("Enter elements of List 2:\n");
    for(int i = 0; i < n2; i++) {
        scanf("%d", &x);

        newNode = (NODE)malloc(sizeof(struct node));
        if(newNode == NULL){
            printf("Memory allocation failed\n");
            exit(1);
        }

        newNode->data = x;
        newNode->next = NULL;

        if(t2 == NULL)
            t2 = newNode;
        else {
            temp = t2;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    /* Concatenate Lists */
    if(t1 == NULL)
        t1 = t2;
    else {
        temp = t1;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = t2;
    }

    /* Display List */
    printf("Concatenated List:\n");
    temp = t1;
    while(temp != NULL){
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
