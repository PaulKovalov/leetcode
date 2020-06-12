#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class RandomizedSet {
public:
    vector<vector<int>> data;
    unordered_map<int, int> m; // mapping
    const int BUCKET_SIZE = 5;

    RandomizedSet() {
        data.push_back({});
    }

    bool insert(int val) {
        if (m.find(val) != m.end())
            return false;
        if (data.back().size() > BUCKET_SIZE)
            data.push_back({});
        data.back().push_back(val);
        m[val] = data.size() - 1;
        return true;
    }
    
    
    bool remove(int val) {
        if (m.find(val) == m.end())
            return false;
        int bucket_idx = m[val];
        m.erase(val);
        if (data[bucket_idx].size() == 1) {
            for (int i = bucket_idx; i < data.size() - 1; ++i) {
                data[i].swap(data[i + 1]);
                for (int j = 0; j < data[i].size(); ++j) {
                    m[data[i][j]]--;
                }
            }
            if (data.size() > 1)
                data.pop_back(); // remove last empty bucket
            else 
                data.back().clear();
        } else {
            auto position = std::find(data[bucket_idx].begin(), data[bucket_idx].end(), val);
            data[bucket_idx].erase(position);
        }
        return true;
    }
    
    
    int getRandom() {
        int bucket = rand() % data.size();
        int element = rand() % data[bucket].size();
        return data[bucket][element];
    }

    // each time element is inserted, push it to the last bucket. Also create a mapping <element, bucket>
    // when element is removed, there are 2 options:
    // - first is that the element is the last in the bucket. In this case all elements to the right are to be rehashed
    // - - the approach is: copy all data from the buckets i the to buckets i - 1, update mappings
    // - second is there are some element(s) left in the bucket, its perfectly fine, do nothing just remove
    // when getRandom is queried, pick random bucket and random element from that bucket. At this step its guaranteed that there will be at least one element in that bucket
    // all operations running time complexity is O(bucket size), which can be relatively small number. In fact the bucket size can be varied
    // and tested for optimal performance
};


int main() {
    RandomizedSet rset;
    rset.insert(0);
    rset.remove(0);
    rset.insert(1);
    rset.remove(0);
    for (int i = 0; i < 20; ++i) {
        cout << rset.getRandom() << endl;
    }
    return 0;
}