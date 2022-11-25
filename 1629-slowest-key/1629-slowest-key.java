class Solution {
    public char slowestKey(int[] releaseTimes, String keysPressed) {
        int last = 0;
        int largestDuration = 0;
        char maxDurationKey = 'z';
        int n = keysPressed.length();
        for(int i = 0; i<=n-1; i++)
        {
            int duration = releaseTimes[i] - last;
            last = releaseTimes[i];
            
            if(duration > largestDuration)
            {
                largestDuration = duration;
                maxDurationKey = keysPressed.charAt(i);
            }
            else if(duration == largestDuration)
            {
                if(keysPressed.charAt(i) > maxDurationKey)
                    maxDurationKey = keysPressed.charAt(i);
            }
        }
        return maxDurationKey;
        
    }
}