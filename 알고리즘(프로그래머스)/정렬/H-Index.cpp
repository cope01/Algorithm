#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int num[10001] = { 0, }; // �ο� Ƚ��
    for(int i = 0; i < citations.size(); ++i){
        for(int j = 0; j <= citations[i]; ++j){
            num[j]++;
        }
    }
    for(int i = citations.size(); i >= 0; --i){ // ���ϸ� �ٷ� ���ͼ� �ٷ� �������� �� �ִ�.
        if(num[i] >= i){
            answer = i;
            return answer;
        }
    }
    return answer;
}
