/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5
*/

public class Solution {
    
    
    
    private void BuildGraph(int[][] prerequisites, Dictionary<int, List<int>> map){
    
        for (int i = 0; i < prerequisites.Length; ++i){
            
            int start = prerequisites[i][0];
            int end = prerequisites[i][1];
            
            if (map.ContainsKey(start)){
                map[start].Add(end);   
            } else {
                List<int> neighbors = new List<int>(){end};
                map[start] = neighbors;
            }
        }
            
    }
    
    private void init(bool[] visited){
        for (int i = 0; i < visited.Length; ++i) visited[i] = false;
    }
    
    public bool CanFinish(int numCourses, int[][] prerequisites) {
        
        Dictionary<int, List<int>> map = new Dictionary<int, List<int>>(); 
        BuildGraph(prerequisites, map);
        bool[] visited = new bool[numCourses];
        for (int i = 0; i < visited.Length; ++i){
            
            if (!dfs(prerequisites, map, visited, i)){
                return false;
            }
            
        }   
        return true;
    }
    
    private bool dfs(int[][] prerequisites, Dictionary<int, List<int>> map, bool[] visited, int start){
        
        
        if (!map.ContainsKey(start)) return true;
        
        if (visited[start]) return false;
        
        visited[start] = true;
        
        List<int> neighbors = map[start];
        for (int i = 0; i < neighbors.Count; ++i){
            if (!dfs(prerequisites, map, visited, neighbors[i])) return false;
        }
       
        //Important line below
        visited[start] = false;
        return true;
        
    }
    
   
}