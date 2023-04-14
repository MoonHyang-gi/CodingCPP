#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 10; //최대 크기

class Map {
public:
    int n, m; //맵 행, 열
    int map[MAX][MAX]; //맵 정보 저장
    int dist[MAX][MAX]; //출발점~각 위치까지 최단거리 저장
    bool visited[MAX][MAX]; //방문 여부
    int dx[4] = { -1, 0, 1, 0 }; //이동 방향 x좌표
    int dy[4] = { 0, 1, 0, -1 }; //이동 방향 y좌표

    //배열 초기화
    Map(int n_, int m_) : n(n_), m(m_) {
        memset(map, 0, sizeof(map));
        memset(dist, 0, sizeof(dist));
        memset(visited, false, sizeof(visited));
    }

    //map 배열값 변경
    void set_map(int i, int j, int val) {
        map[i][j] = val;
    }

    //해당 위치까지의 최단 거리 반환
    int get_dist(int i, int j) {
        return dist[i][j];
    }

    void bfs(int x, int y) {
        queue<pair<int, int>> q;
        q.push(make_pair(x, y)); //시작 위치 push
        dist[x][y] = 0; //시작 위치의 최단거리 = 0
        visited[x][y] = true; //시작 위치는 방문한 것으로 처리

        while (!q.empty()) { //큐가 빌 때까지
            int curr_x = q.front().first; //현재 위치의 x좌표
            int curr_y = q.front().second; //현재 위치의 y좌표
            q.pop();

            if (curr_x == n - 1 && curr_y == m - 1) { //도착점에 도달하면 bfs 종료
                return;
            }

            //현재 위치에서 상하좌우 이동
            for (int i = 0; i < 4; i++) {
                int nx = curr_x + dx[i];
                int ny = curr_y + dy[i];

                //맵 범위 벗어남 or 벽 or 이미 방문한 곳이면)
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (map[nx][ny] == 0 || visited[nx][ny] == true) continue;

                q.push(make_pair(nx, ny)); //이동할 위치 큐 추가
                visited[nx][ny] = true; //방문 처리
                dist[nx][ny] = dist[curr_x][curr_y] + 1; //방문 횟수 +1
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
                if (p->map[i][j] == 0) { //벽이면
                    cout << "■";
                }
                else if (p->visited[i][j]) { //방문한 곳이라면
                    cout << "★";
                }
                else { //이동할 수 있는 곳이라면
                    cout << "□";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int n = 5;
    int m = 5;

    //객체 생성
    Map map(n, m); 
    MapPrinter printer(&map);

    cout << "5x5의 맵입니다." << endl;
    cout << "(1, 1)에서 시작하여(5, 5)까지의 길을 찾습니다." << endl;
    cout << "길은 1, 벽을 만들고 싶은 곳은 0을 입력해 작성해주세요." << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val;
            cin >> val; //맵 정보 입력
            map.set_map(i, j, val);
        }
    }

    map.bfs(0, 0); //시작점 = (1, 1), bfs 수행

    cout << "\n최단 거리: " << map.get_dist(4, 4) << endl; //(5, 5)까지의 최단 거리

    if (map.get_dist(4, 4) == 0)
    {
        cout << "갈 수 없습니다." << endl;
    }
    else {
        printer.print_map(); //맵 출력
    }

    return 0;
}
