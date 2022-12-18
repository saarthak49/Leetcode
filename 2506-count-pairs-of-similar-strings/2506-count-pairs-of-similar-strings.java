class Solution {
    
    public boolean same(String word1, String word2)
    {
        int[] hash1 = new int[26];
        int[] hash2 = new int[26];
        
        for(int i = 0; i<=25; i++)
        {
            hash1[i] = 0;
            hash2[i] = 0;
        }
        int n1 = word1.length();
        int n2 = word2.length();
        for(int i = 0; i<=n1 - 1; i++)
        {
            char c = word1.charAt(i);
            hash1[(int)(c - 'a')]++;
        }
        
        for(int i = 0; i<=n2 - 1; i++)
        {
            char c = word2.charAt(i);
            hash2[(int)(c - 'a')]++;
        }
        
        for(int i = 0; i<=25; i++)
        {
            if(hash1[i] > 0 && hash2[i] == 0 || hash1[i] == 0 && hash2[i] > 0)
            {
                return false;
            }
        }
        System.out.println(word1 + " " + word2);
        
        
        for(int i = 0; i<=25; i++)
        {
            System.out.println(hash1[i] + " " + hash2[i]);
        }
        return true;
    }
    
    
    public int similarPairs(String[] words) {
        int n = words.length;
        
        int count = 0;
        for(int k = 0; k<=n-1; k++)
        {
            for(int j = k + 1; j<=n-1; j++)
            {
                String word1 = words[k];
                String word2 = words[j];
                int[] hash1 = new int[26];
                int[] hash2 = new int[26];

                for(int i = 0; i<=25; i++)
                {
                    hash1[i] = 0;
                    hash2[i] = 0;
                }
                int n1 = word1.length();
                int n2 = word2.length();
                for(int i = 0; i<=n1 - 1; i++)
                {
                    char c = word1.charAt(i);
                    hash1[(int)(c - 'a')]++;
                }

                for(int i = 0; i<=n2 - 1; i++)
                {
                    char c = word2.charAt(i);
                    hash2[(int)(c - 'a')]++;
                }
                boolean flag = true;
                for(int i = 0; i<=25; i++)
                {
                    if(hash1[i] > 0 && hash2[i] == 0 || hash1[i] == 0 && hash2[i] > 0)
                    {
                        flag = false;
                    }
                }
                
                if(!flag)
                    continue;
                else 
                    count++;
            }
        }
        return count;
        
    }
}