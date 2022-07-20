#pragma once
#include <ncurses.h>
#include <utility>
#define KEY_RETURN 10

void Information_Page()
{
    noecho();
    keypad(stdscr, true);

    int x, y;
    getmaxyx(stdscr, y, x);

    box(stdscr, 0, 0);

    int current_x{0};
    int current_y{0};

    attron(A_BOLD);
    mvaddstr(1, (x - 20) / 2, "Welcome to Game 2048");
    attroff(A_BOLD);

    mvhline(2, 1, '*', x - 2);

    attron(A_BOLD);
    // attron(A_REVERSE);
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

    return;
}

std::pair<std::string, std::string> Registeration_Page(int ymax, int xmax, bool Repeated)
{
    WINDOW *Registeration_Page = newwin(ymax, xmax, 0, 0);
    box(Registeration_Page, 0, 0);
    echo();

    wattron(Registeration_Page, A_BOLD);
    wattron(Registeration_Page, A_UNDERLINE);
    mvwaddstr(Registeration_Page, 2 * ymax / 10, xmax / 10, "Player ID");
    mvwaddstr(Registeration_Page, 5 * ymax / 10, xmax / 10, "Password");
    wattroff(Registeration_Page, A_BOLD);
    wattroff(Registeration_Page, A_UNDERLINE);

    mvwhline(Registeration_Page, 2 * ymax / 10 + 1, xmax / 10, 0, 52);
    mvwhline(Registeration_Page, 2 * ymax / 10 + 3, xmax / 10, 0, 52);
    mvwvline(Registeration_Page, 2 * ymax / 10 + 2, xmax / 10 - 1, ACS_VLINE, 1);
    mvwvline(Registeration_Page, 2 * ymax / 10 + 2, xmax / 10 + 51, ACS_VLINE, 1);
    mvwaddch(Registeration_Page, 2 * ymax / 10 + 1, xmax / 10 - 1, ACS_ULCORNER);
    mvwaddch(Registeration_Page, 2 * ymax / 10 + 1, xmax / 10 + 51, ACS_URCORNER);
    mvwaddch(Registeration_Page, 2 * ymax / 10 + 3, xmax / 10 - 1, ACS_LLCORNER);
    mvwaddch(Registeration_Page, 2 * ymax / 10 + 3, xmax / 10 + 51, ACS_LRCORNER);
    if (Repeated == true)
    { mvwaddstr(Registeration_Page, 2 * ymax / 10 + 4, xmax / 10 + 1, "( User Name has been used )");}

    mvwhline(Registeration_Page, 5 * ymax / 10 + 1, xmax / 10, 0, 52);
    mvwhline(Registeration_Page, 5 * ymax / 10 + 3, xmax / 10, 0, 52);
    mvwvline(Registeration_Page, 5 * ymax / 10 + 2, xmax / 10 - 1, ACS_VLINE, 1);
    mvwvline(Registeration_Page, 5 * ymax / 10 + 2, xmax / 10 + 51, ACS_VLINE, 1);
    mvwaddch(Registeration_Page, 5 * ymax / 10 + 1, xmax / 10 - 1, ACS_ULCORNER);
    mvwaddch(Registeration_Page, 5 * ymax / 10 + 1, xmax / 10 + 51, ACS_URCORNER);
    mvwaddch(Registeration_Page, 5 * ymax / 10 + 3, xmax / 10 - 1, ACS_LLCORNER);
    mvwaddch(Registeration_Page, 5 * ymax / 10 + 3, xmax / 10 + 51, ACS_LRCORNER);

    wmove(Registeration_Page, 2 * ymax / 10 + 2, xmax / 10 + 1);
    char Player_ID[51];
    wgetnstr(Registeration_Page, Player_ID, 50);

    std::string Player_Id;
    for (auto it : Player_ID)
    {
        Player_Id += it;
    }

    wmove(Registeration_Page, 5 * ymax / 10 + 2, xmax / 10);
    char PassWord[50];
    wgetnstr(Registeration_Page, PassWord, 49);

    std::string Password;
    for (auto it : PassWord)
    {
        Password += it;
    }

    std::pair<std::string, std::string> User_ID_with_Password;
    User_ID_with_Password = std::make_pair(Player_Id, Password);
    return User_ID_with_Password;
}

std::pair <std::string, std::string> Login_Page(int ymax, int xmax, bool unfound)
{
    WINDOW *Login_Page = newwin(ymax, xmax, 0, 0);
    box(Login_Page, 0, 0);
    echo();
    keypad(Login_Page, true);

    wattron(Login_Page, A_BOLD);
    wattron(Login_Page, A_UNDERLINE);
    mvwaddstr(Login_Page, 2 * ymax / 10, xmax / 10, "Player ID");
    mvwaddstr(Login_Page, 5 * ymax / 10, xmax / 10, "Password");
    wattroff(Login_Page, A_BOLD);
    wattroff(Login_Page, A_UNDERLINE);

    mvwhline(Login_Page, 2 * ymax / 10 + 1, xmax / 10, 0, 52);
    mvwhline(Login_Page, 2 * ymax / 10 + 3, xmax / 10, 0, 52);
    mvwvline(Login_Page, 2 * ymax / 10 + 2, xmax / 10 - 1, ACS_VLINE, 1);
    mvwvline(Login_Page, 2 * ymax / 10 + 2, xmax / 10 + 51, ACS_VLINE, 1);
    mvwaddch(Login_Page, 2 * ymax / 10 + 1, xmax / 10 - 1, ACS_ULCORNER);
    mvwaddch(Login_Page, 2 * ymax / 10 + 1, xmax / 10 + 51, ACS_URCORNER);
    mvwaddch(Login_Page, 2 * ymax / 10 + 3, xmax / 10 - 1, ACS_LLCORNER);
    mvwaddch(Login_Page, 2 * ymax / 10 + 3, xmax / 10 + 51, ACS_LRCORNER);
    if (unfound == true)
    { mvwaddstr(Login_Page, 2 * ymax / 10 + 4, xmax / 10 + 1, "( Player Unfound or Password is Wrong )");}

    mvwhline(Login_Page, 5 * ymax / 10 + 1, xmax / 10, 0, 52);
    mvwhline(Login_Page, 5 * ymax / 10 + 3, xmax / 10, 0, 52);
    mvwvline(Login_Page, 5 * ymax / 10 + 2, xmax / 10 - 1, ACS_VLINE, 1);
    mvwvline(Login_Page, 5 * ymax / 10 + 2, xmax / 10 + 51, ACS_VLINE, 1);
    mvwaddch(Login_Page, 5 * ymax / 10 + 1, xmax / 10 - 1, ACS_ULCORNER);
    mvwaddch(Login_Page, 5 * ymax / 10 + 1, xmax / 10 + 51, ACS_URCORNER);
    mvwaddch(Login_Page, 5 * ymax / 10 + 3, xmax / 10 - 1, ACS_LLCORNER);
    mvwaddch(Login_Page, 5 * ymax / 10 + 3, xmax / 10 + 51, ACS_LRCORNER);

    wmove(Login_Page, 2 * ymax / 10 + 2, xmax / 10 + 1);
    char Player_ID[51];
    wgetnstr(Login_Page, Player_ID, 50);

    std::string Player_Id;
    for (auto it : Player_ID)
    {
        Player_Id += it;
    }

    wmove(Login_Page, 5 * ymax / 10 + 2, xmax / 10);
    char PassWord[50];
    wgetnstr(Login_Page, PassWord, 49);

    std::string Password;
    for (auto it : PassWord)
    {
        Password += it;
    }

    std::pair<std::string, std::string> User_ID_with_Password;
    User_ID_with_Password = std::make_pair(Player_Id, Password);
    return User_ID_with_Password;
}

char Initalization_Window(int ymax, int xmax)
{
    WINDOW *Initalization_Page = newwin(ymax, xmax, 0, 0);
    cbreak();
    noecho();
    keypad(Initalization_Page, true);

    wborder(Initalization_Page, 0, 0, 0, 0, 0, 0, 0, 0);
    wattron(Initalization_Page, A_BOLD);
    wattron(Initalization_Page, A_UNDERLINE);
    mvwaddstr(Initalization_Page, ymax / 4, (xmax - 23) / 2, "Please Make Your Choice");
    wattroff(Initalization_Page, A_BOLD);
    mvwaddstr(Initalization_Page, 2 * ymax / 4 - 2, (xmax / 2 - 30) / 2, "If You Already Have An Account");
    mvwaddstr(Initalization_Page, 2 * ymax / 4 - 2, xmax - (xmax / 2 + 23) / 2, "If You are A New Player");
    wattroff(Initalization_Page, A_UNDERLINE);

    int Input{0};
    int Option{0};
    while (Input != KEY_RETURN && Input != KEY_ENTER)
    {
        wrefresh(Initalization_Page);
        switch (Input)
        {
        case 0:
        {
            wattron(Initalization_Page, A_REVERSE);
            wattron(Initalization_Page, A_BOLD);
            mvwaddstr(Initalization_Page, 2 * ymax / 4, (xmax / 2 - 5) / 2, "Login");
            wattroff(Initalization_Page, A_REVERSE);
            wattroff(Initalization_Page, A_BOLD);

            mvwaddstr(Initalization_Page, 2 * ymax / 4, xmax - (xmax / 2 + 8) / 2, "Register");

            Option = 1;
            break;
        }

        case 1:
        {
            mvwaddstr(Initalization_Page, 2 * ymax / 4, (xmax / 2 - 5) / 2, "Login");

            wattron(Initalization_Page, A_REVERSE);
            wattron(Initalization_Page, A_BOLD);
            mvwaddstr(Initalization_Page, 2 * ymax / 4, xmax - (xmax / 2 + 8) / 2, "Register");
            wattroff(Initalization_Page, A_REVERSE);
            wattroff(Initalization_Page, A_BOLD);

            Option = 2;
            break;
        }
        }
        wrefresh(Initalization_Page);

        Input = wgetch(Initalization_Page);

        if (Input == KEY_LEFT)
        {
            Input = 0;
        }

        else if (Input == KEY_RIGHT)
        {
            Input = 1;
        }
    }

    delwin(Initalization_Page);

    if (Option == 1)
    {
        return 'L';
    }

    return 'R';
}
