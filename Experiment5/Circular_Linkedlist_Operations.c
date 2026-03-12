#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node* NODE;

int main(){

    NODE first = NULL, second = NULL;
    NODE temp, current, prev, last, last1, last2, next;

    int n, x, pos, op;

    while(1){

        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d",&op);

        switch(op){

        case 1:   /* CREATE CLL */
            printf("How many nodes? ");
            scanf("%d",&n);

            first = NULL;
            last = NULL;

            for(int i=1;i<=n;i++){
                scanf("%d",&x);

                temp = (NODE)malloc(sizeof(struct node));
                temp->data = x;
                temp->next = NULL;

                if(first==NULL){
                    first = temp;
                    last = temp;
                    last->next = first;
                }
                else{
                    last->next = temp;
                    last = temp;
                    last->next = first;
                }
            }
            break;

        case 2:   /* INSERT */
            printf("Position: ");
            scanf("%d",&pos);

            printf("Element: ");
            scanf("%d",&x);

            temp = (NODE)malloc(sizeof(struct node));
            temp->data = x;

            if(first==NULL && pos==1){
                temp->next = temp;
                first = temp;
                break;
            }

            current = first;

            if(pos==1){
                while(current->next != first)
                    current=current->next;

                temp->next = first;
                current->next = temp;
                first = temp;
            }
            else{
                int count=1;

                while(count<pos-1 && current->next!=first){
                    current=current->next;
                    count++;
                }

                if(count!=pos-1){
                    printf("Position not found\n");
                }
                else{
                    temp->next=current->next;
                    current->next=temp;
                }
            }
            break;

        case 3:   /* DELETE */
            if(first==NULL){
                printf("CLL is empty\n");
                break;
            }

            printf("Position: ");
            scanf("%d",&pos);

            current = first;
            prev = NULL;
            int count=1;

            if(pos==1){

                if(first->next==first){
                    printf("Deleted element: %d\n",first->data);
                    free(first);
                    first=NULL;
                    break;
                }

                while(current->next!=first)
                    current=current->next;

                temp=first;
                current->next=first->next;
                first=first->next;

                printf("Deleted element: %d\n",temp->data);
                free(temp);
            }
            else{

                while(count<pos && current->next!=first){
                    prev=current;
                    current=current->next;
                    count++;
                }

                if(count!=pos){
                    printf("Position not found\n");
                }
                else{
                    prev->next=current->next;
                    printf("Deleted element: %d\n",current->data);
                    free(current);
                }
            }
            break;

        case 4:   /* DISPLAY */
            if(first==NULL){
                printf("CLL is empty\n");
                break;
            }

            current = first;

            do{
                printf("%d -> ",current->data);
                current=current->next;
            }while(current!=first);

            printf("\n");
            break;

        case 5:   /* REVERSE */

            if(first==NULL || first->next==first)
                break;

            last = first;
            while(last->next!=first)
                last=last->next;

            prev = last;
            current = first;

            do{
                next=current->next;
                current->next=prev;
                prev=current;
                current=next;
            }while(current!=first);

            first=prev;

            printf("CLL reversed\n");

            current=first;
            do{
                printf("%d -> ",current->data);
                current=current->next;
            }while(current!=first);
            printf("\n");

            break;

        case 6:   /* CONCATENATE */

            printf("How many nodes in second CLL? ");
            scanf("%d",&n);

            second=NULL;
            last=NULL;

            for(int i=1;i<=n;i++){
                scanf("%d",&x);

                temp=(NODE)malloc(sizeof(struct node));
                temp->data=x;
                temp->next=NULL;

                if(second==NULL){
                    second=temp;
                    last=temp;
                    last->next=second;
                }
                else{
                    last->next=temp;
                    last=temp;
                    last->next=second;
                }
            }

            if(first==NULL)
                first=second;
            else if(second!=NULL){

                last1=first;
                last2=second;

                while(last1->next!=first)
                    last1=last1->next;

                while(last2->next!=second)
                    last2=last2->next;

                last1->next=second;
                last2->next=first;
            }

            printf("Concatenated CLL:\n");

            current=first;
            if(current!=NULL){
                do{
                    printf("%d -> ",current->data);
                    current=current->next;
                }while(current!=first);
            }
            printf("\n");

            break;

        case 7:
            exit(0);
        }
    }
}
