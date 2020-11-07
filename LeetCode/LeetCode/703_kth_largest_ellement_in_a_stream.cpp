#include "questions.h"

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums): k_(k) {
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (mh_.size() < k_) {
            mh_.push(val);
        }
        else if (mh_.top() < val) {
            mh_.push(val);
            mh_.pop();
        }

        return mh_.top();
    }
private:
    const int k_;
    priority_queue<int, vector<int>, greater<int>> mh_; // min heap
};

int UseKthLargest() {

    cout << "*************** 703. Kth Largest Element in a Stream ***************" << endl;
    const int k = 3;
    vector<int> input = { 4, 5, 8, 2 };
    KthLargest kl(3, input);
    cout << kl.add(3) << endl;   // returns 4
    cout << kl.add(5) << endl;   // returns 5
    cout << kl.add(10) << endl;  // returns 5
    cout << kl.add(9) << endl;   // returns 8
    cout << kl.add(4) << endl;  // returns 8

    return 0;
}