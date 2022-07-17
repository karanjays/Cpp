#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *next;
};
int length(struct Node *head) {
struct Node *temp = head;
int l=0;
while (temp->next != head) {
temp = temp->next;
l++;
}
l++;
return l;
}
void insert_front(struct Node **head, int data) {
struct Node *newnode = (struct Node *)malloc(sizeof(struct Node)), *temp =
*head;
newnode->data = data;
if (*head == NULL) {
*head = newnode;
newnode->next = *head;
}
else {
while (temp->next != *head)
temp = temp->next;
newnode->next = *head;
*head = newnode;
temp->next = *head;
}
}
void insert_middle(struct Node *prev, int data) {
struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
newnode->data = data;
newnode->next = prev->next;
prev->next = newnode;
}
void insert_end(struct Node **head, int data) {
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
void delete_front(struct Node **head) {
struct Node *temp1 = *head, *temp2 = *head;
if (temp1->next == *head) {
*head = NULL;
free(temp1);
}
else {
while (temp1->next != *head)
temp1 = temp1->next;
*head = temp2->next;
temp1->next = *head;
free(temp2);
}
}
void delete_middle(struct Node **head, int value, int count) {
struct Node *temp = *head;
int i;
for (i=0 ; i < count ; i++) {
if (temp->data == value) {
struct Node *temp1 = *head, *temp2 = *head;
if (temp1->next == *head) {
*head = NULL;
free(temp1);
}
else {
while (temp1->next != *head)
temp1 = temp1->next;
*head = temp2->next;
temp1->next = *head;
free(temp2);
}
}
else {
while ((temp->next->data != value) && (temp->next->next !=
*head))
temp = temp->next;
if (temp->next->next != *head) {
struct Node *after = temp->next->next;
free(temp->next);
temp->next = after;
}
else {
free(temp->next);
temp->next = *head;
}
}
}
printf("\n%d deleted from the list %d times\n", value, count);
}
void delete_end(struct Node **head) {
struct Node *temp = *head;
if (temp->next == *head) {
*head = NULL;
free(temp);
}
else {
while (temp->next->next != *head)
temp = temp->next;
free(temp->next);
temp->next = *head;
}
}
void display(struct Node *head) {
struct Node *temp = head;
printf("\nElements of the linked list: ");
printf("[ ");
while (temp->next != head) {
 printf("%d ", temp->data);
 temp = temp->next;
 }
 printf("%d ", temp->data);
printf("]\n");
}
struct Node* find(struct Node *head, int position) {
struct Node *temp = head;
int i;
for (i=0 ; i < position-2 ; i++) {
temp = temp->next;
}
return temp;
}
int find1(struct Node *head, int value) {
struct Node *temp = head;
while (temp->next != head) {
if (temp->data == value)
return 1;
temp = temp->next;
}
if (temp->data == value)
return 1;
return 0;
}
int find2(struct Node *head, int pos) {
int i;
for (i=0 ; i < pos-1 ; i++) {
head = head->next;
}
return head->data;
}
int count(struct Node *head, int value) {
struct Node *temp = head;
int count=0;
while (temp->next != head) {
if (temp->data == value)
count++;
temp = temp->next;
}
if (temp->data == value)
count++;
return count;
}
int main() {
int selection;
struct Node *head = NULL;
do {
printf("\n------------------------");
printf("\n1. Insert at beginning");
printf("\n2. Insert in middle");
printf("\n3. Insert at end");
printf("\n4. Delete at beginning");
printf("\n5. Delete in middle");
printf("\n6. Delete at end");
printf("\n7. Display");
printf("\n8. Quit");
printf("\n------------------------");
printf("\nEnter your selection: ");
scanf("%d", &selection);
switch (selection) {
case 1: {
int value;
printf("\nEnter value to insert: ");
scanf("%d", &value);
insert_front(&head, value);
printf("\n%d inserted at beginning\n", value);
break;
}
case 2: {
int value, pos;
printf("\nEnter value to insert and its position (2-%d): ",
length(head));
scanf("%d %d", &value, &pos);
struct Node *prev = find(head, pos);
if (pos >= length(head)+1)
printf("\nCannot add after last element\n");
else if (pos <= 1)
printf("\nCannot add before first element\n");
else {
insert_middle(prev, value);
printf("\n%d inserted at %d\n", value, pos);
}
break;
}
case 3: {
int value;
printf("\nEnter value to insert: ");
scanf("%d", &value);
insert_end(&head, value);
printf("\n%d inserted at end\n", value);
break;
}
case 4: {
if (head != NULL) {
delete_front(&head);
printf("\nFront element deleted\n");
}
else
printf("\nList is empty\n");
break;
}
case 5: {
if (head != NULL) {
int choice;
printf("\n1. Delete by value");
printf("\n2. Delete by position");
printf("\n---------------------");
printf("\nEnter your selection: ");
scanf("%d", &choice);
if (choice == 1) {
int value;
printf("\nEnter the value to delete: ");
scanf("%d", &value);
if (find1(head, value))
delete_middle(&head, value,
count(head, value));
else
printf("\n%d is not in the list\n");
}
else {
int pos;
printf("\nEnter position (1-%d): ",
length(head));
scanf("%d", &pos);
delete_middle(&head, find2(head, pos), 1);
}
}
else
printf("\nThe list is empty\n");
break;
}
case 6: {
if (head != NULL) {
if (length(head) > 1)
delete_end(&head);
else
delete_front(&head);
printf("\nLast element deleted\n");
}
else
printf("\nList is empty\n");
break;
}
case 7: {
if (head != NULL)
display(head);
else
printf("\nList is empty\n");
break;
}
case 8: {
printf("\nThank you!\n");
break;
}
default: {
printf("\nInalid input\n");
break;
}
}
} while (selection != 8);
return 0;
}
