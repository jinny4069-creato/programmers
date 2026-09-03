#include <iostream>

using namespace std;

/* 한번에 K 칸을 점프, 현재까지 온 거리 X 2 순간이동
*  순간이동을 하면 건전지 사용량이 줄지 않는다.
*  점프하면 K 만큼 건전지 사용
*  거리 N 만큼 이동하려면 점프를 최소화 하여 사용하는 건전지 사용량의 최솟값
*  ex) 거리 5 를 이동 -> 1칸을 점프하고 순간이동 두번, 점프1번 = 사용량 2
*  while 로 n 부터 시작 현재 칸이 0이 될때까지 실행한다
*  step % 2 가 1 이면 점프로 판단
*/
int solution(int n)
{
    int jump = 0;
    int curStep = 0;

    int step = n;
    while (true)
    {
        if (step % 2 > 0)
        {
            jump++;
        }

        step /= 2;

        if (step == 0)
            break;
    }

    return jump;
}