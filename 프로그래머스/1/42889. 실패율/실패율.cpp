#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<float, int>> failpercent;
    for (int i = 1; i <= N; i++)
    {
        float iChallengers = 0.f;
        float iClear = 0.f;
        for (int j = 0; j < stages.size(); j++)
        {
            if (i < stages[j])
                iClear++;
            if (i == stages[j])
                iChallengers++;
        }
        float fail = iChallengers / (iClear + iChallengers);
if (iClear == 0 && iChallengers == 0)
    fail = 0.f;
        failpercent.push_back({ fail, i });
    }
     sort(failpercent.begin(), failpercent.end(), [](auto a, auto b) { if (a.first == b.first) return a.second < b.second; return a.first > b.first; });
    for (auto iter : failpercent)
        answer.push_back(iter.second);
   
    return answer;
}