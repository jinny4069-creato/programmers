#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/* 총 3번의 기회
*  기회마다 점수는 0 에서 10
*  S , D , T 영역이 존재하고 각 영역 당첨 시 점수에서 1, 2, 3 제곱으로 계산
*  스타상 * , 아차상 # 이 존재 
*  스타상 -> 이전 점수 2배
*  아차상 -> 현재 점수 마이너스
*  스타상 은 중첩가능 스타 + 스타 -> 4배 스타 + 아차 -> 2배 마이너스
*  S, D, T 점수마다 하나씩 존재
*  스타상, 아차상은 한개만 존재, 존재 X 가능
*  S D T 를 구분하여 pow 사용
* 
*/

pair<int, int> SquScore(const char word, string& strNum, int round)
{
    pair<int, int> p;
    if (word == 'S')
    {
        p = { round, pow(stoi(strNum), 1) };
    }
    else if (word == 'D')
    {
        p = { round, pow(stoi(strNum), 2) };
    }
    else if (word == 'T')
    {
        p = { round, pow(stoi(strNum), 3) };
    }

    strNum = "";
    return p;
}

void Bonus(const char bonus, vector<pair<int, int>>& rounds)
{
    if (bonus == '*')
    {
        for (int i = 0; i < rounds.size(); i++)
        {
            int bound = rounds.size() - 2;
            if (i >= bound)
            { 
                rounds[i].second *= 2; 
            }
        }
    }
    else if (bonus == '#')
    {
        rounds[rounds.size() - 1].second *= -1;
    }
}

int solution(string dartResult) {
    int answer = 0;
    int square = 0;
    string strNum = "";
    int round = 0;
    vector<pair<int, int>> rounds;

    for (int i = 0; i < dartResult.size(); i++)
    {
        if (dartResult[i] >= 'A' && dartResult[i] <= 'Z')
        {
            round++;
            rounds.push_back(SquScore(dartResult[i], strNum, round));

            if (i + 1 < dartResult.size())
            {
                if (dartResult[i + 1] == '*' || dartResult[i + 1] == '#')
                {
                    Bonus(dartResult[i + 1], rounds);
                }
            }
        }
        else if (dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            strNum += dartResult[i];
        }
    }

    for (int i = 0; i < rounds.size(); i++)
    {
        answer += rounds[i].second;
    }
    return answer;
}