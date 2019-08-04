//list of sons,BST,Union of BST's,show stright
#include <iostream>
#include "Node.h"
#include "test.h"
#include "Gui.h"

using namespace std;

void main()
{
	//Creating BST_for future work
	Node *BST_A = new Node();
	Node *BST_B = new Node();
	Node *BST_C = new Node();
	
	//WORK
	print__root_require();
	get_root_A_B(BST_A, BST_B);
	print_command_discription();
	get_comands(BST_A, BST_B, BST_C);
	
	//Testing;
	//test();
	system("Pause");
}