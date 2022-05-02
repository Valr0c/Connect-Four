#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void arena(char arr[7][8]){
    system("CLS");
    cout << "--Connect 4--" << endl;
    for(int k = 1; k <= 7; k++){
        cout << k << " ";
    }
    cout << endl;
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 7; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool cek_horizontal(char arr[7][8], char &winner){
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 4; j++){
            if(arr[i][j] != '-'  && arr[i][j] == arr[i][j+1] && arr[i][j] == arr[i][j+2] && arr[i][j] == arr[i][j+3]){
                winner = arr[i][j];
                return true;
            }
        }
    }
    return false;
}

bool cek_vertikal(char arr[7][8], char &winner){
    for(int i = 1; i <= 7; i++){
        for(int j = 1; j <= 3; j++){
            if(arr[j][i] != '-'  && arr[j][i] == arr[j+1][i] && arr[j][i] == arr[j+2][i] && arr[j][i] == arr[j+3][i]){
                winner = arr[j][i];
                return true;
            }
        }
    }
    return false;
}

bool cek_diagonal_kanan(char arr[7][8], char &winner){
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 4; j++){
            if(arr[i][j] != '-'  && arr[i][j] == arr[i+1][j+1] && arr[i][j] == arr[i+2][j+2] && arr[i][j] == arr[i+3][j+3]){
                winner = arr[i][j];
                return true;
            }
        }
    }
    return false;
}

bool cek_diagonal_kiri(char arr[7][8], char &winner){
    for(int i = 1; i <= 3; i++){
        for(int j = 7; j >= 4; j--){
            if(arr[i][j] != '-'  && arr[i][j] == arr[i+1][j-1] && arr[i][j] == arr[i+2][j-2] && arr[i][j] == arr[i+3][j-3]){
                winner = arr[i][j];
                return true;
            }
        }
    }
    return false;
}

bool cek_draw(bool arr[6][7]){
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 7; j++){
            if(!arr[i][j]){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    srand(time(NULL));
    char board[7][8], winner;
    string name_p1,name_p2;
    int pil,kolom,px=0,py=0;
    bool papan[6][7],muncul=0,aktif=0;
    do{
        cout << "=== Connect Four ===" << endl;
        cout << "1. Play" << endl;
        cout << "0. Quit" << endl;
        cout << ">>> "; cin >> pil;

        if(pil == 1){
            int turn = 1;
            bool connect = false;
            for(int i = 1; i <= 6; i++){
                for(int j = 1; j <= 7; j++){
                    board[i][j] = '-';
                    papan[i][j] = 0;
                }
            }
            cin.ignore();
            cout << "Player 1's (O) name: ";
            getline(cin,name_p1);
            cout << "Player 2's (X) name: ";
            getline(cin,name_p2);
            while(!connect){
                if(rand() % 2 == 0 && muncul != 1 && aktif != 1){
                    do{
                        px = rand() % 7 + 1;
                        py = rand() % 6 + 1;
                    }while(papan[py][px] == 1);
                    board[py][px] = 'P';
                    muncul = 1;
                }
                if(turn % 2 == 1){
                    arena(board);
                    cout << "Turn: " << name_p1 + " (O)" << endl;
                }else{
                    arena(board);
                    cout << "Turn: " << name_p2 + " (X)" << endl;
                }
                cout << "Insert column: "; cin >> kolom;
                int pos_x = kolom, pos_y = 0;
                if(papan[1][pos_x] == 1 || !(kolom >= 1 && kolom <= 7)){
                    cout << "Choose another column" << endl;
                    system("pause");
                }else{
                    do{
                        if(turn % 2 == 1){
                            arena(board);
                            cout << "Turn: " << name_p1 + " (O)" << endl;
                        }else{
                            arena(board);
                            cout << "Turn: " << name_p2 + " (X)" << endl;
                        }
                        if(pos_y == 6 || papan[pos_y+1][pos_x] == 1){
                            papan[pos_y][pos_x] = 1;
                        }else if(turn % 2 == 1){
                            pos_y++;
                            board[pos_y][pos_x] = 'O';
                            board[pos_y-1][pos_x] = '-';
                        }else{
                            pos_y++;
                            board[pos_y][pos_x] = 'X';
                            board[pos_y-1][pos_x] = '-';
                        }
                        if(pos_y == py && pos_x == px){
                            py = 0;
                            px = 0;
                            muncul = 0;
                            aktif = 1;
                        }
                        Sleep(200);
                    }while(papan[pos_y][pos_x] != 1);

                    if(aktif == 1){
                        turn += 2;
                        aktif = 0;
                    }else{
                        turn++;
                    }

                    if(cek_horizontal(board,winner)){
                        arena(board);
                        cout << "Game Over!" << endl;
                        if(winner == 'O'){
                            cout << name_p1 << " (O) Wins!" << endl;
                        }else if(winner = 'X'){
                            cout << name_p2 << " (X) Wins!" << endl;
                        }
                        system("pause");
                        connect = true;
                        system("CLS");
                    }else if(cek_vertikal(board,winner)){
                        arena(board);
                        cout << "Game Over!" << endl;
                        if(winner == 'O'){
                            cout << name_p1 << " (O) Wins!" << endl;
                        }else if(winner = 'X'){
                            cout << name_p2 << " (X) Wins!" << endl;
                        }
                        system("pause");
                        connect = true;
                        system("CLS");
                    }else if(cek_diagonal_kanan(board,winner)){
                        arena(board);
                        cout << "Game Over!" << endl;
                        if(winner == 'O'){
                            cout << name_p1 << " (O) Wins!" << endl;
                        }else if(winner = 'X'){
                            cout << name_p2 << " (X) Wins!" << endl;
                        }
                        system("pause");
                        connect = true;
                        system("CLS");
                    }else if(cek_diagonal_kiri(board,winner)){
                        arena(board);
                        cout << "Game Over!" << endl;
                        if(winner == 'O'){
                            cout << name_p1 << " (O) Wins!" << endl;
                        }else if(winner = 'X'){
                            cout << name_p2 << " (X) Wins!" << endl;
                        }
                        system("pause");
                        connect = true;
                        system("CLS");
                    }else if(turn >= 42 && cek_draw(papan)){
                        arena(board);
                        cout << "Game Over!" << endl;
                        cout << "Draw!" << endl;
                        system("pause");
                        connect = true;
                        system("CLS");
                    }
                }
            }
        }
    }while(pil != 0);
    return 0;
}
