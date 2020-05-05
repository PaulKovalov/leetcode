class Solution {
public:
    vector<int> split(int n, int p) {
        vector<int> r;
        if (p == 0) {
            r.push_back(n);
        }
        else if (n % p == 0) {
            for (int i = 0; i < p; ++i)
                r.push_back(n/p);
        } else if (n % p) {
            int l = p - (n % p);
            int integer_part = n / p;
            for (int i = 0; i < p; ++i) {
                if (i >= l)
                    r.push_back(integer_part + 1);
                else
                    r.push_back(integer_part);
            }
        }
        reverse(r.begin(), r.end());
        return r;
    } 
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> r;
        string space = " ", current = "";
        int i = 0, from = 0, cl = 0;
        while (i < words.size()) {
            while (i < words.size() && cl + words[i].length() <= maxWidth) {
                cl += words[i].length() + 1;
                ++i;
            }
            cl = 0;
            for (int j = from; j < i; ++j) {
                cl += words[j].length();
            }
            vector<int> spaces = split(maxWidth - cl, i - from - 1);
            for (int j = from; j < i; ++j) {
                current += words[j];
                if (i == words.size() && j < i - 1)
                    current += space;
                else if (j - from < spaces.size())
                    for (int k = 0; k < spaces[j - from]; ++k)
                        current += space;
            }
            if (i == words.size()) {
                int to = maxWidth - current.length();
                for (int j = 0; j < to; ++j)
                    current += space;
            }
            r.push_back(current);
            current = "";
            from = i;
            cl = 0;
        }
        return r;
    }
};