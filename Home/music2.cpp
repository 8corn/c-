#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

vector<int> music[1010];
vector<int> ans;
int ind[1010];

int main() {
    int n, m;
    printf("n : ");
    scanf("%d", &n);
    printf("m : ");
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int t, cur, prev;
        printf("t : ");
        scanf("%d", &t);
        for(int k = 0; k < t; k++) {
            printf("cur : ");
            scanf("%d", &cur);
            if(k == 0) {
                prev = cur;
            } else {
                music[prev].push_back(cur);
                ind[cur]++;
                prev = cur;
            }
        }
    }
    queue<int> q;
    for(int p = 1; p <= n; p++) {
        if(ind[p] == 0) {
            q.push(p);
        }
    }
    for(int j = 1; j <= n; j++) {
        if(q.empty()) {
            printf("0\n");
            return 0;
        }
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(int y : music[x]) {
            ind[y]--;
            if(ind[y] == 0) {
                q.push(y);
            }
        }
    }
    for(int sing : ans) {
        printf("노래 개수 : %d\n", sing);
    }
    return 0;
}