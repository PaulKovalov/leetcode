#include <cctype>
class Solution {
    int charToNumber(char c) {
        switch(c) {
            case '0': {
                return 0;
            }
            case '1': {
                return 1;
            }
            case '2': {
                return 2;
            }
            case '3': {
                return 3;
            }
            case '4': {
                return 4;
            }
            case '5': {
                return 5;
            }
            case '6': {
                return 6;
            }
            case '7': {
                return 7;
            }
            case '8': {
                return 8;
            }
            case '9': {
                return 9;
            }
            default:
                return 0;
        }
    }
public:
    int myAtoi(string str) {
        string str_trimed = "";
        bool is_first_char = true;
        for (int i = 0; i < str.length(); ++i) {
            if (is_first_char && !isdigit(str[i]) && str[i] != ' ' && str[i] != '-' && str[i] != '+') {
                return 0;
            } 
            if (str[i] == '.') {
                break;
            }
            if (!is_first_char && !isdigit(str[i])) {
                break;
            }
            if(isdigit(str[i]) || str[i] == '-' || str[i] == '+') {
                if (str[i] == '+' || str[i] == '-') {
                    if (i > 0) {
                        if (str[i] == '+') {
                            if (str[i - 1]  == '-') {
                                return 0;
                            }
                        }
                        if (str[i] == '-') {
                            if (str[i - 1]  == '+')
                                return 0;
                        }
                    }
                }
                if (is_first_char) {
                    is_first_char = false;
                }
                str_trimed += str[i];
            }
        }
        double res = 0;
        for (int i = 0; i < str_trimed.length(); ++i) {
            res += charToNumber(str_trimed[i])*pow(10, str_trimed.length() - i - 1);
        }
        if (str_trimed[0] == '-') {
            res *= -1;
        }
        if (res > INT_MAX) {
            return INT_MAX;
        }
        if (res < INT_MIN) {
            return INT_MIN;
        }
        return res;
    }
};