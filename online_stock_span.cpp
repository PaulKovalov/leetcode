#include <iostream>
#include <stack>

using namespace std;

class StockSpanner {
public:
    stack<pair<int, int> > s;
    StockSpanner() {
        
    }

    int next(int price) {
        int ans = 1;
        while (!s.empty() && s.top().first <= price) {
            ans += s.top().second;
            s.pop();
        }
        s.push({price, ans});
        return ans;
    }
};

int main() {
    int n, x;
    StockSpanner spanner;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        cout << spanner.next(x) << endl;
    }
    return 0;
}