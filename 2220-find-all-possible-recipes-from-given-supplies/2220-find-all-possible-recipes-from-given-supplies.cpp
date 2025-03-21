class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> rec;
        unordered_map<string, int> sup; 
        unordered_map<string, bool> memo;
        unordered_set<string> visited;
        vector<string> res;
        
        for (auto& s : supplies) sup[s] = 1;
        for (int i = 0; i < recipes.size(); i++) rec[recipes[i]] = ingredients[i];
        for (auto& r : recipes) 
            if (dfs(r, rec, sup, visited, memo)) res.push_back(r);
        return res;
    }

    bool dfs(string s, auto& rec, auto& sup, auto& visited, auto& memo) {
        if (!rec.count(s)) return true;
        if (memo.count(s)) return memo[s];
        if (!visited.insert(s).second) return false;  
        
        for (auto& p : rec[s]) 
            if ((!rec.count(p) && !sup.count(p)) || (rec.count(p) && !dfs(p, rec, sup, visited, memo))) 
                return visited.erase(s), memo[s] = false;
        return visited.erase(s), memo[s] = true;
    }
};