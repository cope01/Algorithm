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

    while(day < k){
        day += stock;
        stock = 0;
        vector <pair <int, int> > temp;
        // supply���� ������ �̴µ� day ������ �����ϴ� ���� ������ �װ��� pq���� �����ϰ� stock�� �߰����ش�.
        while(1){
            int d = pq.top().first;
            int supply = pq.top().second;
            pq.pop();
            if(d <= day){
                stock = supply;
                answer++;
                for(int i = 0; i < temp.size(); ++i){
                    pq.push(temp[i]);
                }
                break;
            }else{
                temp.push_back(pair<int, int>(d, supply)); // day���� ������������ supply���� �������°� ����.
            }
        }
    }
    answer--;
    return answer;
}
