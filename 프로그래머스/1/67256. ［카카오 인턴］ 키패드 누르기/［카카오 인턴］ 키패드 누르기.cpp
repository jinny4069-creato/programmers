#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* 왼손 오른손의 엄지손가락만 이용해서 숫자입력
*  처음에 왼손은 * 오른손은 # 에 위치에서 시작
*  손가락은 상하좌우 4가지 방향으로만 이동 할 수 있다.
*  1, 4, 7 을 입력할때는 왼손을 사용
*  3, 6, 9 를 입력할때는 오른손 사용
*  2, 5, 8, 0 을 입력할때는 더 가까운 손가락 사용
*  만약 거리가 같다면 오른손잡이는 오른손, 왼손잡이는 왼손 사용
*  각 번호를 누른 손가락이 어디인지 나타내는 문자열 return
* 
*  1. for 문으로 numbers 를 돌린다.
*  2. 1, 4, 7 은 vector lhands 3, 6, 9 는 rhands 로 저장한다.
*  3. 처음은 *, # 로 시작 *, 0, # 을 임의로 10, 11, 12 로 만들기
*/

int calDist(int number, int left, int right, string hand)
{
    int rowL = -1;
    int colL = -1;

    int rowR = -1;
    int colR = -1;

    int rowNum = -1;
    int colNum = -1;

    vector<vector<int>> phoneNum{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 0, 12} };
    for (int i = 0; i < phoneNum.size(); i++)
    {
        for (int j = 0; j < phoneNum[i].size(); j++)
        {
            if (phoneNum[i][j] == left)
            {
                rowL = i;
                colL = j;
            }
            else if (phoneNum[i][j] == right)
            {
                rowR = i;
                colR = j;
            }
            if (phoneNum[i][j] == number)
            {
                rowNum = i;
                colNum = j;
            }
        }
    }

    int rowLD = rowNum - rowL;
    int colLD = colNum - colL;
    int leftDist = abs(rowNum - rowL) + abs(colNum - colL);

    int rowRD = rowNum - rowR;
    int colRD = rowNum - colR;
    int rightDist = abs(rowNum - rowR) + abs(colNum - colR);

    if (leftDist == rightDist)
    {
        if (hand == "left")
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if (leftDist < rightDist)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int curleft = 10;       // *
    int curright = 12;      // #
    vector<int> lNum{ 1, 4, 7 };
    vector<int> rNum{ 3, 6, 9 };

    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] != 0 && numbers[i] % 3 == 0)
        {
            for (auto num : rNum)
            {
                if (numbers[i] == num)
                {
                    answer += "R";
                    curright = num;
                    break;
                }
            }
        }
        else if (numbers[i] % 3 == 1)
        {
            for (auto num : lNum)
            {
                if (numbers[i] == num)
                {
                    answer += "L";
                    curleft = num;
                    break;
                }
            }
        }
        else
        {
            // 0 이면 left, 1 이면 right;
            int dist = calDist(numbers[i], curleft, curright, hand);
            if (dist == 0)
            {
                answer += "L";
                curleft = numbers[i];
            }
            else
            {
                answer += "R";
                curright = numbers[i];
            }
        }
    }

    return answer;
}