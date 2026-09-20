#include <string>
#include <vector>
#include <stack>

using namespace std;

/* A, B 가 괄호 문자열
*  대괄호, 중괄호, 소괄호 이루어진 문자열 s
*  왼쪽으로 x 길이 만큼 회전시킬때
*  s 가 올바른 괄호 문자열이 되게 하는 x 의 개수 return
*  왼쪽부호, 오른쪽 부호의 s 의 위치를 find 한다.
*  오른쪽 배열값이 왼쪽보다 작으면 false
*/
bool match(string s)
{
    stack<char> bracket;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
            bracket.push(s[i]);
        else
        {
            if (bracket.empty())
                return false;

            int minus = s[i] - bracket.top();

            if (minus == 2 || minus == 1)
                bracket.pop();
        }
    }

    if (bracket.empty())
        return true;

    return false;
}

int solution(string s) {
    int answer = 0;
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        bool bMatch = match(s);
        
        if (bMatch)
            answer++;

        char last = s[0];
        s.erase(s.begin() + 0);
        s.push_back(last);
    }

    return answer;
}