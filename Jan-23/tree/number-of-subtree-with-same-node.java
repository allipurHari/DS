https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/

class Solution {
    int[] result;
    private int[] addTempToA(int[] temp, int[] a){
        for(int i = 0;i < temp.length;i++){
            a[i] += temp[i];
        }
        return a;
    }

    private int[] solve(List<List<Integer>> list, boolean[] visited, String labels, int idx){
        int[] a = new int[26];
        visited[idx] = true;
        for(int num : list.get(idx)){
            if(visited[num] == false){
                int[] temp = solve(list, visited, labels, num);
                a = addTempToA(temp, a);
            }
        }
        int charIdx = labels.charAt(idx)-'a';
        a[charIdx]++;
        result[idx] = a[charIdx];
        return a;
    }

    public int[] countSubTrees(int n, int[][] edges, String labels) {
        List<List<Integer>> list;
        list = new ArrayList<>(n);
        for(int i = 0; i < n; i++){
            list.add(new ArrayList<>());
        }   
        boolean[] visited = new boolean[n];
        result = new int[n];
        for(int[] edge: edges){
            list.get(edge[0]).add(edge[1]);
            list.get(edge[1]).add(edge[0]);
        }
        solve(list, visited, labels, 0);
        return result;
    }
}
