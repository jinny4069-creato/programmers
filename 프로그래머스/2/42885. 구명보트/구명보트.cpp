#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/* 한번에 최대 2 명 && 무게 100 kg 이하 만 탈수있는 구명보트 
*  무게제한 int limit, 배열 people
*  필요한 구명보트의 최소값 return
*/
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), less<>());
    vector<bool> board;
    board.resize(people.size(), false);

    int left = 0;
    

    for (int right = people.size() - 1; right >= 0; right--)
    {
        if (board[right] == true)
            continue;

        board[right] = true;
        answer++;

        if (left < right && people[left] + people[right] <= limit)
        {
            board[left] = true;
            left++;
        }
    }

    return answer;
}