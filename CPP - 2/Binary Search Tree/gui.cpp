#include "Gui.h"

void print__root_require()
{
	std::cout << "A,B,C BST's already created so you can operate them" << std::endl;
	std::cout << "BST C used for union_tree function,so he is available only to print" << std::endl;
	std::cout << "At first you must change the root of A,B" << std::endl;
}

void get_root_A_B(Node* BST_A, Node* BST_B)
{
	int root_A, root_B;
	std::cout << "Root_A = "; std::cin >> root_A; std::cout << std::endl;
	std::cout << "Root_B = "; std::cin >> root_B; std::cout << std::endl;
	BST_A->root->data = root_A;
	BST_B->root->data = root_B;
}
//______TODO: if 2 BST's not setted up.Cant Union them.
//Done.
void print_command_discription()
{
	std::cout << "Write Commands to your BST application" << std::endl;
	std::cout << "%Tree_name% has 2 possible value A,B" << std::endl;
	std::cout << "If you want add node to your BST type command: 1 %node_value% %Tree_Name% " << std::endl;
	std::cout << "If you want to print your BST type command: 2 %Tree_Name% " << std::endl;
	std::cout << "If you want to Union your BST's A and B and show created BST C type command: 3 " << std::endl;
	std::cout << "If you want to Close the application type command: 4" << std::endl;
}

void com_add_node(Node* BST_A, Node* BST_B)
{
	std::string tree_name;
	int node_value;
	std::cin >> node_value >> tree_name;
	if (tree_name == "A")
	{
		std::cout << "Node " << node_value << "Added to BST_A" << std::endl;
		std::cin.clear();
		add_node(node_value, BST_A);
	}
	else if (tree_name == "B")
	{
		std::cout << "Node " << node_value << " Added to BST_B" << std::endl;
		std::cin.clear();
		add_node(node_value, BST_B);
	}
	else {
		std::cout << "Wrong attribute sended,write the command again!" << std::endl;
		return;
	}
}

void com_print_tree( Node* BST_A,  Node* BST_B)
{
	std::string tree_name;
	std::cin >> tree_name;
	if (tree_name == "A")
	{
		std::cout << "BST_A is : ";
		show_tree(BST_A);
	}
	if (tree_name == "B")
	{
		std::cout << "BST_B is : ";
		show_tree(BST_B);
	}
	else {
		std::cout << "Wrong attribute sended,write the command again!" << std::endl;
		return;
	}
}

void com_union_print(Node* BST_A, Node* BST_B, Node* BST_C)
{
	BST_C = union_tree(BST_A, BST_B);
	std::cout << "BST_C is :";
	show_tree(BST_C);
}

void get_comands(Node* BST_A, Node* BST_B, Node* BST_C)
{
	int command_id;
	do {
		std::cin >> command_id;
		if (command_id == ADD_NODE)
		{
			com_add_node(BST_A, BST_B);
		}
		if (command_id == PRINT_TREE)
		{
			com_print_tree(BST_A, BST_B);
		}
		if (command_id == UNION_TREES)
		{
			com_union_print(BST_A, BST_B, BST_C);
		}
	} while (command_id != Exit);
}