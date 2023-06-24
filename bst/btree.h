#ifndef __BTREE_H_
#define __BTREE_H_

struct TreeNode {
    int val;
    struct TreeNode* left, right;
};

struct TreeNode* init(int x);
struct TreeNode* Insert(struct TreeNode* T, int x);
struct TreeNode* Delete(struct TreeNode* T, int x);
struct TreeNode* Find(struct TreeNode* T, int x);
struct TreeNode* Find_min(struct TreeNode* T);
int Delete_min(struct TreeNode* T);
void In_order_traversal(struct TreeNode* T);
void pre_order_traversal(struct TreeNode* T);
void post_order_traversal(struct TreeNode* T);
void Print_leaf(struct TreeNode* T, int sum);
int Are_identical(struct TreeNode* T1, struct TreeNode* T2);

#endif

// pre_order_traversal --> [root] -- [left] -- [right]
// In_order_traversal --> [left] -- [root] -- [right]
// post_order_traversal --> [left] -- [right] -- [root]