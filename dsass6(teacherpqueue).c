#include<stdio.h>
int front1 = 0, front2 = 0, rear1 = 0, rear2 = 0, l = 0;
int queue[30];
char ans[30];
int isEmpty()
{
if (front1 == rear1 && front2 == rear2)
return 0;
else
return 1;
}
void dequeue(int a, int i)
{
if (a == 0){
queue[i] = 99;
rear1--;
}
else{
queue[i] = 99;
rear2++;
}
}

void enqueue(int x, int a)
{
if (a == 0)
queue[front1--] = x;
else
queue[front2++] = x;
}
int main()
{
int n, x, i;
printf("Enter the number of teacher requests : ");
scanf("%d", &n);
front1 = n - 1, rear1 = n - 1;
printf("Enter the teacher requests in time in seconds : ");
for (i = 0; i < n; i++){
scanf("%d", &x);
enqueue(x, 0);
}
printf("\nEnter the number of students requests : ");
scanf("%d", &n);
front2 = rear1 + 1, rear2 = rear1 + 1;
printf("Enter the student requests in time in seconds : ");
for (i = 0; i < n; i++){
scanf("%d", &x);
enqueue(x, 1);
}
printf("\nThe order of serving:\n");
n = 1, x = 0;
while (isEmpty())
{
for (i = rear1; i > front1; i--)
{
if (queue[i] <= n){
dequeue(0, i);
x++;
ans[l++] = 'T';
break;
}
}
if (n == x){
n++;
continue;
}
for (i = rear2; i < front2; i++)
{
if (queue[i] <= n)
{
dequeue(1, i);
x++;
ans[l++] = 'S';
break;
}
}
n++;
}
printf("%s", ans);
return 0;
}
