#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 두정수 X, Y 0 ~9 까지이 숫자 k 를 이용하여
*  만들 수 있는 가장 큰 정수를 두 수의 짝꿍 이라고 한다.
*  X, Y 의 짝꿍이 없으면 짝꿍은 -1 이다.
*  ex) X = 3403 이고 Y = 13203 이면 X 와 Y 의 같은 숫자는 3, 0, 3
*      이고 이거로 가장 큰 정수를 만들면 330 이다.
*  for 문으로 공통 정수를 찾는다. 
*/
string solution(string X, string Y) {
    string answer = "";
    int matchX[10] = { 0 };
    int matchY[10] = { 0 };
    vector<int> mates;

    for (int i = 0; i < X.size(); i++)
    {
        int num = X[i] - 48;
        matchX[num]++;
    }

    for (int i = 0; i < Y.size(); i++)
    {
        int num = Y[i] - 48;
        matchY[num]++;
    }

    for (int i = 9; i >= 0; i--)
    {
        if (matchX[i] == 0 || matchY[i] == 0)
        {
            continue;
        }

        int count = min(matchX[i], matchY[i]);

        answer.append(count, i + '0');
    }

    if (answer.empty())
    {
        return answer = "-1";
    }

    if (answer[0] == '0')
    {
        return answer = "0";
    }
    return answer;
}