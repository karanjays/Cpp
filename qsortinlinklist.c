#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};
void push(struct Node **head, int data) {
struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
struct Node *last = *head;
newnode->data = data;
newnode->next = NULL;
if (*head == NULL)
*head = newnode;
else {
while (last->next != NULL)
last = last->next;
last->next = newnode;
}
}
void display(struct Node *head) {
while (head != NULL) {
 printf("%d ", head->data);
 head = head->next;
 }
}
struct Node *sort(struct Node *head) {
if (head == NULL)
return;
struct Node *l = head, *r = head->next, *pivot = head, *prev, *ptr;
int temp;
while (r != NULL) {
if (r->data < pivot->data) {
prev = l;
ptr = l->next;
temp = l->data;
l->data = r->data;
r->data = temp;
}
r = r->next;
}
if (l != head) {
temp = l->data;
l->data = pivot->data;
pivot->data = temp;
prev->next = NULL;
sort(head);
prev->next = ptr;
}
sort(l->next);
return head;
}
int main() {
struct Node *head = NULL, *tail = NULL;
int n, value, i;
printf("\nEnter the number of elements: ");
scanf("%d", &n);
printf("\nEnter the elements: ");
for (i=0 ; i < n ; i++) {
int val;
scanf("%d", &val);
push(&head, val);
}
head = sort(head);
printf("\nList after sorting: ");
display(head);
return 0;
}
