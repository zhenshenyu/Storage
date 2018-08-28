import java.util.ArrayList;

public class MaxInWindows {
    private static ArrayList<Integer> maxInWindows(int [] num, int size) {
        int length = num.length;
        ArrayList<Integer> result = new ArrayList<Integer>(length - size + 1);
        if (length < size || size == 0) {
            return result;
        }
        int max=num[0];
        int max_pos = 0;
        for (int i = 0; i < size; i++){
            if (num[i] >= max) {
                max = num[i];
                max_pos = i;
            }
        }
        result.add(max);
        for (int i = 0; i < length - size; i++) {
            if (num[i + size] < max && max_pos > i) {
                result.add(max);
            }
            else {
                max = num[i + size];
                for (int j = size - 1; j > 0; j--) {
                    if (num[i + j] > max) {
                        max = num[i + j];
                        max_pos = i + j;
                    }
                }
                result.add(max);
            }
        }
        return result;
    }

    public static void main(String argv[]){
        int test_array[] = {2, 3, 4, 2, 6, 2, 5, 1};
        ArrayList<Integer> res = maxInWindows(test_array, 3);
        for (int elem : res) {
            System.out.println(elem);
        }
    }
}
