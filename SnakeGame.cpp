#include<iostream>
using namespace std;
int width = 30;
int height = 20;
void draw(){
    system("cls");
    for(int i = 0; i < width; i++){
        cout << '#';
    }
    cout << endl;
    for(int i = 0; i<height; i++){
        for(int j = 0; j< width; j++){
            if(j == 0 || j == width - 1){
                cout << '#';
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
    for(int i = 0; i < width; i++){
        cout << '#';
    }
}
int main(){
    draw();
    return 0;
}