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

void searchElement(Node** head, int searchValue) {
    Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == searchValue) {
            printf("1");
            return;
        }
        temp = temp->next;
    }
    printf("-1");
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
	int value, n, search;
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
	printf("search = ");
	scanf("%d", &search);
	searchElement(&head, search);
	return 0;
}

