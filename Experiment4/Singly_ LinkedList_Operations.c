#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {

    struct Node* head = NULL;
    struct Node* newNode;
    struct Node* current;
    struct Node* temp;

    int size = 0;
    int num_elements, data, position, choice;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &num_elements);

    printf("Enter the elements:\n");

    for(int i = 0; i < num_elements; i++) {
        scanf("%d", &data);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            current = head;
            while(current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    while(1) {

        printf("\nLinked List Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Reverse\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {

            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position to insert: ");
            scanf("%d", &position);

            if(position < 0 || position > size) {
                printf("Invalid position\n");
                continue;
            }

            newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;

            if(position == 0) {
                newNode->next = head;
                head = newNode;
            } else {
                current = head;
                for(int i = 0; i < position - 1; i++) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
            }

            size++;
            printf("Element inserted\n");
        }

        else if(choice == 2) {

            printf("Enter position to delete: ");
            scanf("%d", &position);

            if(position < 0 || position >= size) {
                printf("Invalid position\n");
                continue;
            }

            if(position == 0) {
                temp = head;
                head = head->next;
            } else {
                current = head;
                for(int i = 0; i < position - 1; i++) {
                    current = current->next;
                }
                temp = current->next;
                current->next = temp->next;
            }

            free(temp);
            size--;
            printf("Element deleted\n");
        }

        else if(choice == 3) {

            struct Node* prev = NULL;
            struct Node* next = NULL;

            current = head;

            while(current != NULL) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            head = prev;

            printf("Reversed List: ");

            current = head;
            while(current != NULL) {
                printf("%d -> ", current->data);
                current = current->next;
            }
            printf("NULL\n");
        }

        else if(choice == 4) {

            printf("Linked List: ");
            current = head;

            while(current != NULL) {
                printf("%d -> ", current->data);
                current = current->next;
            }

            printf("NULL\n");
        }

        else if(choice == 5) {
            printf("Exiting program\n");
            break;
        }

        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
