package videoexamples.module00.javareview;

public class Functions {

	// Example of a function - since we are calling it without instantiating 
	//  an object it has to be static.
	// Print the numbers up to n
	public static void print_numbers_up_to(int n) {
		for (int ii=1;ii<=n;ii++) {
			System.out.print(ii + " ");
		}
	}

	// Example of a function that returns a value
	// Print the sum of an integer array
	public static int sumArray(Integer[] numbers) {
		int sum = 0;
		
		for (int ii=0;ii<numbers.length;ii++) {
			sum = sum + numbers[ii];
		}
		
		return sum;
	}

	public static void main(String[] args) {
		
		Integer nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		
		System.out.print("Print the numbers up to 10: ");
		print_numbers_up_to(10);
		System.out.println();
		
		System.out.println();
		System.out.println("The sum of the array nums is " + sumArray(nums));
		
	}

}
