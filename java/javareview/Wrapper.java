package videoexamples.module00.javareview;

import java.util.ArrayList;

public class Wrapper {

	public static void main(String[] args) {
		int num1 = 10;
		Integer num2 = 20;
		
		char char1 = 'A';
		Character char2 = 'B';
		
		double float1 = 3.14;
		Double float2 = 12.34;
		
		String str1 = "42";
		String str2 = "6.022";
		
		//ArrayList<int> intArr = new ArrayList<int>();
		ArrayList<Integer> intArr = new ArrayList<Integer>();
		intArr.add(7);
		intArr.add(10);
		
		System.out.println("Primitive Type\tWrapper Class");
		System.out.println("--------------\t-------------");
		System.out.println("num1=" + num1 + "\t\tnum2=" + num2);
		System.out.println("char1=" + char1 + "\t\tchar2=" + char2);
		System.out.println("float1=" + float1 + "\tfloat2=" + float2);
		
		System.out.println();
		System.out.println("Integer range: " + Integer.MIN_VALUE + " - " + Integer.MAX_VALUE);
		System.out.println("Integer.parseInt(str1) = " + Integer.parseInt(str1));
		System.out.println("Double.parseDouble(str2) = " + Double.parseDouble(str2));
		System.out.println("Integer.min(10, 20) = " + Integer.min(10, 20));
		System.out.println("Integer.max(10, 20) = " + Integer.max(10, 20));
		
		System.out.println();
		System.out.println("num1=" + num1);
		System.out.println("\tnum1=" + Integer.toBinaryString(num1) + " (binary)");
		System.out.println("\tnum1=" + Integer.toOctalString(num1) + " (octal)");
		System.out.println("\tnum1=" + Integer.toHexString(num1) + " (hexidecimal)");
		System.out.println("573845");
		System.out.println("\t573845=" + Integer.toBinaryString(573845) + " (binary)");
		System.out.println("\t573845=" + Integer.toOctalString(573845) + " (octal)");
		System.out.println("\t573845=" + Integer.toHexString(573845) + " (hexidecimal)");
		
		System.out.println();
		System.out.println("addTen(1)=" + addTen(1));
		System.out.println("addTen(num1)=" + addTen(num1));
		System.out.println("addTen(num2)=" + addTen(num2));
	}
	
	public static int addTen(Integer x) {
		return x + 10;
	}

}
