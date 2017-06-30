/*
DataTypes

Description
=============
Takes a file as an input and gives the number
of characters, number of floats, number of
integers, number of lines , number of spaces,
sum of integers and sum of floats

Authors:
Sai Kiran Davuluri <saikiran.davuluri@gmail.com>
Harsha Anirudh <harsha.anirudh@gmail.com>

*/
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int fininte[20];
float finflo[20];
int doempty(char a[20],int i)
{
	int j;
	for(j=0;j<=i;j++)
	a[j]=0;
	return 0;
}
int getInteger(char a[100],int j)
{
	int i,k=0,l=0;
	char temp[20];
	for(i=0;i<=j;i++)
	{
		if(a[i]=='.')
		{
			k=doempty(temp,k);
			while(a[i+1]!='\n'&&a[i+1]!=' '&&a[i+1]!='\0')
			i++;
			continue;
		}
		if((isdigit(a[i])) && (!isalpha(a[i-1])) )
		{
			if(a[i-1]=='+')
			{
				temp[k]='+';
				k++;
			}
			if(a[i-1]=='-')
			{
				temp[k]='-';
				k++;
			}
			temp[k]=a[i];
			k++;
			if(a[i+1]=='\n' || a[i+1]==' ' || a[i+1]=='\0')
			{
				fininte[l]=atoi(temp);
				l++;
				k=doempty(temp,k);
			}
		}
	}
	return l;

}
int getFloat(char a[100],int j)
{
	int i,k=0,l=0,h,count=0;
	char temp[20];
	for(i=0;i<=j;i++)
	{
		if((isdigit(a[i])) && (!isalpha(a[i-1])) || (a[i]=='.'&&(isdigit(a[i-1]))&&isdigit(a[i+1])))
		{
			/*if(a[i]=='.')
			{
			count++;
			if(count>1)
			continue;
		}*/
		if(a[i-1]=='+')
		{
			temp[k]='+';
			k++;
		}
		if(a[i-1]=='-')
		{
			temp[k]='-';
			k++;
		}
		temp[k]=a[i];
		k++;
		/*	for(h=0;h<k;h++)
		{
		if(temp[h]=='.')
		{
		count++;
		if(count>1)
		k=doempty(temp,k);
	}
}*/
if(a[i+1]=='\n' || a[i+1]==' ' || a[i+1]=='\0')
{
	for(h=0;h<k;h++)
	{
		if(temp[h]=='.')
		{
			count++;
		}
	}
	if(count>1)
	{
		k=doempty(temp,k);
		break;
	}

	if(count==1)
	{
		finflo[l]=atof(temp);
		l++;
	}
}
k=doempty(temp,k);
count=0;
}
}

return l;
}
void main()
{
	FILE *fp;
	fp=fopen("new.txt","r");
	char ch,temp[100];
	float fsum=0;
	int i=0,j=0,c=0,k=0,f=0,l=0,w=0,n=0,sum=0;
	while((ch=getc(fp))!=EOF)
	{
		temp[i]=ch;
		i++;
	}
	for(j=0;j<=i;j++)
	printf("%c",temp[j]);
	c=j;

	k=getInteger(temp,c);
	f=getFloat(temp,c);
	for(j=0;j<=i;j++)
	{
		if(temp[j]=='\n')
		l++;
		if(temp[j]=='\n'||temp[j]==' ')
		w++;
	}
	printf("\n NO.of lines : %d",l);
	printf("\n NO.of words : %d",w-k-f);
	for(j=0;j<k;j++)
	{
		sum=sum+fininte[j];
	}
	for(j=0;j<f;j++)
	{
		fsum=fsum+finflo[j];
	}
	printf("\n no of integers %d",k);
	printf("\n integers: ");
	for(n=0;n<k;n++)
	printf("%d,",fininte[n]);
	printf("\n no of flating type numbers %d",f);
	printf("\n floating type nmbers: ");
	for(n=0;n<f;n++)
	printf("%f,",finflo[n]);
	printf("\n sum of integers= %d",sum);
	printf("\n sum of float= %f",fsum);

}
