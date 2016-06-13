/*
	https://www.reddit.com/r/dailyprogrammer/comments/4lpygb/20160530_challenge_269_easy_basic_formatting/
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getNumLines(FILE *inputFile);
char* getSpacer(FILE *inputFile);
int removeLeadingSpaces(FILE *inputFile);
int fixSpacing(FILE *inputFile, char *spacer);

int readsize = 1024;

int main()
{
	FILE *inputFile;
	int lines;
	char *spacer;
	
	inputFile = fopen("unformattedBasic.txt","r");
	
	lines = getNumLines(inputFile);
	getSpacer(inputFile, spacer);
	
	removeLeadingSpaces(inputFile);
	fixSpacing(inputFile, spacer);
	
	fclose(inputFile);
	
	return 0;
}

int getNumLines(FILE *inputFile)
{
	char tmp[readsize];
	fgets(tmp, readsize, inputFile);
	
	int n = atoi(tmp);

	free(tmp);
	return n;
}

int getSpacer(FILE *inputFile, char* spacer)
{
	fgets(spacer, readsize, inputFile);
	return 0;
}

int removeLeadingSpaces(FILE *inputFile)
{
	FILE *outputFile = fopen("tmp.txt", "r");
	
	
	
	return 0;
}

int fixSpacing(FILE *inputFile, char *spacer)
{
	return 0;
}