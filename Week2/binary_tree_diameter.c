/*  @Author: Kaushal Dokania
    Date: 13th May 2020

URL: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/529/week-2/3293/
Title:  Diameter of Binary Tree

Description: The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
            This path may or may not pass through the root.
    Note: The length of path between two nodes is represented by the number of edges between them.

Solution: Diameter of tree can be calculated by modifying the height() or depth() function.
            Diameter of a tree is equal to the sm of the height/depth of left and right subtree.
            diameter = height(node->left) + height(node->right)

*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

struct TreeNode* newNode(int val) {
    struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


int getDiameter(struct TreeNode* root, int *diameter){
    int ltree_height, rtree_height;

    if (root == NULL)
        return 0;
    else {
        ltree_height = getDiameter(root->left, diameter);
        rtree_height = getDiameter(root->right, diameter);
        
        if (*diameter < (ltree_height + rtree_height))
            *diameter = ltree_height + rtree_height;           // ltree_h and rtree_h are just the heights of subtrees, actual height is + 1
        //printf("\ndata:%d, lh:%d, rh:%d, diameter:%d", root->val, ltree_height, rtree_height, *diameter);
        
        return (ltree_height > rtree_height) ? ltree_height+1 : rtree_height+1;
    }
}

int diameterOfBinaryTree(struct TreeNode* root){
    int diameter=0;
    getDiameter(root, &diameter);
    return diameter;
}

int main() {
    int diameter=0;
    struct TreeNode *node, *root = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3);

    node = root->left;
    node->left  = newNode(4); 
    node->right = newNode(5);

    node = root->left->left;
    node->left  = newNode(7);
    node->right  = newNode(8);

    node = root->left->right;
    printf("\nnode:%d", node->val);
    node->left  = newNode(9);
    node->right  = newNode(10);
    printf("\nnode:%d, left:%d, right:%d]\n", node->val, node->left->val, node->right->val);

    node = root->left->left->left;
    node->left  = newNode(11);
    node->right = newNode(12);

    node = root->left->right->left;
    node->left  = newNode(13); 
    node->right  = newNode(14); 

    node->left->left = newNode(100);

    printf("\nDiameter: %d", diameterOfBinaryTree(root));
    return 0;
}