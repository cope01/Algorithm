#include <iostream>
#include <fstream>
#include <stack>
#define MAX 100000

using namespace std;

int L; // �ϼ����� ����.
int k; // �⺻ Ʃ���� ����.
int type[11] = { 0, }; // l1 ..
int sum; // �� Ʃ���� ���� (subtubelength)
int num; // ��� Ʃ���� ����.
int output = MAX; // default = 0, ���������� �ڵ����� default���� 0���� �ʱ�ȭ�ȴ�.
int eachsum[11] = { 0, };
stack< pair <int, int> > st;
int main(void){
    ifstream in("tube.inp");
    ofstream out("tube.out");

    in >> L;
    in >> k;

    for(int i = 0; i < k; ++i){
        in >> type[i];
    }
    st.push(make_pair(0, 0));

    while(!st.empty()){
        auto x = st.top();
        sum = x.first;
        num = x.second + 1;
        st.pop();
        for(int i = 0; i < k; ++i){
            eachsum[i] = sum + type[i];
            if(eachsum[i] == L){
                if(num < output){
                    output = num;
                    break;
                }
            }else if(eachsum[i] < L){
                st.push(make_pair(eachsum[i], num));
            }else if(eachsum[i] > L){
                break; // i1 < i2 �̹Ƿ� ���� ���� �翬�� eachsum[i] > L �̹Ƿ� üũ���ʿ���� break.
            }
        }
        if(output != MAX){
            out << output;
            return 0;
        }
    }

    if(output == MAX) // Ʃ���� ���� �����ϰ� �����ؼ� L������ �ϼ����� ���̸� ���� �� ���ٸ� 0����.
        output = 0;

    out << output;

    in.close();
    out.close();

    return 0;
}
