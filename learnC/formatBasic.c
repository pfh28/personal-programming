/*
	https://www.reddit.com/r/dailyprogrammer/comments/4lpygb/20160530_challenge_269_easy_basic_formatting/
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getNumLines(FILE *inputFile);
int getSpacer(FILE *inputFile, char* spacer);
int removeLeadingSpaces(FILE *inputFile);
int fixSpacing(FILE *inputFile, char *spacer);
char* trimString(char* string);

int readsize = 1024;

int main()
{
	FILE *inputFile;
	int lines;
	char *spacer;
	
	inputFile = fopen("unformattedBasic.txt","r");
	
	lines = getNumLines(inputFile);
	getSpacer(inputFile, spacer);					//not working
	
	removeLeadingSpace(inputFile);
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

int removeLeadingSpace(FILE *inputFile)
{
	FILE *outputFile = fopen("tmp.txt", "w");
	char tmp[readsize];
	char* trimmed;
	
	do 
	{
		fgets(tmp, readsize, inputFile);
		trimmed = trimString(tmp);
		fputs(trimmed, outputFile);
	}
	while(!feof(inputFile));
	
	return 0;
}

int fixSpacing(FILE *inputFile, char *spacer)
{
	return 0;
}

char* trimString(char* string)
{
	//while(isspace(*string))					//for use with actual whitespace
	//	string++;
	 
	while((string[0] == '·' || (string[0] == '»')))		//for use with the exercise
	{
		string++;
	}
	
	return string;
}