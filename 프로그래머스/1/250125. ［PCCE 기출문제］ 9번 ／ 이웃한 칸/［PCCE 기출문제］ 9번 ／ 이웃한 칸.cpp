#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    vector<int>row = { 0, 1, -1, 0 };
    vector<int>column = { 1, 0, 0, -1 };

    string baseColor = board[h][w];
 for (int i = 0; i < 4; i++)
 {
      if (h + row[i] >= 0 && w + column[i] >= 0 && h + row[i] < board.size() && w + column[i] < board.size())
 {
     if (board[h + row[i]][w + column[i]] == baseColor)
         answer++;
 }
 }

    return answer;
}