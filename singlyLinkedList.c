#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *createNode(int val)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

void insertionAtEnd(int val)
{
    struct Node *new_node = createNode(val);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        tail->next = new_node;
    }
    tail = new_node;
}

void insertionAtStart(int val)
{
    struct Node *new_node = createNode(val);
    if (tail == NULL)
    {
        tail = new_node;
    }

    new_node->next = head;
    head = new_node;
}

void insertionInBetween(int val, int val2){
    struct Node *new_node = createNode(val2);
    struct Node *temp = head;
    while(temp->data != val){
        temp=temp->next;
    }
    if(temp->data==val){
        new_node->next= temp->next;
        temp->next = new_node;
    }
}


void inserationAtPosition(int position, int val){
    struct Node *new_node = createNode(val);
    struct Node *temp = head;
    int count = 0;
    while(count!=(position-1)){
        temp=temp->next;
        count++;
    }
    new_node->next= temp->next;
    temp->next = new_node;
}

void deletionFromStart(){
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void deletionFromEnd(){
    struct Node *prev = NULL;
    struct Node *end = head;
    while(end->next){
        prev= end;
        end = end->next;
    }
    prev->next = NULL;
    free(end);
}

void deleteFromPosition(int position){
    struct Node* prev = head;
    struct Node* temp = NULL;
    for(int i =0; i<position-1;i++){
        prev=prev->next;
    }
    temp = prev->next;
    prev->next = temp->next;
    free(temp);

}

void show()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insertionAtStart(60);
    insertionAtEnd(20);
    insertionAtEnd(30);
    insertionAtEnd(40);
    insertionAtStart(50);
    insertionAtEnd(80);
    insertionInBetween(30,70);
    inserationAtPosition(2,45);
    show();
    deletionFromStart();
    show();
    deletionFromEnd();
    show();
    deleteFromPosition(1);
    show();
    return 0;
}
