package videoexamples.module00.staticexample;

public class StaticExample {
	public static void main(String[] args) {
		Static static1 = new Static("Kendra", 13);
		Static static2 = new Static("Seth", 11);
		
		System.out.println(static1);
		System.out.println(static2);
		
		System.out.println();
		static1.nonStaticMethod(1);
		System.out.println(static1);
		System.out.println(static2);
		
		System.out.println();
		static2.nonStaticMethod(2);
		System.out.println(static1);
		System.out.println(static2);
		
		
		System.out.println();
		Static.staticMethod(10);
		System.out.println(static1);
		System.out.println(static2);
	}
	
}
