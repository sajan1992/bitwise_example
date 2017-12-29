#include<stdio.h>
#include<stdlib.h>
int getbinary(unsigned char);
int get_toggle(unsigned char,int);
int main()
{
	int i;
	unsigned char c[10];
	printf("Enter the character to its its binary:\n");
	for(int k=0;k<10;k++)
	scanf("%c",&c[k]);
        printf("Binary code :\n");
	for(int k=0;k<10;k++)
	{
        	printf("bit : %d -->",k);
		getbinary(c[k]);
		printf("\n");
	}
	printf("Enter the bit number to be toggle:\n");
	scanf("%d",&i);
	if(i%8 == 0)
	{
		c[((i/8)-1)]=get_toggle(c[(i/8)-1],i);
	}
	if(i%8 !=0)
	c[((i/8))]=get_toggle(c[(i/8)],i);
        printf("Toggled Binary code at pos %d:\n",i);
	for(int k=0;k<10;k++)
	{
		printf("bit : %d -->",k);
		getbinary(c[k]);
		printf("\n");
	}
	return 0;
}
//function to toggle a bit.
int get_toggle(unsigned char c,int i)
{
	int k;
	unsigned char byte = 1;
	if(i%8 == 0)
	{
		i=7;
		byte <<=i;
		c ^=byte;
		return c;
	}
	if(i%8 != 0)
	{
		k=i/8;
		i=i - (k*8);
		i=i-1;
		byte <<=i;
		c ^=byte;
		return c;
	}
}
// function to print binary of a character in correct order.
int getbinary(unsigned char c)
{
	int j=0;
	unsigned char byte=c;
        while(j<=7)
        {
                    c <<=j;
                    c >>=7;
                    printf("%d",c);
                    c=byte;
                    j++;
         }
	 printf(" ");
}
