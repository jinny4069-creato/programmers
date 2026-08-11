#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    string result = "";
    int answer = -1;

    for (int i = 0; i < s.size(); i++)
    {
        if (!result.empty() && result.back() == s[i])
            result.pop_back();
        else
            result.push_back(s[i]);
       
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return result.empty() ? 1 : 0;
}