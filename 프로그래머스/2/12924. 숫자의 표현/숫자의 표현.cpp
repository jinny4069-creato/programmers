#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    int sum = 0;

    for (int i = 1; i <= n / 2;)
    {
        sum += i;

        for (int j = 1; j <= n / 2; j++)
        {
            sum += i + j;

            if (sum == n)
            {
                answer++;
                sum = 0;
                break;
            }
            else if (sum > n)
            {
                sum = 0;
                break;
            }
        }

        i++;
    }
  answer++;
    return answer;
}