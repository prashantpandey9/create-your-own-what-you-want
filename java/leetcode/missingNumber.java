import java.util.Arrays;
public class missingNumber {
    public static void main(String[] args) {
        int[] nums = {4,0,2,1};
        System.out.println(missingNum(nums));
    }
    public static int missingNum(int[] nums){
        int i = 0;
        while(i<nums.length){
            int correct = nums[i];
            if(nums[i]<nums.length && nums[i]!=nums[correct]){
                swapp(nums,i,correct);
            }
            else{
                i++;
            }
        }
        for(int index = 0;index<nums.length;index++){
            if(nums[index] != index){
                return index;
            }
        }
        return nums.length;
    }
    static void swapp(int[] nums, int first, int second){
        int temp = nums[first];
        nums[first] = nums[second];
        nums[second] = temp;
    }
}
