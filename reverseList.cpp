#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node* next;
};

void insert(struct node** headRef, int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}

void printList(struct node* head){
	struct node* current = head;
	while (current != NULL){
		cout<<current->data<<" ";
		current = current->next;
	}
	cout<<endl;
}

void reverseList(struct node** headRef){

	struct node* first = *headRef;

	if (first == NULL) return;

	struct node* rest = first->next;

	if (rest == NULL) return;

	reverseList(&rest);

	first->next->next = first;
	first->next = NULL;

	*headRef = rest;
}


int main() {
	struct node* head = NULL;
	insert(&head,3);
	insert(&head,2);
	insert(&head,1);
	printList(head);
	reverseList(&head);
	printList(head);
}