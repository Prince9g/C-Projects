#include<iostream>
#include<conio.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int ntail;
enum eDirection {Stop = 0, Left, Right, up, down};
eDirection dir;
void setup(){
    gameOver = false;
    dir = Stop;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void draw(){
    cout << x;
    system("cls");
    for(int i = 0; i <= width; i++){
        cout << '-';
    }
    cout << endl;
    for(int i = 0; i<height; i++){
        for(int j = 0; j< width; j++){
            if(j == 0 || j == width - 1){
                cout << '#';
            }
            if(i == y && j == x){
                cout << "O";
            }
            else if(i == fruitY && j == fruitX){
                cout << "F";
            }
            else{
                bool print = false;
                for(int k=0; k<ntail; k++){
                    if(tailY[k] == i && tailX[k] == j){
                        print = true;
                        cout << 'o';
                    }
                }
                if(!print){
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    for(int i = 0; i <= width; i++){
        cout << '#';
    }
    cout << endl;
    cout << "Score: " << score << endl;
}
void input(){
    if(_kbhit){
        switch(_getch()){
            case 'a' :
                dir = Left;
                break;
            case 'd':
                dir = Right;
                break;
            case 'w': 
                dir = up;
                break;
            case 's':
                dir = down;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}
void logic(){
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2x, prev2y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i=0; i<ntail; i++){
        prev2x = tailX[i];
        prev2y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2x;
        prevY = prev2y;
    }
    switch(dir){
        case Left:
            x--;
            break;
        case Right:
            x++;
            break;
        case up:
            y--;
            break;
        case down:
            y++;
            break;
        default:
            break;
    }

    if(x > width || x < 0 || y > height || y < 0){
        gameOver = true;
    }
    for(int i=0; i<ntail; i++){
        if(tailX[i] == x && tailY[i] == y){
            gameOver = true;
        }
    }
    if(x == fruitX && y == fruitY){
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        ntail++;
    }
}
int main(){
    setup();
    while(!gameOver){
        draw();
        input();
        logic();
    }
    return 0;
}