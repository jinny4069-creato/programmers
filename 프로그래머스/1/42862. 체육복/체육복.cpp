#include <string>
#include <vector>

using namespace std;
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n, 1);

    for (int i = 0; i < lost.size(); i++)
    {
        int lostIndex = lost[i] - 1;
        student[lostIndex] -= 1;
    }

    for (int i = 0; i < reserve.size(); i++)
    {
        int reserveIndex = reserve[i] - 1;
        student[reserveIndex]++;
    }

    for (int i = 0; i < student.size(); i++)
{
    if (student[i] == 2)
    {
        if (i + 1 >= student.size())
            continue;

        if (student[i + 1] == 0)
        {
            student[i + 1]++;
            student[i]--;
        }
    }

    if (student[i] == 0)
    {
        if (i + 1 >= student.size())
            continue;

        if (student[i + 1] == 2)
        {
            student[i + 1]--;
            student[i]++;
        }
    }
}

    for (int i = 0; i < student.size(); i++)
    {
        if (student[i] >= 1)
            answer++;
    }
    return answer;
}