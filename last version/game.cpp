#include "game.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <time.h>  
#include <windows.h>
#include <cstdlib>
#include <string>
#include <chrono> 
int y;
void gotoxy(short x, short y) //goto any no. of row and coloumn in the console window                                           
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}

void ckeck_validation_of_card() {
    gotoxy(news_col, news_row);
    std::cout << "the card  is not  valid  ....choose anoter one please";
    gotoxy(news_col + 53, news_row);
    std::cout << "                                               ";
    gotoxy(news_col + 55, news_row);


}
void Node::appendLast(Node** head_ref, int new_data_left, int new_data_right) //Insert at the end of the linked list
{
    Node* new_node = new Node();
    Node* last = *head_ref; //Pointer to move along the Linked List iteratively
    new_node->data_right = new_data_right;
    new_node->data_left = new_data_left;
    new_node->next = NULL;

    if (*head_ref == NULL) //case if linked list is empty
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)//traverse along linked list
    {
        last = last->next;
    }
    last->next = new_node;
}
int demons::Get_Right_edge_number(Node* head_ref)
{

    Node* last = head_ref; // Pointer to move along the Linked List iteratively

    if (head_ref == NULL)//case if linked list are empty
    {
        return 0;
    }

    while (last->next != NULL)//while loop to get right edge card
    {
        last = last->next;
    }
    return (last->data_right);//return the right data of right edge card
}
int demons::Get_Left_edge_number(Node* head)
{
    return head->data_left;//return the left data of left edge card
}


void demons::push_Front(Node** Ground, int left, int right)
{
    Node* new_node = new Node();//allocate node 
    new_node->data_left = left;//put left number in the data_left
    new_node->data_right = right;//put right number in the data_right

    new_node->next = (*Ground);//make next of new node as head
    (*Ground) = new_node;//move the head to point to the new node
    return;
}

void demons::Computer_take_from_bank(Node** bank, Node** comp)
{
    (*comp)->appendLast(&(*comp), (*bank)->data_left, (*bank)->data_right);//appends new node(new card) which is first card(node) in the bank cards at the end of computer cards 
    deleteelement(&(*bank), (*bank)->data_left, (*bank)->data_right);//delete the first card(node) in the bank cards 
}

int demons::Check_buffa(Node* temp)
{

    for (int i = 1; i <= getCount(temp); i++)//for loop to return the position of the buffa card
    {
        if (temp->data_right == 6 && temp->data_left == 6)
        {
            return i;
        }
        else if (temp->data_right == 5 && temp->data_left == 5)
        {
            return i;

        }
        else if (temp->data_right == 4 && temp->data_left == 4)
        {
            return i;

        }
        else if (temp->data_right == 3 && temp->data_left == 3)
        {
            return i;

        }
        else if (temp->data_right == 2 && temp->data_left == 2)
        {
            return i;

        }
        else if (temp->data_right == 1 && temp->data_left == 1)
        {
            return i;

        }
        else if (temp->data_right == 0 && temp->data_left == 0)
        {
            return i;

        }
        temp = temp->next;
    }
    return 0;//return 0 if buffa cards did not excit in the linked list

}

void demons::Printlist_bank(Node* n) //Printing a bank cards by print bank cards by one coloumn and rows and no. of rows depend on size of bank cards
{
    int x = 0;//local variable

    while (n != NULL)//while loop to print cards in the colloumn of the bank and different rows
    {
        gotoxy(col_bank, x + row_bank);//go to colloumn of the bank and different rows in the console window
        std::cout << "  " << y << " [" << n->data_left; std::cout << "|";
        std::cout << n->data_right << "]";
        n = n->next;//to move to next node(card)
        x++;//to increment the row by one 
    }

}
void demons::Printlist_user(Node* n) //Printing a user cards by print maximum 9 card in each row for organize
{
    y = 1;//global variable
    if (getCount(n) <= 9)//if no. of card is less than or equal 9 and in this case we will print all cards in the same row
    {
        gotoxy(col_user, row_user);//go to colloumn and row of the user in the console window


        while (n != NULL)//while loop to print cards in the user row
        {
            std::cout << "  " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;//to move to next node(card)
            y++;//to put the no. of card beside each card 
        }
    }
    else if (getCount(n) <= 18)//if no. of card is less than or equal 18 and in this case we will print first nine cards in the first row and remainder cards in the second row
    {
        gotoxy(col_user, row_user);//go to colloumn and row of the user in the console window

        for (int i = 0; i < 9; i++)//for loop to print first nine card in the first row of the user row
        {
            std::cout << "   " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }
        gotoxy(col_user, 1 + row_user);//goto second row of user in the console window


        while (n != NULL)//while loop to print remainder cards in the second row of the user row
        {
            std::cout << "  " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }

    }
    else//if no. of card is greater then 18 and in this case we will print first nine cards in the first row and second nine cards in the second row and remainder of cards in the third row
    {
        gotoxy(col_user, row_user);//go to colloumn and row of the user in the console window

        for (int i = 0; i < 9; i++)//for loop to print first nine card in the first row of the user row
        {
            std::cout << "   " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }
        gotoxy(col_user, 1 + row_user);//goto second row of user in the console window
        for (int i = 0; i < 9; i++)//for loop to print second nine cards in the second row of the user row
        {
            std::cout << "  " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;

        }
        gotoxy(col_user, 2 + row_user);//goto third row of user in the console window

        while (n != NULL)//while loop to print remainder cards in the third row of the user row
        {
            std::cout << "  " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }

    }

}
void demons::Printlist_comp(Node* n) //Printing a computer cards by print maximum 9 card in each row for organize
{
    y = 1;//global variable
    if (getCount(n) <= 9) //if no.of card is less than or equal 9 and in this case we will print all cards in the same row
    {
        gotoxy(col_comp, row_comp);//go to colloumn and row of the computer in the console window


        while (n != NULL)//while loop to print cards in the computer row
        {
            std::cout << "  " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;//to move to next node(card)
            y++;//to put the no. of card beside each card
        }
    }
    else if (getCount(n) <= 18)//if no. of cards is less than or equal 18 and in this case we will print first nine cards in the first row and remainder cards in the second row
    {
        gotoxy(col_comp, row_comp);//go to colloumn and row of the computer in the console window

        for (int i = 0; i < 9; i++)//for loop to print first nine card in the first row of the computer row
        {
            std::cout << "   " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }
        gotoxy(col_comp, 1 + row_comp);//goto second row of computer in the console window


        while (n != NULL)//while loop to print remainder cards in the second row of the computer row
        {
            std::cout << "  " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }

    }
    else//if no. of card is greater then 18 and in this case we will print first nine cards in the first row and second nine cards in the second row and remainder of cards in the third row
    {
        gotoxy(col_comp, row_comp);//go to colloumn and row of the computer in the console window

        for (int i = 0; i < 9; i++)//for loop to print first nine card in the first row of the computer row
        {
            std::cout << "   " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }
        gotoxy(col_comp, 1 + row_comp);//goto second row of computer in the console window
        for (int i = 0; i < 9; i++)//for loop to print second nine cards in the second row of the computer row
        {
            std::cout << "  " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;

        }
        gotoxy(col_comp, 2 + row_comp);//goto third row of computer in the console window

        while (n != NULL)//while loop to print remainder cards in the third row of the computer row
        {
            std::cout << "  " << y << " [" << n->data_left; std::cout << "|";
            std::cout << n->data_right << "]";
            n = n->next;
            y++;
        }

    }

}
bool demons::add_to_ground(Node** ground, Node** player, int position_card)
{
    Node* ptrp = *player;
    Node* ptrg = *ground;
    int v;
    for (int i = 1; i < position_card; i++)//for loop to traverse the linked list until reach to the node(card) which given position 
        ptrp = ptrp->next;//move to next node(card)
    if (getCount(*ground) == 0)//if the ground are empty we will put the card dirrectly in ground 
    {
        push_Front(ground, ptrp->data_left, ptrp->data_right);
        deleteelement(player, ptrp->data_left, ptrp->data_right);

        return true;
    }
    else
    {

        int right = Get_Right_edge_number(ptrg);//get right data of right edge card in the ground and declare variable right to store this data
        int left = Get_Left_edge_number(ptrg);//get left data of left edge card in the ground and declare variable left to store this data
    sorry:      if (((right == ptrp->data_right) && (left == ptrp->data_left)) || ((right == ptrp->data_left) && (left == ptrp->data_right)))
    {

        gotoxy(news_col, 1 + news_row);
        std::cout << "                                                                           ";
        gotoxy(news_col, 1 + news_row);

        cout << " press L to left enter or R to  right enter ";
        v = _getch();
        gotoxy(news_col, 1 + news_row);
        std::cout << "                                                                           ";
        if ((v == 76) || (v == 114) || (v == 82) || (v == 108))
        {
            if (v == 82 || v == 114)
            {
                if (ptrp->data_left == right)
                    goto right;
                if (ptrp->data_right == right)
                    goto right1;
            }
            else if (v == 108 || v == 76)
            {
                if (ptrp->data_left == left)
                    goto left;
                if (ptrp->data_right == left)
                    goto left1;
            }

        }
        else
            goto sorry;
    }
    else
    {
        if (ptrp->data_left == left)//if left number of the card equal left we will be able to put it in the ground 
        {
        left:
            push_Front(ground, ptrp->data_right, ptrp->data_left);
            deleteelement(player, ptrp->data_left, ptrp->data_right);
            return true;
        }
        else if (ptrp->data_right == left)//if right number of the card equal left we will be able to put it in the ground
        {
        left1:
            push_Front(ground, ptrp->data_left, ptrp->data_right);
            deleteelement(player, ptrp->data_left, ptrp->data_right);
            return true;
        }
        else if (ptrp->data_left == right)//if left number of the card equal right we will be able to put it in the ground
        {
        right:    ptrg->appendLast(ground, ptrp->data_left, ptrp->data_right);
            deleteelement(player, ptrp->data_left, ptrp->data_right);
            return true;
        }
        else if (ptrp->data_right == right)//if right number of the card equal right we will be able to put it in the groun
        {
        right1:   ptrg->appendLast(ground, ptrp->data_right, ptrp->data_left);
            deleteelement(player, ptrp->data_left, ptrp->data_right);
            return true;

        }
        else {

            ckeck_validation_of_card();//we will not be able to put this card in the ground because 4 previous cases not achieved
            return false;

        }
    }
    }

}

void demons::first_play(Node** cards)
{
    int check = Check_buffa(*cards);
}

void demons::user_take_from_bank(Node** bank, Node** user)
{
    (*user)->appendLast(&(*user), (*bank)->data_left, (*bank)->data_right);//appends new node(new card) which is first card(node) in the bank cards at the end of user cards
    deleteelement(&(*bank), (*bank)->data_left, (*bank)->data_right);//delete the first card(node) in the bank cards
}

HANDLE console_color;
int x1 = 0;
void  demons::print_ground(Node* ground)
{
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    x1 = 0;
    if (getCount(ground) <= 9)
    {

        gotoxy(col_ground, row_ground);



        while (ground != NULL)
        {
            if (!(ground->next) || x1 == 0)
            {
                SetConsoleTextAttribute(console_color, 4);
                x1++;
            }
            else
                SetConsoleTextAttribute(console_color, 15);
            std::cout << "[" << ground->data_left; std::cout << "|";
            std::cout << ground->data_right << "]";
            ground = ground->next;
            SetConsoleTextAttribute(console_color, 15);

        }
    }
    else if (getCount(ground) <= 18)
    {
        gotoxy(col_ground, row_ground);

        for (int i = 0; i < 9; i++)
        {
            if (!(ground->next) || x1 == 0)
            {
                SetConsoleTextAttribute(console_color, 4);
                x1++;
            }
            else
                SetConsoleTextAttribute(console_color, 15);
            std::cout << "[" << ground->data_left; std::cout << "|";
            std::cout << ground->data_right << "]";
            ground = ground->next;
            SetConsoleTextAttribute(console_color, 15);


        }
        int i = 0;

        while (ground != NULL)
        {
            gotoxy(36 - 5 * i + 1 + col_ground, 2 + row_ground);

            if (!(ground->next) || x1 == 0)
            {
                SetConsoleTextAttribute(console_color, 4);
                x1++;
            }
            else
                SetConsoleTextAttribute(console_color, 15);
            std::cout << "   [" << ground->data_right; std::cout << "|";
            std::cout << ground->data_left << "]";
            ground = ground->next;
            SetConsoleTextAttribute(console_color, 15);
            i++;
        }

    }
    else
    {
        gotoxy(col_ground, row_ground);

        for (int i = 0; i < 9; i++)
        {
            if (!(ground->next) || x1 == 0)
            {
                SetConsoleTextAttribute(console_color, 4);
                x1++;
            }
            else
                SetConsoleTextAttribute(console_color, 15);
            std::cout << "[" << ground->data_left; std::cout << "|";
            std::cout << ground->data_right << "]";
            ground = ground->next;
            SetConsoleTextAttribute(console_color, 15);

        }
        for (int i = 0; i < 9; i++)
        {
            gotoxy(36 - 5 * i + 1 + col_ground, 2 + row_ground);

            if (!(ground->next) || x1 == 0)
            {
                SetConsoleTextAttribute(console_color, 4);
                x1++;
            }
            else
                SetConsoleTextAttribute(console_color, 15);
            std::cout << "[" << ground->data_right; std::cout << "|";
            std::cout << ground->data_left << "]";
            ground = ground->next;
            SetConsoleTextAttribute(console_color, 15);

        }
        gotoxy(col_ground, 4 + row_ground);

        while (ground != NULL)
        {
            if (!(ground->next) || x1 == 0)
            {
                SetConsoleTextAttribute(console_color, 4);
                x1++;
            }
            else
                SetConsoleTextAttribute(console_color, 15);
            std::cout << "[" << ground->data_left; std::cout << "|";
            std::cout << ground->data_right << "]";
            ground = ground->next;
            SetConsoleTextAttribute(console_color, 15);

        }

    }
}

void demons::delete_Printlist_user(Node* n) //delete linked list of user by over wrighting
{
    gotoxy(col_user, row_user);
    std::cout << "                                                                                       ";
    gotoxy(col_user, 1 + row_user);
    std::cout << "                                                                                       ";
    gotoxy(col_user, 2 + row_user);
    std::cout << "                                                                                       ";
}
void demons::delete_Printlist_bank(Node* n) //delete linked list of user by over wrighting
{
    std::cout << getCount(n);
    for (int i = 14; i > getCount(n); i--)
    {
        gotoxy(col_bank, -1 + i + row_bank);

        std::cout << "     " << ' '; std::cout << " ";
        std::cout << ' ' << " ";

    }

}

int demons::getCount(Node* head)
{
    int x7 = 0;//local variable
    while (head != NULL)
    {
        x7++;//counter to count no. of card
        head = head->next;//move to the next card 
    }
    return x7;
}
void demons::deleteelement_by_given_position(Node** head_ref, int position) {
    Node* temp = *head_ref;

    // If head needs to be removed
    if (position == 1) {

        // Change head
        *head_ref = temp->next;

        // Free old head
        delete temp;
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 2; i < position; i++)
        temp = temp->next;
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node* next = temp->next->next;

    // Unlink the node from linked list
    delete temp->next; // Free memory

    // Unlink the deleted node from list
    temp->next = next;
}

void demons::deleteelement(Node** headref, int key_left, int key_right) {

    Node* temp = *headref;
    Node* prev = NULL;

    if (temp != NULL && temp->data_right == key_right && temp->data_left == key_left) { //special case :: if the head is to be deleted 
        *headref = temp->next;// Change head
        delete temp;//delete old head
        return;
    }

    else {

        while (temp != NULL && (temp->data_right != key_right || temp->data_left != key_left)) {
            prev = temp;
            temp = temp->next;
            // Node temp->next is the node to be deleted
            // Node previous is the previous of node to be deleted
        }

        if (temp == NULL)//if the key did not exicts in the linked list
            return;

        prev->next = temp->next;//make next of previous node is the same next of temp
        delete temp;// Free memory
    }


}
demons::demons()
{
    int x;//local variable

    Node* current = total;
    //in the following lines of code we will create each card in the dominoes game and the no. of total cards is 28
    for (int i = 0; i < 7; i++)
    {//create 7 cards which left number in each is 0 and right number in each from 0 to 6   
        total->appendLast(&total, 0, i);
    }
    for (int i = 1; i < 7; i++)
    {//create 6 cards which left number in each is 1 and right number in each from 1 to 6
        total->appendLast(&total, 1, i);
    }
    for (int i = 2; i < 7; i++)
    {//create 5 cards which left number in each is 2 and right number in each from 2 to 6
        total->appendLast(&total, 2, i);
    }
    for (int i = 3; i < 7; i++)
    {//create 4 cards which left number in each is 3 and right number in each from 3 to 6
        total->appendLast(&total, 3, i);
    }
    for (int i = 4; i < 7; i++)
    {//create 3 cards which left number in each is 4 and right number in each from 4 to 6
        total->appendLast(&total, 4, i);
    }
    for (int i = 5; i < 7; i++)
    {//create 2 cards which left number in each is 5 and right number in each from 5 to 6
        total->appendLast(&total, 5, i);
    }
    for (int i = 6; i < 7; i++)
    {//create 1 card which left number and right number is 6 
        total->appendLast(&total, 6, i);
    }

    int i = 0, count = 0;//local variables
    srand(time(NULL));//random function to give us random card
    while (count < 7)//give random 7 cards to user
    {
        current = total;
        i = 28 - count;// i start with 28 because in the begining we have 28 card and in each entry the cards decrement by one so i will be decrement by 1
        x = rand() % i;// to limit the no. of card in each entry 

        for (int i = 0; i < x; i++)//get random card according to x
            current = current->next;
        count++;
        user->appendLast(&user, current->data_left, current->data_right);//append the card at the end of linked list of the user 
        deleteelement(&total, current->data_left, current->data_right);//delete the card in the linked list of the total cards 

    }


    while (count < 14)//give random 7 cards to user and remember that value of count in the first entry is 7
    {
        current = total;
        i = 28 - count;
        x = rand() % i;// to limit the no. of card in each entry

        for (int i = 0; i < x; i++)//get random card according to x
            current = current->next;

        count++;

        comp->appendLast(&comp, current->data_left, current->data_right);//append the card at the end of linked list of the computer
        deleteelement(&total, current->data_left, current->data_right);//delete the card in the linked list of the total cards


    }

    while (count < 28)//give random 14 cards to user and remember that value of count in the first entry is 14
    {
        current = total;
        i = 28 - count;
        x = rand() % i;// to limit the no. of card in each entry

        for (int i = 0; i < x; i++)//get random card according to x
            current = current->next;
        count++;
        bank->appendLast(&bank, current->data_left, current->data_right);//append the card at the end of linked list of the bank
        deleteelement(&total, current->data_left, current->data_right);//delete the card in the linked list of the total cards

    }

};

void print_template_begin()
{
    HANDLE console_color;
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
    gotoxy(begin_template + 3 * size_col / 8, begin_template + name_game);
    SetConsoleTextAttribute(console_color, 30);
    std::cout << "/ THE DOMINO's GAME /";

    gotoxy(begin_template + 3 * size_col / 8, begin_template + 1 + name_game);
    std::cout << "/////////////////////";

    gotoxy(begin_template, begin_template);
    for (int i = 0; i < size_col; i++)
        std::cout << '/';
    for (int i = 0; i < size_row; i++)
    {
        gotoxy(begin_template, begin_template + i);

        std::cout << '/';
    }


    for (int i = 0; i < size_row; i++)
    {
        gotoxy(size_col + begin_template, begin_template + i);

        std::cout << '/';
    }
    gotoxy(begin_template, begin_template + size_row);
    for (int i = 0; i < size_col; i++)
    {

        std::cout << '/';

    }


    SetConsoleTextAttribute(console_color, 15);

}
void print_template()
{
    HANDLE console_color;
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
    gotoxy(begin_template + 3 * size_col / 8, begin_template + name_game);
    SetConsoleTextAttribute(console_color, 30);
    std::cout << "/ THE DOMINO's GAME /";

    gotoxy(begin_template + 3 * size_col / 8, begin_template + 1 + name_game);
    std::cout << "/////////////////////";

    gotoxy(begin_template, begin_template);
    for (int i = 0; i < size_col; i++)
        std::cout << '/';
    for (int i = 0; i < size_row; i++)
    {
        gotoxy(begin_template, begin_template + i);

        std::cout << '/';
    }


    for (int i = 0; i < size_row; i++)
    {
        gotoxy(size_col + begin_template, begin_template + i);

        std::cout << '/';
    }
    gotoxy(begin_template, begin_template + size_row);
    for (int i = 0; i < size_col; i++)
    {

        std::cout << '/';

    }
    gotoxy(+4 + col_bank, -1 + row_bank);
    std::cout << "BANK";
    gotoxy(10 + begin_template + 3 * size_col / 8, 2 + begin_template + 1 + name_game);

    std::cout << "COMPUTER";

    gotoxy(12 + begin_template + 3 * size_col / 8, 14 + begin_template + 2 + name_game);
    std::cout << "..YOU..";

    SetConsoleTextAttribute(console_color, 15);

}
bool demons::check_ability(Node* turn, Node* ground)
{
    if (ground == NULL)
        return true;//if ground is empty so all cards in linked list are valid to put it in ground
    int right = Get_Right_edge_number(ground);//get right data of right edge card in the ground and declare variable right to store this data
    int left = Get_Left_edge_number(ground);//get left data of left edge card in the ground and declare variable left to store this data

    while (turn != NULL)//while loop to check any cards in the linked list are valid to put it in ground by test 4 possible cases in each card as shown in the next line of code 
    {
        if (left == turn->data_left || left == turn->data_right || right == turn->data_right || right == turn->data_left)
            return true;
        turn = turn->next;//move to the next card

    }
    return false;// return false if all cards in the linked list are not valid to put it in the ground or if linked list is empty
}
int demons::comp_play(Node* ground, Node* comp)
{
    if (ground == NULL)
        return 1;//if ground is empty the computer will return 1 and it means the computer will play the first card in linked list
    int left = Get_Left_edge_number(ground);//get left data of left edge card in the ground and declare variable left to store this data
    int right = Get_Right_edge_number(ground);//get right data of right edge card in the ground and declare variable right to store this data
    int n = 1;
    while (comp != NULL)//we will traverse allong the linked list until finding a card that achieve one of these 4 condition in the next line of code
    {
        if (left == comp->data_left || left == comp->data_right || right == comp->data_right || right == comp->data_left)
            return n;//return the position of the card which computer will play it 
        comp = comp->next;//move to the next card
        n++;
    }
}
void demons::delete_Printlist_comp(Node* n) //delete linked list of computer by over wrighting
{
    gotoxy(col_comp, row_comp);
    std::cout << "                                                                           ";
    gotoxy(col_comp, 1 + row_comp);
    std::cout << "                                                                           ";
    gotoxy(col_comp, 2 + row_comp);
    std::cout << "                                                                           ";
}
int  no_check(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (int(input[i]) > 48 && int(input[i]) < 60);
        else return 100;

    }
    return stoi(input);
}


void demons::Winner(Node* User, Node* Comp, int size_comp, int size_user)
{
    int score_comp = get_data_sum(User, size_user);//score of the computer is the sum of numbers of user cards
    int score_user = get_data_sum(Comp, size_comp);//score of the user is the sum of numbers of computer cards

    if (score_user > score_comp)
    {
        gotoxy(news_col, news_row);
        std::cout << "                                                                           ";
        gotoxy(news_col, 1 + news_row);
        std::cout << "                                                                           ";
        gotoxy(news_col, news_row);
        std::cout << "( user wins )     score -->  (" << score_user << "  - " << score_comp << " )" << endl;
    }
    else
    {
        gotoxy(news_col, news_row);
        std::cout << "                                                                           ";
        gotoxy(news_col, 1 + news_row);
        std::cout << "                                                                           ";
        gotoxy(news_col, news_row);
        std::cout << "( comp wins )     score -->  (" << score_comp << "  - " << score_user << " )" << endl;

    }
}
bool demons::Check_if_closed(Node* Ground, Node* User, Node* Comp, Node* Bank)
{
    if (getCount(Bank) == 0 && check_ability(User, Ground) == 0, check_ability(Comp, Ground) == 0)
    {
        return 1;       //the game is closed
    }
    else
    {
        return 0;       //the game is still open
    }
}
int demons::get_card_sum(Node* Cards, int position_of_card) {
    int sum = 0;//local variable
    for (int i = 1; i < position_of_card; i++)//for loop to traverse the linked list to reach to the card with given position
    {
        Cards = Cards->next;
    }
    sum = sum + ((Cards->data_left) + (Cards->data_right));//get the sum of 2 numbers of the card with given position
    return sum;
}

int demons::get_data_sum(Node* Cards, int size_of_card)
{

    int sum = 0;//local variable
    for (int i = 0; i < size_of_card; i++)//for loop to traverse the linked list to get sum of 2 numbers in the cards
    {
        sum = sum + ((Cards->data_left) + (Cards->data_right));
        Cards = Cards->next;//move to the next card
    }
    return sum;
}
bool demons::Choose_Random_Mode()
{
    srand(time(0));
    int random_Value = rand();
    return(random_Value % 2);               //  0 ---> Computer begins to play
}                                           //  1 ---> User begins to play
void play_game(int i)
{
    demons* game = new demons;//create object of demons class
    Node* ptru = game->user;
    Node* ptrc = game->comp;
    Node* ptrg = game->Ground;
    Node* ptrb = game->bank;
    string x5;
    int size_of_user = game->getCount(ptru), size_of_comp = game->getCount(ptrc), size_of_bank = game->getCount(ptrb);

    print_template();


    game->Printlist_user(ptru);

    game->Printlist_comp(ptrc);
    game->print_ground(ptrg);
    game->Printlist_bank(ptrb);
    while (1)
    {
        if (i == 0)
        {

        }
    leable1:
        game->Printlist_user(ptru);

        if (size_of_user > 0)
            if (game->check_ability(ptru, ptrg))
            {
                gotoxy(news_col, news_row);
                cout << "                                                                 ";
                gotoxy(news_col, 1 + news_row);
                cout << "                                                                 ";
                gotoxy(news_col, news_row);
                cout << "please enter the no. of card you want to play ";
            again:
                cin >> x5;

                if (no_check(x5) > size_of_user)
                {
                    ckeck_validation_of_card();
                    goto again;
                }

                if (game->add_to_ground(&ptrg, &ptru, no_check(x5)))
                {
                    size_of_user--;
                    game->print_ground(ptrg);
                    if (size_of_user == 0)
                        goto end1;
                    game->delete_Printlist_user(ptru);
                    gotoxy(news_col, news_row);
                    cout << "                                                       ";
                    gotoxy(news_col, 1 + news_row);
                    cout << "                                                       ";
                }
                else goto again;

            }
            else if (size_of_bank > 0)
            {
                size_of_user++;
                size_of_bank--;
                game->user_take_from_bank(&ptrb, &ptru);
                game->delete_Printlist_bank(ptrb);
                game->Printlist_user(ptru);

                goto leable1;

            }
            else if (game->Check_if_closed(ptrg, ptru, ptrc, ptrb))
                goto end1;
            else goto computer;
        else goto end1;

    computer:
        game->Printlist_comp(ptrc);

        if (size_of_comp > 0)
            if (game->check_ability(ptrc, ptrg))
            {
                game->add_to_ground(&ptrg, &ptrc, game->comp_play(ptrg, ptrc));
                size_of_comp--;
                if (size_of_comp == 0)
                    goto end1;
                game->delete_Printlist_comp(ptrc);

                game->Printlist_comp(ptrc);

                game->print_ground(ptrg);

            }
            else if (size_of_bank > 0)
            {
                game->Computer_take_from_bank(&ptrb, &ptrc);
                size_of_bank--;
                size_of_comp++;
                game->delete_Printlist_bank(ptrb);
                game->Printlist_comp(ptrc);
                goto computer;
            }
            else if (game->Check_if_closed(ptrg, ptru, ptrc, ptrb))
                goto end1;
            else goto leable1;

    }



end1:
    {
        game->Winner(ptru, ptrc, size_of_comp, size_of_user);

    }
    delete game;

    gotoxy(news_col, news_row + 1);
    cout << "please press any button ... ";
    _getch();
    system("cls");
}
