class Solution {
public:
    int compute(vector<int> &arr, int value)
    {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i<=n-1; i++)
        {
            if(arr[i]<value)
                sum += arr[i];
            else
                sum += value;
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int low = 0;
        int high = *max_element(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        
        int finalAnswer = -1;
        
        while(low<=high)
        {
            int mid = low + (high - low) / 2;
            int arrSum = compute(arr, mid);
            if(arrSum < target)
            {
                if(target - arrSum < minDiff)
                {
                    minDiff = target - arrSum;
                    finalAnswer = mid;
                }
                else if( target - arrSum == minDiff && mid < finalAnswer)
                    finalAnswer = mid;
                    
                // finalAnswer = mid;
                low = mid + 1;
            }
            else if(arrSum >= target)
            {
                if(arrSum - target < minDiff)
                {
                    minDiff = arrSum - target;
                    finalAnswer = mid;
                }
                // finalAnswer = mid;
                high = mid - 1;
            }
        }
        return finalAnswer;
        
    }
};