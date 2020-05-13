#include <vector>
#include <string>
#include <queue>

using namespace std;

struct comp{
    bool operator()(pair <int, int> a, pair <int, int> b){ // first : dates, second : supplies
        if(a.first == b.first){ // dates������ supplies ���� ���� ���.
            return a.second < b.second;
        }
        // dates �ٸ� ������ ���� dates�� ���� ������ ���� ���.
        return a.first > b.first;
    }
};

int solution(int stock, vector <int> dates, vector <int> supplies, int k){
    int answer = 0;
    int day = 0;
    int sz = dates.size();
    priority_queue <pair <int, int>, vector <pair <int, int> >, comp> pq;

    for(int i = 0; i < sz; ++i){
        pq.push(pair<int, int>(dates[i], supplies[i]));
    }

    while(day < k){
        day += stock;
        stock = 0;
        vector <pair <int, int> > temp;
        int eff = 0; // day�ȿ� supply���� ���� ȿ������ ���� ������ ����.
        int effFirst = -1;
        while(pq.top().first <= day && !pq.empty()){
            temp.push_back(pair<int, int>(pq.top().first, pq.top().second));
            if(pq.top().second > eff){ // supply ���� ���� ���� �����ϱ� ����.
                effFirst = pq.top().first;
                eff = pq.top().second;
            }
            pq.pop();
        }

        // day���� ���� �͵� ���޹��� �� �ִ� ���߿� ���� supply���� ���� �����ϰ�� �ٽ� pq�� �ִ´�.
        for(int i = 0; i < temp.size(); ++i){
            if(temp[i].first != effFirst || temp[i].second != eff){ // �ϳ��� �ٸ��� eff �ƴ�.
                pq.push(temp[i]);
            }
        }
        answer++;
        stock += eff;// += �� = �� �������
    }

    answer--;
    return answer;
}
