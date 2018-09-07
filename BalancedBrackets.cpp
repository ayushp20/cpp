#include <bits/stdc++.h>

using namespace std;
string isBalanced(string s) {
   stack<char> st;
    char a, b, c;
    // Traversing the session
    for (int i=0; i<s.length(); i++)
    {
        if (s[i]=='('||s[i]=='['||s[i]=='{')
        {
            // Push the element in the st
            st.push(s[i]);
        }
        else
        {
            switch (s[i])
            {
            case ')':

                // Store the top element in a
                a = st.top();
                st.pop();
                if (a=='{'||a=='[')
                    return "NO";
            case '}':

                // Store the top element in b
                b = st.top();
                st.pop();
                if (b=='('||b=='[')
                    return "NO";
            case ']':

                // Store the top element in c
                c=st.top();
                st.pop();
                if (c=='('||c=='{')
                    return "NO";
            }
        }
    }
    if(st.empty())
        return "YES";
    else
        return "NO";
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
