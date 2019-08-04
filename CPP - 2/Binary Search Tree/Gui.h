#pragma once
#include "Node.h"
#include <string>

//Commands_ID Enum
enum comands {
	ADD_NODE = 1,
	PRINT_TREE,
	UNION_TREES,
	Exit,
};

// Asking to input root BST_A,BST_B
void print__root_require(); 

//Getting ROOT_A,ROOT_B
void get_root_A_B(Node* BST_A, Node* BST_B); 

//Command Discription
void print_command_discription(); 

//Fuction for get commands 
void get_comands(Node* BST_A, Node* BST_B, Node* BST_C);

//Commands
void com_add_node(Node* BST_A, Node* BST_B);
void com_print_tree(Node* BST_A, Node* BST_B);
void com_union_print(Node* BST_A, Node* BST_B, Node* BST_C);


