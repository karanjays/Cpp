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
void exchange(struct Node **head) {
struct Node *temp = *head, *tmp = *head;
while (temp->next->next != *head)
temp = temp->next;
temp->next->next = tmp->next;
tmp->next = temp->next;
temp->next = *head;
*head = tmp->next;
}
void display(struct Node *head) {
struct Node *temp = head;
printf("[ ");
while (temp->next != head) {
 printf("%d ", temp->data);
 temp = temp->next;
 }
printf("%d ", temp->data);
printf("]");
}
void deleteAlt(struct Node **head) {
struct Node *prev = *head;
struct Node *curr = prev->next;
while ((prev->next->next != *head) && (prev->next != *head)) {
prev->next = curr->next;
free (curr);
prev = prev->next;
curr = prev->next;
}
if (prev->next->next == *head) {
prev->next = *head;
free(curr);
}
}
int main() {
struct Node *head = NULL;
int n, i, selection;
input:
printf("\nEnter the number of nodes: ");
scanf("%d", &n);
if (n <= 0) {
printf("\nEnter positive integer");
goto input;
}
printf("\nEnter the elements: ");
for (i=0 ; i < n ; i++) {
int num;
scanf("%d", &num);
push(&head, num);
}
do {
printf("\n-------------------------------");
printf("\n1- Exchange first and last node");
printf("\n2- Delete every alternate node");
printf("\n3- Split the circular list");
printf("\n4- Quit");
printf("\n-------------------------------");
printf("\nEnter your selection (1-4): ");
scanf ("%d", &selection);
switch (selection) {
case 1: {
printf("\nBefore exchnage: ");
display(head);
exchange(&head);
printf("\nAfter exchnage: ");
display(head);
break;
}
case 2: {
printf("\nBefore deletion: ");
display(head);
deleteAlt(&head);
printf("\nAfter deletion: ");
display(head);
break;
}
case 3: {
struct Node *mid = head, *last = head, *head1, *head2;
while ((last->next->next != head) && (last->next != head)) {
mid = mid->next;
last = last->next->next;
}
if (last->next->next == head)
last = last->next;
head1 = head;
if (head->next != head)
head2 = mid->next;
last->next = mid->next;
mid->next = head;
printf ("\nList 1: ");
display(head1);
printf(" List 2: ");
display(head2);
break;
}
case 4: {
printf("\nThank you!\n");
break;
}
default: {
printf("\nInvalid input\n");
break;
}
}
} while (selection != 4);
return 0;
}
