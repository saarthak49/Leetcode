class Solution {

    public int numberOfGoodPaths(int[] vals, int[][] edges) {

        var G = new Graph(edges);

        var nodeRanks = new TreeMap<Integer, List<Integer>>();

        for (var i = 0; i < vals.length; ++i) {
            nodeRanks.computeIfAbsent(vals[i], k -> new ArrayList<>()).add(i);
        }

        var uf = new UnionFind(G.V());
        var goodPaths = 0;

        for (var rank : nodeRanks.keySet()) {
            for (var v : nodeRanks.get(rank)) {
                for (var w : G.adj(v)) {
                    if (vals[v] >= vals[w]) {
                        uf.union(v, w);
                    }
                }
            }

            var groups = new HashMap<Integer, Integer>();
            for (var v : nodeRanks.get(rank)) {
                var w = uf.find(v);
                groups.put(w, groups.getOrDefault(w, 0) + 1);
            }

            for (var group : groups.keySet()) {
                var size = groups.get(group);
                goodPaths += size * (size + 1) / 2;
            }
        }

        return goodPaths;
    }
}

class UnionFind {

    private final int[] id;
    private final int[] rank;

    UnionFind(int N) {
        this.id = new int[N];
        this.rank = new int[N];

        for (int i = 0; i < N; ++i)
            id[i] = i;
    }

    public int find(int p) {
        while (p != id[p])
            p = id[p];
        return p;
    }

    public void union(int p, int q) {
        var pID = find(p);
        var qID = find(q);

        if (pID == qID)
            return;

        if (rank[pID] > rank[qID])
            id[qID] = pID;
        else if (rank[pID] < rank[qID])
            id[pID] = qID;
        else {
            id[qID] = pID;
            rank[pID]++;
        }
    }
}

class Graph {

    private final int V;
    private final List<Integer>[] adj;

    Graph(int[][] edges) {
        this.V = edges.length + 1;
        this.adj = new List[this.V];

        for (var i = 0; i < V; ++i) {
            adj[i] = new ArrayList<>();
        }

        for (var edge : edges) {
            adj[edge[0]].add(edge[1]);
            adj[edge[1]].add(edge[0]);
        }
    }

    int V() {
        return V;
    }

    Iterable<Integer> adj(int v) {
        return adj[v];
    }
}