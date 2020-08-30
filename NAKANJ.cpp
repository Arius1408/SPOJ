#include <iostream>
#include <queue>
#include <string>

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int d[64][64];

std::queue<int> q;

int stringToCell(std::string s) {
    return (s[0] - 'a') * 8 + (s[1] - '0') - 1;
}

int main() {
    //freopen("file.inp", "r", stdin); freopen("file.out", "w", stdout);

    for (int i = 0; i < 64; ++ i) {
        d[i][i] = 1; /// default
        q.push(i);
        while(!q.empty()) {
            int curCell = q.front();
            int x = curCell / 8, y = curCell % 8;
            q.pop();
            for (int j = 0; j < 8; ++ j) {
                int newx = x + dx[j], newy = y + dy[j];
                if (newx < 0 || newx >= 8 || newy < 0 || newy >= 8) continue;
                int newCell = newx * 8 + newy;
                if (d[i][newCell]) continue;
                d[i][newCell] = d[i][curCell] + 1;
                q.push(newCell);
            }
        }
    }

    int nTest; std::cin >> nTest;

    while(nTest --) {
        std::string cell1, cell2; std::cin >> cell1 >> cell2;
        int startCell = stringToCell(cell1), finishCell = stringToCell(cell2);
        std::cout << d[startCell][finishCell] - 1 << "\n";
    }

    return 0;
}
