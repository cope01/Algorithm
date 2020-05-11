#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> v1; // parti
vector <string> v2; // complet

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    bool flag = false;
    int pre;
    for(int i = 0; i < completion.size(); ++i){
        if(participant[i] != completion[i]){
            if(flag == false){ // ���� ó�� �߻��� �� pre�� ����.
                pre = i;
                flag = true;
            }else{ // ���� 2��° �߻�.
                return participant[pre];
            }
            /*
            // �� ���� �ٸ� ���
            [0]�� [1]�� �ٸ� ��.
            // �߰��� �ٸ� ���3sdfj
            [0]���� ���ٰ� n���� ���̰� �߻��� ��. �׷��� participant[n]�� ���.
            */
        }
    }
    if(flag == true){
        answer = participant[pre];
    }else{
        // �ٸ� �� �߰����� ���Ұ�� �� �������� �����ִ� ��.
        answer = participant[participant.size()-1];
    }


    return answer;
}

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        v1.push_back(s);
    }
    for(int i = 0; i < n-1; ++i){
        string s;
        cin >> s;
        v2.push_back(s);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for(int i = 0; i < v1.size(); ++i){
        cout << v1[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < v2.size(); ++i){
        cout << v2[i] << " ";
    }
    cout << endl;
    cout << solution(v1, v2);

    return 0;
}
