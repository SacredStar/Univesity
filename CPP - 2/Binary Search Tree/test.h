#pragma once
#include "node.h"
#include <vector>
#include <cassert>
//�������� ��� ������������ Union
Node* create_A();
Node* create_B();
//�������� ������� �,B
Node* create_A_test_A();
Node* create_B_test_B();
//������� Tree � Vector ��� Assets
void print_tree_to_vec(const Node*,std::vector<int>&);
//����� ��������
void test_A();
void test_B();
//���� ����������
void test_union();
void test();
//������
void tesing_manualy();
