#include <iostream>
#include <conio.h>
#include <queue>
#include <vector>

using namespace std;

//1. �� ����� o
//2. �ʿ� ��ֹ� ��ġ o
//3. �÷��̾�� ĳ���� ���� o
//4. ĳ���ʹ� ����Ű�� �̵� o ?
//5. �� ���� o
//6. ���� �ִ� ��� dfs / bfs �� �÷��̾ ����� ?

// ���� ���� �ְ� �ִ� ��� ��Ž��

const int ROW = 10; //���� �� ũ��
const int COL = 20; //���� �� ũ��

bool visited[ROW][COL];
queue<pair<int, int>> q;

char map[ROW][COL] = { //�� �迭
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

//BFS�� X�� O�� �Ѿư��� �Լ�
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
    int x = 1; //O �ʱ� x��ǥ
    int y = 1; //O �ʱ� y��ǥ

    int x2 = 18;
    int y2 = 8;

    // �� ���
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == y && j == x) { //O�� ��ġ�� ��
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

    //Ű���� �̵�
    while (true) {
        if(_kbhit()){
            char input = _getch(); //�Է¹��� Ű ����
            //input = getchar();

            int new_x = x; //���ο� Ox ��ǥ
            int new_y = y; //���ο� Oy ��ǥ

            int new_x2 = x2; //���ο� Xx ��ǥ
            int new_y2 = y2; //���ο� Xy ��ǥ

            //�Է¹��� Ű�� ���� ���ο� ��ġ ���
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
            //ESC ������ ���� //(18,1)�� �����ϸ� ���� ����
            if ((input == 27) || (new_x == 18 && new_y == 1)) 
            {
                break;
            }

            if (map[new_y][new_x] == '*') {
                continue;
            }

            //���ο� ��ġ�� O ������
            x = new_x;
            y = new_y;

            if (x != x2 || y != y2) {
                // X�� O�� ã�� BFS �˰��� ȣ��
                memset(visited, false, sizeof(visited)); //visited �迭 false�� �ʱ�ȭ
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
