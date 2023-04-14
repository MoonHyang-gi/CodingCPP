#pragma once

class MapPrinter {
private:
    Map* map;

public:
    MapPrinter(Map* map_) : map(map_) {}

    void print_map() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map->map[i][j] == 0) {
                    cout << "бс";
                }
                else if (map->get_dist(i, j) != -1) {
                    cout << "б┌";
                }
                else {
                    cout << "бр";
                }
            }
            cout << endl;
        }
    }
};