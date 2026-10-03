#include <string>
#include <vector>
#include <map>
using namespace std;

/*  성격유형검사
*   1 번 지표 : R, T
*   2 번 지표 : C, F
*   3 번 지표 : J, M
*   4 번 지표 : A, N
*   총 16 가지의 성격유형이 나온다.
*   n 개의 질문이 있고 각 질문에는 7개의 선택지가 있다.
*   매우 동의 / 매우 비동의 -> 3점
*   동의 / 비동의 -> 2점
*   약간 동의 / 약간 비동의 -> 1점
*   모르겠음 -> 0점
*   문자열 배열 survey 와 선택지 정수 배열 choices
*   검사지 결과를 지표 번호 순서대로 return 하기
*   1. 지표에 따라 char 순서를 바꿔야한다.
*   2. survey 기준 점수를 계산하고 점수에 따라 어떤 char 인지 계산
*   3. 같은 문항 다른 점수 일 경우 점수, char 를 pair 로 묶어 저장한다
*   4. 같은 유형인지 알아야 하니까 survey 에서 indicator for 문 돌려서
*   5. 유형을 묶어야 한다.
*/
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    //vector<pair<char, int>> results;
    vector<string> indicator{ "RT", "CF", "JM", "AN"};
    map<char, int> score;
    // 점수가 있고 survey 별 점수를 types 에 저장한 거 에서 가져와서
    // 점수 로 어떤 값이 더 큰지 비교해서 내보낼 유형을 정해야 한다.

    for (int i = 0; i < survey.size(); i++)
    {
        if (choices[i] > 4)
        {
            score[survey[i][1]] += choices[i] - 4;
        }
        else
        {
            score[survey[i][0]] += 4 - choices[i];
        }
    }

    // 점수 계산을 해야한다. 같은 유형의 값들이 있는지 확인
    // 있으면 - 해서 결과값 기준으로 정해햐 한다.
    for (int i = 0; i < indicator.size(); i++)
    {
        if (score[indicator[i][0]] >= score[indicator[i][1]])
        {
            answer += indicator[i][0];
        }
        else
        {
            answer += indicator[i][1];
        }
    }

  
    return answer;
}