#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};
void push(struct Node **head, int data) {
struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
struct Node *temp = *head;
newnode->data = data;
if (*head == NULL) {
*head = newnode;
newnode->next = *head;
}
else {
while (temp->next != *head)
temp = temp->next;
temp->next = newnode;
newnode->next = *head;
}
}
struct Node* mid_n (struct Node *head) {
struct Node *hare = head, *tortoise = head;
while (hare->next!=head && hare->next->next!=head) {
tortoise = tortoise->next;
hare = hare->next->next;
}
return tortoise;
}
int main() {
struct Node *head = NULL;
int n, i;
printf("\nEnter the number of nodes: ");
scanf("%d", &n);
printf("\nEnter the elements: ");
for (i=0 ; i < n ; i++) {
int num;
scanf("%d", &num);
push(&head, num);
}
struct Node *mid = mid_n(head);
printf("\nMiddle node: %d", mid->data);
return 0;
}
