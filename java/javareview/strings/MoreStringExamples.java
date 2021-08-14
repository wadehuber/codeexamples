package videoexamples.module00.strings;

public class MoreStringExamples {
	
	public static void main(String[] args) {

		String s1 = "More String examples";
		String s2 = "abcd123ABCD";

		System.out.println("S1: " + s1);
		System.out.println("S2: " + s2);
		
		System.out.println();
		System.out.println("Change case:");
		System.out.println("  " + s1.toLowerCase());
		System.out.println("  " + s2.toLowerCase());
		System.out.println("  " + "This is a string literal".toLowerCase());
		System.out.println("  " + s1.toUpperCase());
		System.out.println("  " + s2.toUpperCase());
		System.out.println("  " + "This is a string literal".toUpperCase());
		
		System.out.println();
		System.out.println("Getting sub-strings:");
		System.out.println("  " + s1.substring(3));
		System.out.println("  " + s2.substring(3));
		System.out.println("  " + "This is a string literal".substring(3));
		System.out.println("  " + s1.substring(3,8));
		System.out.println("  " + s2.substring(4,7));
		System.out.println("  " + "This is a string literal".substring(10,16));

		System.out.println();
		System.out.println("Concatenating strings:");
		System.out.println("  " + s1.concat(s2));
		System.out.println("  " + s2.concat(s1));
		System.out.println("  " + "This program has ".concat(s1));

		
	}
}
