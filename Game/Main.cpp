#include <iostream>
#include <locale.h>
#include "Game.h"
#include <conio.h>





int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    Board b(5, 5, '-');
    Game g(b);

    g.Menu();

    return 0;
}

