#include <string>
#include <vector>

using namespace std;

/* 피보나치 수
*  1 이상의 n 에 대하여 F(n) = F(n-1) + F(n-2) 가 적용된다
*  ex) F(2) = F(1) + F(0) = 0 + 1 = 1
*      F(3) = F(2) + F(1) = 1 + 1 = 2
*      F(4) = F(3) + F(2) = 2 + 1 = 3
*  2 이상의 n 이 입력되었을 때, F(n) % 1234567 의 나머지를 return 해라
*  1. 재귀 함수로 만든다. n 은 2 이상이어야한다.
*  2. 재귀로 나온 값에 % 1234567 한다 -> answer = 결과괎 % 1234567
*  1. for 문으로 돌린다 
*  2. i++ 로 n 까지 증가하고 이전 계산값을 가지고 있어야한다.
*/

int Fibo(int n)
{
    return 0;
    //return n >= 2 ? Fibo(n - 1) + Fibo(n - 2) : n;
}

int solution(int n) {
    int answer = 0;

    //int num = Fibo(n);

    int num1 = 0;
    int num2 = 1;

    for (int i = 2; i <= n; i++)
    {
        int num3 = 0;
        num3 += (num1 + num2) % 1234567;
        num1 = num2;
 num2 = num3;
    }

    answer = num2;

    return answer;
}