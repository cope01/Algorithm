#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0; // ���� Ƚ��

    priority_queue < int, vector<int>, greater<int> > pq;
    int sz = scoville.size();
    for(int i = 0; i < sz; ++i){
        pq.push(scoville[i]);
    }
    while(1){ // �� K�̻��� �Ǿ��ų� 1�� ���Ͽ��� ���� ���� ���� ��� ����.
        if(pq.top() >= K || pq.size() <= 1)
            break;
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        int z = x + 2*y;
        answer++;
        pq.push(z);
    }
    // ���� �� �� �����°� K���� ������ -1�� ����.
    if(pq.top() < K)
        answer = -1;
    return answer;
}
