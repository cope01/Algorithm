#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define MAX 100000000

using namespace std;
// �۾��ð� ���԰ɸ��°ͺ��� �� ������ �Ǿ���� ���߿� ��հ��� ���� ������. �ƴҼ��� �ֳ�?
struct comp{
    // �켱���� : ��� ���۽ð� �����ź���, ��� ���۽ð��� ������ �۾��ҿ�ð� �������� �����°ɷ�.
    bool operator()(pair <int, int> a, pair<int, int> b){ // first : ��� ���� �ð� second : �۾� �ҿ� �ð�.
        if(a.first == b.first){
            a.second > b.second;
        }
        return a.first > b.first;
    }
};
int solution(vector<vector<int>> jobs) {
    int now = 0; // ���� �ð�
    int answer = 0;
    priority_queue <pair <int, int>, vector< pair <int, int> >, comp> pq;

    int sz = jobs.size();

    for(int i = 0; i < sz; ++i){
        int x = jobs[i][0];
        int y = jobs[i][1];
        pq.push(make_pair(x, y));
    }

    int request; // request time ��� ���� �ð�
    int elapsed; // elapsed time �ҿ� �ð�
    while(!pq.empty()){ // } && temp.size() != 0){
        vector < pair <int, int> > temp;
        request = pq.top().first;
        elapsed = pq.top().second;
        if(request > now){ // ���� �� �� �ִ°� �ƹ��͵� ������� �׳� �ð��� �帣�°�.
            now++;
            continue;
        }
        while(request <= now && !pq.empty()){ // request <= now�ε��� ��� vector �� �־��ְ�. ������ �ð��� ���� ���� �ͺ���.
            temp.push_back(pair<int, int>(request, elapsed));
            pq.pop();
            request = pq.top().first;
            elapsed = pq.top().second;
        }
        int minVal = MAX; // request <= now �����ϴ� ���߿��� �ҿ�ð� �ּ��� ���� ã�´�.
        int minIndex = -1;
        for(int i = 0; i < temp.size(); ++i){
            int requestToEnd = now + temp[i].second - temp[i].first;
            if(requestToEnd < minVal){
                minVal = requestToEnd;
                minIndex = i;
            }
        }
        for(int i = 0; i < temp.size(); ++i){
            if(i != minIndex){
                pq.push(temp[i]);
            }
        }
        answer += minVal;
        now += temp[minIndex].second;
    }
    answer /= sz;
    return answer;
}

int main(void){
    vector < vector<int> > v;
    vector <int> v1;
    v1.push_back(0);
    v1.push_back(3);
    vector <int> v2;
    v2.push_back(1);
    v2.push_back(9);
    vector <int> v3;
    v3.push_back(2);
    v3.push_back(6);


    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    cout << solution(v);

    return 0;
}

/*
    for(int i = 0; i < sz; ++i){
        while(pq.top().first < now){ // �۾��� �����ϰ� ���� �������� now�� ��� ���������ָ�ȴ�.
            now++; // �̷��� now �ȿ� �۾��ð� ���ɸ��°� ����ȵɼ��ֳ�.
        }
        int x = pq.top().first;
        int y = pq.top().second;
        answer = now + y - x;
        now = now + y;
        pq.pop();
    }
    */


