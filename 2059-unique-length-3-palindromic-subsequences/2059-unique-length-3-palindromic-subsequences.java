class Solution {
    public int countPalindromicSubsequence(String s) {
        int n = s.length();
        int[][] arr = new int[n][26];
        arr[0][s.charAt(0)-'a'] = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<26; j++){
                arr[i][j] = arr[i-1][j];
            }
            arr[i][s.charAt(i)-'a']++;
        }
        Set<String> st = new HashSet<>();
        for(int i=1; i<n-1; i++){
            for(int j=0; j<26; j++){
                if(arr[i-1][j]>0 && (arr[n-1][j]-arr[i][j])>0){
                    String s3 = String.valueOf(j) + s.charAt(i) + String.valueOf(j);
                    st.add(s3);
                }
            }
        }
        System.out.println(st);
        return st.size();
    }
}