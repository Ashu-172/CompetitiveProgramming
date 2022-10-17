////////////////// Q 92: Babbar450: search element in Rotated Sorted Array //////////////////
// first search for the starting index using binary search.
// check in which part of the array the target will be present, based on that do the binary search for the target in selected sub-array.
public class S_S_SearchInRotatedArray {
    public static int search(int[] nums, int target) {
        int l = 0, r = nums.length - 1;

        int start = (nums.length == 1) ? 0 : findRotationIndex(nums, l, r);

        if (target >= nums[start] && target <= nums[r])
            return findTarget(nums, start, r, target);
        else
            return findTarget(nums, l, start - 1, target);
    }

    private static int findRotationIndex(int[] nums, int l, int r) {
        int mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (nums[mid] > nums[l])
                l = mid;
            else
                r = mid;
        }
        return l + 1;
    }

    private static int findTarget(int[] nums, int l, int r, int target) {
        if (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                return findTarget(nums, mid + 1, r, target);
            else
                return findTarget(nums, l, mid - 1, target);
        }
        return -1;
    }

    public static void main(String[] args) {
        int arr[] = { 4, 5, 6, 7, 0, 1, 2 };
        int target = 0;

        int res = search(arr, target);
        System.out.println(res);
    }
}
