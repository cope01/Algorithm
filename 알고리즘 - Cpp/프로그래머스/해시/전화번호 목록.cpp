#include <string>
#include <algorithm> // sort
#include <vector>

using namespace std;
// ���ξ�� false, ���ξ �ƴϸ� true

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    // �����ϰ� v[i] �� ���ϴ� ���(i+1, i+2 ...)�� ó������ ������ ������ ���ξ�.
    // v[i]�� ������ �Ȱ��µ� �ٸ� �κ� ã���� i++, j = i+1;
    int i = 0, j = i+1;
    while(i < phone_book.size()-1){
        for(int k = 0; k < phone_book[i].size(); ++k){
            if(phone_book[i][k] == phone_book[j][k]){
                if(k == phone_book[i].length()-1){ // ������ �ڸ�
                    answer = false;
                    return answer;
                }
            }else{
                i++;
                j = i+1;
                break;
            }
        }

    }
    return answer;
}
