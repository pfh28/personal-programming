/*
	https://www.reddit.com/r/dailyprogrammer/comments/4lpygb/20160530_challenge_269_easy_basic_formatting/
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getNumLines(FILE *inputFile);
int getSpacer(FILE *inputFile, char* spacer);
int removeLeadingSpace(FILE *inputFile, FILE* tmpFile);
int fixSpacing(FILE* inputFile, char* spacer, FILE* tmpFile);
char* trimString(char* string);
int startsWith(const char *prefix, const char *str);
char* addSpacing(char* input, int indents, char* spacer);

int readsize = 1024;

int main()
{
	FILE *tmpFile;
	FILE *inputFile;
	int lines;
	char spacer[readsize];
	
	inputFile = fopen("unformattedBasic.txt","r");
	tmpFile = fopen("tmp.txt", "w");
	
	lines = getNumLines(inputFile);
	getSpacer(inputFile, spacer);
	removeLeadingSpace(inputFile, tmpFile);
	//move tmpfile to input
	//clear tmpfile
	fixSpacing(inputFile, spacer);
	//move tmpfile to inputfile
	
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
	int indents = 0;
	int trailing = 0;
	do
	{
		fgets(tmp, readsize, inputFile);
		trailing = indents;
		
		if(startsWith("FOR", tmp) || startsWith("IF", tmp))
		{
			indents++;
		}
		
		if(startsWith("NEXT", tmp) || startsWith("ENDIF", tmp))
		{
			indents--;
		}
		addSpacing(tmp, trailing, spacer);
		
		fputs(tmp, tmpFile)
	}
	while(!feof(inputFile));
	
	
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
	char spaceBlock[readsize];
	char tmp[readsize];
	strcpy(tmp, spacer);
	int i;
	for(i=0; i<indents; i++)
	{
		strcat(spaceBlock, tmp);
	}
	strcpy(tmp, input);
	strcat(spaceBlock, tmp);


	strcpy(input, spaceBlock);
	return input;
}