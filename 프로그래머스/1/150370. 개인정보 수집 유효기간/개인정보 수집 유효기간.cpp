#include <string>
#include <vector>
using namespace std;

/*  개인정보 n 개 유효기간이 지나면 파기해야한다.
*   모든 달은 28일까지 있다고 가정
*   ex) 21년1월5일의 개인정보는 22년1월4일까지 보관가능하다.
*   문자열 today 유효기간 배열 terms 개 개인정보 배열 privacies
*   파기해야할 개인정보 번호를 오름차순으로 return
*/

bool IsExpire(vector<int> expireDay, vector<int> today)
{
    if (expireDay[0] < today[0])    return true;
    if (expireDay[0] > today[0])    return false;
    if (expireDay[1] < today[1])    return true;
    if (expireDay[1] > today[1])    return false;
    if (expireDay[2] < today[2])    return true;

    return false;
}

vector<pair<char, int>> Type(vector<string>terms)
{
    vector<pair<char, int>> types;
    for (int i = 0; i < terms.size(); i++)
    {
        char type = terms[i][0];
        string strNum = "";
        for (int j = 2; j < terms[i].size(); j++)
        {
            strNum += terms[i][j];
        }
        int num = stoi(strNum);
        types.push_back({ type, num });
    }
    return types;
}

int FindType(vector<pair<char, int>>types, char myType)
{
    for (int i = 0; i < types.size(); i++)
    {
        if (types[i].first == myType)
        {
            return types[i].second;
        }
    }
    return 0;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
   
    vector<int> vecToday;
    vecToday.push_back(stoi(today.substr(0, 4)));
    vecToday.push_back(stoi(today.substr(5, 2)));
    vecToday.push_back(stoi(today.substr(8, 2)));
    vector<pair<char, int>> types = Type(terms);

    int year = 0;
    int month = 1;
    int day = 2;
    for (int i = 0; i < privacies.size(); i++)
    {
        vector<int> membership;
        char myType = '\0';
        string str = "";
        for (int j = 0; j < privacies[i].size(); j++)
        {
            str += privacies[i][j];
            if (j == 9)
            {
                membership.push_back(stoi(str.substr(0, 4)));
                membership.push_back(stoi(str.substr(5, 2)));
                membership.push_back(stoi(str.substr(8, 2)));
            }
            if (j == privacies[i].size() - 1)
            {
                myType = privacies[i][j];
            }
        }

        int period = FindType(types, myType);

        vector<int> expireDay;
        expireDay.push_back(membership[year]);
        expireDay.push_back(membership[month] + period);
        expireDay.push_back(membership[day] - 1);
        if (expireDay[day] <= 0)
        {
            expireDay[day] += 28;
            expireDay[month] -= 1;
        }
        while (expireDay[month] > 12)
        {
            expireDay[month] = expireDay[month] - 12;
            expireDay[year] += 1;
        }

        bool expire = IsExpire(expireDay, vecToday);

        if (expire)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}
