//monotonic stack, 84. Largest Rectangle in Histogram
//https://www.cnblogs.com/grandyang/p/4322667.html
//Runtime: 92 ms, faster than 20.43% of C++ online submissions for Maximal Rectangle.
//Memory Usage: 12 MB, less than 35.98% of C++ online submissions for Maximal Rectangle.

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;
        
        //push back 0 to "h"!
        vector<int> heights(n+1);
        int ans = 0;
        
        for(int i = 0; i < m; i++){
            /*
            we view each row as a problem of 84.Largest Rectangle in Histogram
            */
            stack<int> stk;
            /*
            here the heights.size() is the size of h
            after pushing a 0 into it,
            so it's n+1,
            that's because we want the last element of
            original h to be processed
            */
            for(int j = 0; j < heights.size(); j++){
                //update heights for current row
                if(j < n){
                    heights[j] = (matrix[i][j] == '1') ? heights[j]+1 : 0;
                }
                //same as 84. Largest Rectangle in Histogram
                while(!stk.empty() && heights[j] < heights[stk.top()]){
                    int cur = stk.top(); stk.pop();
                    ans = max(ans, heights[cur] * (stk.empty() ? j : (j-1-stk.top())));
                }
                stk.push(j);
            }
        }
        
        return ans;
    }


