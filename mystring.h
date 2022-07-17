//Write all the program logic/functions in the user-defined header file “mystring.h”. 
//Your user-defined function should work similarly to the inbuilt function of the library header file string.h.
//The header file is:-


int length( char a[]){
int l=0,i;
for(i=0;a[i]!='\0';i++)
l++;
return l;
}

char *concate(char a[],char b[],char r[]){
int i=0,j=0,k=0;
 while (a[i] != '\0')
 r[k++] = a[i++];
 while (b[j] != '\0')
 r[k++] = b[j++];
r[k]='\0';
return r;
}


char *copy(char a[],char r[]){
int i=0,k=0;
 while (a[i] != '\0')
 r[k++] = a[i++];
r[k]='\0';
return r;
}


char *cmp(char a[],char b[]){
int i=0,j=0,k;
while(a[i]!='\0' || b[j]!='\0'){
if(a[i]>b[j])
return "1st string is bigger";
else if(a[i]<b[j])
return "2st string is bigger";
i++;
j++;
}
if(i==length(a) && j==length(b))
return "Both are same.";
}
int src(char a[],char b[]){
int i;
for(i=0;a[i]!='\0';i++){
if(a[i]==b[0])
{
return (i+1);
}
}
if(i==length(a))
return -1;
}


char *issubstr(char b[],char a[]){
int M=length(a),N=length(b),i,j;
 for (i = 0; i <= N - M; i++) {
 for (j = 0; j < M; j++)
 if (b[i + j] != a[j])
 break;

 if (j == M)
 return "Yes the string is present.";
 }
 return "No the string is not present.";
}
char *rev(char a[]){
int i=0,j=length(a)-1;
char t;
for(;i<j;i++,j--){
t=a[i];
a[i]=a[j];
a[j]=t;
}
return a;
}
