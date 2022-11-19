class Solution {
public:
    
    
    
    
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        if(a.second != b.second)
            return a.second<b.second;
        return a.first<b.first;
    }

    
    
    

    

    void buildGraph(vector<vector<int> > &times, int n, vector<vector<pair<int, int> > > &graph)
    {
        vector<pair<int, int> > temp;
        for(int i = 0; i<= n-1; i++)
            graph.push_back(temp);

        int si = times.size();
        for(int i = 0; i<=si - 1; i++)
            graph[times[i][0] - 1].push_back({times[i][1] - 1, times[i][2]});
    }

    int networkDelayTime(vector<vector<int> > &times, int n, int k) {
        vector<vector<pair<int, int> > > graph;
        buildGraph(times, n, graph);
        unordered_map<int, int> dist;
        set<pair<int, int>, decltype(&cmp) > sptSet(cmp);
        for(int i = 0; i<=n-1; i++)
        {
            if(i != k-1)
            {
                sptSet.insert({i, INT_MAX});
                dist[i] = INT_MAX;
            }
            else
            {
                sptSet.insert({i, 0});
                dist[i] = 0;
            }
            
        }
        // int step = 0;
        // for(auto it: graph)
        // {
        //     cout<<step<<": ";
        //     for(auto nei: it)
        //     {
        //         cout<<nei.first<<", ";
        //     }
        //     cout<<endl;
        //     step++;
        // }
        

        while(!sptSet.empty())
        {
            int vertex = (*(sptSet.begin())).first;
            sptSet.erase({vertex, dist[vertex]});
            int numOfNeighbours = graph[vertex].size();
            for(int i = 0; i<=numOfNeighbours - 1; i++)
            {
                // cout<<vertex<<" "<<graph[vertex][i].first<<endl;
                if(sptSet.find({graph[vertex][i].first, dist[graph[vertex][i].first]}) != sptSet.end() && dist[vertex] != INT_MAX &&  dist[vertex] + graph[vertex][i].second < dist[graph[vertex][i].first])
                {
                    //remove from the set
                    sptSet.erase(sptSet.find({graph[vertex][i].first, dist[graph[vertex][i].first]}));
                    //update in the dist
                     dist[graph[vertex][i].first] = dist[vertex] + graph[vertex][i].second;
                    // add again to the set
                    sptSet.insert({graph[vertex][i].first, dist[graph[vertex][i].first]});
                }
            }
            
            
            sptSet.erase({vertex, dist[vertex]});
            
        }

        int answer = -1;
        for(auto it: dist)
        {
            answer = max(answer, it.second);
            // cout<<it.first<<" "<<it.second<<endl;
        }
        if(answer == INT_MAX)
            return -1;
        return answer;
    }
    
    
    
};