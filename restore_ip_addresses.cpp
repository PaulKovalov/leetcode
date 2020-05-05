class Solution {
public:
    void backtrack_solution(string s, string result, int expected_length, set<string>& answer, int step_count = 0) {
        if (step_count == 4) {
            if (result.size() - 4 == expected_length) {
                answer.insert(result.substr(0, result.size() - 1));
            }
            return;
        }
        for (int i = 1; i < 4; ++i) {
            string curr_part = s.substr(0, i);
            if (curr_part != "") {
                int curr_part_int = stoi(curr_part);
                if (curr_part_int < 256 && s.size() >= i) {
                    string new_result = result + to_string(curr_part_int) + ".";
                    backtrack_solution(s.substr(i), new_result, expected_length, answer, step_count + 1);   
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4) {
            return vector<string>();
        }
        set<string> result;
        backtrack_solution(s, "", s.length(), result);
        vector<string> answer;
        for (auto s: result) {
            answer.push_back(s);
        }
        return answer;
    }
};