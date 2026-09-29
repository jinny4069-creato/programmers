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
    vector<pair<int, int>> matchX;
    vector<pair<int, int>> matchY;
    vector<int> mates;

    for (int i = 0; i <= 9; i++)
    {
        matchX.push_back({ i, 0 });
        matchY.push_back({ i, 0 });
    }

    for (int i = 0; i < matchX.size(); i++)
    {
        for (int j = 0; j < X.size(); j++)
        {
            if (matchX[i].first == X[j] - 48)
            {
                matchX[i].second++;
            }
        }
    }

    for (int i = 0; i < matchY.size(); i++)
    {
        for (int j = 0; j < Y.size(); j++)
        {
            if (matchY[i].first == (Y[j] - 48))
                matchY[i].second++;
        }
    }

    for (int i = 0; i < matchX.size(); i++)
    {
        if (matchX[i].second == 0 || matchY[i].second == 0)
        {
            continue;
        }

        int count = min(matchX[i].second, matchY[i].second);
        for (int j = 1; j <= count; j++)
        {
            mates.push_back(matchX[i].first);
        }
    }

    if (mates.empty())
    {
        return answer = "-1";
    }

    sort(mates.begin(), mates.end(), greater<>());
    
    if (mates[0] == 0)
    {
        return answer = "0";
    }

    for (int i = 0; i < mates.size(); i++)
    {
        answer += to_string(mates[i]);
    }
    return answer;
}