#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
using namespace std;

// 1. ��� ���� ��� �� ���ؼ� ������ ������ ������ ��� �Ϳ� ���� �������� �����ϰ� �ִ� [i][j]�� �����ָ� �ȴ�.
// ������ ��� �Ϳ� ���� �������� �����ϰ� �ִ� [i][j]�� ���ٸ� 0�� ����ϸ� �ȴ�.
// 2. _�� ó���Ǿ� �ִ� �͵��� �ϳ��� ���Ƽ� bfs�� ������ �� ������ ���� �ش� [i][j]�� ����ϸ� �ȴ�.
// 2���� ������� Ǯ����.

ifstream in("lock.inp");
ofstream out("lock.out");
int n, m;
int resultX, resultY; // T �� ��ġ�� ��Ÿ��.
int startX, startY; // S�� ��ġ�� ��Ÿ��.
char ar[31][31] = { 0, };
bool visited[31][31] = { 0, }; // �ش� i, j�� �湮�� Ƚ��.
int result = -1; // T �� ������ Ƚ��.

// result �� visited[i][j] �� ���� �����̸� �װ��� ���̵ȴ�. ��� �信�� �� ���ľ� �ϴ� ��ζ�� ���̱⶧��
void input();

int main(void){
    ios_base::sync_with_stdio(false);
    in.tie(nullptr);

    input();
    queue <pair <int, int> > q;
    vector <pair <int, int> > v;
    // �ش� ���ϴ� ����.
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(ar[i][j] == '_'){
                ar[i][j] = '#'; // �ӽ÷� �ٲ۴�.
                q.push(pair<int, int>(startX, startY));

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    visited[x][y] = true; // �ش� [i][j]�� �湮��.
                    q.pop();
                    if(x == resultX && y == resultY)
                        result++;
                    if(visited[x+1][y] == false && ar[x+1][y] != '#' && x < m)
                        q.push(pair<int, int>(x+1, y));
                    if(visited[x][y+1] == false && ar[x][y+1] != '#' && y < n)
                        q.push(pair<int, int>(x, y+1));
                    if(visited[x-1][y] == false && ar[x-1][y] != '#' && x > 1)
                        q.push(pair<int, int>(x-1, y));
                    if(visited[x][y-1] == false && ar[x][y-1] != '#' && y > 1)
                        q.push(pair<int, int>(x, y-1));

                }
                if(result == -1){ // ���� ���� �� ���� ���. ��, lockdown�� ���.
                    v.push_back(pair<int, int>(i, j));
                }
                // �ʱ�ȭ�۾�
                result = -1;
                ar[i][j] = '_'; // �ٽ� �����·�.
                memset(visited, 0, sizeof(visited));
            }else{
                continue;
            }
        }
    }

    if(v.size() == 0){ // lockdown�ϴ� ���� ���� ���.
        out << 0;
        return 0;
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
