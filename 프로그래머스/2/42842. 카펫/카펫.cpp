#include <string>
#include <vector>
#include <cmath>
using namespace std;

/* 가로세로 크기를 구해라
*  정사각형 12개 가 모여있는 직사각형 크기에 대해
*  테두리 갈색, 중앙 노란색 사각형으로 이루어짐
*  갈색 격자 수 8이상  노란색 1이상
*  전체크기는 정사각형 이거나 가로가 더 큰 직사각형이다.
*  ex) 갈색 10, 노란색 2 -> return 가로4, 세로3
*  1. 가로가 세로보다 길어야한다
*  2. yellow 의 가로 갯수 + 2 가 brown 의 가로 개수
*  3. yellow 의 세로 개수 + 2 = brown 의 세로 개수
*  4. yellow 가 1, 4, 16, 25 제곱이어야 정사각형이다.
*  5. 제곱이 아닌경우 배수인지 확인하기
*  6. 배수도 아니면 세로 3 가로 yellow + 2 = brown 가로 개수
*/ 
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<vector<int>> extent;
    int a = sqrt(yellow);
    int b = a * a;
    if (yellow == b)
    {
        answer.push_back(a +2);
        answer.push_back(a + 2);
    }
    else
    {
        for (int i = 1; i <= yellow; i++)
        {
            if (yellow % i == 0)
            {
                int num = yellow / i;
                if (num > i)
                    extent.push_back({ num, i });
                else
                    extent.push_back({ i, num });
            }
        }

        for (int i = 0; i < extent.size(); i++)
        {
            if ((extent[i][0] * 2 + 2) + (extent[i][1] * 2 + 2) == brown)
            {
                answer.push_back(extent[i][0] + 2);
                answer.push_back(extent[i][1] + 2);
                break;
            }
        }
        int c = yellow;
       
    }


    return answer;
}