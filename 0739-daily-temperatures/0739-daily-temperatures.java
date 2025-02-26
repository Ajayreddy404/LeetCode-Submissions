class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        // elements sorted in non-increasing order
        Stack<Integer> stk = new Stack<>();  // to store the indices of elements
        int n = temperatures.length;
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            while(stk.size()>0 && temperatures[stk.peek()]<temperatures[i]){
                arr[stk.peek()] = i-stk.peek();
                stk.pop();
            }
            stk.push(i);
        }
        while(stk.size()>0){
            arr[stk.peek()] = 0;
            stk.pop();
        }
        return arr;
    }
}