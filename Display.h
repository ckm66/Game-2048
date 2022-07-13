#pragma once
#include <ncurses.h>

void Information_Page()
{
    initscr();

    noecho();

    int x, y;
    getmaxyx(stdscr, y, x);

    box(stdscr, 0, 0);

    attron(A_BOLD);
    attron(A_REVERSE);
    mvaddstr(1, (x - 20) / 2, "Welcome to Game 2048");
    attroff(A_BOLD);
    attroff(A_REVERSE);

    mvhline(2, 1, '*', x - 2);

    attron(A_BOLD);
    //attron(A_REVERSE);
    mvaddstr(3, 1, "General Description:");
    attroff(A_BOLD);
    mvaddstr(4, 1, "Inspired by One of the most famous game on Earth, 2048, this project aims to bring the old but yet outdated game from Moible Phone to Desktop.");


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