class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> r(n);
        for (int i = 0; i < n; ++i) {
            r[i] = nums[i] % k;
        }
        
        vector<vector<int>> l(k);
        for (int i = 0; i < n; ++i) {
            l[r[i]].push_back(i);
        }
        
        int m = 0;
        for (const auto& lst : l) {
            m = max(m, (int)lst.size());
        }
        
        if (k == 0 || k == 1) {
            return m;
        }
        
        for (int x = 0; x < k; ++x) {
            for (int y = x + 1; y < k; ++y) {
                const auto& a = l[x];
                const auto& b = l[y];
                int la = a.size();
                int lb = b.size();
                if (la == 0 && lb == 0) {
                    continue;
                }
                int i = 0, j = 0;
                int sx = 0, sy = 0;
                while (i < la || j < lb) {
                    if (j == lb || (i < la && a[i] < b[j])) {
                        int nx = sy > 0 ? sy + 1 : 1;
                        if (nx > sx) {
                            sx = nx;
                        }
                        ++i;
                    } else {
                        int ny = sx > 0 ? sx + 1 : 1;
                        if (ny > sy) {
                            sy = ny;
                        }
                        ++j;
                    }
                }
                int c = max(sx, sy);
                if (c > m) {
                    m = c;
                }
            }
        }
        return m;
    }
};