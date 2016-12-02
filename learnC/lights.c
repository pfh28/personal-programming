#include <stdio.h>
#include <string.h>

int flip(int btm, int tp, int* lights)
{

	if(btm > tp)
	{
		int tmp = btm;
		btm = tp;
		tp = tmp;
	}
	
	int i;
	for(i=btm;i<=tp;i++)
	{
		if(lights[i] == 0)
			lights[i] = 1;
		else
			lights[i] = 0;
	}
	return 0;
}

int main()
{
	int l;
	int max = 25;
	char item[max];
	FILE *inpt;
	
	inpt = fopen("lightSwitches.txt","r");
	
	fgets(item, max, (FILE*)inpt);
	l = atoi(item);
	
	int lights[l];
	
	int i;
	for(i=0;i<l;i++)
	{
		lights[i] = 0;
	}
	
	int btm;
	int tp;
	char *tmp;
	
	do
	{
		fgets(item, max, (FILE*)inpt);
		tmp = strtok(item, " ");
		btm = atoi(tmp);
		tmp = strtok(NULL, " ");
		tp = atoi(tmp);
		
		//printf("%d %d\n", btm, tp);
		flip(btm,tp,lights);
	}while(!feof(inpt));
	fclose(inpt);
	
	int count = 0;
	for(i=0;i<l;i++)
	{
		if(lights[i] == 1)
			count++;
	}
	
	printf("%d",count);
	
	return 0;
}