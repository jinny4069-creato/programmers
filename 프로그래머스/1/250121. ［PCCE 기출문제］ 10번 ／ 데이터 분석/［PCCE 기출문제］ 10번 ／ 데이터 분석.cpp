#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* 코드번호, 제조일, 최대수량, 현재수량 으로 구성되어있는 데이터
*  ex) {3, 20300401, 10, 8} , {1, 20300104, 100, 80}
*  이차원 정수 리스트 data  기준 문자열 ext  기준값 val_ext
*  정렬 기준 문자열 sort_by 
*  data 에서 ext 값이 val_ext 보다 작은 데이터만 뽑은 후
*  sort_by 에 해당하는 값을 기준으로 오름차순 정렬하고 return 하기
*  
*  data 의 0 = code, 1 = date, 2 = maximum, 3 = remain
*  vector 로 string 저장한다. ext 와 contents 를 비교해서 같은 문자열이면 기준
*  val_ext 보다 작은 것만 push_back
*  
*/
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    vector<string> contents{ "code", "date", "maximum", "remain" };
    int iExt = -1;
    for (int i = 0; i < contents.size(); i++)
    {
        if (contents[i] == ext)
        {
            iExt = i;
            break;
        }
    }
   
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][iExt] < val_ext)
        {
            answer.push_back(data[i]);
        }
    }

    int iSort = -1;
    for (int i = 0; i < contents.size(); i++)
    {
        if (contents[i] == sort_by)
        {
            iSort = i;
            break;
        }
    }
    
    int com = answer[0][iSort];
    int num = 0;
    for (int i = 0; i < answer.size(); i++)
    {
        if (i > num)
        {
            if (answer[i][iSort] < com)
            {
                swap(answer[i], answer[num]);
                i = 0;
            }
        }
        com = answer[i][iSort];
        num = i;
    }

    return answer;
}