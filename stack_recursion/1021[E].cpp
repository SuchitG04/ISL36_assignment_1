class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> pars;
        string ans;

        for (auto p: s) {
            if (p == '(') {
                pars.push(p);
                if (pars.size() > 1) {
                    ans += p;
                }
            }
            else {
                pars.pop();
                if (pars.size() != 0) {
                    ans += p;
                }
            }
        }

        return ans;
    }
};
