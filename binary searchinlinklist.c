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
struct Node *Mid(struct Node *l, struct Node *r) {
if (l == NULL)
return NULL;
struct Node *pre = l;
struct Node *post = l->next;
while (post != r) {
post = post->next;
if (post != r) {
pre = pre->next;
post = post->next;
}
}
return pre;
}
struct Node *bin(struct Node *head, int value) {
struct Node *l = head, *r = NULL;
do {
struct Node *mid = Mid(l, r);
if (mid == NULL)
return NULL;
if (mid->data == value)
return mid;
else if (mid->data < value)
l = mid->next;
else
r = mid;
} while (r==NULL || r != l);
return NULL;
}
int main () {
struct Node *head = NULL;
int n, value, i;
printf("\nEnter the number of elements: ");
scanf("%d", &n);
printf("\nEnter the elements in sorted order: ");
for (i=0 ; i < n ; i++) {
int val;
scanf("%d", &val);
push(&head, val);
}
printf("\nEnter the number to find: ");
scanf("%d", &value);
if (bin(head, value))
printf("\n%d is present", value);
else
printf("\n%d is not present", value);
return 0;
}
