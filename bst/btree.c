#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "btree.h"

struct TreeNode* init(int x) {
    struct TreeNode* T = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    assert(T != NULL);
    T->val = x;
    T->left = NULL;
    T->right = NULL;
    return T;
}

struct TreeNode* Insert(struct TreeNode* T, int x) {
    if (T == NULL) T = init(x);
    else {
        if (x < T->val) T->left = Insert(T->left, x);
        else T->right = Insert(T->right, x);
    }
    return T;
}

struct TreeNode* Delete(struct TreeNode* T, int x) {
    if (T != NULL) {
        if (x > T->val) T->right = Delete(T->right, x);
        else if (x < T->val) T->left = Delete(T->left, x);
        else { // found the node to be deleted
            // case 1: no children or one child
            if (T->right == NULL || T->left == NULL) {
                struct TreeNode* temp = T;
                if (T->left == NULL) T = T->right;
                else if (T->right == NULL) T = T->left;
                free(temp);
            }
            // case 2: two children
            else {
                // struct TreeNode* temp = Find_min(T->right);
                // T->val = temp->val;
                // T->right = Delete(T->right, T->val);
                T->val = Delete_min(T);
            }
        }
        return T;
    }
}

struct TreeNode* Find_min(struct TreeNode* T) {
    if (T != NULL) {
        if (T->left != NULL) return Find_min(T->left);
        else return T;
    }
    return T;
}

int Delete_min(struct TreeNode* T) {
    struct TreeNode* curr = T;
    struct TreeNode* temp = T->right;

    while (temp->left != NULL) {
        curr = temp;
        temp = temp->left;
    }

    if (curr != T) curr->left = temp->right;
    else curr->right = temp->right;
    return temp->val;
}

struct TreeNode* Find(struct TreeNode* T, int x) {
    // recursive
    if (T != NULL) {
        if (x == T->val) return T;
        else if (x < T->val) return Find(T->left, x);
        else return Find(T->right, x);
    }

    // non-recursive
    while (T != NULL) {
        if (x == T->val) return T;
        else if (x < T->val) T = T->left;
        else T = T->right;
    }
    return T;
}

void In_order_traversal(struct TreeNode* T) {
    // [left] -- [root] -- [right]
    if (T != NULL) {
        In_order_traversal(T->left);
        printf("%d ", T->val);
        In_order_traversal(T->right);
    }
}

void pre_order_traversal(struct TreeNode* T) {
    // [root] -- [left] -- [right]
    if (T != NULL) {
        printf("%d ", T->val);
        pre_order_traversal(T->left);
        pre_order_traversal(T->right);
    }
}

void post_order_traversal(struct TreeNode* T) {
    // [left] -- [right] -- [root]
    if (T != NULL) {
        post_order_traversal(T->left);
        post_order_traversal(T->right);
        printf("%d ", T->val);
    }
}

void Print_leaf(struct TreeNode* T, int sum) {
    if (T == NULL) return;
    if (T->left == NULL && T->right == NULL)
        printf("%d\n", sum + T->val);
    else {
        Print_leaf(T->left, sum + T->val);
        Print_leaf(T->right, sum + T->val);
    }
}

int Are_identical(struct TreeNode* T1, struct TreeNode* T2) {
    if (T1 == NULL && T2 == NULL) return 1;
    else if (T1 == NULL || T2 == NULL) return 0;
    else if (T1->e == T2->e)
        return (Are_identical(T1->left, T2->left) && Are_identical(T1->right, T2->right));
    else return 0;
}