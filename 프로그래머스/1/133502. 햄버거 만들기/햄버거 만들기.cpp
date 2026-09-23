#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    vector<int>burger = { 1, 2, 3, 1 };
    vector<int> stack;
    stack.reserve(ingredient.size());
 
    for (int i = 0; i < ingredient.size(); i++)
    {
        stack.push_back(ingredient[i]);
        
        if (stack.size() < 4) { continue; }
        
        int startIndex = stack.size() - 4;
        bool bOrder = false;
        for (int j = 0; j < burger.size(); j++)
        {
            if (stack[startIndex + j] != burger[j]) 
            {
                bOrder = false; 
                break; 
            }
            else { bOrder = true; }
        }
        if (bOrder)
        {
            answer++;
            stack.pop_back();
            stack.pop_back();
            stack.pop_back();
            stack.pop_back();
        }

    }

    return answer;
}