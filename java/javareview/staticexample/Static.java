package videoexamples.module00.staticexample;

public class Static {
	
	private static int staticVariable;   // Static variable - shared by all objects
	private int nonStaticVariable;       // Non-static variable - each object gets its own copy
	private String name;
	private static final int answer = 42;

	private int myNum;                   // Non-static variable - each object gets its own copy
	private static int counter = 0;      // Static variable - shared by all objects

	
	public Static(String name, int nonStaticVariable) {
		super();
		this.name = name;
		this.nonStaticVariable = nonStaticVariable;
		counter++;
		this.myNum = counter;
	}

	// Static method - can be called without instantiating an object
	// Can only access static members!
	public static void staticMethod(int x) {
		staticVariable += x;
	}

	// Non-static method
	public void nonStaticMethod(int x) {
		staticVariable += 1;
		nonStaticVariable += x;
	}
	
	@Override
	public String toString() {
		return name + " [" + myNum + " of " + counter + "]" + 
	            ": [nonStaticVariable=" + nonStaticVariable + 
				", staticVariable=" + staticVariable + ", answer=" + answer + "]";
	}
	
}
