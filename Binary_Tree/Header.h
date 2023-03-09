#pragma once
#include <iostream>
using namespace std;
typedef int TYPEINFO;
struct node {
	TYPEINFO data;
	node* left;
	node* right;
};
typedef node* tree;
void init(tree& bst);
void duyetNodeLeftRight(tree bst);
void duyetLeftNodeRight(tree bst);
void duyetLeftRightNode(tree bst);

tree createNode(TYPEINFO x);
int insertNode(tree& bst, TYPEINFO x);
tree search(tree bst, TYPEINFO x);
void infoNode(tree bst);
int remove(tree& bst, TYPEINFO x);
