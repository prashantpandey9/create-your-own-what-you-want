//LeetCode Medium ,, 287. Find the Duplicate Number

public class duplicateNumber {
    public static void main(String[] args) {

    }
    static int duplicate(int[] nums){
        int i=0;
        while(i<nums.length){
            if(nums[i]!=i+1){
                int current = nums[i]-1;
                if(nums[i]!=nums[current]){
                    swap(nums,i,current);
                }else {
                    return nums[i];
                }
            }
            else{
                i++;
            }
        }
        return -1;
    }
    static void swap(int[]nums,int first,int second){
        int temp = nums[first];
        nums[first] = nums[second];
        nums[second] = temp;
    }

}
