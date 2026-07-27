#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<string> week = { "SUN","MON", "TUE", "WED", "THU", "FRI", "SAT"};
    vector<int> lastday = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int month = 1;
    int day = 1;
    int aLastDay = 0;
    int countWeek = 0;
    string answer = "";
    for (int i = 1; i <= a; i++)
    {
        aLastDay = lastday[i - 1];

        for (int j = 1; j <= aLastDay; j++)
        {
            if (i == 1 && j == 1)
                countWeek = 5;
if (i == a && j == b)
            {
                answer = week[countWeek];
                return answer;
            }
            countWeek++;

            if (countWeek >= week.size())
                countWeek = 0;

            
        }
    }
  
    return answer;
}