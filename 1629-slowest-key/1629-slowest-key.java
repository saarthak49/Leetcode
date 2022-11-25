class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int last = 0;
        int largestDuration = 0;
        char maxDurationKey = 'z';
        int n = keysPressed.size();
        for(int i = 0; i<=n-1; i++)
        {
            int duration = releaseTimes[i] - last;
            last = releaseTimes[i];
            
            if(duration > largestDuration)
            {
                largestDuration = duration;
                maxDurationKey = keysPressed[i];
            }
            else if(duration == largestDuration)
            {
                if(keysPressed[i] > maxDurationKey)
                    maxDurationKey = keysPressed[i];
            }
        }
        return maxDurationKey;
    }
};