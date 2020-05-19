#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // x : ����, y : ����.
    // xy-(x-2)(y-2) = brown
    // (x-2)(y-2) = yellow
    // xy = sum = brown + yellow
    int sum = brown + yellow;
    // ������ ���� �ִ� 2500����. 2500�̸� �� ���� ���δ� �� �ִ밡 5000�̴ϱ�.
    // ���ξ� �ϴ� �Ѵ� ���� ���� 3���� ����.
    int x = 0, y = 0;
    for(int i = 3; i <= 2500; ++i){
        // ����
        for(int j = 3; j <= i; ++j){
            if(i*j == sum && (i-2)*(j-2) == yellow){
                x = i;
                y = j;
                break;
            }
        }
        if(x > 0 && y > 0)
            break;
    }
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}
