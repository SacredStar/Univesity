#pragma once
#include <iostream>


class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node *parent;
private:
	Node *root;

public:
	Node();
	Node(int);

	friend void add_node(int, Node*);//Add_node_to_tree
	friend Node* union_tree(Node*, Node*); //Union 2 trees
	friend void get_root_A_B(Node*, Node*); //function to set BST_A->root,BST_B->root in gui.cpp
};


void show_tree(const Node*); //Print tree to screen

Node* union_tree(Node*, Node*);//Union Tree Function

void add_tree(Node*,Node*); //Adding_Tree to Tree function


