#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 0과 1로 이루어진 문자열 x 에 대한 이진 변환
*  1. x 의 모든 0을 제거
*  2. 0제거한 x 의 길이 c
*  ex) c = 4 이면 4를 이진법으로 100
*       여기서 또 0을 지운다 (2개 지우기)
*       그럼 1이됨
*  이진변환 count , 제거한 0 개수 return 하기
*/

string erase1(string s, int &zero)
{
    int count = 0;
    for (int i = 0; i < s.size();)
    {
        if (s[i] == '0')
        {
            s.erase(s.begin() + i);
            i = 0;
            count++;
        }
        else
            i++;
    }

    zero += count;
    return s;
}

string binary(int num)
{
    string binary = "";
    int quo = num;
    while (quo > 1)
    {
        binary += to_string(quo % 2);
        quo = quo / 2;
        
    }
    if (quo == 1)
        binary += to_string(quo);
    reverse(binary.begin(), binary.end());
    return binary;
}

bool check1(string s)
{
    return s != "1";
}

vector<int> solution(string s) {

    vector<int> answer;

    int countTrans = 0;

    int zero = 0;

    while (check1(s))
    {
        countTrans++;
        s = erase1(s, zero);
        s = binary(s.size());
    }
    answer = { countTrans, zero };
    
    return answer;
}

int main()
{
    string s = "110010101001";
    solution(s);
}