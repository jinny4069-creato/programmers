#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// schedules_len은 배열 schedules의 길이입니다.
// timelogs_rows는 2차원 배열 timelogs의 행 길이, timelogs_cols는 2차원 배열 timelogs의 열 길이입니다.
/* 출근희망시각 + 10 분 까지 출근해야한다.
*  단, 토요일 일요일 출근 시각은 제외
*  모든 시각은 시에 100을 곱하고 분을 더한 정수로 표현
*  직원 n 명의 출근희망시각이 있는 배열 schedules
*  일주일 출근시각을 담은 timelogs, 이벤트 시작 요일 startday
*  이때 상품을 받을 직원의 수 return
*  1. startday 는 1 - 7까지 timelogs 는 0 - 6 까지
*  2. schedules 에 10을 더한다. 
*  3. timelogs 반복문으로 i 번째 직원의 timelogs 를 탐색한다.
*  4. int day = startday; 를 만들고 같이 ++
*  5. 이때 day 가 6, 7 이면 continue;
*  6. schedules 에 10 을 더했을때 60 이상이면 예외처리
*/

int TimeCalcul(int iScheduleTime)
{
    int hour = iScheduleTime / 100;
    int minute = iScheduleTime % 100;
    minute = minute + 10;
    if (minute >= 60)
    {
        hour++;
        minute -= 60;
    }
    int limit = minute + hour * 100;
    return limit;
}
int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    for (int i = 0; i < timelogs.size(); i++)
    {
        bool bSuccess = true;
        int limit = TimeCalcul(schedules[i]);
        
        for (int j = 0; j < timelogs[i].size(); j++)
        {
            int day = (startday - 1 + j) % 7 + 1;
            if (day > 5)
            {
                continue;
            }
            if (timelogs[i][j] > limit)
            {
                bSuccess = false;
                break;
            }
        }
        if (bSuccess)
        {
            answer++;
        }
    }
    return answer;
}