package videoexamples.module00.javareview;

public class ClassExample {
	
	// Public members are only visible inside the class.  If we want these to
	//   change from outside the class we need to provide public methods.
	private String name;
	private int count;
	private int num;
	
	// Constructors are methods named the same as the class with no return
	//  values.  Constructors are called when we instantiate the class.
	//  They are used to initialize the object.
	// We can have multiple constructors (overridden) as long as they have
	//  different signatures (type & number of parameters).  This allows us 
	//  to initialize objects in different ways.
	public ClassExample(String name, int num) {
		this(name, num, 0);  // Call ClassExample constructor with 3 parameters
	}
	public ClassExample(String name, int num, int count) {
		super();  // Constructor of the parent class
		
		// The "this" references refers to the current object
		this.name = name;
		setNum(num);
		this.count = count;
	}
	
	// To allow changes to an object's data members to be made from outside 
	//   the class we need to provide accessor/mutator methods (also called 
	//   getters & setters).  
	// We will not allow users of the class to change the name
	
	// For num we will allow the number to be changed by users of our class.
	//  However, we insist that the number must be positive.
	public int getNum() {
		return num;
	}
	
	public void setNum(int num) {
		if (num < 0) {
			this.num = 0;
		}
		else {
			this.num = num;
		}
	}
	
	// We have decided not to provide access to the count variable, but 
	//   it can be changed by alling the increment method.  
	public void increment() {
		this.count ++;
	}
	
	// We typically want to provide a toString method which should return
	//   a string representation of the state of our object.  Not all 
	//   data members need to be included, it depends on what the 
	//   programmer thinks is best
	// Note that you should NOT have any println statements in your toString
	@Override
	public String toString() {
		return ("ClassExample [name=" + name + ", count=" + count + ", num=" + num + "]");
	}
	
	public static void main(String[] args) {
		System.out.println("Test of ClassExample class");
		
		// Instantiate some objects
		ClassExample object1 = new ClassExample("Object1", 10);
		ClassExample object2 = new ClassExample("Object2", 20, 100);
	
		// Our toString method lets print the objects easily
		System.out.println(object1);
		System.out.println(object2);
		System.out.println();
		
		// Change object1
		object1.setNum(45);
		object1.increment();
		
		// Change object2
		object2.setNum(-3);
		for(int ii=0;ii<23;ii++) {
			object2.increment();
		}

		System.out.println("After changing the objects:");
		System.out.println(object1);
		System.out.println(object2);
	}
}