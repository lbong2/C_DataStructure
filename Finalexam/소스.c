#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable : 4996)
#define len 26

#include <string.h>
#pragma warning(disable : 4996)
#include "BTS_library.h"

node* head;
const char delim[] = " \t\r\n,.-%u";



void print_wcount(void* a)
{
	printf("%s : %d\n", ((wcount*)a)->word, ((wcount*)a)->count);
}
void main()
{
	int i, num = 0, cnt = 0;;
	char* tok;
	char str[256];
	wcount wc, * wcp;
	init_tree(&head);
	FILE* fp;
	fp = fopen("test.txt", "rt");
	fgets(str, 255, fp); // read one line
	while (1) {
		tok = strtok(str, delim);
		while (tok) {
			if (tok == NULL)
				break;
			strcpy(wc.word, tok);
			wcp = (wcount*)btv_search(&wc, head, &num, sizeof(wcount), wcount_cmp);
			if (wcp == NULL) {
				wc.count = 1; // count frequency
				btv_insert(&wc, head, &num, sizeof(wcount), wcount_cmp);
			}
			else
				(*wcp).count++;
			tok = strtok(NULL, delim);
		}
		if (feof(fp))
			break;
		fgets(str, 255, fp);
	}
	btv_balance(head, &num, sizeof(wc));
	printf("\n");
	btv_list(head->left, print_wcount);

}