#include <string>
#include <vector>
#include <algorithm> // sort
#include <cmath> // sqrt

using namespace std;

int solution(string numbers){
    int answer = 0;
    int len = numbers.length();
    sort(numbers.begin(), numbers.end());
    reverse(numbers.begin(), numbers.end());
    int num = stoi(numbers); // ������ ���� ū ��.
    int *sosu = new int[num + 1]; // ó������ 0���� �ʱ�ȭ.

    for(int i = 2; i <= sqrt(num); ++i){ // ��Ŭ���� ȣ����. �Ҽ��� ���� �� ã�Ƴ��´�.
        if(sosu[i] == 0){ // ���� �Ҽ�(0)���� �Ҽ��� ����� �� �Ҽ��ƴ�(1)ó��.
            for(int j = 2*i; j <= num; j += i){
                sosu[j] = 1; // �Ҽ��ƴϸ� 1 ����.
            }
        }
    }

    for(int i = 2; i <= num; ++i){
        if(sosu[i] == 0){ // �Ҽ��� ���
            int temp1 = num;
            int temp2 = i;
            vector <int> check;
            vector <int> soCheck;

            while(temp1){
                int k = temp1 % 10;
                check.push_back(k);
                temp1 /= 10;
            }
            while(temp2){
                int k = temp2 % 10;
                soCheck.push_back(k);
                temp2 /= 10;
            }

            int cnt = 0;
            for(int j = 0; j < soCheck.size(); ++j){
                for(int k = 0; k < check.size(); ++k){
                    if(soCheck[j] == check[k]){
                        check[k] = -1; // �ߺ� ���ϱ� ����.
                        cnt++;  // �Ҽ��� ����(���ڼ�)�� cnt�� ���ؼ� ���߿� ������ numbers����
                        break;  // �Ҽ��� ��� ���ڸ� �����ϴ� ��. ���� answer++ �����ϴ�.
                    }
                }
            }
            if(cnt == soCheck.size())
                answer++;
        }
    }
    delete [] sosu;
    return answer;
}
