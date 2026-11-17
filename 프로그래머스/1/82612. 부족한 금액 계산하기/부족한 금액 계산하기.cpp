using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long total = 0;
    for (int i = 1; i <= count; i++)
    {
        long long num1 = price * i;
        total += num1;
    }
    long long num2 = total - money;
    if (num2 > 0)
        answer = num2;
    else
        answer = 0;

    return answer;
}