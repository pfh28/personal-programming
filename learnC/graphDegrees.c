#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int readSize = 10;
	FILE *graph;
	int *degrees;
	int nodes;
	
	graph = fopen("graph.txt","r");

	char tmp[readSize];
	fgets(tmp, readSize, graph);
	nodes = atoi(tmp);
	
	printf("%d", nodes);

	degrees = (int*)malloc(sizeof(int)*nodes);
	
	int i;
	for(i=0; i < nodes; i++)
	{
		degrees[i] = 0;
	}

	char* tmp2;
	int n;			//node

	do
	{
		fgets(tmp, readSize, graph);
		tmp2 = strtok(tmp, " ");
		n = atoi(tmp2);
		degrees[n-1]++;
		n = atoi(strtok(0, " "));
		degrees[n-1]++;
		
		i++;
	}while(!feof(graph));
	fclose(graph);
	
	for(i=0; i < nodes; i++)
	{
		printf("\n node %d has degree %d", i+1,degrees[i]);
	}
	
	free(degrees);
	return 0;
}