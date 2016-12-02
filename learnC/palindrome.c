#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int isPalindrome(char* str, int len);
int lower(char* str);

int main(int argc, char* argv[])
{
	char* inpt = calloc(100, sizeof(char));
	char* cpy = calloc(100, sizeof(char));
	
	printf("Enter a candidate string\n");
	scanf("%99s", inpt);
	strcpy(cpy, inpt);
	int len = strlen(inpt);
	
	lower(cpy);
	int pal = isPalindrome(cpy, len);

	if(pal)
	{
		printf("%s is a palindrome", inpt);
	}
	else
	{
		printf("%s is not a palindrome", inpt);
	}
	
	return 0;
}

int isPalindrome(char* str, int len)
{
	char* fp = str;
	char* bp = str+len-1;			//last non-null char
	int i = 0;
	int resp = 1;					//default true
	while(i < len/2)
	{
		if(*fp != *bp)
		{
			resp = 0;
		}
		i++;
		fp++;
		bp--;
	}
	
	return resp;
}

int lower(char* str)
{
	char* p = str;
	while(*p)
	{
		*p = tolower(*p);
		p++;
	}
	return 0;
}