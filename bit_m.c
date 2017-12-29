#include<stdio.h>
#include<stdlib.h>
int getbinary(unsigned char);
int get_toggle(unsigned char,int);
int main()
{
	int i;
	unsigned char c;
	printf("Enter the character to its its binary:\n");
	scanf("%c",&c);
        printf("Binary code : ");
	getbinary(c);
	printf("Enter the bit number to be toggle:\n");
	scanf("%d",&i);
	c=get_toggle(c,(i-1));
        printf("Toggled Binary code at pos %d: ",i);
	getbinary(c);
	return 0;
}
//function to toggle a bit.
int get_toggle(unsigned char c,int i)
{
	unsigned char byte = 1;
	byte <<=i;
	c ^=byte;
	return c;
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
         printf("\n");
}
