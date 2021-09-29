#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct comp{
    bool operator()(int a, int b){
        //return a < b; // �̷��� ���� ū�ź��� ���� ���´�.
        return a > b; // �̷��� ���� ���� �ͺ��� ���� ���´�.
    }
};

int main(void){
    priority_queue <int, vector <int>, comp> pq;
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        pq.push(x);
    }

    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}
