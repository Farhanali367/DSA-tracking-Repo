class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        for (int i = 0; i < arr1.size(); i++) {
            for (int j = 0; j < arr2.size(); j++) {
                int x = abs(arr1[i] - arr2[j]);
                if ((x <= d))
                    break;
                if (x > d && j == arr2.size() - 1)
                    count++;
            }
        }
        return count;
    }
};