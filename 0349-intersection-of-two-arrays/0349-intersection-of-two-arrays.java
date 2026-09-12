class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer>st = new HashSet<>();
        for(int i : nums1){
            st.add(i);
        }
        ArrayList<Integer>ans = new ArrayList<>();


        for(int i : nums2){
            if(st.contains(i)){
                ans.add(i);
                st.remove(i);
            }
        }
        int[] array = ans.stream()
                .mapToInt(Integer::intValue)
                .toArray();
                return array;
    }
    
}