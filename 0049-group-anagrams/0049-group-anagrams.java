class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> hmp = new HashMap<>();
        for(String s: strs){
            char[] arr = s.toCharArray();
            Arrays.sort(arr);
            String str = new String(arr);
            hmp.putIfAbsent(str, new ArrayList<>());
            hmp.get(str).add(s);
        }
        List<List<String>> lst = new ArrayList<>();
        for(Map.Entry<String, List<String>> e: hmp.entrySet()){
            lst.add(e.getValue());
        }
        return lst;
    }
}