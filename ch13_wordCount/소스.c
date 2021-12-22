#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable : 4996)

typedef struct _wcount {
	int count;
	char word[20];
}wcount;

int wcount_cmp(const void* a, const void* b)
{
	return strcmp(((wcount*)a)->word, ((wcount*)b)->word);
}
void print_wcount(void* a)
{
	printf("%s : %d\n", ((wcount*)a)->word, ((wcount*)a)->count);
}

void main() {
	char s[] = "All the things you are";
	char delim[] = ", .:";
	char* token;
	token = strtok(s, delim);
	printf("%s\n", token);
	while (token != NULL) {
		token = strtok(NULL, delim);
		printf("%s\n", token);
	}
}
