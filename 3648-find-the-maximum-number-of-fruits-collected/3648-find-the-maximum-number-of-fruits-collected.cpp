class Solution {
public:
    int n;
    vector<vector<int>> t;

private:
    int child2collect(int i, int j, vector<vector<int>>& fruits) {
        if (i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (j == n - 1 && i == n - 1)
            return 0;
        if (i == j || i > j) {
            return 0;
        }
        if(t[i][j] != -1) return t[i][j];
        int bottomLeft = fruits[i][j] + child2collect(i + 1, j - 1, fruits);
        int bottom = fruits[i][j] + child2collect(i + 1, j, fruits);
        int bottomRight = fruits[i][j] + child2collect(i + 1, j + 1, fruits);

        return t[i][j] = max({bottomLeft, bottom, bottomRight});
    }
    int child3collect(int i, int j, vector<vector<int>>& fruits) {
        if (i >= n || j < 0 || j >= n) {
            return 0;
        }
        if (j == n - 1 && i == n - 1)
            return 0;
        if (i == j || j > i) {
            return 0;
        }
        if(t[i][j] != -1) return t[i][j];
        int upLeft = fruits[i][j] + child3collect(i - 1, j + 1, fruits);
        int up = fruits[i][j] + child3collect(i, j + 1, fruits);
        int upRight = fruits[i][j] + child3collect(i + 1, j + 1, fruits);

        return t[i][j] = max({upLeft, up, upRight});
    }

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        // for child 1 -> diagonals only
        //  child 2 -> till diagonal -1 only as diagonals taken, cant go beyond
        //  that
        // same for child 3

        n = fruits.size();
        t.resize(n, vector<int>(n,-1));
        int answer = 0;
        for (int i = 0; i < fruits.size(); i++) {
            answer += fruits[i][i];
            fruits[i][i] = 0;
        }

        int c2 = child2collect(0, n - 1, fruits);
        int c3 = child3collect(n - 1, 0, fruits);

        answer = answer + c2 + c3;

        return answer;
    }
};