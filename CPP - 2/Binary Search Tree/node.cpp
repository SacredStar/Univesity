#include "Node.h"

Node::Node()
{
	data = NULL;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	root = this;
}

Node::Node(int x)
{
	data = x;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	root = this;
}

void add_node(int x, Node* tree)
{
	if (tree->root == nullptr)
	{
		tree->root = tree;
	}
	//Проверяем где должен быть нод, слева или справа
	if (x >= tree->data)
	{
		if (tree->right == nullptr) //Если свободен устанавливаем правый указатель указателем на текущую ноду
		{
			Node* node_new = new Node(x);
			node_new->root = tree->root;
			tree->right = node_new;
			node_new->parent = tree;
		}
		else {
			add_node(x, tree->right);
		}
	}
	else if (x < tree->data)
	{
		if (tree->left == nullptr)	//Если свободен устанавливаем левый указатель указателем на текущую ноду
		{
			Node* node_new = new Node(x);
			node_new->root = tree->root;
			tree->left = node_new;
			node_new->parent = tree;
		}
		else {
			add_node(x, tree->left);
		}

	}

}

void show_tree(const Node* tree)
{
	if (tree != NULL)
	{
		std::cout << tree->data << " ";
		if (tree->left != nullptr)
		{
			show_tree(tree->left);
		}
		if (tree->right != nullptr)
		{
			show_tree(tree->right);
		}
	}
}

void add_tree(Node* new_tree,Node* adding_tree)
{
	if (adding_tree != NULL)
	{
		if (adding_tree != nullptr)
		{
			add_node(adding_tree->data, new_tree);
		}
		if (adding_tree->left != nullptr && adding_tree != nullptr)
		{
			add_tree(new_tree, adding_tree->left);
		}
		if (adding_tree->right != nullptr && adding_tree != nullptr)
		{
			add_tree(new_tree, adding_tree->right);
		}
	}
}

Node* union_tree(Node* tree_A, Node* tree_B)
{
	
	if (tree_A->root->data == tree_B->root->data)
	{
		Node* tree_C = tree_A;
		//Исключаем дублирование корня
		add_tree(tree_C->left, tree_B->left);
		add_tree(tree_C->right, tree_B->right);
		return tree_C;
	}
	if (tree_A->root->data > tree_B->root->data)
	{
		Node* tree_C = tree_A;
		add_node(tree_B->root->data, tree_C->left);
		add_tree(tree_C->left, tree_B->left);
		add_tree(tree_C->left, tree_B->right);
		return tree_C;
	}
	if (tree_A->root->data < tree_B->root->data)
	{
		Node* tree_C = tree_B;
		add_node(tree_A->root->data, tree_C);
		add_tree(tree_C->left, tree_A->left);
		add_tree(tree_C->left, tree_A->right);
		return tree_C;
	}
	return NULL;
}
