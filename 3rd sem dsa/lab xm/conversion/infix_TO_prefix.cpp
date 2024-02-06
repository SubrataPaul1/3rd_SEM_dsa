#include <bits/stdc++.h>

using namespace std;
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string infix_To_Prefix(string str)
{
    stack<char> st;
    string ans;
    reverse(str.begin(), str.end());
    for (int i = 0; i <= str.length(); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            ans += str[i];
        else if (str[i] == ')')
            st.push(str[i]);
        else if (str[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && prec(st.top()) >= prec(str[i]))
            {
                ans += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    // string infix = "(a-b/c)*(a/k-l)";
    string infix = "a+b";

    cout << infix_To_Prefix(infix);
}

//! algorithm
/*
//make two function 1-precdeing(char c)
                        |(^) > (* /) > (+ -)
                    2-infix to prefix(string str)
                        |->make a stack st & answer string s
                        |->reverse the str using function reverse function
                        |->initate a for from i(0->str.length()) where take every str[i]
                            //?|if str[i] is alphabet
                                    //*add in the string add in the answe string
                            //?|else if str[i] -> )
                                    //*push into the stack
                            //?|else if str[i] -> (
                                    //* pop stack & add them in the answer str untill st.top() != )
                                    //* if any leftover bracket present pop st
                            //?| else {means operator case}
                            //?|    pop element from the stack untill stack top element precednce higer than str[i]
                            //?|    pop each element & add them in the answer string
                            //?|    if while loop fails add the expression in the stack
                        |-> if any leftover is present in stack pop those by while loop & add them in the stack
                        |->reverse the answer string & return
*/