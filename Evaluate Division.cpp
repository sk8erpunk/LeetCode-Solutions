/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/
class Solution {
    
    typedef unordered_map<string, unordered_map<string,double>> Graph;
    
public:
    double dfs(string u, string v, Graph& graph, unordered_set<string>& visited){
        if(graph.count(u) == 0) // u doesnt exist 
            return -1.0;
        
        if(graph[u].count(v))   // v found in a path
            return graph[u][v];
        
        visited.insert(u);
        for(auto& child: graph[u]){                 // go through u children
            if(visited.count(child.first) == 0){     // child not visited
                double w = dfs(child.first, v, graph, visited);
                if(w != -1.0)
                    return w * child.second;
            }
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values,                         vector<pair<string, string>> queries) {
        Graph graph;
        for(int i = 0; i < equations.size(); i++){
            string u = equations[i].first;
            string v = equations[i].second;
            double w = values[i];
            if(graph.count(u) == 0)
                graph[u] = unordered_map<string,double>();
            graph[u][v] = w;
            if(graph.count(v) == 0)
                graph[v] = unordered_map<string,double>();
            graph[v][u] = 1.0/w;
        }
        
        vector<double> res;
        for(int j = 0; j < queries.size(); j++){
            string start = queries[j].first;
            string end = queries[j].second;
            unordered_set<string> visited;
            res.push_back(dfs(start, end, graph, visited));
        }
        
        return res;
    }
};