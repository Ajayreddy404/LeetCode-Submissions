class Solution {
    public String reorganizeString(String s) {
        Map<Character, Integer> mp = new HashMap<>();
        int n = s.length(), maxCnt = 0;
        for(int i=0; i<n; i++){
            char c = s.charAt(i);
            if(mp.containsKey(c)){
                mp.put(c, mp.get(c)+1);
            }else{
                mp.put(c, 1);
            }
            maxCnt = Math.max(maxCnt, mp.get(c));
        }
        if(maxCnt > (n+1)/2)    return "";

        StringBuilder str = new StringBuilder();
        // Pair<Integer, Character> p = new Pair(1,"a");
        PriorityQueue<Pair<Integer, Character>> pq = new PriorityQueue<>((a,b)->{
            if(b.getKey()==a.getKey()){
                return a.getValue()-b.getValue();
            }else{
                return b.getKey()-a.getKey();
            }
        });
        for(Map.Entry<Character, Integer> e: mp.entrySet()){
            pq.add(new Pair(e.getValue(), e.getKey()));
        }

        while(!pq.isEmpty()){
            Pair<Integer, Character> p1 = pq.peek();
            pq.poll();
            str.append(p1.getValue());
            

            if(!pq.isEmpty()){
                Pair<Integer, Character> p2 = pq.peek();
                pq.poll();
                str.append(p2.getValue());
                
                if(p2.getKey()>1) pq.add(new Pair(p2.getKey()-1, p2.getValue()));
            }
            if(p1.getKey()>1) pq.add(new Pair(p1.getKey()-1, p1.getValue()));
        }
        
        return str.toString();
    }
}