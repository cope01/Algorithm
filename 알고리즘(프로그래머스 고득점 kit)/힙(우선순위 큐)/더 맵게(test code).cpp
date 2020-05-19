#include <iostream>
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
        cout << x << " ";
        pq.pop();
        int y = pq.top();
        cout << y << " " << endl;
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

int main(void){
    vector <int> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << solution(v, 7);
    return 0;
}

