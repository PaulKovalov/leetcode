class Solution {
public:
    char opposite(char c) {
        switch(c) {
            case '(': {
                return ')';
            }
            case ')': {
                return '(';
            }
            case ']': {
                return '[';
            }
            case '[': {
                return ']';
            }
            case '{': {
                return '}';
            }
            case '}': {
                return '{';
            }
        }
        return '0';
    }
    bool isValid(string s) {
        stack<char> st;
        
            for (int i = 0; i < s.length(); ++i) {
                if (!st.empty() &&  st.top() == opposite(s[i])) {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
                
            }
        
        return st.empty();
        
    }
};