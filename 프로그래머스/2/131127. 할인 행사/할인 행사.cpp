#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/* 10일 동안 회원 자격 부여 할인제품은 하루에 하나만 구매
*  제품과 수량이 할인하는 날짜와 10 일 연속으로 일치할 경우에 맞추어 회원가입
*  ex) 바나나3 / 사과2 / 쌀2 / 돼지2 / 냄비1/ 원하는 목록
*      14일간 할인제품이 치킨, 사과, 사과, 바나나, 쌀, 사과, 돼지, 바나나, 돼지, 쌀, 냄비, 바나나, 사과, 바나나
*      ->1일 부터 10일 동안 냄비가 아니니까 가입 X
*      ->2일 부터 12일간 바나나를 원하는 만큼 구매할 수 없기 때문에 2일 회원가입 X
*      ->3, 4, 5 부터 일치하기 때문에 셋 중 하루에 가입한다.
*  원하는 제품 문자열 want, 수량 number, 할인제품 문자열 discount
*  원하는 제품을 모두 할인 받을 수 있는 회원등록 날짜의 총 일수 return
*/


int solution(vector<string> want, vector<int> number, vector<string> discount) {

    unordered_map<string, int> wish;
  
    for (int i = 0; i < want.size(); i++)
    {
        wish.insert({ want[i], number[i]});
    }
    
    int left = 0;
    int right = 9;
    int count = 0;
   
    unordered_map<string, int> sell;

    for (int j = left; j <= right; j++)
    {
        auto iter = sell.find(discount[j]);
        if (iter != sell.end())
            iter->second++;
        else
            sell.insert({ discount[j], 1 });
    }

    while (right < discount.size())
    {
        bool bCorrect = true;

        if (wish == sell)
            count++;

        sell[discount[left]]--;
        if (sell[discount[left]] == 0)
            sell.erase(discount[left]);

        left++;
        right++;

        if (right >= discount.size())
            continue;

        auto product = sell.find(discount[right]);
        if (product == sell.end())
            sell.emplace(discount[right], 1);
        else
            sell[discount[right]]++;
    }
        
    return count;
}