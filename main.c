#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FLUSH stdin=freopen(NULL,"r",stdin)
#define MAX_LEN 50

#define RMN(str) str[strcspn(str,"\n")]=0

typedef struct node {
    char name[MAX_LEN];
    
    struct node* next;
} student_t;

student_t* createList();

student_t* createNode();

void displayList();

void pushBack(student_t**);
void pushFront(student_t**);

void removeFirst(student_t**);
void removeLast(student_t**);

// --------------------------------------
int main() {
  
    student_t* head = createList();
 
    printf("== Printing Linked List:\n");
    displayList(head);
    
    printf("1. Adding new node to the back:\n");
    pushBack(&head);
    displayList(head);
    
    printf("2. Adding new node at the front:\n");
    pushFront(&head);
    displayList(head);    
    
    printf("4. Removing last node:\n");
    removeLast(&head);
    displayList(head);
    
    printf("5. Removing first node:\n");
    removeFirst(&head);
    displayList(head);

    return 0;
}

void pushFront(student_t** head) {
    
    student_t* new_node = createNode();
    if (new_node !=NULL) {
        new_node->next = *head;
        *head = new_node;
    }   
}

void removeFirst(student_t** head) {
    
    if (*head == NULL) {
        printf("Error: List is empty! Cannot remove first element.");
        return;
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        student_t *tmp;
        tmp = *head;
        free(*head);
        *head = tmp->next;
    }
}

void pushBack(student_t** head) {
    
    if (*head == NULL) {
        *head = createNode();
    }
    else {
        student_t* current = *head;
        while (current->next !=NULL ) {
            current=current->next;
        }
        current->next = createNode();
    }
}

void removeLast(student_t** head){
    
    if (*head == NULL) {
        printf("Cannot remove last. Linked list is empty!\n");
    }
    else if ( (*head)->next ==NULL  ) {
        free(*head);
        *head=NULL;
    }
    else {
    
        student_t* current = *head;
        while ( current->next->next !=NULL ) {
            current=current->next;
        }

        free(current->next);
        current->next = NULL;
    }

}

student_t* createNode() {
    
    student_t* node =NULL;
    
    char tmp[MAX_LEN]={0};
    
    printf("Please enter student's name: ");
    fgets(tmp, MAX_LEN, stdin );
    RMN(tmp);
    FLUSH;
    
    if (strlen(tmp)>0) {
        node = (student_t*) malloc( sizeof(student_t) );
        if (node == NULL) {
            printf("Cannot allocate memory for a person!\n");
            exit(1);
        }
        strcpy(node->name, tmp);
        
        node->next = NULL;
        
    }
    
    return node;
}

student_t* createList(){
    student_t *head = NULL, *new_node=NULL, *current=NULL;
    
    while(  (new_node=createNode()) !=NULL ) {
        
        if (current == NULL) {
            head = new_node;
        }
        else {
            current->next = new_node;
        }
        current = new_node;

    }
    
    return head;
}


void displayList(student_t* head) {
    
    if (head == NULL) {
        printf("Linked list is empty!\n");
    }
    else {
        student_t* current = head;
        while (current !=NULL){
            printf("%s\n", current->name);
            current = current->next;
        }
    }
}