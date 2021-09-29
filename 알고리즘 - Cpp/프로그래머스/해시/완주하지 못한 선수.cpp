#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    bool flag = false;
    int pre;
    for(int i = 0; i < completion.size(); ++i){
        if(participant[i] != completion[i]){
            if(flag == false){ // ���� ó�� �߻��� �� pre�� ����. 1)
                pre = i;
                flag = true;
            }else{ // ���� 2��° �߻�. 2)
                return participant[pre];
            }
            /*
            // �� ���� �ٸ� ���
            [0]�� [1]�� �ٸ� ��.
            // �߰��� �ٸ� ���
            [0]���� ���ٰ� n���� ���̰� �߻��� ��. �׷��� participant[n]�� ���.
            */
        }
    }
    if(flag == true){ // 1) �� �߻��ߴµ� 2)�� ���� ������ Ʋ�� �� ���
        answer = participant[pre];
    }else{
        // �ٸ� �� �߰����� ���Ұ�� �� �������� �����ִ� ��.
        answer = participant[participant.size()-1];
    }

    return answer;
}
