package videoexamples.module00.javareview;

import java.util.Scanner;

public class ControlStructures {
	public static void main(String[] args) {
		// Control Structure examples 
		int a = 5;
		int b, ii;
		Scanner scn = new Scanner(System.in);
		
		System.out.println("Enter an integer : ");
		b = scn.nextInt();
		scn.close();
		
		// If-then-else statement
		if (a < b) {
			System.out.println(a + " is less than " + b);
		}
		else {
			System.out.println(a + " is not less than " + b);
		}
		
		// Switch statement
		switch (b) {
			case 1 :
				System.out.println("You entered a one.");
				break;
			case 2 :
				System.out.println("You entered a two.");
				break;
			case 3 :
				System.out.println("You entered a three.");
				break;
			case 4 :
				System.out.println("You entered a four");
				break;
			default :  // The default case is used when no other cases match
				System.out.println("You entered a number greater than 4 or less than 1");
		}
		
		System.out.println("\nWhile loop : ");
		ii = 0;
		while (ii <= b)
		{
			System.out.println("  Your number = " + b + ", loop variable = " + ii);
			ii = ii + 2;
		}

		System.out.println("\nDo-while loop : ");
		do {
			System.out.println("  Your number = " + b + ", loop variable = " + ii);
			ii -= 2;
		} while ( (ii > 0) );

		System.out.println("\nFor loop : ");
		for (ii=0;ii<b;ii++) {
			System.out.println("  loop variable = " + ii);
		}

		System.out.println("\nBreak example : ");
		for(;;) { 
			// Once a is bigger than 1000 exit the loop
			if (a > 100) {
				System.out.println("  Breaking . . ");
				break;
			}
			else {
				a++;
			}
		}
		
		System.out.println("\nContinue example : ");
		for (ii=0;ii<=b;ii++) {
			/* If ii is not a multiple of 3 then go to next loop iteration */
			if ( (ii % 3) != 0) {
				continue; 
			}
			System.out.println(ii);
		}
		System.out.println();
	}
}
