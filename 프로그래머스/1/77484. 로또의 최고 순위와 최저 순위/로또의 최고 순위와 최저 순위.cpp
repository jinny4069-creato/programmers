#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 1부터 45까지 숫자 중 6개를 적는다.
*  알아 볼 수 없는 번호 0 으로 표기
*  ex) 번호가 lottos { 44, 1, 0, 0, 31, 25 } 일때
*  당첨번호가 win_nums { 31, 10, 45, 1, 6, 19 } 라면
*  당첨 가능한 최고 순위와 최저 순위 를 배열에 담아서 return
*  1. win_nums 를 for 문 돌리고 find(lottos.begin(), lottos.end(), win_nums[i] 한다
*  2. 찾으면 int win++
*  3. lottos 에 0 이 몇개인지 count
*  4. win + count 해서 switch 로 int high 최고 순위 계산
*  5. count 없이 win 해서 int low 최저 순위 계산
*/

int Rank(int num)
{
    switch (num)
    {
    case 0:
        return 6;
    case 1:
        return 6;
    case 2:
        return 5;
    case 3:
        return 4;
    case 4:
        return 3;
    case 5:
        return 2;
    case 6:
        return 1;
    }
    return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int win = 0;
    int count = 0;
    for (int i = 0; i < win_nums.size(); i++)
    {
        auto it = find(lottos.begin(), lottos.end(), win_nums[i]);
        if (it != lottos.end())
            win++;
    }

    for (int i = 0; i < lottos.size(); i++)
    {
        if (lottos[i] == 0)
            count++;
    }

    int high = Rank(win + count);
    int low = Rank(win);
    
    answer.push_back(high);
    answer.push_back(low);

    return answer;
}