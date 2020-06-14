#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <stack>
#define MAX 10000
using namespace std;

ifstream in("angle.inp");
ofstream out("angle.out");
int px[1001] = { 0, };
int py[1001] = { 0, };
pair <int, int> O; // ����.

void input(int n);
int pow(int a, int n);
int fromODistance(int a, int b); // �������κ����� �Ÿ�.
int calSignedArea(pair <int, int> p1, pair <int, int> p2);
struct comp{
    bool operator()(pair <int, int> p1, pair <int, int> p2){

        if(calSignedArea(p1, p2) < 0) // p1�� ���ʿ� p2��.
            return 1;
        else if(calSignedArea(p1, p2) == 0) // ���ϼ��� �����ϴ� ���.
           return fromODistance(p1.first, p1.second) < fromODistance(p2.first, p2.second);
        return 0;

    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    in.tie(nullptr);

    int n;
    in >> n;
    input(n);
    // ���� ����.
    O.first = 0;
    O.second = 0;

    priority_queue <pair <int, int>, vector <pair <int, int> >, comp> pq;
    stack <int> st;
    //pq.push(pair<int, int>(0, MAX));
    // 1 ��и� ���� ó��.
    for(int i = 1; i <= n; ++i){
        if(px[i] >= 0 && py[i] >= 0)
            pq.push(pair<int, int>(px[i], py[i]));
    }

    while(!pq.empty()){
        for(int i = 1; i <= n; ++i){
            if(px[i] == pq.top().first && py[i] == pq.top().second)
                st.push(i);
                //cout << i << "\n";
        }
        //cout << pq.top().first << " " << pq.top().second << "\n";
        pq.pop();
    }

    while(!st.empty()){
        out << st.top() << endl;
        cout << px[st.top()] << " " << py[st.top()] << "\n";
        st.pop();
    }

     // 2 ��и� ���� ó��.
    for(int i = 1; i <= n; ++i){
        if(px[i] < 0 && py[i] > 0)
            pq.push(pair<int, int>(px[i], py[i]));
    }

    while(!pq.empty()){
        for(int i = 1; i <= n; ++i){
            if(px[i] == pq.top().first && py[i] == pq.top().second)
                st.push(i);
                //cout << i << "\n";
        }
        //cout << pq.top().first << " " << pq.top().second << "\n";
        pq.pop();
    }

    while(!st.empty()){
        out << st.top() << endl;
        cout << px[st.top()] << " " << py[st.top()] << "\n";
        st.pop();
    }

     // 3 ��и� ���� ó��.
    for(int i = 1; i <= n; ++i){
        if(px[i] <= 0 && py[i] <= 0)
            pq.push(pair<int, int>(px[i], py[i]));
    }

    while(!pq.empty()){
        for(int i = 1; i <= n; ++i){
            if(px[i] == pq.top().first && py[i] == pq.top().second)
                st.push(i);
                //cout << i << "\n";
        }
        //cout << pq.top().first << " " << pq.top().second << "\n";
        pq.pop();
    }

    while(!st.empty()){
        out << st.top() << endl;
        cout << px[st.top()] << " " << py[st.top()] << "\n";
        st.pop();
    }

     // 4 ��и� ���� ó��.
    for(int i = 1; i <= n; ++i){
        if(px[i] > 0 && py[i] < 0)
            pq.push(pair<int, int>(px[i], py[i]));
    }

    while(!pq.empty()){
        for(int i = 1; i <= n; ++i){
            if(px[i] == pq.top().first && py[i] == pq.top().second)
                st.push(i);
                //cout << i << "\n";
        }
        //cout << pq.top().first << " " << pq.top().second << "\n";
        pq.pop();
    }

    while(!st.empty()){
        out << st.top() << endl;
        cout << px[st.top()] << " " << py[st.top()] << "\n";
        st.pop();
    }
    in.close();
    out.close();
    return 0;
}

void input(int n){
    for(int i = 1; i <= n; ++i){ // 1������ �Է�.
        in >> px[i] >> py[i];
    }
}

int fromODistance(int a, int b){
    int ret = pow(a, 2) + pow(b, 2);
    return ret;
}

int calSignedArea(pair <int, int> p1, pair <int, int> p2){
    int ret = (p1.first*O.second + p2.first*p1.second + O.first*p2.second)
        - (O.first*p1.second + p1.first*p2.second + p2.first*O.second);
    return ret;
}

int pow(int a, int n){
    int ret = 1;
    for(int i = 0; i < n; ++i){
        ret *= a;
    }
    return ret;
}
