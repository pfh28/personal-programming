/*
	https://www.reddit.com/r/dailyprogrammer/comments/4lpygb/20160530_challenge_269_easy_basic_formatting/
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getNumLines(FILE *inputFile);
int getSpacer(FILE *inputFile, char* spacer);
int removeLeadingSpace(FILE *inputFile, FILE* tmpFile);
int fixSpacing(FILE *inputFile, char *spacer);
char* trimString(char* string);
int startsWith(const char *prefix, const char *str);
char* addSpacing(char* input, int indents, char* spacer);

int readsize = 1024;

int main()
{
	char* result = addSpacing("this is a string", 5, ".");
	printf(result);
/*	FILE *tmpFile = fopen("tmp.txt", "w");
	FILE *inputFile;
	int lines;
	char spacer[readsize];
	
	inputFile = fopen("unformattedBasic.txt","r");
	tmpFile = fopen("tmp.txt", "w");
	
	lines = getNumLines(inputFile);
	getSpacer(inputFile, spacer);					//not working
	removeLeadingSpace(inputFile, tmpFile);
	fixSpacing(inputFile, spacer);
	
	fclose(inputFile);
	*/
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

int removeLeadingSpace(FILE *inputFile, FILE *tmpFile)
{
	char tmp[readsize];
	char* trimmed;
	
	do 
	{
		fgets(tmp, readsize, inputFile);
		trimmed = trimString(tmp);
		fputs(trimmed, tmpFile);
	}
	while(!feof(inputFile));
	
	return 0;
}

int fixSpacing(FILE *inputFile, char *spacer)
{
	char tmp[readsize];
	char* spaced = (char*)malloc(sizeof(char)*readsize);
	int indents = 0;
	do
	{
		fgets(tmp, readsize, inputFile);
		spaced = addSpacing(tmp, indents, spacer);
		
		if(startsWith("FOR", tmp) || startsWith("IF", tmp))
		{
			
		}
	}
	while(!feof(inputFile));
	
	free(spaced);
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

int startsWith(const char *prefix, const char *str)
{
    return strncmp(prefix, str, strlen(prefix)) == 0;
}

char* addSpacing(char* input, int indents, char* spacer)
{
	char spaceBlock[readsize] = "";
	int i;
	for(i=0; i < indents; i++)
	{
		snprintf(spaceBlock, readsize, "%s%s", spaceBlock, spacer);
	}
	
	char rv[readsize];
	snprintf(rv, readsize, "%s%s", spaceBlock, readsize);
	return rv;
}