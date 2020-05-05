class Solution {
public:
    int maxDiff(int num) {
        // find max number
        string s1 = "", t;
    while (num) {
        s1 += to_string(num%10);
        num/=10;
    }
    reverse(s1.begin(), s1.end());
    // max
    int mm = 0, mi = 1e9;
    for (int i = 0; i < s1.size(); ++i) {
        t = s1;
        // pick a digit
        int dig = (t[i] - '0');
        for (int j = 0; j < t.size(); ++j) {
            if ((t[j] - '0') == dig)
                t[j] = max(dig, 9) + '0';
        }
        int tt = stoi(t);
        if (tt > mm)
            mm = tt;
    }
    // find a minimum
    for (int i = 0; i < s1.size(); ++i) {
        t = s1;
        // pick a digit
        int dig = (t[i] - '0');
        for (int j = 0; j < t.size(); ++j) {
            if ((t[j] - '0') == dig)
                if (dig == (s1[0] - '0'))
                    t[j] = min(dig, 1) + '0';
                else 
                    t[j] = min(dig, 0) + '0';
        }
        int tt = stoi(t);
        if (tt < mi)
            mi = tt;
    }
    return mm - mi;
        
    }
};