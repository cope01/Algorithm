#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ���� �켱����ť�� �̿��ؼ� �����ϰ��� �ϸ� -�� �̿��ϸ� �ȴ�.

vector<int> solution(vector<string> operations) {
    deque <int> dq;

    int sz = operations.size();
    for(int i = 0; i < sz; ++i){
        if(operations[i][0] == 'I'){
            int k = stoi(operations[i].substr(2));
            dq.push_back(k);
            sort(dq.begin(), dq.end());
        }else if(operations[i] == "D 1"){
            if(!dq.empty()){
                dq.pop_back(); // �ִ� ����.
            }
        }else if(operations[i] == "D -1"){
            if(!dq.empty()){
                dq.pop_front(); // �ּڰ� ����
            }
        }
    }

    vector<int> answer;
    if(!dq.empty()){
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }else{
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
