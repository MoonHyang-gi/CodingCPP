#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 10; //�ִ� ũ��

class Map {
public:
    int n, m; //�� ��, ��
    int map[MAX][MAX]; //�� ���� ����
    int dist[MAX][MAX]; //�����~�� ��ġ���� �ִܰŸ� ����
    bool visited[MAX][MAX]; //�湮 ����
    int dx[4] = { -1, 0, 1, 0 }; //�̵� ���� x��ǥ
    int dy[4] = { 0, 1, 0, -1 }; //�̵� ���� y��ǥ

    //�迭 �ʱ�ȭ
    Map(int n_, int m_) : n(n_), m(m_) {
        memset(map, 0, sizeof(map));
        memset(dist, 0, sizeof(dist));
        memset(visited, false, sizeof(visited));
    }

    //map �迭�� ����
    void set_map(int i, int j, int val) {
        map[i][j] = val;
    }

    //�ش� ��ġ������ �ִ� �Ÿ� ��ȯ
    int get_dist(int i, int j) {
        return dist[i][j];
    }

    void bfs(int x, int y) {
        queue<pair<int, int>> q;
        q.push(make_pair(x, y)); //���� ��ġ push
        dist[x][y] = 0; //���� ��ġ�� �ִܰŸ� = 0
        visited[x][y] = true; //���� ��ġ�� �湮�� ������ ó��

        while (!q.empty()) { //ť�� �� ������
            int curr_x = q.front().first; //���� ��ġ�� x��ǥ
            int curr_y = q.front().second; //���� ��ġ�� y��ǥ
            q.pop();

            if (curr_x == n - 1 && curr_y == m - 1) { //�������� �����ϸ� bfs ����
                return;
            }

            //���� ��ġ���� �����¿� �̵�
            for (int i = 0; i < 4; i++) {
                int nx = curr_x + dx[i];
                int ny = curr_y + dy[i];

                //�� ���� ��� or �� or �̹� �湮�� ���̸�)
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (map[nx][ny] == 0 || visited[nx][ny] == true) continue;

                q.push(make_pair(nx, ny)); //�̵��� ��ġ ť �߰�
                visited[nx][ny] = true; //�湮 ó��
                dist[nx][ny] = dist[curr_x][curr_y] + 1; //�湮 Ƚ�� +1
            }
        }
    }
};

class MapPrinter {
public:
    Map* p;
    MapPrinter(Map* map_) : p(map_) {}

    void print_map() {
        for (int i = 0; i < p->n; i++) {
            for (int j = 0; j < p->m; j++) {
                if (p->map[i][j] == 0) { //���̸�
                    cout << "��";
                }
                else if (p->visited[i][j]) { //�湮�� ���̶��
                    cout << "��";
                }
                else { //�̵��� �� �ִ� ���̶��
                    cout << "��";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int n = 5;
    int m = 5;

    //��ü ����
    Map map(n, m); 
    MapPrinter printer(&map);

    cout << "5x5�� ���Դϴ�." << endl;
    cout << "(1, 1)���� �����Ͽ�(5, 5)������ ���� ã���ϴ�." << endl;
    cout << "���� 1, ���� ����� ���� ���� 0�� �Է��� �ۼ����ּ���." << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val;
            cin >> val; //�� ���� �Է�
            map.set_map(i, j, val);
        }
    }

    map.bfs(0, 0); //������ = (1, 1), bfs ����

    cout << "\n�ִ� �Ÿ�: " << map.get_dist(4, 4) << endl; //(5, 5)������ �ִ� �Ÿ�

    if (map.get_dist(4, 4) == 0)
    {
        cout << "�� �� �����ϴ�." << endl;
    }
    else {
        printer.print_map(); //�� ���
    }

    return 0;
}
