#include <vector>
#include <string>
#include <queue>

using namespace std;

struct comp{
    bool operator()(pair <int, int> a, pair <int, int> b){ // first : dates, second : supplies
        if(a.second == b.second){ // supplies ������ dates ���� ���� ���
            return a.first > b.first;
        }
        // supplies ������ ���� supplies ���� �� ������� ���� ���.
        return a.second < b.second;
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
    day += stock;
    stock = 0;
    while(day < k){
        vector <pair <int, int> > temp;
        while(1){ // �а��簡 �ٴڳ� �� �ۿ� ���� ���� �����Ƿ� pq.empty()�� ������� �ʾƵ� �ȴ�.
            int d = pq.top().first;
            int supply = pq.top().second;
            pq.pop();
            if(d <= day){
                stock = supply;
                answer++;
                for(int i = 0; i < temp.size(); ++i){
                    pq.push(temp[i]);   // day���� ������������ supply���� �������°� ������ ���� �ٽ� pq�� �ִ´�.
                }
                break;
            }else{
                temp.push_back(pair<int, int>(d, supply)); // day���� ������������ supply���� �������°� ����.
            }
        }
        day += stock;
        stock = 0;
    }
    return answer;
}
