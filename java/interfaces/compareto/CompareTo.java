package videoexamples.module03.compareto;

public class CompareTo {

	public static void main(String[] args) {

		MyClass A = new MyClass(2,"Hello");
		MyClass B = new MyClass(1,"World");

		System.out.println("A:" + A);
		System.out.println("B:" + B);

		doCompare(A, A);
		doCompare(B, B);
		doCompare(A, B);
		doCompare(B, A);
	}

	public static void doCompare(MyClass m1, MyClass m2) {
		if (m1.compareTo(m2) == 0) 
			System.out.println (m1 + " and " + m2 + " are equal.");
		else if (m1.compareTo(m2) < 0) 
			System.out.println (m1 + " is smaller than " + m2);
		else if (m1.compareTo(m2) > 0) 
			System.out.println (m1 + " is bigger  than " + m2);
	}

}
