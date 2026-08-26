#include <string>
#include <vector>

using namespace std;

/* 문자열 s, skip, 자연수 index
*  문자열 s 의 각 알파벳을 index 만큼 뒤의 알파벳으로 바꾼다.
*  z 를 넘어갈 경우 다시 a 로 돌아간다
*  skip 에 있는 알파벳을 건너뛴다.
*  1. skip 의 문자를 제외한 알파벳 문자열을 만들고 
   2. 매개변수로 문자 와 index 를 받는 함수만든다 문자 return.
*  3. for 문 문자열 s 를 탐색하고 함수에 전달한다.
* 
*/


string Make(string skip)
{
    string array = "";

    for (int i = 'a'; i <= 'z'; i++)
    {
        bool bSkip = false;
        for (int j = 0; j < skip.size(); j++)
        {
            if (i == skip[j])
            {
                bSkip = true;
                break;
            }
        }

        if (!bSkip)
            array += i;
    }
    return array;
}

char ChangeWord(char word, int index, const string& array)
{
    char alphabet = '\0';

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] == word)
        {
            int change = i + index;
            if (change >= array.size())
               change = change % array.size();

            alphabet = array[change];
            break;
        }
    }

    return alphabet;
}

string solution(string s, string skip, int index) {
    string answer = "";
   
    string array = Make(skip);

    for (int i = 0; i < s.size(); i++)
    {
        char word = '\0';
        word = ChangeWord(s[i], index, array);
        answer += word;
    }

    return answer;
}
