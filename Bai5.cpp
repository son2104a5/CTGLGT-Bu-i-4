#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

Node* createNote(int value){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

void insertHead(Node** head, int value){
	Node* newNode = createNote(value);
	newNode->next = *head;
	*head = newNode;
}

void insertEnd(Node** head, int value){
	Node* newNode = createNote(value);
	if(*head == NULL){
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

void insertElementOnPosition(Node** head, int value, int position) {
    Node* newNode = createNote(value);
    if (*head == NULL || position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    int currentPos = 0;
    while (temp != NULL && currentPos < position - 1) {
        temp = temp->next;
        currentPos++;
    }
    if (temp == NULL) {
        printf("vi tri nay khong co trong danh sach\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}


void printList(Node* head){
	Node* temp = head;
	while(temp != NULL){
		printf("%d-->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main(){
	Node* head = NULL;
	int value, n, position;
	printf("n = ");
	scanf("%d", &n);
	if(n == 0){
		printf("danh sach trong");
		return 0;
	}
	printf("gia tri cua cac phan tu:\n");
	for(int i = 0; i < n; i++){
		scanf("%d", &value);
		insertEnd(&head, value);
	}
	printf("danh sach lien ket: ");
	printList(head);
	printf("gia tri can chen: ");
	scanf("%d", &value);
	printf("vi tri: ");
	scanf("%d", &position);
	insertElementOnPosition(&head, value, position);
	printf("danh sach lien ket sau khi chen: ");
	printList(head);
	return 0;
}

