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
    {
        mvwaddstr(Registeration_Page, 2 * ymax / 10 + 4, xmax / 10 + 1, "( User Name has been used )");
    }

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
    std::string Player_Id(Player_ID);

    wmove(Registeration_Page, 5 * ymax / 10 + 2, xmax / 10);
    char PassWord[51];
    wgetnstr(Registeration_Page, PassWord, 50);
    std::string Password(PassWord);

    std::pair<std::string, std::string> User_ID_with_Password;
    User_ID_with_Password = std::make_pair(Player_Id, Password);
    return User_ID_with_Password;
}

std::pair<std::string, std::string> Login_Page(int ymax, int xmax, bool unfound)
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
    {
        mvwaddstr(Login_Page, 2 * ymax / 10 + 4, xmax / 10 + 1, "( Player Unfound or Password is Wrong )");
    }

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
    char PassWord[51];
    wgetnstr(Login_Page, PassWord, 50);

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

int game_Menu(int ymax, int xmax, bool previous_Game)
{
    WINDOW *Menu = newwin(ymax, xmax, 0, 0);
    box(Menu, 0, 0);
    keypad(Menu, true);

    struct menu_Option
    {
        int y_Position;
        int x_Position;
        std::string Option;
    } Options[4];

    Options[0].y_Position = 5 * ymax / 10;
    Options[0].x_Position = (xmax - 9) / 2;
    Options[0].Option = "Load Game";

    Options[1].y_Position = 6 * ymax / 10;
    Options[1].x_Position = (xmax - 8) / 2;
    Options[1].Option = "New Game";

    Options[2].y_Position = 7 * ymax / 10;
    Options[2].x_Position = (xmax - 4) / 2;
    Options[2].Option = "Rank";

    Options[3].y_Position = 8 * ymax / 10;
    Options[3].x_Position = (xmax - 4) / 2;
    Options[3].Option = "Exit";

    wattron(Menu, A_UNDERLINE);
    wattron(Menu, A_BOLD);
    mvwaddstr(Menu, ymax / 10, (xmax - 15) / 2, "Welcome To 2048");
    wattroff(Menu, A_BOLD);

    int Highlight = 1;
    if (previous_Game == true)
    {
        Highlight = 0;
    }

    while (true)
    {
        for (int n = 0; n < 4; n++)
        {
            if (previous_Game == false && n == 0)
            {
                continue;
            }

            if (n == Highlight)
            {
                wattron(Menu, A_REVERSE);
                wattron(Menu, A_BOLD);
            }

            mvwaddstr(Menu, Options[n].y_Position, Options[n].x_Position, Options[n].Option.c_str());
            wattroff(Menu, A_REVERSE);
            wattroff(Menu, A_BOLD);
        }

        int Direction = wgetch(Menu);
        switch (Direction)
        {
        case KEY_UP:
            Highlight--;
            break;

        case KEY_DOWN:
            Highlight++;
            break;

        case KEY_RETURN:
            delwin(Menu);
            return Highlight;

        default:
            continue;
        }

        if (Highlight > 3)
        {
            Highlight = 3;
        }

        else if (Highlight < 0 && previous_Game == true)
        {
            Highlight = 0;
        }

        else if (Highlight < 1 && previous_Game == false)
        {
            Highlight = 1;
        }
    }
}

int game_Size(int ymax, int xmax)
{
    WINDOW *Game_Size_Window = newwin(ymax, xmax, 0, 0);
    box(Game_Size_Window, 0, 0);
    keypad(Game_Size_Window, true);

    wattron(Game_Size_Window, A_BOLD);
    mvwaddstr(Game_Size_Window, ymax / 2, (xmax - 44) / 2, "Please Choose Your Desire Game Board Size: ");
    wattroff(Game_Size_Window, A_BOLD);
    int option{0};
    int board_size{2};
    while (option != KEY_RETURN)
    {
        wattron(Game_Size_Window, A_REVERSE);
        wattron(Game_Size_Window, A_BOLD);
        mvwprintw(Game_Size_Window, ymax / 2, (xmax - 44) / 2 + 44, "%02d", board_size);
        wattroff(Game_Size_Window, A_REVERSE);
        wattron(Game_Size_Window, A_BOLD);

        option = wgetch(Game_Size_Window);
        switch (option)
        {
        case KEY_UP:
            board_size++;
            break;
        case KEY_DOWN:
            board_size--;
            break;
        case KEY_RETURN:
            delwin(Game_Size_Window);
            return board_size;
        default:
            continue;
        }

        if (board_size < 2)
        {
            board_size = 2;
        }

        else if (board_size > 5)
        {
            board_size = 5;
        }
    }
    return 0;
}

char Game_Board(int ymax, int xmax)
{
    WINDOW *Game_Board = newwin(ymax, xmax, 0, 0);
    box(Game_Board, 0, 0);
    wrefresh(Game_Board);

    mvwaddch(Game_Board, 0, 8 * xmax / 10, ACS_TTEE);
    mvwvline(Game_Board, 1, 8 * xmax / 10, ACS_VLINE, ymax - 2);
    mvwaddch(Game_Board, ymax - 1, 8 * xmax / 10, ACS_BTEE);

    mvwhline(Game_Board, 3 * ymax / 10, 8 * xmax / 10 + 1, 0, 2 * xmax / 10 - 1);

    char swipe;
    while (true)
    {
        swipe = wgetch(Game_Board);
        if (swipe == 'w' || swipe == 'a' || swipe == 's' || swipe == 'd')
        {
            break;
        }
    }
    return swipe;
}