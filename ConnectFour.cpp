#include <iostream>
#include <cstdlib>
#include <unistd.h>


int tab[7][6];
int ch, p;
bool end = false;
int a=0;

/* this function prints the choice by user be it player 1 or player two
this is the display function of the program */

int draw()
{
    system("clear");
    for(int i = 0; i<9; i++)
    {
        if(i<2)
        {
        std::cout<<"-";
        } else if(i>7)
        {
        std::cout<<i-1<<"--"<< "\n";
        } else {
        std::cout<<i-1<<"----";
        }
    }
    for(int i = 0; i<6; i++)
    {
        for(int j = 0; j<7; j++)
        {
            if(tab[j][i]!=0)
            {
                if(tab[j][i]==1)
                {
                std::cout<<"| R |";
                }else
                std::cout<<"| Y |";
            }
            else std::cout<<"|   |";
        } std::cout<<"\n";
    }
    for(int i = 0; i<35; i++)
    {
        std::cout<<"=";
    } std::cout<<"\n";
}

/* This function is used to check whether the choice 
is of player 1 or player 2 and if it is in specified range provided*/

void check(int x)
{
    if(tab[x-1][a]!=0 && a<6)
    {
        a++;
        check(x);
    }   else if (p==1 && a<6)
            {
            //checking for player 1
            tab[x-1][a]=1;
            a=0;
            }
        else if (p==2 && a<6)
            {
            //checking for player 2
            tab[x-1][a]=2;
            a=0;
            }
        else
        {
        std::cout << "Choose Number Between 1 to 7!" ;
        a=0;
        p++;
        }
}

/* This Function checks which player won here we check different conditions
where we can get four consecutive signs of a particular player */

int win_check()
{
    for(int i = 0; i<6; i++)
    {
        for(int j = 0; j<7; j++)
        {
        if(tab[j][i]==1 && tab[j+1][i+1]==1 && tab[j+2][i+2]==1 && tab[j+3][i+3]==1)
            {
            end = true;
            std::cout << "\n Player 1 WIN!";
            }
        if(tab[j][i]==1 && tab[j+1][i-1]==1 && tab[j+2][i-2]==1 && tab[j+3][i-3]==1)
            {   
            std::cout << "\n Player 1 WIN!";
            end = true;
            }
        if(tab[j][i]==2 && tab[j+1][i-1]==2 && tab[j+2][i-2]==2 && tab[j+3][i-3]==2)
            {
            std::cout << "\n Player 2 WIN!";
            end=true;
            }
        else if(tab[j][i]==2 && tab[j-1][i-1]==2 && tab[j-2][i-2]==2 && tab[j-3][i-3]==2)
            {
            end = true;
            std::cout << "\n Player 2 WIN!";
            }
        else if(tab[j][i]==1 && tab[j][i-1]==1 && tab[j][i-2]==1 && tab[j][i-3]==1)
            {
            std::cout << "\n Player 1 WIN!";
            end = true;
            }
        else if(tab[j][i]==1 && tab[j-1][i]==1 && tab[j-2][i]==1 && tab[j-3][i]==1)
            {
            std::cout << "\n Player 1 WIN!";
            end = true;
            }
        else if(tab[j][i]==2 && tab[j][i-1]==2 && tab[j][i-2]==2 && tab[j][i-3]==2)
            {
            std::cout << "\n Player 2 WIN!";
            end = true;
            }
        else if(tab[j][i]==2 && tab[j-1][i]==2 && tab[j-2][i]==2 && tab[j-3][i]==2)
            {
            std::cout << "\n Player 2 WIN!";
            end = true;
            }
        }
    }
}

/* here choice is taken from the user and passed to the draw function */

int p_ch()
{
    p = 1;
    while(end!=true)
    {
    std::cout << "Player " << p << ": ";
    std::cin >> ch;

        if (ch>0 && ch<8)
        {
            check(ch);
            draw();
            if (p == 1)
            {
                p++;
            }
            else
            {
                p--;
            }
        }
    else
        {
            std::cout << "Choose Number Between 1 to 7";           
        }
    win_check();
    }
}

int main()
{
    system("clear");
    std::cout<<"WELCOME IN CONNECT 4 \n";
    sleep(1);
    draw();
    p_ch();
    return 0;
}


