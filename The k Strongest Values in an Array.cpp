/*
The k Strongest Values in an Array

Given an array of integers arr and an integer k.

A value arr[i] is said to be stronger than a value arr[j] if |arr[i] - m| > |arr[j] - m| where m is the median of the array.
If |arr[i] - m| == |arr[j] - m|, then arr[i] is said to be stronger than arr[j] if arr[i] > arr[j].

Return a list of the strongest k values in the array. return the answer in any arbitrary order.

Median is the middle value in an ordered integer list. More formally, if the length of the list is n, the median is the element in position ((n - 1) / 2) in the sorted list (0-indexed).

For arr = [6, -3, 7, 2, 11], n = 5 and the median is obtained by sorting the array arr = [-3, 2, 6, 7, 11] and the median is arr[m] where m = ((5 - 1) / 2) = 2. The median is 6.
For arr = [-7, 22, 17, 3], n = 4 and the median is obtained by sorting the array arr = [-7, 3, 17, 22] and the median is arr[m] where m = ((4 - 1) / 2) = 1. The median is 3.
 

Example 1:

Input: arr = [1,2,3,4,5], k = 2
Output: [5,1]
Explanation: Median is 3, the elements of the array sorted by the strongest are [5,1,4,2,3]. The strongest 2 elements are [5, 1]. [1, 5] is also accepted answer.
Please note that although |5 - 3| == |1 - 3| but 5 is stronger than 1 because 5 > 1.
*/

//sort by greater median(m). If you have same median, then sort by greater value.
bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first == b.first ? a.second > b.second : a.first > b.first;
}
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        //Sort the given array to find the median.
        sort(arr.begin(), arr.end());        
        vector<int> res;
        //value-median, value
        vector<pair<int, int>> medianValue;
        
        int m = arr[(arr.size() - 1)/2];
        //Calculate median for each element and make pair{median, value}
        for(int i : arr)
            medianValue.push_back({abs(i-m), i});
        //Sort the array as per greater median value
        sort(medianValue.begin(), medianValue.end(), compare);
        //Add k elements to result vector and return.
        for(int i = 0; i < k; i++)
            res.push_back(medianValue[i].second);
        
        return res;
    }
};
