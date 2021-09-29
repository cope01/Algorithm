#include <string>
#include <vector>
#include <queue>
using namespace std;

// �� ���ķ� �������־���. �켱���� ť�� �켱������ ��� �������� �߿��ϴ�.
// �ϳ��ϳ� ���ϴ� ������ �����ϴ� ���� �߿�!
struct cmp{
    bool operator()(int a, int b){
        string s1 = to_string(a) + to_string(b);
        string s2 = to_string(b) + to_string(a);
        if(s1 < s2){
            return true;
        }else{
            return false;
        }
    }
};
string solution(vector<int> numbers) {
    string answer = "";
    priority_queue <int, vector<int>, cmp> pq;
    for(int i = 0; i < numbers.size(); ++i){
        pq.push(numbers[i]);
    }
    while(!pq.empty()){
        answer += to_string(pq.top());
        pq.pop();
    }
    if(answer[0] == '0')
        answer = "0";
    return answer;
}
