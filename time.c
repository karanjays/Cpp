#include<stdio.h>
#include<stdlib.h>
void main()
{
	int h=0,m=0,s=0;
	long long int i;
	printf("please enter a time format in HH:MM:SS");
	scanf("%d%d%d",&h,&m,&s);
	system("cls");
	while(1){
	for (h;h<24;h++)
	{	for (m;m<60;m++)
		{	for (s;s<60;s++)
			{	printf("\n\n\n\t\t\t%.2d:%.2d:%.2d",(h%12)+1,m,s);
				if (h<12)
					printf(" AM");
				else
					printf(" PM");
				
				for(i=0;i<262157892;i++){}
			system("cls");	
			}s=0;
		}m=0;
	}h=0;
	}
}
