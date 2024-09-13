class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i=1; i<arr.size(); i++) {
            arr[i]  = arr[i] ^ arr[i-1];
            cout<<arr[i]<<" ";
        }
        vector<int> v;
        for(int i=0; i<queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];

            if(a == 0) {
                v.push_back(arr[b]);
            }
            else {
                v.push_back(arr[a-1] ^ arr[b]);
            }
        }

        return v;
    }
};