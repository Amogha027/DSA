#ifndef __SLL_H_
#define __SLL_H_

struct Node {
	int num;
	struct Node* next;
};

struct Node* init_node(int X);
struct Node* init_list();

void Insert_start(struct Node* L, int X);
void Insert_end(struct Node* L, int X);
int Insert_pos(struct Node* L, int X, int pos); 

void Delete_start(struct Node* L);
void Delete_end(struct Node* L);
int Delete_pos(struct Node* L, int pos); 

void Print(const struct Node* L);

#endif