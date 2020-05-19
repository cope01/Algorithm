#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    for(int day = 1; day < k; ++day){ // if(day == k) // ����.
        stock--;
        if(stock == 0){
            int eff = 0;
            int effIndex = -1;
            for(int i = 0; i < dates.size(); ++i){
                if(dates[i] <= day && eff < supplies[i]){
                    eff = supplies[i];
                    effIndex = i;
                }
            }
            cout << dates[effIndex] << " " << supplies[effIndex] << endl;
            stock += supplies[effIndex]; // =�� +=�� ���� ������ stock == 0 �϶� �����ϴ� �Ŷ�
            supplies[effIndex] = 0;
            answer++;
            // ���� �� �ִ� ���޹޴� �� ���޹ް� 0���� �����.
            // ���⼭ ������ �ּڰ��� ã���� �ð����⵵ Ŀ����. ���⼭ �� ����ؾ� ��
            // 1) <= day�� �ش��ϸ鼭 2) supply ���� ���� index�� ã�Ƽ�
            // pq���� pop()����� �Ѵ�.

            // �޸� ���ϸ� supply[i] �ִ���� ã�µ�, date[i] <= day
            // priority_queue�ε� pair <int, int> �� �־��ְ�. �켱������ supply ���� ���� �ɷ� ��������� �Ѵ�.
        }
    }
    return answer;
}
