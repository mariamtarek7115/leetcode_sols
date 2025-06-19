class Solution {
public:
    bool canPartition(vector<int>& arr) {
            int size = arr.size();
    int sum = 0;
    if (size == 0) {
        return true;
    }
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    if (sum % 2 != 0) {
        return false;
    }

    int targetSum = sum / 2;

    // Create a simple array to track reachable sums
    vector<bool> dp(targetSum + 1, false);
    dp[0] = true; // Sum 0 is always possible (empty subset)

    for (int i = 0; i < size; i++) {
        for (int j = targetSum; j >= arr[i]; j--) {
            if (dp[j - arr[i]]) {
                dp[j] = true;
            }
        }
    }

    return dp[targetSum];
}
};