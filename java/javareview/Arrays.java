package videoexamples.module00.javareview;

public class Arrays {

	public static void main(String[] args) {
		
		Integer[] nums = new Integer[10];
		Integer[] moreNums = {10, 20, 30};
		
		System.out.println("Array Example");
		System.out.println();
		
		// add numbers to nums array
		for (int ii=0;ii<nums.length; ii++) {
			nums[ii] = ii;
		}
		
		// Change the first element of the array (keep in mind the first index is 0
		nums[0] = -10;
		
		// Change the 6th element of the array (index 5)
		nums[5] = 30;
		
		System.out.println("nums: ");
		// print the nums array on one line separated by a space
		// When traversing arrays using a loop, always use the length attribute
		//   instead of an integer literal (hard-coded value)
		for (int ii=0;ii<nums.length;ii++) {
			System.out.print(nums[ii] + " ");   // print() does not add a newline
		}
		System.out.println("\n");
		
		// print the moreNums array, one number per line
		System.out.println("moreNums:");
		for(int ii=0;ii<moreNums.length;ii++) {
			System.out.println("  " + moreNums[ii]);
		}
		System.out.println();
	}

}
