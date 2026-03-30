#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // nearest smaller on left
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if(st.empty()) left[i] = -1;
            else left[i] = st.top();

            st.push(i);
        }

        // clear stack
        while(!st.empty()) st.pop();

        // nearest smaller on right
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if(st.empty()) right[i] = n;
            else right[i] = st.top();

            st.push(i);
        }

        // find max area
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};