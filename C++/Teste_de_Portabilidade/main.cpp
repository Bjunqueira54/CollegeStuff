/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: gothicdread
 *
 * Created on November 9, 2018, 5:42 PM
 */

#include "main.h"
#include <ncurses.h>
#include <curses.h>

using namespace std;

int main(int argc, char** argv)
{
    setScreenSize(50, 50);
    initscr();
    mvwaddstr(stdscr, 0, 0, "Hello!");
    refresh();
    getch();
    endwin();
    return 0;
}

