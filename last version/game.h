#pragma once
#pragma once
#include <conio.h>
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <time.h>  
#include <windows.h>
#include <cstdlib>
#include <string>
#include <chrono> 

using namespace std;
using namespace std::chrono;

#define col_bank  4 //coloumn of the bank card
#define row_bank  4 //raw of the bank card
#define col_comp  24 //coloumn of the computer card
#define row_comp  5 //raw of the computer card
#define col_ground 24 //coloumn of the ground card
#define row_ground 10 //raw of the ground card
#define col_user  24 //coloumn of the user card
#define row_user  18 //raw of the user card
#define news_col 5 //coloumn of the input 
#define news_row  22 //raw of the input 
#define size_col  115 //total coloumn of the console window 
#define size_row  25 //total raw of the console window
#define begin_template 0
#define name_game 1
#define clock 19
//int y;//globa variable


class Node //Creating a Node with single pointer
{
public:
    int data_right; //the right number of the dominoes card
    int data_left; //the right number of the dominoes card
    Node* next; //Pointer of class (Node) to data of its type
    void appendLast(Node** head_ref, int new_data_left, int new_data_right);
};

class demons //creat the dominoes play 
{
public:
    Node* total; //create linked list of the total cards
    Node* user; //create linked list of the user cards
    Node* comp; //create linked list of the computer cards
    Node* bank; //create linked list of the bank cards
    Node* Ground; //create linked list of the ground cards

    demons();//default constructor

    void Printlist_bank(Node* n); //print linked list of the bank cards
    void Printlist_comp(Node* n); //print linked list of the computer cards
    void Printlist_user(Node* n); //print linked list of the user cards
    void deleteelement(Node** headref, int key_left, int key_right); //delete ellement of linked list by given key
    void delete_Printlist_bank(Node* n); //delete linked list of the bank cards
    void delete_Printlist_comp(Node* n); //delete linked list of the computer cards
    void delete_Printlist_user(Node* n); //delete linked list of the user cards
    int getCount(Node* head); //get the number of node(card) of given linked list  
    int Get_Right_edge_number(Node* head_ref); //get the right number of the right edge card in the ground cards 
    int Get_Left_edge_number(Node* head_ref); //get the left number of the left edge card in the ground cards
    void push_Front(Node** Ground, int left, int right); //push node(card) in the ground cards  
    int Check_buffa(Node* temp); //chech if the buffa cards in the linked list 
    void Computer_take_from_bank(Node** bank, Node** comp);//computer get card from bank cards
    void user_take_from_bank(Node** bank, Node** user);//computer get card from bank cards
    bool add_to_ground(Node** ground, Node** player, int position_card);//retuen true if the given card valid to put it in the ground and return false if not valid to put it in the ground 
    void print_ground(Node* ground);//print the ground cards
    bool check_ability(Node* turn, Node* ground);//check if the user or computer can play any card of its linked list in the ground
    int comp_play(Node* ground, Node* comp);//return the no. of the node(card) which the computer played
    bool Choose_Random_Mode();// choose which computer or user will be play first if they didn't have buffa card 
    int get_data_sum(Node* Cards, int size_of_card);//get the sum of all numbers in the nodes(cards) of given linked list
    bool Check_if_closed(Node* Ground, Node* User, Node* Comp, Node* Bank);//check if the computer and user can't play any card when the bank is empty 
    void Winner(Node* User, Node* Comp, int size_comp, int size_user);//print which the computer or user winner and print the score
    int get_card_sum(Node* Cards, int position_of_card);//get the sum of 2 numbers of given card
    void deleteelement_by_given_position(Node** headref, int position);//delete ellement of linked list by given position 
    void first_play(Node** cards);

};
void gotoxy(short x, short y);//goto any no. of row and coloumn in the console window                                           
void print_template_begin();
void play_game(int i);

