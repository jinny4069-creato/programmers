#include <string>
#include <vector>

using namespace std;

/* 아이디 추천 프로그램
*  1. 길이는 3 ~ 15 자
*  2. 알파벳 소문자, 숫자, 빼기, 밑줄, 마침표 문자만 사용가능
*  3. 마침표는 처음, 끝에 사용 X, 연속 X
*  입력한 아이디 new_id 처리 후 추천 아이디 return
* 
*  1. 대문자 -> 소문자로 치환
*  2. 소문자, 숫자, 빼기, 밑줄, 마침표 를 제외한 모든 문자 제거
*  3. .. 두개이면 하나로 치환한다.
*  4. 마침표가 처음, 끝에 위치하면 제거
*  5. 길이가 16 이상이면 16번째 부터 뒤 문자 삭제
*  6. 만약 끝이 . 이라면 . 제거
*  7. 길이가 2 이하라면 마지막 문자를 길이가 3 이 될때까지 반복한다.
* 
*  1. 대문자 -> 소문자 는 if ('A' <= 'Z') 이면 +32 
*  2. 소문자, 숫자, -, _, . 만 string 에 +
*  3. . 을 찾고 이전 . 의 i 를 비교하여 +1 -1 이면 pop 한다.
*/

string step_one(string new_id)
{
    string one = "";
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
        {
            one += new_id[i] + 32;
        }
        else
        {
            one += new_id[i];
        }
    }

    return one;
}

string step_two(string new_id)
{
    // 소문자는 97 - 122
    // 숫자는 48 - 57
    // - 는 45
    // _ 는 95
    // . 은 46
    string two = "";
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] >= 'a' && new_id[i] <= 'z') { two += new_id[i]; }
        else if (new_id[i] >= '0' && new_id[i] <= '9') { two += new_id[i]; }
        else if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') { two += new_id[i]; }
    }

    return two;
}

string step_three(string new_id)
{
    string three = "";
    bool bDot = false;
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] == '.')
        {
            if (!bDot && !three.empty())
            {
                three += new_id[i];
                bDot = true;
            }
        }
        else
        {
            three += new_id[i];
            bDot = false;
        }
    }
    
    return three;
}

string step_four(string new_id)
{
    string four = "";
    if (new_id.empty())
    {
        four += "a";
    }
    else
    {
        four = new_id;
    }
    return four;
}

string step_five(string new_id)
{
    //string five = "";

    new_id = new_id.substr(0, 15);
    //for (int i = 0; i < new_id.size(); i++)
    //{
    //    if (i < 15)
    //    {
    //        five += new_id[i];
    //    }
    //}
   
    return new_id;
}

string step_six(string new_id)
{
    string six = "";

    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] == '.')
        {
            if (i != 0 && i != new_id.size() - 1)
            {
                six += new_id[i];
            }
        }
        else
        {
            six += new_id[i];
        }
    }

    return six;
}

string step_seven(string new_id)
{
    string seven = "";

    int i = 0;
    if (new_id.size() < 3)
    {
        while (seven.size() < 3)
        {
            seven += new_id[i];
            if (i < new_id.size() - 1)
            {
                i++;
            }
        }
    }
    else
    {
        seven = new_id;
    }

    return seven;
}

string solution(string new_id) {
    string answer = "";
    
    answer = step_one(new_id);
    answer = step_two(answer);
    answer = step_three(answer);
    answer = step_four(answer);
    answer = step_five(answer);
    answer = step_six(answer);
    answer = step_seven(answer);

    return answer;
}