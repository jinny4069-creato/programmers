#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/* 참여자 이름 배열 participant    완주자 이름 completion
*  미완주자 이름을 return 하시오
*  
*/
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> hashs;

    for (string str : participant)
    {
        hashs[str]++;
    }

    for (int i = 0; i < completion.size(); i++)
    {
        hashs[completion[i]]--;
    }

    for (const auto& iter : hashs)
    {
        if (iter.second == 1)
            answer = iter.first;
    }

    return answer;
}