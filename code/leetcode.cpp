#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.size(), plen = p.size();
        if (slen < plen) {
            return vector<int>();
        }
        
        vector<int> ans;
        vector<int> cnt(26);
        for (int i = 0; i < plen; i++) {
            cnt[s[i] - 'a']++;
            cnt[p[i] - 'a']--;
        }
        for (auto i : cnt) cout << i << "|";
        cout << "\n";

        int differ = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) {
                differ++;
            }
        }

        // the first compare;
        if (differ == 0) {
            ans.emplace_back(0);
        }
        cout << differ << "\n";

        for (int i = 0; i < slen - plen; i++) {
            if (cnt[s[i] - 'a'] == 1) {
                differ--;
            } else if (cnt[s[i] - 'a'] == 0) {
                differ++;
            }
            cnt[s[i] - 'a']--;

            // -1 : pre have now not
            if (cnt[s[i + plen] - 'a'] == -1) {
                differ--;
            } else if (cnt[s[i + plen] - 'a'] == 0) {
                differ++;
            }
            cnt[s[i + plen] - 'a']++;

            if (differ == 0) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};
int main() {
    Solution S;
    string s = "cbaebabacd", p = "abc";
    vector<int> ans = S.findAnagrams(s, p);
    for (auto p : ans) cout << p << " ";
    cout << "\n";
    return 0;
}