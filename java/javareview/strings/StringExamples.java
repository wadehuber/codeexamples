package videoexamples.module00.strings;
// Examples of manipulating strings

public class StringExamples {

	public static void main(String[] args) {
		
		String myStr1 = "Hello";
		String myStr2 = new String("Hello");

	    String str1 = "The sooner you get behind in your work, the more time you have to catch up.";
	    String str2 = "The speed of a non-working program is irrelevant.";
	    String str3 = "---> We have 5 example strings in CSC205! <---";
	    
	    System.out.println("Length of myStr1: " + myStr1.length());
	    System.out.println("Length of myStr2: " + myStr2.length());
	    System.out.println("Length of str1: " + str1.length());
	    System.out.println("Length of str2: " + str2.length());
	    System.out.println("Length of str3: " + str3.length());
	   
	    // String comparison
	    System.out.println();
	    System.out.println("Comparing strings with ==:");
	    if (myStr1 == "Hello") {
	    	System.out.println("  " + myStr1 + " == " + myStr2);
	    }

	    else {
	    	System.out.println("  " + myStr1 + " != " + myStr2);
	    }
	    
	    if (myStr1 == myStr2) {
	    	System.out.println("  " + myStr1 + " == " + myStr2);
	    }

	    else {
	    	System.out.println("  " + myStr1 + " != " + myStr2);
	    }

	    System.out.println("Comparing strings with equals():");
	    if (myStr1.equals(myStr2)) {
	    	System.out.println("  " + myStr1 + " == " + myStr2);
	    }

	    else {
	    	System.out.println("  " + myStr1 + " != " + myStr2);
	    }

	    System.out.println("Comparing strings with compareTo():");
	    if (myStr1.compareTo(myStr2)==0) {
	    	System.out.println("  " + myStr1 + " == " + myStr2);
	    }

	    else {
	    	System.out.println("  " + myStr1 + " != " + myStr2);
	    }
	    System.out.println();

	    System.out.println("Original String 1: " + str1);
	    System.out.println("   Letters only: " + String205.justLetters(str1));
	    System.out.println("   Vowels removed: " + String205.noVowels(str1));
	    System.out.print("   Individual words: ");
	    String205.individualWords(str1);
	    System.out.println();
	    
	    System.out.println("Original String 2: " + str2);
	    System.out.println("   Letters only: " + String205.justLetters(str2));
	    System.out.println("   Vowels removed: " + String205.noVowels(str2));
	    System.out.print("   Individual words: ");
	    String205.individualWords(str2);
	    System.out.println();

	    System.out.println("Original String 3: " + str3);
	    System.out.println("   Letters only: " + String205.justLetters(str3));
	    System.out.println("   Vowels removed: " + String205.noVowels(str3));
	    System.out.print("   Individual words: ");
	    String205.individualWords(str3);
	    System.out.println();

	}

}
