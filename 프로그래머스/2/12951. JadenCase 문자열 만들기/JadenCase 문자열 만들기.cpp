#include <string>
#include <vector>

using namespace std;

string solution(string s) {

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            if (i == 0 || s[i - 1] == ' ')
                s[i] = s[i] - 32;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (i != 0 && s[i - 1] != ' ')
                s[i] = s[i] + 32;
        }
    }

    return s;
}