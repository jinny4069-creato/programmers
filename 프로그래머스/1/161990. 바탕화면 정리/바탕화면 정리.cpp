#include <string>
#include <vector>
using namespace std;

/* 바탕화면의 상태를 나타낸 문자열 배열 wallpaper
*  왼쪽 위 0, 0 에서 시작 빈칸은 . 파일이 이쓴 칸은 #
*  최소한의 이동거리를 갖는 한번의 드래그로 모든 파일 선택 하고 삭제 하려한다.
*  드래그는 바탕화면의 격자점 S(lux, luy) 를 마우스 왼쪽 버튼 클릭한 상태로
*  격자점 E(rdx, rdy) 로 이동한 뒤 마우스 왼쪽을 떼는 행동
*  점 S 시작점 점 E 끝점
*  드래그 한 거리 = |rdx - lux| + |rdy + luy|
*  드래그 하면 직사각형 내부에 있는 모든 파일이 선택된다.
*  
*  # 중 행렬 최소값 = S   # 중 행렬 최대값 = E 여야한다.
*  최소값과 최대값 을 구해야 한다.
* 
*/
vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    int lux = wallpaper.size();
    int luy = wallpaper[0].size();
    int rdx = 0;
    int rdy = 0;

    for (int i = 0; i < wallpaper.size(); i++)
    {
        for (int j = 0; j < wallpaper[i].size(); j++)
        {
            if (i == 6)
                int a = 10;
            if (wallpaper[i][j] == '#')
            {
                if (i < lux )
                {
                    lux = i;
                }
                if (i > rdx)
                {
                    rdx = i;
                }
                if (j < luy)
                {
                    luy = j;
                }
                if (j > rdy)
                {
                    rdy = j;
                }
            }
        }
    }

    // 행에서 최소 & 최대 열에서 최소 & 최대 인 # 4개를 구해야한다
    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx + 1);
    answer.push_back(rdy + 1);

    return answer;
}