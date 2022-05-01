

#include "game.h"

extern int  y;
void main()
{

    auto start = high_resolution_clock::now();                                  //get time before finction 



    string begin_of_the_game = "welcome in our  game ... DOMINO'S ...";
    int key;
    while (1)
    {
        int i = 0;
        print_template_begin();
        /*
                gotoxy(col_ground, -1 + row_ground);


                for (int i = 0; i < begin_of_the_game.length(); i++)
                {
                    cout << begin_of_the_game[i];
                    delay_time(clock);
                }
        */
        gotoxy(col_ground, 1 + row_ground);
        cout << "                                       ";
        gotoxy(col_ground, 2 + row_ground);
        cout << "please press any button to play   ... ";
        gotoxy(col_ground, 3 + row_ground);
        cout << "or press esc to  exit  ... ";
        key = _getch();
        if (key != 27)
        {
            system("cls");
            play_game(i);
        }
        else break;


    }
    auto stop = high_resolution_clock::now();                            // get time after funtion
    auto duration = duration_cast<milliseconds>(stop - start);           // get time differnce  (time excution)

    gotoxy(col_ground, 1 + row_ground + 9);
    cout << "                                                  ";
    gotoxy(col_ground, 1 + row_ground + 9);
    cout << "time excution  " << (float)(duration.count()) / (10E3) << endl;          //print time excution in seconds
    gotoxy(col_ground + 10, 16 + row_ground);

}