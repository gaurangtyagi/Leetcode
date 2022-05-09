class Solution {
public:
    vector <string> vec = {"" , "abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" }, ans;
    
    void find(string& digits,int ind, string temp)
    {
        if(ind == digits.length())
        {
            if(temp != "")
                ans.push_back(temp); return;
        }
        for(int i=0; i<vec[digits[ind]-'1'].length(); i++)
        {
            find(digits,ind+1, temp + vec[digits[ind]-'1'][i]);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits == "")
        {
            return ans;
        }
        find(digits, 0, "");
        return ans;
    }
};