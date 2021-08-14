package videoexamples.module00.javareview;

public class CommonMistakes {

	public static void main(String[] args) {
		
		int x;
		// Mistake 1: Not using arrays and loops when appropriate
		
		int num1 = 8;
		int num2 = 3;
		int num3 = 19;
		int num4 = 34;
		int num5 = 13;
		
		System.out.println("num1 = " + num1);
		System.out.println("num2 = " + num2);
		System.out.println("num3 = " + num3);
		System.out.println("num4 = " + num4);
		System.out.println("num5 = " + num5);

	
		// = vs ==
		
		System.out.println("x = 3 : " + (x=3));    
		System.out.println("x == 3 : " + (x==3));
		
		// Working with values
		System.out.println("3 / 2 = " + (3 / 2));
		System.out.println("3 / 2.0 = " + (3 / 2.0));
		System.out.println("3.0 / 2 = " + (3.0 / 2));
		
		int total = 793;
		int count = 7;
		double avg = (double) total / count;


		// Comparing values
		String str1 = "TestString";
		String str2 = new String("TestString");
		String str3 = "TestString";
		
		System.out.println("Strings:");
		System.out.println("  str1=" + str1);
		System.out.println("  str2=" + str2);
		System.out.println("  str3=" + str3);
		
		System.out.println("Comparing str1 & str2 using ==:");
		testDoubleEqual(str1, str2);
		System.out.println("Comparing str1 2 str3 using ==:");
		testDoubleEqual(str2, str3);
		System.out.println("Comparing str1 & str3 using ==:");
		testDoubleEqual(str1, str3);
		
		System.out.println();
		System.out.println("Comparing str1 & str2 using equals():");
		testEquals(str1, str2);
		System.out.println("Comparing str1 2 str3 using equals():");
		testEquals(str2, str3);
		System.out.println("Comparing str1 & str3 using equals():");
		testEquals(str1, str3);

	}

	public static void testDoubleEqual(String s1, String s2) {
		if (s1==s2) {
			System.out.println("    The strings are the same according to ==");
		}
		else {
			System.out.println("    The strings are NOT the same according to ==");
		}
	}
	
	public static void testEquals(String s1, String s2) {
		if (s1.equals(s2)) {
			System.out.println("    The strings are the same according to equals()");
		}
		else {
			System.out.println("    The strings are NOT the same according to equals()");
		}
	}

}
