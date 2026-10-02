#include <string>
#include <vector>
#include <stack>
using namespace std;

/* N x N 크기의 정사각 격자 아래칸부터 인형이 쌓여있다.
*  12345 열이 있고, 집게가 나중에 저장된 것 부터 꺼낸다.
*  만약 같은 모양의 인형 두개가 바구니에 연속해서 쌓이면 두 인형은 삭제된다.
*  2차원 배열 board 와 집게 위치가 담긴 배열 moves
*  집게를 모두 작동 시킨 후 터트려져 사라진 인형의 개수를 return
* 
*  board[행][열] 로 구성 moves 가 1 이면 
*  board 의 각 행 당 1열을 탐색 -> 0부터 4까지 하다가 0 이 아닌 값이 있으면 꺼내오기
*  stack 에 push 하고 해당 행은 가져온 값을 0으로 만든다.
*  
*/

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> gets;

    for (int i = 0; i < moves.size(); i++)
    {
        int num1 = 0;
        int num2 = 0;

        int col = moves[i] - 1;
        for (int j = 0; j < board.size(); j++)
        {
            if (!gets.empty())
            {
                num1 = gets.top();
            }

            int get = board[j][col];

            if (get != 0)
            {
                num2 = get;
                board[j][moves[i] - 1] = 0;

                if (num1 != 0 && num1 == num2)
                {
                    gets.pop();
                    answer += 2;
                }
                else
                {
                    gets.push(num2);
                }
                break;
            }
        }
    }
    return answer;
}