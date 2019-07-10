class Solution {
public:
    string arabicToRoman(int i) {
        switch(i) {
            case 1000: {
                return "M";
            }
            case 900: {
                return "CM";
            }
            case 500:{
                return "D";
            }
            case 400:{
                return "CD";
            }
            case 100:{
                return "C";
            }
            case 90:{
                return "XC";
            }
            case 50:{
                return "L";
            }
            case 40:{
                return "XL";
            }
            case 10:{
                return "X";
            }
            case 9:{
                return "IX";
            }
            case 5:{
                return "V";
            }
            case 4:{
                return "IV";
            }
            case 1:{
                return "I";
            }
        }
        return "";
    }
    string intToRoman(int num) {
        int values[] = {1000, 900,500,400,100,90,50,40,10,9,5,4,1};
        vector<int> d;
        int n = num, k = 0;
        while(num) {
            if (num - values[k] >= 0) {
                num -= values[k];
                d.push_back(values[k]);
            } else {
                ++k;
            }
        }
        string answer = "";
        for (int i = 0; i < d.size(); ++i) {
            answer += arabicToRoman(d[i]);
        }
        return answer;
        
    }
};