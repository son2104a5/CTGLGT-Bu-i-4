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

void deleteNodeOnposition(Node** head, int position) {
    Node* temp = *head;
    Node* prev = NULL;
    int currentPos = 0;
    while (temp != NULL && currentPos != position) {
        prev = temp;
        temp = temp->next;
        currentPos++;
    }
    if (temp == NULL) return;

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
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
	printList(head);
	printf("vi tri can xoa: ");
	scanf("%d", &position);
	deleteNodeOnposition(&head, position);
	printf("danh sach sau khi xoa: ");
 	printList(head);
	return 0;
}

