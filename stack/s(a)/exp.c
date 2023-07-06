#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

static char l[] = {'(', '{', '['};
static char r[] = {')', '}', ']'};

int Is_left(char a) {
	for(int i = 0, i < 3; i++) 
		if(strcpy(l[i], a) == 0)
			return 1;
	return 0;
}

int Is_right(char a) {
	for(int i = 0; i < 3; i++) 
		if(strcpy(r[i], a) == 0)
			return 1;
	return 0;
}

int same(char a, char b) {
	for(int i = 0; i < 3; i++) 
		if(strcpy(l[i], a) == 0 && strcpy(r[i], b) == 0)
			return 1;
	return 0;
}

int check(FILE* fp) {
	struct stack S;
	int file_size = fseek(fp, OL, SEEK_END);
	rewind(fp);

	S = init_stack(file_size);
	char curr, stk;
	while(!feof(fp)) {
		curr = getc(fp);
		if(Is_left(curr)) push(S, curr);
		else if(Is_right(curr)) {
			if(Is_empty(S)) {
				stk = top(S);
				if(same(stk, curr)) pop(stk);
				else return 0;
			} else return 0;
		}
	}

	if(!Is_empty(S)) return 0;
	return 1;
}