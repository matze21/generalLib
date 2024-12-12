class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n,false);
        // vector of cities and their connections
        // true/false indicates whether the connection is original or not
        vector<vector<pair<int,bool>>> graph(n);

        for(auto& conn : connections){
            // add the present connection from city to new city
            graph[conn[0]].push_back({conn[1],true});
            // add the reversed connection from city to new city
            graph[conn[1]].push_back({conn[0],false});
        }

        int reversed = 0;
        dfs(visited, graph, 0, reversed);
        return reversed;
    }

    void dfs(vector<bool>& visited, vector<vector<pair<int,bool>>>& graph, int city, int& reversed){
        visited[city] = true;
        for(auto& [neighbor, original] : graph[city]){
            if(!visited[neighbor]){
                // for the original direction, from source city to neighbor, 
                // we need to reverse the direction since there we can't reach the source
                if(original){reversed++;}
                dfs(visited,graph,neighbor,reversed);
            }
        }
    }
};