#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

void backtracking(int x, int y, int val);
bool checkCorrect(int x, int y);
int n;
int ar[10][10] = { 0, };
int result;
vector < pair <int, int> > v; // x y ������ ������ ���� �͵��� �� ����.
stack < pair< pair <int, int>, int> > st; // x y n
int main(void){
    ifstream in("detroit.inp");
    ofstream out("detroit.out");
    ios_base::sync_with_stdio(false);
    in.tie(nullptr);
    in >> n;

    int index = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            in >> ar[i][j];
            if(ar[i][j] == 0){ // ������ ���� ������ ������ (= 0�̸�) vector�� �ִ´�.
                v.push_back(make_pair(i, j));
            }
        }
    }
    if(v.size() == 0){ // ������ �ϼ��Ǿ� ������
        out << 1; // 1�� ����ϰ� ����. // sampledata 4��.
        return 0;
    }
    // ó�� ������ ��.
    int x = v[0].first;
    int y = v[0].second;
    for(int i = 1; i <= n; ++i){
        //st.push(make_pair(make_pair(x, y), i)); // st.push(make_pair(v[0], i));
        st.push(make_pair(v[0], i)); // ex) n = 4 �̸� 4���� ���ÿ� �ִ°�.
    }
    //cout << v.size();
    while(!st.empty()){
        auto a = st.top();
        x = a.first.first;
        y = a.first.second;
        int val = a.second;
        ar[x][y] = val;
/*
        cout << x << " " << y << " " << val << " " << index << endl; //Ư���� : n == 4�� val = 4�� ù����� ����.
        //cout << st.size() << endl;
        cout << endl;
/*

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout << ar[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
*/
        if(checkCorrect(x, y)){ // ���� ���� ��� �����ؼ� �� �ڸ��� �ִ°� ������ ���.
            // st.push(make_pair(v[index], i);�� ���� for������ ��ü������ ���� ����������Ѵ�.
            if(v.size()-1 == index){
/*
                for(int i = 0; i < n; ++i){
                    for(int j = 0; j < n; ++j){
                        cout << ar[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
*/
                result++;
                ar[x][y] = 0; // ������ ���� 0���� �ٲٰ�
                st.pop(); // ������.

                //index--;
            }else{
                index = index + 1;
                st.pop();
                for(int i = 1; i <= n; ++i){
                    st.push(make_pair(v[index], i)); // v[index]�� x, y ������ �ִ�.
                }
            }
        }else{

            if(ar[x][y] == 1){
                if(st.size() == 1) // ��
                    break;
                index--;
            // ���Ⱑ �ſ� �����ϱ�� ��.
            // 3���� ����������.. -> �ٰ� : ���� ����ִ� ��(���� ���� ������ 1�̾ ���ÿ� �ƹ��͵� �������� �ʴ°�� �ѹ� �� �����ΰ��ִ� �۾�. 11111 �̷��� 3���̻��������ȵǴµ� ������ ���Ƶ� 2�� 11�� �Ұ����ϰ� [1][5]�� 1, [2][1]�� 1�ΰ�� �̷���츸 ������ָ� �ȴ�.
                if(ar[v[index].first][v[index].second] == 1){
                    ar[v[index].first][v[index].second] = 0;
                    index--;
                }
                if(ar[v[index].first][v[index].second] == 1){
                    ar[v[index].first][v[index].second] = 0;
                    index--;
                }
                if(ar[v[index].first][v[index].second] == 1){
                    ar[v[index].first][v[index].second] = 0;
                    index--;
                }
            }
            ar[x][y] = 0;
            st.pop();
            //index--;
        }

        /*
        // ã�� ���
        if(v.size() == index){
            result++;
            st.pop();
        }
        */
    }

    //backtracking(x, y, 1); // recursion���� ���� �ʰ� Ǯ��.
    // ar[0][0] = 0�̸� �Ϸ����ߴµ� ���� ���� ���������� �� �����ϱ�.

    out << result;

    in.close();
    out.close();
    return 0;
}
/*
void backtracking(int x, int y, int n){
    if(checkCorrect(x, y)){ // ������ ���� ���.
        //backtracking();
    }else{
        backtracking(x, y, n+1);
    }

}
*/

bool checkCorrect(int x, int y){ // 0�̻��϶��� üũ.
    for(int i = 0; i < n; ++i){
        if(x != i){
            if(ar[x][y] == ar[i][y])
                return false;
        }
    }
    for(int i = 0; i < n; ++i){
        if(y != i){
            if(ar[x][y] == ar[x][i])
                return false;
        }
    }
	return true;
}
