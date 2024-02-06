#include <bits/stdc++.h>
using namespace std;
int prec(int c)
{
    if (c == '^')
        return 3;
    else if (c == '+' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string infixToPostfix(string str)
{
    stack<char> st;
    string ans;
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            ans += str[i];
        else if (str[i] == '(')
            st.push(str[i]);
        else if (str[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && prec(st.top()) > prec(str[i]))
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
    return ans;
}
int main()
{
    string infix = "(a-b/c)*(a/k-l)";
    cout << infixToPostfix(infix);
}