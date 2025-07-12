#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

enum Direction
{
    STOP,
    LEFT,
    RIGHT,
    TOP,
    BOTTOM
};
Direction dir;

const int height = 20;
const int width = 25;
int headx, heady, fruitx, fruity, score = 0;
int tail_length = 0;
int tailx[100];
int taily[100];
bool game_over;

// Functions that are used in this code.
void snake_setup();
void snake_draw();
void snake_input();
void snake_logic();

void snake_clearScreen()
{
    cout << "\033[2J\033[1;1H"; // ANSI clear screen
}

int main()
{
    char start;
    cout << "---------------------------\n";
    cout << "---- Welcome to the game ----\n";
    cout << "---------------------------\n";
    cout << "Press s to start the game.\n";
    do
    {
        cin >> start;

        if (start == 's')
        {
            cout << "Your game has been started\n";
            snake_setup();
            while (!game_over)
            {
                snake_draw();
                snake_input();
                snake_logic();
            }
        }
        else
        {
            cout << "Please enter 's' to start the game\n";
        }
    } while (start != 's');

    return 0;
}

void snake_setup()
{
    game_over = false;
    dir = STOP;
    headx = width / 2;
    heady = height / 2;
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;
}

void snake_draw()
{
    snake_clearScreen();
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (x == 0)
                cout << "#";
            if (headx == x && heady == y)
                cout << "O";
            else if (fruitx == x && fruity == y)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < tail_length; k++)
                {
                    if (tailx[k] == x && taily[k] == y)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
            if (x == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}

void snake_input()
{
    char c;
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'w':
            dir = TOP;
            break;
        case 's':
            dir = BOTTOM;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'e':
            game_over = true;
            cout << "Exited game.\n";
            break;
        }
    }
}

void snake_logic()
{
    int prevx = tailx[0], prevy = taily[0], prev2x, prev2y;
    tailx[0] = headx;
    taily[0] = heady;
    for (int i = 1; i < tail_length; i++)
    {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    // code for snake movement
    switch (dir)
    {
    case TOP:
        heady--;
        break;
    case BOTTOM:
        heady++;
        break;
    case LEFT:
        headx--;
        break;
    case RIGHT:
        headx++;
        break;
    }
    // code to pass through walls
    if (headx >= width)
        headx = 0;
    else if (headx < 0)
        headx = width - 1;
    if (heady >= height)
        heady = 0;
    else if (heady < 0)
        heady = height - 1;

    if (headx == fruitx && heady == fruity)
    {
        score += 10;
        fruitx = rand() % width;
        fruity = rand() % height;
        tail_length++;
    }
}
