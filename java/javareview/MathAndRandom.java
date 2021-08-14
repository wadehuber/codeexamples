package videoexamples.module00.javareview;

import java.util.Random;

public class MathAndRandom {

	public static void main(String[] args) {
		Random rand = new Random();
		
		System.out.println("java.lang.Math");
		System.out.println("  Math.PI = " + Math.PI);
		System.out.println("  Math.abs(6) = " + Math.abs(6));
		System.out.println("  Math.abs(-6) = " + Math.abs(-6));
		System.out.println();

		System.out.println("Exponents");
		System.out.println("  Math.pow(2, 8) = " + Math.pow(2, 8));
		System.out.println("  Math.pow(27, 1.0 / 3.0) = " + Math.pow(27, 1.0 / 3.0));
		System.out.println("  Math.pow(2, -2) = " + Math.pow(2, -2));
		System.out.println("  Math.exp(1) = " + Math.exp(1));
		System.out.println("  Math.exp(-1) = " + Math.exp(-1));
		System.out.println("  Math.exp(2) = " + Math.exp(2));
		System.out.println();
		
		System.out.println("Logarithms");
		System.out.println("  Math.log(10) = " + Math.log(10));
		System.out.println("  Math.log(Math.exp(1)) = " + Math.log(Math.exp(1)));
		System.out.println("  Math.log10(10) = " + Math.log10(10));
		System.out.println("  Math.log10(1000) = " + Math.log10(1000));
		System.out.println("  Logs base 2:");
		System.out.println("     1/4 : " + Math.log10(.25) / Math.log10(2));
		System.out.println("     2 : " + Math.log10(2) / Math.log10(2));
		System.out.println("     16 : " + Math.log10(16) / Math.log10(2));
		System.out.println();

		System.out.println("Minimum & Maximum");
		System.out.println("  Math.min(7, 8) = " + Math.min(7, 8));
		System.out.println("  Math.max(7, 8) = " + Math.max(7, 8));
		System.out.println("  Math.min(4.2, 3.1) = " + Math.min(4.2, 3.1));
		System.out.println("  Math.max(4.2, 3.1) = " + Math.max(7, 3.1));
		System.out.println();

		System.out.println("Round, Floor, & Ceiling");
		System.out.println("  Math.round(9.1) = " + Math.round(9.1));
		System.out.println("  Math.round(9.5) = " + Math.round(9.5));
		System.out.println("  Math.round(9.9) = " + Math.round(9.9));
		System.out.println("  Math.floor(9.1) = " + Math.floor(9.1));
		System.out.println("  Math.floor(9.5) = " + Math.floor(9.5));
		System.out.println("  Math.floor(9.9) = " + Math.floor(9.9));
		System.out.println("  Math.ceil(9.1) = " + Math.ceil(9.1));
		System.out.println("  Math.ceil(9.5) = " + Math.ceil(9.5));
		System.out.println("  Math.ceil(9.9) = " + Math.ceil(9.9));
		System.out.println();

		System.out.println("Trig Functions");
		Double angle1 = Math.PI / 6.0;
		Double angle2 = Math.PI / 2.0;
		Double angle3 = Math.toRadians(45);
		System.out.println("  Angle 1: " + angle1);
		System.out.println("     Math.cos = " + Math.cos(angle1));
		System.out.println("     Math.sin = " + Math.sin(angle1));
		System.out.println("     Math.tan = " + Math.tan(angle1));
		System.out.println("  Angle 2: " + angle2);
		System.out.println("     Math.cos = " + Math.cos(angle2));
		System.out.println("     Math.sin = " + Math.sin(angle2));
		System.out.println("     Math.tan = " + Math.tan(angle2));
		System.out.println("  Angle 3: " + angle3);
		System.out.println("     Math.cos = " + Math.cos(angle3));
		System.out.println("     Math.sin = " + Math.sin(angle3));
		System.out.println("     Math.tan = " + Math.tan(angle3));
		System.out.println();
		
		System.out.println();
		System.out.println("java.lang.Random");
		System.out.print("  nextInt(): ");
		for (int ii=0;ii<10;ii++) {
			System.out.print("  " + rand.nextInt());
		}
		System.out.println();
		
		System.out.print("  nextInt(10): ");
		for (int ii=0;ii<10;ii++) {
			System.out.print("  " + (rand.nextInt(10)+1));
		}
		System.out.println();
		
		System.out.print("  nextDouble(): ");
		for (int ii=0;ii<10;ii++) {
			System.out.print("  " + rand.nextDouble());
		}
		System.out.println();
		
		System.out.print("  nextBoolean(): ");
		for (int ii=0;ii<10;ii++) {
			System.out.print("  " + rand.nextBoolean());
		}
		System.out.println();
	}
		
}
