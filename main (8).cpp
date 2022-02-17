#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[15][15];
bool c[11];

void ch(int x, int y, bool z) {
    if (x > 1 && y > 0) c[a[x-2][y-1]] = z;
    if (x > 1 && y < 14) c[a[x-2][y+1]] = z;
    if (x > 0 && y > 1) c[a[x-1][y-2]] = z;
    if (x < 14 && y > 1) c[a[x+1][y-2]] = z;
}

int main() {
    int t, n, r, x, y;
    for (int i = 2; i < 15; i++) {
        x = 0, y = i;
        for (; y >= 0; x++, y--) {
            if (x == 1 && y == 1) continue;
            ch(x, y, true);
            for (int j = 0; j < 5; j++) if (!c[j]) { a[x][y] = j; break; }
            ch(x, y, false);
        }
    }
    for (int i = 1; i < 15; i++) {
        x = i, y = 14;
        for (; x <= 14; x++, y--) {
            //cout << x << " " << y << endl;
            ch(x, y, true);
            for (int j = 0; j < 10; j++) if (!c[j]) { a[x][y] = j; break; }
            ch(x, y, false);
        }
    }
    cin >> t;
    while (t--) {
        r = 0;
        cin >> n;
        while (n--) {
            cin >> x >> y;
            x--, y--;
            r ^= a[x][y];
        }
        
        if (r) cout << "First" << endl;
        else cout << "Second" << endl;
    }
}