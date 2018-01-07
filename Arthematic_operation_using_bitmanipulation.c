#include<stdio.h>
#include<stdlib.h>
int getbinary(unsigned int);
int getsum(int,int);
int getsub(int,int);
int getmul(int,int);
int getdiv(int,int);
int getchoice();
int getval();
int main()
{
 	int val1,val2,result,ch;
	while(1)
	{
		ch=getchoice();
		switch(ch)
		{
			case 1:
				val1 = getval();
				val2 = getval();
				result=getsum(val1,val2);
				printf("sum = %d\n",result);
				break;
			case 2:
				val1 = getval();
				val2 = getval();
				result=getsub(val1,val2);
				printf("difference = %d\n",result);
				break;
			case 3:
				val1 = getval();
				val2 = getval();
				result=getmul(val1,val2);
				printf("product = %d\n",result);
				break;
			case 4:
				val1 = getval();
				val2 = getval();
				result=getdiv(val1,val2);
				printf("division = %d\n",result);
				break;
			case 0:
				exit(EXIT_SUCCESS);
			default:
				printf("Invalid choice!\n");
				break;
		}
	}

	return 0;	
}
int getval()
{
	int val;
	printf("Enter the value: ");
	scanf("%d",&val);
	return val;
} 
int getchoice()
{
	int ch;
	printf("Enter the choice:\n1.Add\n2.Subtract\n3.Multiply\n4.Division\n0.Exit\n");
	scanf("%d",&ch);
	return ch;
}
int getbinary(unsigned int c)
{
	unsigned int byte = c;
	int k=0;
	while(k<=31)
	{
		c <<=k;
		c >>=31;
		printf("%d",c);
		k++;
		if (k%8 == 0)
			printf(" ");
		c=byte;
	}

	printf("\n");
}

int getdiv(int val1,int val2)
{
	int result = 0,i=0;
	while(val1 > result)
	{	
		++i;
		result = getmul(val2,i);	
		
	}
	return i;
		
}
int getmul(int val1,int val2)
{
	int result = 0;
	while(val2 !=0)
	{
		if(val2 & 01)
		{
			result = result+val1;
		}
		val1 <<=1;
		val2 >>=1;
	}
	return result;
		
}
int getsub(int val1,int val2)
{
	while(val2 !=0)
	{
		int carry = ~val1 & val2;
		val1 ^=val2;
		val2 = carry <<1;
	}
	return val1;
}
int getsum(int val1,int val2)
{
	while(val2 !=0)
	{
		int carry = val1 & val2;
		val1 =val1^val2;
		val2 = carry <<1;
	}
	return val1;
}
