#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 80;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum Direction {STOP = 0, LEFT, RIGHT, UP, DOWN};
Direction dir;
int tailX[100], tailY[100], tailLength;


void Setup(){
    gameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw(){
    system("cls");

    for(int i=0; i < width+2  ; i++ )
        cout<<"#";

    for(int i=0; i < height ; i++ ){
            cout<<endl;
        for(int j = 0; j < width; j++){
            if(j == 0 || j == width-1)
                cout<<"#";

            if(i == y && j == x)
                cout<<"O";

            else if(i == fruitY && j == fruitX)
                cout<<"@";

            else{
                bool print = false;
                for(int k = 0;k < tailLength; k++){

                    if(tailX[k] == j && tailY[k] == i){
                        cout<<"o";
                        print  = true;
                    }

                }
                if(!print)
                    cout<<" ";
            }

        }

    }
    cout<<endl;

    for(int i=0; i < width +2 ; i++ )
        cout<<"#";
    cout<<endl;

    cout<<"SCORE  = "<<score;
}

void Input(){

    if(_kbhit()){
            switch(_getch()){
                case 'a' : dir = LEFT;break;
                case 'd' : dir  = RIGHT;break;
                case 's' : dir = DOWN;break;
                case 'w' : dir = UP;break;
                case 'x' : gameOver = true;break;

            }
    }
}

void Logic(){

    int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
    tailX[0] = x, tailY[0] = y;

    for(int i = 1; i< tailLength; i++){
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(dir){
        case LEFT : x--;break;
        case RIGHT : x++;break;
        case UP : y--;break;
        case DOWN : y++;break;
        default : break;

    }

    if(x > width || x < 0 ||y > height || y < 0  )
        gameOver = true;

    for(int i = 0; i < tailLength; i++)
        if(tailX[i] == x && tailY[i] == y)
            gameOver = true;


    if(x == fruitX && y == fruitY){
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        tailLength++;
    }
}

int main(){
    Setup();
    while(!gameOver){
      Draw();
      Input();
      Logic();
      Sleep(40);

    }
    return 0;
}
