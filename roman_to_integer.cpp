class Solution {
public:
    int romanToArabic(char c) {
        switch(c){
            case 'M': {
                return 1000;
            }
            case 'D': {
                return 500; 
            }
            case 'C':{
                return 100;
            }
            case 'L':{
                return 50;
            }
            case 'X':{
                return 10;
            }
            case 'V':{
                return 5;
            }
            case 'I':{
                return 1;
            }
        }
        return 0;
    }
    int romanToInt(string s) {
        vector<int> ints;
        for (int i = 0; i < s.length(); ++i) {
            ints.push_back(romanToArabic(s[i]));
        }
        int sum = 0;
        for (int i = 0; i < ints.size() - 1; ++i) {
            if (ints[i] < ints[i + 1]) {
                ints[i] = -ints[i];
            }
            sum += ints[i];
        }
        sum += ints[ints.size() - 1];
        return sum;
        
    }
};