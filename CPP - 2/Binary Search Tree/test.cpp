#include "test.h"


//Tree_A = {5,3,1,4,5,6}
Node* create_A_test_A()
{
	Node *Tree_A = new Node(5);
	add_node(3, Tree_A);
	add_node(1, Tree_A);
	add_node(4, Tree_A);
	add_node(5, Tree_A);
	add_node(6, Tree_A);
	return Tree_A;
}
//Tree_B = { 4,2,1,1,7,5,8 }
Node* create_B_test_B()
{
	Node *Tree_B = new Node(4);
	add_node(2, Tree_B);
	add_node(7, Tree_B);
	add_node(1, Tree_B);
	add_node(1, Tree_B);
	add_node(5, Tree_B);
	add_node(8, Tree_B);
	return Tree_B;
}
//Tree_A = {5,3,6}
Node* create_A()
{
	Node *Tree_A = new Node(5);
	add_node(3, Tree_A);
	add_node(6, Tree_A);
	return Tree_A;
}
//Tree_B = {4,2,1,3}
Node* create_B()
{
	Node *Tree_B = new Node(4);
	add_node(2, Tree_B);
	add_node(1, Tree_B);
	add_node(3, Tree_B);
	return Tree_B;
}

void print_tree_to_vec(const Node* tree,std::vector<int>& vec)
{
	vec.push_back(tree->data);
	if (tree->left != nullptr)
	{
		print_tree_to_vec(tree->left, vec);
	}
	if (tree->right != nullptr)
	{
		print_tree_to_vec(tree->right, vec);
	}
}

void test_A()
{
	auto Tree_A = create_A_test_A();
	std::vector<int> v_a = { 5,3,1,4,5,6 };
	std::vector<int> v_a_try;
	print_tree_to_vec(Tree_A, v_a_try);
	assert(v_a_try == v_a);
	std::cout << "Test A - Clear" << std::endl;
}

void test_B()
{
	auto Tree_B = create_B_test_B();
	std::vector<int> v_b = { 4,2,1,1,7,5,8 };
	std::vector<int> v_b_try;
	print_tree_to_vec(Tree_B, v_b_try);
	assert(v_b_try == v_b);
	std::cout << "Test B - Clear" << std::endl;
}

//TODO: manually_testing function
/*
void tesing_manualy()
{
	//Root's
	int root_a = 4;
	int root_b = 5;
	//Vector to add for Tree's
	std::vector<int> vec_to_test_A = { 1,2,3,4,5,6,22,532 };
	std::vector<int> vec_to_test_B = { 2,5,32,213,543,324,213,534,654 };
	Node *Tree_B = new Node(root_a);
	Node *Tree_A = new Node(root_b);
	Node *Tree_C = union_tree(Tree_A, Tree_B);
	//Exposed vector V_C
	std::vector <int> vec_C = {};
	print_tree_to_vec(Tree_C, vec_C);
	assert(vec_C == v_c);
	std::cout << "Test Union - Clear" << std::endl;

}
*/

void test_union()
{
	auto Tree_A = create_A();
	auto Tree_B = create_B();
	auto Tree_C = union_tree(Tree_A, Tree_B);
	std::vector<int> v_c = { 5,3,2,1,4,3,6 };
	std::vector<int> v_c_try;
	print_tree_to_vec(Tree_C, v_c_try);
	assert(v_c_try == v_c);
	std::cout << "Test Union - Clear" << std::endl;
}

void test()
{
	test_A();
	test_B();
	test_union();
}

