class Solution {
    public int minFlipsMonoIncr(String s) {
        
        
        int n=s.length();
        
        int zero=0,one=0;
        for(int i=n-1;i>=0;i--)
        {
            char ch=s.charAt(i);
            if(ch=='0')
            zero++;
            else one++;
        }
        int ans=Integer.MAX_VALUE,flips=0,prev_flips=0;
        for(int i=0;i<n-1;i++)
        {
             char ch=s.charAt(i);

             if(ch=='0')
             { 
                 //not flip--> nothing to do,just move ahead

                 //flip
                 flips++;// '0' ---> '1'
                 int zero_count_after=zero;
                 flips+=zero_count_after+prev_flips;
                 
                 ans=Math.min(flips,ans);
                 flips=0;

                 zero--;//current index 0 is eliminated from our count
             }

             else //'1'
             {
                 //not flip
                { int zero_count_after=zero;
                 flips+=zero_count_after+prev_flips;
                 ans=Math.min(ans,flips);
                 flips=0;
                }

                //flip
                {
                    prev_flips++;
                }

                one--;//current index 1 is eliminated from our count

             }
             if(zero==0||one==0)
            // either the count of 'zeros' is 0 or 'ones' is 0 ahead
             ans=Math.min(ans,prev_flips);

             if(zero==0||one==0)
             break; //out of the loop

        }
        return ans;

    }
}