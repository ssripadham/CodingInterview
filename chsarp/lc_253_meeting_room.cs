/*
253. Meeting Rooms II
Medium

3197

52

Add to List

Share
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

public class Solution {
    
    private class CmpIntvl : IComparer<int[]>{
        public int Compare(int[] a, int[] b){
            if (a[1] == b[1]){
                return a[0].CompareTo(b[0]);
            }
            return a[1].CompareTo(b[1]);
        }    
    }
    
    public int MinMeetingRooms(int[][] intervals) {
        
        if (intervals == null || intervals.Length == 0){
            return 0;
        }
        
        SortedDictionary< int[], int> d = new SortedDictionary< int[], int>(new CmpIntvl());
        
        Array.Sort(intervals, new CmpIntvl());
        
        int ans = 1;
        d.Add(intervals[0],0);
        for (int i = 1; i < intervals.Length; ++i){
        
            //Console.WriteLine($"{intervals[i][0]},{intervals[i][1]}");
            while (d.Count > 0 && d.Keys.First()[1] < intervals[i][0]){
                //Console.WriteLine($"Remove {d.Keys.First()[0]},{d.Keys.First()[1]}");
                d.Remove(d.Keys.First());
            }
            
            d.Add(intervals[i],0);
            ans = Math.Max(ans, d.Count);
            
        }
        
        return ans;
        
    }
}