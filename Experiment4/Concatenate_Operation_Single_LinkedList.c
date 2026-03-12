struct node {
    NODE newNode = createNode(x);

    if(first == NULL)
        return newNode;

    NODE temp = first;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return first;    
    
    
    
}

NODE concatenate(NODE t1, NODE t2) {
    if(t1 == NULL)
        return t2;

    if(t2 == NULL)
        return t1;

    NODE temp = t1;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = t2;


    return t1;    
    
    
    
}

void displayList(NODE first) {
    NODE temp = first;

    while(temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }


    printf("NULL\n");    
    
    
    
}
