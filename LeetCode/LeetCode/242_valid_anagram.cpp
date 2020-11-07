#include "questions.h"

// Time:  O(n)
// Space: O(1)
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> char_num;

        for (char c : s) {
            ++ char_num[tolower(c)];
        }
        for (char c : t) {
            -- char_num[tolower(c)];
            if (char_num[tolower(c)] < 0) {
                return false;
            }
        }

        return true;
    }
};

// Time:  O(nlogn)
// Space: O(n)
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};


// 242. Valid Anagram
int UseIsAnagram() {

    cout << "*************** 242. Valid Anagram ***************" << endl;

    string s = "anagram", t = "nagaram";
    Solution1 S;
    cout << "Whether two string are anagram is: " << S.isAnagram(s, t) << endl;
    return 0;
}