#include <string>
#include <vector>
#include <iostream>

using namespace std;

/* 1번부터 번호 순서대로 한 사람씩 차례대로 단어를 말한다.
*  마지막 사람이 단어를 말하면 1번부터 다시시작
*  앞사람이 말한 단어의 마지막 문자로 시작하는 단어를 말해야한다.
*  이전에 등장한 단어는 사용 X
*  한 글자는 인정 X
*  사람의 수 n 과 단어 words 가 매개변수일 때
*  가장 먼저 탈락하는 사람의 번호와 그 사람이 자신의 몇번째에 탈락하는지 구하기
*  1. 이중 for 문 사용 첫번째 char 하고 마지막 char 을 가져온다
*  2. i++ 할때 마다 이전 last 문자가 현재 first 와 같은지 비교
*  3. false 면 return 한다. i / n -> 몇번째 턴 i % n 는 몇번 사람인지
*  4. words for 문을 한번 더 돌려 같은 단어가 있는지 확인한다.
*/
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    char first = '\0';
    char last = '\0';
    bool wrong = 0;
    for (int i = 0; i < words.size(); i++)
    {
        first = words[i][0];

        if (last != '\0' && last != first)
            wrong = true;
          
        if (words[i].size() == 1)
            wrong = true;

        for (int j = 0; j < i; j++)
        {
            if (words[i] == words[j])
                wrong = true;
        }

        last = words[i][words[i].size() - 1];
        
        if (wrong)
        {
            int turn = (i + 1) / n;
            int num = (i + 1) % n;
            if (num == 0)
                num = n;
            else
                turn += 1;
            answer.push_back(num);
            answer.push_back(turn);
            return answer;
        }
    }

    answer.push_back(0);
    answer.push_back(0);
    return answer;
}