class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string, int> mp;
        
        for(auto it: dictionary)
            mp[it]++;
        
        int n = sentence.size();
        string word = "";
        string root = "";
        string finalString = "";
        for(int i = 0; i<=n; i++)
        {
            if(sentence[i] == ' ' || i == n)
            {
                if(root != "")
                    finalString += root + " ";
                else
                    finalString += word + " ";
                word = "";
                root = "";
                continue;
            }
            word += sentence[i];
            
            if(mp[word] != 0 && root == "")
            {
                // cout<<"The word so far is : "<<word<<endl;
                // cout<<"The identified root is: "<<word<<endl;
                root = word;
            }
        }
        n = finalString.size();
        return finalString.substr(0, n-1);
        
    }
};