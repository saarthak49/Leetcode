class Solution {
public:
    
    
    // dsu solutioon with path compression and ranksBased union
    int getParent(vector<int> &dsu, int i)
    {
        if(dsu[i] == -1)
            return -1;
        
        
        if(dsu[i] == i)
            return i;
        
        dsu[i] = getParent(dsu, dsu[i]);
        
        return dsu[i];
    }
    
    int getRank(vector<int> &dsu, vector<int> &ranks, int i)
    {
        int parent = getParent(dsu, i);
        if(parent == -1)
            return 0;
        return ranks[parent];
    }
    
    void makeUnion(vector<int> &dsu, vector<int> &ranks, int var1, int var2)
    {
        int par1 = getParent(dsu, var1);
        int par2 = getParent(dsu, var2);
        if(par1 == -1)
        {
            dsu[var1] = var1;
            par1 = var1;
            ranks[par1] = 0;
        }
        if(par2 == -1) {
            dsu[var2] = var2;
            par2 = var2;
            ranks[par2] = 0;
        }
        
        
        
        if(par1 != par2)
        {
            int rank1 = ranks[par1];
            int rank2 = ranks[par2];
            if(rank1 < rank2)
            {
                dsu[par1] = par2;
            }
            else if(rank1 > rank2)
                dsu[par2] = par1;
            else
            {
                dsu[par1] = par2;
                ranks[par2] = rank2 + 1;
            }
        }
    }
    
    bool inequality(vector<int> &dsu, int var1, int var2)
    {
        if(var1 == var2)
            return false;
        int par1 = getParent(dsu, var1);
        if(par1 == -1)
        {
            dsu[var1] = var1;
            par1 = var1;
        }
        int par2 = getParent(dsu, var2);
        if(par2 == -1)
        {
            dsu[var2] = var2;
            par2 = var2;
        }
        
        
    
        if(par1 == par2)
            return false;
        
        return true;
    }
    
    
    
    bool equationsPossible(vector<string>& equations) {
        vector<int> dsu;
        vector<int> ranks;
        
        int n = equations.size();
        
        for(int i = 0; i<=25; i++)
        {
            ranks.push_back(0);
            dsu.push_back(-1);
        }
        
        
        for(int i = 0; i<=n-1; i++)
        {
            int var1 = equations[i][0] - 'a';
            int var2 = equations[i][3] - 'a';
            if(equations[i][1] == equations[i][2])
                makeUnion(dsu, ranks, var1, var2);
        }
        
        for(int i = 0; i<=n-1; i++)
        {
            int var1 = equations[i][0] - 'a';
            int var2 = equations[i][3] - 'a';
            if(equations[i][1] != equations[i][2])
            {
                
                if(!inequality(dsu, var1, var2))
                    return false;
            }
        }
        return true;
    }
};