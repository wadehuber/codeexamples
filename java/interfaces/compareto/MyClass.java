package videoexamples.module03.compareto;

public class MyClass implements Comparable<MyClass> {
	
	int num;
	String name;
	
	public MyClass(int num, String name) {
		this.num = num;
		this.name = name;
	}

	@Override
	public String toString() {
		return "[" + num + ", " + name + "]";
	}

	@Override
	public int compareTo(MyClass o) {
		// Conventions when comparing "this" to "o"
		//   if we have a.compareTo(b)
		//      return 0 if a == b
		//      return a negative if a < b
		//      return a positive if a > b

		// return this.name.compareTo(o.name);
		return this.num - o.num;
	}

}
