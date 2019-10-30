#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

const int MAXN = 505;
int n, m, stx, sty;
char map[MAXN][MAXN];
inline void dfs(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m) return ;
    if (map[x + 1][y] != '#' && map[x + 1][y] != '!') {
        map[x + 1][y] = '!';
        dfs(x + 1, y);
    }
    if (map[x][y + 1] != '#' && map[x][y + 1] != '!') {
        map[x][y + 1] = '!';
        dfs(x, y + 1);
    }
    if (map[x - 1][y] != '#' && map[x - 1][y] != '!') {
        map[x - 1][y] = '!';
        dfs(x - 1, y);
    }
    if (map[x][y - 1] != '#' && map[x][y - 1] != '!') {
        map[x][y - 1] = '!';
        dfs(x, y - 1);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 's') {
                stx = i; sty = j;
            }
        }
    dfs(stx, sty);
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (map[i][j] == 'g') {
                flag = 0;
                break;
            }
        if (!flag) break;
    }
    if (flag) printf("Yes\n"); else printf("No\n"); 
    return 0;
}