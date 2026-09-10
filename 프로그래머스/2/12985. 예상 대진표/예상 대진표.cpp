#include <iostream>

using namespace std;

/* N 명의 참가자 토너먼트 대회
*  1번 & 2번 게임에서 2번이 이기면 다음 라운드에서 1번을 부여받는다.
*  최종 1명이 남을때까지 진행
*  게임참가자 수 N, 참가자 A, 참가자 B 일때
*  처음 라운드에서 A 번을 가진 참가자는 B번 참가자와 몇번째 라운드에서 만나는지
*  A번 참가자와 B번 참가자는 만나기 전까지 항상 이긴다.
*  경기는 n / 2 라운드 
*  1번이라면 유지 나머지 A - 1 번으로 올라감
*  n 을 2로 나누어 1이 될때까지 나눔
*  1번 2번 이 있다면 둘이 만났다는 것을 어떻게 아냐
*  차이가 1이 나고 큰숫자가 짝수이다
*  
*/
int solution(int n, int a, int b)
{
    int answer = 0;

    int aWin = a;
    int bWin = b;
    while (aWin != bWin)
    {
       

        aWin = aWin / 2 + aWin % 2;
        bWin = bWin / 2 + bWin % 2;

        answer++;
    }

    return answer;
}