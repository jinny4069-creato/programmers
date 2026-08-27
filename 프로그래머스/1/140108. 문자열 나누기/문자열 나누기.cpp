#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    int start = s[0];
    int equal = 0;
    int unequal = 0;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (start == s[i]) equal++;
        else unequal++;

        if (i + 1 == s.size() || equal == unequal)
        {
            answer++;
            equal = 0;
            unequal = 0;
            start = s[i + 1];
        }
    }

    return answer;
}