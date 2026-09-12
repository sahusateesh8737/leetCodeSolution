class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int left = 0;
        int right = 0;
        int n = nums1.length;
        int m = nums2.length;
        ArrayList<Integer>ans = new ArrayList();
        while(left < n && right < m){
            if(nums1[left] == nums2[right]){
                if(ans.isEmpty() || ans.get(ans.size() - 1) != nums1[left]){
                   ans.add(nums1[left]);
                }
                
                left++;
                right++;
            }
            else if(nums1[left] < nums2[right]){
                left++;
            }
            else {
                right++;
            }
        }
        int[] array = ans.stream().mapToInt(Integer::intValue).toArray();
        return array;
    }
}