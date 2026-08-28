#include <string>
#include <vector>

using namespace std;

/* 1번 키부터 할당된 문자들이 순서대로 담긴 문자열배열 keymap 과 
*  입력하려는 문자열이 담긴 배열 targets 
*  각 문자열을 작성하기 위해 키를 최소 몇번 씩 눌러야 하는지
*  순서대로 배열에 담아 return 하기 (목표 문자열을 작성할 수 없을 때는 -1)
*  keymap 배열에서 찾는 알벳의 최소값을 구해야한다. 
*  
*/

int Find(const vector<string>& keymap, char alphabet)
{
    int minimum = 999;

    for (int i = 0; i < keymap.size(); i++)
    {
        for (int j = 0; j < keymap[i].size(); j++)
        {
            if (alphabet == keymap[i][j])
            {
                if (minimum > j)
                    minimum = j;
            }
        }
    }
    return minimum == 999 ? -1 : minimum + 1;
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    for (int i = 0; i < targets.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < targets[i].size(); j++)
        {
            int find = Find(keymap, targets[i][j]);
            if (find == -1)
{
    count = -1;
    break;
}
            else
                count += find;
           
        }
        answer.push_back(count);
    }

    return answer;
}
