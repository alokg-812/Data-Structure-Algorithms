

class Solution {
public:
    int largestRectangleArea(vector<int>& arr){
        int n = arr.size();
        vector<int> nsi(n);
        stack<int> st;
        nsi[n - 1] = n;
        st.push(n - 1);
        for (int i = n - 2; i >= 0;i--){
            while (st.size() > 0 && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.size() == 0) nsi[i] = n;
            else nsi[i] = st.top();
            st.push(i);
        }
        vector<int> psi(n);
        stack<int> stp;
        psi[0] = -1;
        stp.push(0);
        for(int i =1;i<n;i++){
            while(stp.size()>0 && arr[stp.top()]>=arr[i]){
                stp.pop();
                }
            if(stp.size()==0) psi[i]=-1;
            else psi[i] = stp.top();
            stp.push(i);
        }
        
        int maxArea= 0;
        for(int i=0;i<n;i++){
            int height = arr[i];
            int breadth = nsi[i] - psi[i] - 1;
            int area=height * breadth;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        if(n==0) return 0;
        int m = mat[0].size();
        vector<vector<int>> intMat(n, vector<int>(m, 0));
        for(int j=0;j<m;j++){
            for(int i =0;i<n;i++){
                if(mat[i][j] =mat[i][j] -'0';
            }
        }
        for(int j =0;j <m;j++){
            for(int i = 0;i<n;i++){
                if(intMat[i][j] ==0) intMat[i][j] = 0;
                else if(i >0) intMat[i][j] += intMat[i - 1][j];
            }
        }
        int area = 0;
        for (int i = 0; i < n; i++) {
            area = max(area, largestRectangleArea(intMat[i]));
        }
        return area;
    }
};
