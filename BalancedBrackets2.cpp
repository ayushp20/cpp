#include <bits/stdc++.h>

using namespace std;

string isBalanced(string s) {
    // Complete this function
     stack <char> stack;
        int i=0;
    if(s.length()%2==1)
        return "NO";
    else
    {

        while(s[i]!='\0')
        {
            if(s[i]=='{'||s[i]=='['||s[i]=='(')
            {
                stack.push(s[i]);
                i++;
            }
            else
            {
                if(s[i]=='}')
                {
                    if(stack.top()=='{')
                    {
                        stack.pop();
                        i++;
                    }
                    else
                        return "NO{";
                }
                else if(s[i]==']')
                {
                    if(stack.top()=='[')
                    {
                        stack.pop();
                        i++;
                    }
                    else
                        return "NO[";

                }
                else if(s[i]==')')

                    if(stack.top()=='(')
                    {
                        stack.pop();
                        i++;
                    }
                    else
                        return "NO(";
            }

        }
    }
    if(stack.empty()==1)
        return "YES";
    else
        return "NOl";
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        string result = isBalanced(s);
        cout << result << endl;
    }
    return 0;
}

