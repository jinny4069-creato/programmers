#include <string>
#include <vector>

using namespace std;

/* 한번에 1칸, 또는 2칸을 뛴다.
*  ex) 4칸이 잇다면 총 5가지 방법으로 끝 칸에 도달할 수 있다.
*  칸의 수 n 에 대해 몇가지 방법으로 끝 칸에 갈 수 있는가
*  여기에 1234567 을 나눈 나머지를 리턴하는 함수
*  1. n 이 1이라면 방법은 1개, 2라면 방법은 2개 3이라면 방법은 3개 4 라면 5개
*  2. n 의 n - 1 의 값 n - 2 의 값 을 더한게 n 의 값이다.
*  3. n 의 이전 값 1 하고 이전값 2 를 저장해 for 반복한다.
*/

long long solution(int n) {
    long long prev1 = 1;
    long long prev2 = 2;

    long long count = 0;
    for (int i = 3; i <= n; i++)
    {
        count = prev1 + prev2;

        prev1 = prev2;
        prev2 = count;

        prev2 %= 1234567;
    }

    if (n == 1)
        return prev1;

    return prev2;
}