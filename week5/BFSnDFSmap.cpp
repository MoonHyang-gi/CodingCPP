#include <iostream>
#include <conio.h>
#include <queue>
#include <vector>

using namespace std;

//1. 맵 만들기 o
//2. 맵에 장애물 배치 o
//3. 플레이어블 캐릭터 생성 o
//4. 캐릭터는 방향키로 이동 o ?
//5. 적 생성 o
//6. 적은 최단 경로 dfs / bfs 로 플레이어를 따라옴 ?

// 골인 지점 있고 최단 경로 역탐색

const int ROW = 10; //맵의 행 크기
const int COL = 20; //맵의 열 크기

bool visited[ROW][COL];
queue<pair<int, int>> q;

char map[ROW][COL] = { //맵 배열
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', '*', ' ', '*', ' ', '*', '*', '*', '*', '*', ' ', '*', '*', '*', '*', ' ', '*', ' ', '*'},
    {'*', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*'},
    {'*', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', '*', ' ', '*', ' ', '*', ' ', '*'},
    {'*', ' ', '*', '*', '*', '*', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', '*', '*', '*', ' ', '*', ' ', '*', ' ', '*'},
    {'*', ' ', '*', '*', '*', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*'},
    {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
};

//BFS로 X가 O를 쫓아가는 함수
void move_x(int x, int y, int& new_x, int& new_y) {
    int dir_x[4] = { 0, 0, 1, -1 };
    int dir_y[4] = { 1, -1, 0, 0 };

    queue<pair<int, int>> q;
    q.push({ y, x });

    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
    visited[y][x] = true;

    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + dir_y[i];
            int next_x = cur_x + dir_x[i];

            if (next_y < 0 || next_x < 0 || next_y >= ROW || next_x >= COL) continue;
            if (map[next_y][next_x] == '*') continue;
            if (visited[next_y][next_x]) continue;

            visited[next_y][next_x] = true;
            q.push({ next_y, next_x });
        }
    }

    int min_dist = ROW * COL;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (visited[i][j]) {
                int dist = abs(y - i) + abs(x - j);
                if (min_dist > dist) {
                    min_dist = dist;
                    new_x = j;
                    new_y = i;
                }
            }
        }
    }
}


int main() {
    int x = 1; //O 초기 x좌표
    int y = 1; //O 초기 y좌표

    int x2 = 18;
    int y2 = 8;

    // 맵 출력
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == y && j == x) { //O의 위치일 때
                cout << 'O';
            }
            else if (i == y2 && j == x2) {
                cout << 'X';
            }
            else {
                cout << map[i][j];
            }
        }
        cout << endl;
    }

    //키보드 이동
    while (true) {
        if(_kbhit()){
            char input = _getch(); //입력받은 키 저장
            //input = getchar();

            int new_x = x; //새로운 Ox 좌표
            int new_y = y; //새로운 Oy 좌표

            int new_x2 = x2; //새로운 Xx 좌표
            int new_y2 = y2; //새로운 Xy 좌표

            //입력받은 키에 따라 새로운 위치 계산
            switch (input) {
            case 'w':
                new_y--;
                break;
            case 'a':
                new_x--;
                break;
            case 's':
                new_y++;
                break;
            case 'd':
                new_x++;
                break;
            default:
                break;
            }
            //ESC 누르면 종료 //(18,1)에 도달하면 게임 종료
            if ((input == 27) || (new_x == 18 && new_y == 1)) 
            {
                break;
            }

            if (map[new_y][new_x] == '*') {
                continue;
            }

            //새로운 위치로 O 움직임
            x = new_x;
            y = new_y;

            if (x != x2 || y != y2) {
                // X가 O를 찾는 BFS 알고리즘 호출
                memset(visited, false, sizeof(visited)); //visited 배열 false로 초기화
            }
            else break;

            system("cls");

            for (int i = 0; i < ROW; i++) {
                for (int j = 0; j < COL; j++) {
                    if (i == y && j == x) { 
                        cout << 'O';
                    }
                    else if (i == y2 && j == x2) {
                        
                        cout << 'X';
                    }
                    else {
                        cout << map[i][j];
                    }
                }
                cout << endl;
            }
        }
    }

    return 0;
}
