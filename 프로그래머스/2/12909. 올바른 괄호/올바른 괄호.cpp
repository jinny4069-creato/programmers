#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = false;
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            count++;
        if (s[i] == ')')
            count--;

        if (count < 0)
        {
            return false;
        }
    }

    if (count != 0)
        return false;
    else
        return true;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

}