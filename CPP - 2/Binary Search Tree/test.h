#pragma once
#include "node.h"
#include <vector>
#include <cassert>
//Создание для тестирования Union
Node* create_A();
Node* create_B();
//Создание больших А,B
Node* create_A_test_A();
Node* create_B_test_B();
//Перевод Tree в Vector для Assets
void print_tree_to_vec(const Node*,std::vector<int>&);
//Тесты создания
void test_A();
void test_B();
//Тест соединения
void test_union();
void test();
//Ручное
void tesing_manualy();
