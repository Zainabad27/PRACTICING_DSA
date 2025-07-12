#include <iostream>
#include<cstdlib>
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
void setup();
void draw();
void input();
void logic();
int main()
{
    char start;
    cout << "   \t\t---------------------------" << endl;
    cout << "    \t\t----Welcome to the game----" << endl;
    cout << "     \t\t---------------------------" << endl;
    cout << "      \t\t Press s to start the game." << endl;
    do
    {
        cin >> start;

        if (start == 's')
        {
            cout << "Your game has been started" << endl;
            setup();
            while (!game_over)
            {
                draw();
                input();
                logic();
            }
        }
        else
        {
            cout << "Please enter 's' to start the game\n"
                 << endl;
        }
    } while (start != 's');

    return 0;
}

void setup()
{
    game_over = false;
    dir = STOP;
    headx = width / 2;
    heady = height / 2;
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;
}
void draw()
{
    system("cls");
    // Drawing uper border.
    cout << "\t\t";
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // Left border
            if (x == 0)
            {
                cout << "\t\t#";
            }
            // printing the head of the snake on the screen.
            if (headx == x && heady == y)
            {
                cout << "O";
            }
            //printing the fruit
            else if (fruitx == x && fruity == y)
            {
                cout << "F";
            }
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
                {
                    cout << " ";
                }
            }

            if (x == width - 1)
            {
                cout << "#";
            }
        }
        cout << endl;
    }
    cout << "\t\t";
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
    cout << "Your score is: " << score << endl;
}
void input()
{ // taking input by the keyboard and changing the direction.
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

            cout << "You have been exited from the game." << endl;
            break;
        }
    }
}
void logic()
{
    // implementing the tail of the snake.

    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x, prev2y;
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

    //when the direction is chaged by the keyboard
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
    // to pass through the walls
    if (headx >= width)
    {
        headx = 0;
    }
    else if (headx <= 0)
    {
        headx = width - 1;
    }
    else if (heady >= height)
    {
        heady = 0;
    }
    else if (heady <= 0)
    {
        heady = height - 1;
    }
    // when snake eats the fruit
    else if (headx == fruitx && heady == fruity)
    {
        fruitx = rand() % width;
        fruity = rand() % height;
        tail_length++;
        score += 10;
    }
}