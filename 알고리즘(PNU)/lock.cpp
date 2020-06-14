#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;

// 1. ��� ���� ��� �� ���ؼ� ������ ������ ������ ��� �Ϳ� ���� �������� �����ϰ� �ִ� [i][j]�� �����ָ� �ȴ�.
// ������ ��� �Ϳ� ���� �������� �����ϰ� �ִ� [i][j]�� ���ٸ� 0�� ����ϸ� �ȴ�.
// 2. _�� ó���Ǿ� �ִ� �͵��� �ϳ��� ���Ƽ� bfs�� ������ �� ������ ���� �ش� [i][j]�� ����ϸ� �ȴ�.
// 2���� ������� Ǯ����.

ifstream in("lock.inp");
ofstream out("lock.out");
int n, m;
int startX, startY; // S�� ��ġ�� ��Ÿ��.
int resultX, resultY; // T �� ��ġ�� ��Ÿ��.
char ar[31][31] = { 0, };
int order[31][31] = { 0, }; //  �湮 ����
bool visited[31][31] = { 0, }; // �ش� i, j�� �湮�� Ƚ��.
bool isCut[31][31] = { 0, }; // �ش��ϴ� vertex�� cut vertex���� ����.
int cnt; // �湮���� count.
bool result = false; // T �� ������ ��� -> true;
void input();
int dfs(int x, int y, int root);
void solution();
int main(void){
    ios_base::sync_with_stdio(false);
    in.tie(nullptr);
    input();

    // cut vertex ���ϱ�.
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(visited[i][j] == false)
                dfs(i, j, true);
        }
    }

    // �ش� ���ϴ� ����.
    vector <pair <int, int> > v;
    stack <pair <int, int> > st;
    queue <pair <int, int> > q;

    int prevX[31] = { 0, }; // ������ �湮�� ��. ���߿� result�� ���� ���� ���� �ڿ� ������ �Ұ���.
    int prevY[31] = { 0, };
    pair <int, int> prev[31][31];
    // ó������ �����Ǿ� �ִ� ��������� ����.
    q.push(pair<int, int>(startX, startY));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        visited[x][y] = true; // �ش� [i][j]�� �湮��.
        q.pop();
        if(x == resultX && y == resultY){
            result = true; // ���� -> ������ ��찡 �ִٴ� �͸� ã�Ҵٸ� ���̻� ���ص� �ȴ�.
            break;
        }
        if(visited[x+1][y] == false && ar[x+1][y] != '#' && x < m){
            q.push(pair<int, int>(x+1, y));
            prev[x+1][y].first = x;
            prev[x+1][y].second = y;

        }
        if(visited[x][y+1] == false && ar[x][y+1] != '#' && y < n){
            q.push(pair<int, int>(x, y+1));
            prev[x][y+1].first = x;
            prev[x][y+1].second = y;
        }
        if(visited[x-1][y] == false && ar[x-1][y] != '#' && x > 1){
            q.push(pair<int, int>(x-1, y));
            prev[x-1][y].first = x;
            prev[x-1][y].second = y;
        }
        if(visited[x][y-1] == false && ar[x][y-1] != '#' && y > 1){
            q.push(pair<int, int>(x, y-1));
            prev[x][y-1].first = x;
            prev[x][y-1].second = y;
        }
    }
    if(result == false){ // ó������ �����Ǿ� �մ� ���.
        out << 0;
        return 0;
    }
    // ó������ �����Ǿ� ���� ���� ���. �ʱ�ȭ �۾�.
    result = false;
    memset(visited, false, sizeof(visited));
/*
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(isCut[i][j])
                cout << i << " " << j << "\n";
        }
    }
*/
    bool isCutST[31][31] = { 0, };
    int i = resultX;
    int j = resultY;
    while(startX != i || startY != j){
        int x = prev[i][j].first;
        int y = prev[i][j].second;
        isCutST[x][y] = true;
        i = x;
        j = y;
    }

    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(isCut[i][j] && !isCutST[i][j])
                isCut[i][j] = false;
        }
    }

    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(isCut[i][j] == true && ar[i][j] == '_'){ //
                ar[i][j] = '#'; // �ӽ÷� �ٲ۴�.
                queue <pair <int, int> > q2;
                q2.push(pair<int, int>(startX, startY));

                while(!q2.empty()){
                    int x = q2.front().first;
                    int y = q2.front().second;
                    visited[x][y] = true; // �ش� [i][j]�� �湮��.
                    q2.pop();
                    if(x == resultX && y == resultY){
                        result = true; // ���� -> ������ ��찡 �ִٴ� �͸� ã�Ҵٸ� ���̻� ���ص� �ȴ�.
                        break;
                    }
                    if(visited[x+1][y] == false && ar[x+1][y] != '#' && x < m)
                        q2.push(pair<int, int>(x+1, y));
                    if(visited[x][y+1] == false && ar[x][y+1] != '#' && y < n)
                        q2.push(pair<int, int>(x, y+1));
                    if(visited[x-1][y] == false && ar[x-1][y] != '#' && x > 1)
                        q2.push(pair<int, int>(x-1, y));
                    if(visited[x][y-1] == false && ar[x][y-1] != '#' && y > 1)
                        q2.push(pair<int, int>(x, y-1));
                }
                if(result == false){ // ���� ���� �� ���� ���. ��, lockdown�� ���.
                    v.push_back(pair<int, int>(i, j));
                }
                // �ʱ�ȭ�۾�
                result = false;
                ar[i][j] = '_'; // �ٽ� �����·�.
                memset(visited, false, sizeof(visited));
            }
        }
    }

    if(v.size() == 0){ // lockdown�ϴ� ���� ���� ���.
        out << 0;
    }else{ // ���� �����ϴ� ���.
        out << v.size() << endl;
        for(int i = 0; i < v.size(); ++i){
            out << v[i].first << " " << v[i].second << endl;
        }
    }

	return 0;
}

void input(){
    in >> n >> m;
    for(int j = 1; j <= n; ++j){ // �ε��� ��ġ�� �� �ٸ��� �̰��� ������ ���ؼ� �ش��ϴ� �� ã������.
        for(int i = 1; i <= m; ++i){
            in >> ar[i][n+1-j];
            //cout << i << " " << n+1-j;
            if(ar[i][n+1-j] == 'S'){
                startX = i;
                startY = n+1-j;
            }else if(ar[i][n+1-j] == 'T'){
                resultX = i;
                resultY = n+1-j;
            }
        }
    }
}

int dfs(int x, int y, int root){
    order[x][y] = ++cnt;
    int ret = order[x][y];
    int childNum = 0;

    if(order[x+1][y] == true)
        ret = min(ret, order[x+1][y]);
    else if(order[x+1][y] == false && ar[x+1][y] != '#' && x < m){
        childNum++;
        int val = dfs(x+1, y, false);
        if(root == false && val >= order[x][y]){
            isCut[x][y] = true;
        }

        ret = min(ret, val);
    }
    if(order[x][y+1] == true)
        ret = min(ret, order[x][y+1]);
    else if(order[x][y+1] == false && ar[x][y+1] != '#' && y < n){
        childNum++;
        int val = dfs(x, y+1, false);
        if(root == false && val >= order[x][y])
            isCut[x][y] = true;

        ret = min(ret, val);
    }
    if(order[x-1][y] == true)
        ret = min(ret, order[x-1][y]);
    else if(order[x-1][y] == false && ar[x-1][y] != '#' && x > 1){
        childNum++;
        int val = dfs(x-1, y, false);
        if(root == false && val >= order[x][y])
            isCut[x][y] = true;

        ret = min(ret, val);
    }
    if(order[x][y-1] == true)
        ret = min(ret, order[x][y-1]);
    else if(order[x][y-1] == false && ar[x][y-1] != '#' && y > 1){
        childNum++;
        int val = dfs(x, y-1, false);
        if(root == false && val >= order[x][y])
            isCut[x][y] = true;

        ret = min(ret, val);
    }

    if(root == true && childNum >= 2){
        isCut[x][y] = true;
    }
    return ret;
}
