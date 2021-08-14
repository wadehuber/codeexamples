package videoexamples.module00.javareview;

public class ObjectReferences {

	private static class Thing {
		private int num;
		private String name;
		
		public Thing(int num, String name) {
			super();
			this.num = num;
			this.name = name;
		}

		public void setNum(int num) { this.num = num; }

		public void print() {
			System.out.println("Thing [num=" + num + ", name=" + name + "]");
		}
	}

	public static void main(String[] args) {
		
		// Primitive variables
		int x = 10;
		double pi = 3.14159;
		
		// Object reference variables
		String str = "Hello, CSC205";
		Thing tng = new Thing(42, "Gorgu");
		Thing anthr = new Thing(4, "Privet");
		Thing yeti = new Thing(2020, "Arizona");
		
		// Print everything out
		System.out.println("Primitive variables:");
		System.out.println("   x = " + x);
		System.out.println("  pi = " + pi);
		System.out.println();
		System.out.println("Object reference variables:");
		System.out.println("   str = " + str);
		System.out.println("   tng = " + tng);
		System.out.println(" anthr = " + anthr);
		System.out.println("  yeti = " + yeti);
		
		System.out.println();
		tng.print();
		anthr.print();
		yeti.print();
		
		anthr = tng;
		System.out.println();
		System.out.println("After anthr = tng");
		tng.print();
		anthr.print();
		
		anthr.setNum(123);
		System.out.println();
		System.out.println("After anthr.setNum(123)");
		tng.print();
		anthr.print();

		System.out.println();
		System.out.println("Object reference variables:");
		System.out.println("   str = " + str);
		System.out.println("   tng = " + tng);
		System.out.println(" anthr = " + anthr);
		System.out.println("  yeti = " + yeti);
		
		
	}

}
