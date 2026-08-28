#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/* 1번 키부터 할당된 문자들이 순서대로 담긴 문자열배열 keymap 과 
*  입력하려는 문자열이 담긴 배열 targets 
*  각 문자열을 작성하기 위해 키를 최소 몇번 씩 눌러야 하는지
*  순서대로 배열에 담아 return 하기 (목표 문자열을 작성할 수 없을 때는 -1)
*  keymap 배열에서 찾는 알벳의 최소값을 구해야한다. 
*  
*/

unordered_map<char, int> Find(const vector<string>& keymap)
{
    unordered_map<char, int> array;

    for (int i = 0; i < keymap.size(); i++)
    {
        for (int j = 0; j < keymap[i].size(); j++)
        {
            auto find = array.find(keymap[i][j]);
            if (find == array.end())
                array[keymap[i][j]] = j;
            else
            {
                if (find->second > j)
                    array[keymap[i][j]] = j;
            }
        }
    }
    
    return array;
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    unordered_map<char, int> array = Find(keymap);

    for (int i = 0; i < targets.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < targets[i].size(); j++)
        {
            auto find = array.find(targets[i][j]);
            
            if (find == array.end())
            {
                count = -1;
                break;
            }
            else
            {
                count += find->second + 1;
            } 
        }
        answer.push_back(count);
    }

    return answer;
}