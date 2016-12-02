#include <stdio.h>
int main()	//main declaration
{
	int n,i;
	printf("enter number \n");	//print statment
	scanf("%d", &n);
	i=0;
	while(n > 1)
	{
		if(n%3 == 0)
			n = n/3;
		else
		{
			if(n+1%3 == 0)
				n++;
			else
				n--;
		}
		i++;
		printf("%d\n",n);
	}
	
	printf("%d steps",i);
	return 0;				
}