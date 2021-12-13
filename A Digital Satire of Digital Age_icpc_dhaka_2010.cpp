#include<bits/stdc++.h>
using namespace std;
const char nl = '\n';

int leftlevel, rightlevel;
string lst, rst;
char leftgrid[7][8], rightgrid[7][8];

int weight(string s) {
    int res = 0;
    for(int i = 0; i < s.size(); i++) {
        int x = s[i];
        while(x) {
            if(x % 2) res += 500;
            else res += 250;
            x /= 2;
        }
    }
    return res;
}

void buildgrid(int startpos, string s, bool type) {
    char grid[7][8];
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 8; j++) grid[i][j] = '.';
    }

    for(int i = startpos, j = 3; (i < (startpos + 4)) and (j >= 0); i++, j--) grid[i][j] = '/';
    for(int i = startpos, j = 4; (i < (startpos + 4)) and (j < 8); i++, j++) grid[i][j] = '\\';
    for(int i = startpos + 3, j = 1; j <= s.size(); j++) grid[i][j] = s[j-1];
    for(int i = startpos + 4, j = 0; j < 8; j++) {
        if(j == 0) grid[i][j] = '\\';
        else if(j == 7) grid[i][j] = '/';
        else grid[i][j] = '_';
    }

    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 8; j++) {
            if(type) rightgrid[i][j] = grid[i][j];
            else leftgrid[i][j] = grid[i][j];
        }
    }
}

void printres() {
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 8; j++) cout << leftgrid[i][j];
        cout << "||";
        for(int j = 0; j < 8; j++) cout << rightgrid[i][j];
        cout << nl;
    }
}

int main() {
    int t, test = 1;
    cin >> t;
    while(t--) {

        string s;
        lst = "", rst = "";
        for(int level = 0; level < 7; level++) {
            cin >> s;
            for(int i = 0; i < 18; i++) {
                if(i and s[i] == '\\' and s[i-1] == '/' and i < 7) leftlevel = level;
                else if(i and s[i] == '\\' and s[i-1] == '/') rightlevel = level;

                if(i < 7 and s[i] >= 'A' and s[i] <= 'Z') lst += s[i];
                if(i > 10 and s[i] >= 'A' and s[i] <= 'Z') rst += s[i];
            }
        }
        cin >> s;

        bool flag = 0;
        if(weight(lst) > weight(rst)) {
            if(leftlevel > rightlevel) flag = 1;
            else {
                buildgrid(2, lst, 0);
                buildgrid(0, rst, 1);
            }
        } else if(weight(rst) > weight(lst)) {
            if(leftlevel < rightlevel) flag = 1;
            else {
                buildgrid(0, lst, 0);
                buildgrid(2, rst, 1);
            }
        } else {
            if(leftlevel == rightlevel) flag = 1;
            else {
                buildgrid(1, lst, 0);
                buildgrid(1, rst, 1);
            }
        }

        cout << "Case " << test++ << ":" << nl;
        if(flag) cout << "The figure is correct." << nl;
        else printres();
    }

    return 0;
}
