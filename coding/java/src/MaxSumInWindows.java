import java.util.ArrayList;


public class MaxSumInWindows {
    private static ArrayList<Integer> maxSumInWindows(int[] num, int size) {
        ArrayList<Integer> res = new ArrayList<Integer>();
        int length = num.length;
        if (length < size) {
            return res;
        }
        int start = 0;
        int max;
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += num[i];
        }
        max = sum;
        for (int i=0;i<length-size;i++) {
            sum += num[i + size];
            sum -= num[i];
            if (num[i + size] > num[i]) {
                if (sum > max) {
                    max = sum;
                    start = i+1;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            res.add(num[start + i]);
        }
        return  res;
    }

    public static void main(String args[]){
        int nums[] = {1,2,4,5,3,2,1};
        ArrayList<Integer> res = maxSumInWindows(nums,4);
        for (int elem : res) {
            System.out.println(elem);
        }
    }
}
