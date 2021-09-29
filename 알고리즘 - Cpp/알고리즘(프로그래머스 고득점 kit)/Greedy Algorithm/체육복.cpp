#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int stu[31] = { 0, };
    for(int i = 1; i <= n; ++i){
        stu[i] = 1; // 1�� �ʱ�ȭ.
    }
    for(int i = 0; i < lost.size(); ++i){
        stu[lost[i]]--; // ������ 0.
    }
    for(int i = 0; i < reserve.size(); ++i){
        stu[reserve[i]]++; // ���� ������ 2��. lost, reserve�Ѵ� ���ԵǾ� ������ 1��.
    }

    stu[0] = 1; // �Ʒ� ���� ���� ����.
    // reserve�� �����ְ� �Ǹ� 2�� �ƴ� ���� �־ �߸��� ���� ���� �� �ִ�.
    for(int i = 1; i <= n; ++i){
        if(stu[i] == 2 && stu[i-1] == 0){
            stu[i-1] += 1;
            stu[i] -= 1;
        }else if(stu[i] == 2 && stu[i+1] == 0){
            stu[i+1] += 1;
            stu[i] -= 1;
        }
    }

    for(int i = 1; i <= n; ++i){
        if(stu[i] >= 1){
            answer++;
        }
    }
    return answer;
}
