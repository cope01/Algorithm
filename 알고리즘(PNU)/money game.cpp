#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int opResult(int a, char c, int b);
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream in("mgame.inp");
    ofstream out("mgame.out");

    int dp[31][31] = { 0, }; // �ʿ������?
    int num[31] = { 0, }; // ����.
    char op[30] = { 0, }; // ������.
    int maxdp[31][31] = { 0, };
    int mindp[31][31] = { 0, };

    string s;
    in >> s;

    int n = s.length()/2 + 1; // ������ ����.
    int m = s.length()/2; // �������� ����.

    for(int i = 0, j = 0; i < n; i++, j=j+2){
        num[i] = s[j]-'0';
        cout << num[i] << endl;
    }
    for(int i = 0, j = 1; i < m; i++, j=j+2){
        op[i] = s[j];
        cout << op[i] << endl;
    }
    /*
    num[0], num[1]�� op[0]�� ������ ���ؼ� ������ ���� dp[0][0]�� ����.
    num[1], num[2]�� op[1]�� ������ ���ؼ� ������ ���� dp[1][1]�� ����.
    num[2], num[3]�� op[2]�� ������ ���ؼ� ������ ���� dp[2][2]�� ����.
    num[3], num[4]�� op[3]�� ������ ���ؼ� ������ ���� dp[3][3]�� ����.
    num[4], num[5]�� op[4]�� ������ ���ؼ� ������ ���� dp[4][4]�� ����.
    */
    // 1. �ʱⰪ ����.
    int p = n-1; // �򰥸����ʱ����� p�� dp�� ����.
    for(int i = 0; i < p; ++i){
        maxdp[i][i] = opResult(num[i], op[i], num[i+1]);
        mindp[i][i] = opResult(num[i], op[i], num[i+1]);
    }

    for(int gap = 1; gap < p; ++gap){ // -999 ���� ���ؼ� ��ûū���̵ɼ���. �׷�?
        for(int i = 0; i < p; ++i){
            int j = i + gap;
            maxdp[i][j] = max(opResult(num[i], op[i], maxdp[i+1][j]), opResult(num[i], op[i], mindp[i+1][j])); // �ʱ�ȭ.
            mindp[i][j] = min(opResult(num[i], op[i], maxdp[i+1][j]), opResult(num[i], op[i], mindp[i+1][j]));
            for(int k = i; k < j; ++k){
                int tempmax;
                int tempmin;
                if(k == j-1){ // ��������. ���Ⱑ ����.
                    tempmax = max(opResult(maxdp[i][k], op[k+1], num[k+2]), opResult(mindp[i][k], op[k+1], num[k+2]));
                    tempmin = min(opResult(maxdp[i][k], op[k+1], num[k+2]), opResult(mindp[i][k], op[k+1], num[k+2]));
                }
                else{
                    int temp1 = max(opResult(mindp[i][k], op[k+1], mindp[k+2][j]), opResult(mindp[i][k], op[k+1], maxdp[k+2][j]));
                    int temp2 = max(opResult(maxdp[i][k], op[k+1], mindp[k+2][j]), opResult(maxdp[i][k], op[k+1], maxdp[k+2][j]));
                    tempmax = max(temp1, temp2);

                    temp1 = min(opResult(mindp[i][k], op[k+1], mindp[k+2][j]), opResult(mindp[i][k], op[k+1], maxdp[k+2][j]));
                    temp2 = min(opResult(maxdp[i][k], op[k+1], mindp[k+2][j]), opResult(maxdp[i][k], op[k+1], maxdp[k+2][j]));
                    tempmin = min(temp1, temp2);


                }
                mindp[i][j] = min(mindp[i][j], tempmin);
                maxdp[i][j] = max(maxdp[i][j], tempmax);
            }
        }
    }
    // ��� Ȯ��
    for(int i = 0; i < p; ++i){
        for(int j = 0; j < p; ++j){
            cout << mindp[i][j] << " " << maxdp[i][j] << '\t';
        }
        cout << endl;
    }

    // ���������� ���ؾ� �ϴ� ���� dp[0][n-1];
    out << maxdp[0][p-1];

    in.close();
    out.close();
    return 0;
}

int opResult(int a, char c, int b){
    int ret;
    if(c == '*'){
        ret = a * b;
    }else if(c == '+'){
        ret = a + b;
    }else if(c == '-'){
        ret = a - b;
    }
    return ret;
}
