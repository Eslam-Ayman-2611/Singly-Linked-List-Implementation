//////////////////////////////////////////////////////////////////////////////
// Created by Eslam Ayman Mohamed Refai 
// ID : 152300027 
// Department : Computer Engineering
// last edit on 8/6/2024. 
//////////////////////////////////////////////////////////////////////////////

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Colors.h"

// libyayies 
#include<iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
using namespace std;

// macros
#define DELAY_MS 12

//////////////structure////////////////////////////////////////////////////////////////

//  Our structure of node and the pointer to the head of the linked list
struct node 
{
int data ;
node *next; 
};

node *Sptr = nullptr ;
int out = 0 ;


////////////functions//////////////////////////////////////////////////////////////////

////////////Main functions//////////////////
void welcome_message();
void creat_linked_list();
void options();
void Exit();
////////////////////////////////////////////

//////////////inserting/////////////////////
void main_inserting_options();

void insert_at_head();
void insert_at_end();
void insert_in_index();
void insert_after_data();
////////////////////////////////////////////

//////////////deleting//////////////////////
void main_deleting_options();
void choose_where_Delete();

void delete_from_head();
void delete_from_end();
void delete_by_index();
void delete_by_data();
void delete_all();
////////////////////////////////////////////

///////////////searching////////////////////

void main_searching_options();

void Search_specific_Data();  
void  search_for_smallest_value();
void  search_for_largest_value();

node* find_last_node();
node* find_befor_last_node();
node* find_specific_node(int needed_data);
node* find_before_specific_node(int needed_data);

////////////////////////////////////////////

///////////////Movement////////////////////
void main_movement_options();

void Move_largest_to_end();
void Move_smallest_to_beginning();
void reverse ();
////////////////////////////////////////////

///////////////Reverse////////////////////
void reverse();
////////////////////////////////////////////

///////////////sorting////////////////////
void main_sorting_options();

void Ascending_order_sorting();
void  Descending_order_sorting();
////////////////////////////////////////////

///////////////calculations////////////////////
void main_calculations_options();

void Sum_Average_All_nodes();
void Sum_Average_specific_nodes();
void even_values();
void odd_values();
void specific_values();
////////////////////////////////////////////

///////////////displaying///////////////////
string pointer_To_String(const void* pointer);
void printBox(const string& title, const string& line1, const string& line2, const string& line3);
void printGlobalPointer();
void printNodeInfo(node* currentNode, int nodeIndex);
void display_linked_list();
void printCenteredLine(const string& text, size_t width);
/////////////Reversed////////////////////////
void display_reversed_list(node* Reversed);
void printGlobalPointerReversed(node* head);

///////////////Extra functions//////////////
void clear_Terminal();
void typeText(const string& text);
void typeCText(const string& text, const string& color = "");
void Continue();
// counting
int count_nodes();

#endif