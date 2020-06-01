#include <string>
#include <vector>
#include <algorithm> // min

using namespace std;

int solution(string name) {
    int answer = 0;
    int answer1 = 0, answer2 = 0;
    int len = name.length();
    bool allA = true;
    // A ���� �ش� ���ĺ�����, Z���� �ش� ���ĺ����� + 1 �߿� ���� ���� answer�� �����ش�.
    for(int i = 0; i <= len-1; ++i){
        int minVal = min('Z'-name[i]+1, name[i]-'A');
        if(minVal == 0 && i != 0){ // A�� ���.
            answer1--;
        }else{
            answer1 += minVal;
        }
        answer1++;
        if(i == len-1)
            answer1--;
    }

    answer2++; // �Ųٷ� ���ư��� ��
    for(int i = len-1; i >= 0; --i){
        int minVal = min('Z'-name[i]+1, name[i]-'A');
        if(minVal == 0 && i != len){ // A�� ���.
            answer2--;
        }else{
            answer2 += minVal;
        }
        answer2++;
        if(i == 0)
            answer2--;
    }

    answer = min(answer1, answer2);
    return answer;
}


/*
BBABA �� 6
BBBAAB �� 8
BBAABAA �� 7
BBAABBB �� 10
BBAABAAAA �� 7
BBAABAAAAB �� 10
*/
