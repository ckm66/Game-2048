#pragma once
#include <ncurses.h>

void Information_Page()
{
    initscr();

    noecho();

    int x, y;
    getmaxyx(stdscr, y, x);

    box(stdscr, 0, 0);

    int current_x {0};
    int current_y {0};

    attron(A_BOLD);
    mvaddstr(1, (x - 20) / 2, "Welcome to Game 2048");
    attroff(A_BOLD);

    mvhline(2, 1, '*', x - 2);

    attron(A_BOLD);
    //attron(A_REVERSE);
    mvaddstr(3, 1, "General Description:");
    attroff(A_BOLD);
    mvaddstr(4, 1, "Inspired by One of the most famous game on Earth, 2048, this project aims to bring the old but yet outdated game from Moible Phone to Desktop.");
    mvaddstr(5, 1, "This Project is original HKU Computer Course Group Project. The Current Vision is revisted and built on my own.");

    mvhline(6, 1, '*', x - 2);
    
    attron(A_BOLD);
    mvaddstr(7, 1, "Achievement:");
    mvaddstr(8, 1, "-");
    attroff(A_BOLD);

    
    mvaddstr(8, 2, " Acheived Project Full Marks");

    mvhline(9, 1, '*', x - 2);

    attron(A_BOLD);
    mvaddstr(10, 1, "Features: ");
    mvaddstr(11, 1, "-");
    mvaddstr(12, 1, "-");
    mvaddstr(13, 1, "-");
    mvaddstr(14, 1, "-");
    attroff(A_BOLD);

    mvaddstr(11, 2, " Written in C++ & NCurses");
    mvaddstr(12, 2, " Save & Load Game");
    mvaddstr(13, 2, " Use of Arrow Key for Game Operation");
    mvaddstr(14, 2, " Score Board");


    mvhline(15, 1, '*', x - 2);


    attron(A_BOLD);
    mvaddstr(16, 1, "Designed and Produced by");
    mvaddstr(17, 1, "Cheung Kam Man, Stephen");
    attroff(A_BOLD);

    attron(A_BOLD);
    attron(A_REVERSE);
    mvaddstr(y - 2, (x - 25) / 2, "Click Any Key To Continue");
    attroff(A_BOLD);
    attroff(A_REVERSE);



    getch();

    refresh();

    endwin();

    return;
}  