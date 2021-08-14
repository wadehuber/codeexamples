package videoexamples.module00.strings;

// Examples of manipulating strings in Java
// The Character & String classes are filled with helpful methods you can use

public class String205 {

	// Example of using Character.isLetter method
	public static String justLetters(String s) {
		String ret = "";
		
		for (int ii=0;ii<s.length();ii++) {
			if(Character.isLetter(s.charAt(ii))) {
				ret += s.charAt(ii);
			}
		}

		return ret;
	}
	
	// Returns a string with the vowels removed
	public static String noVowels(String s) {
		String ret = "";
		
		for (char c : s.toCharArray()) {
			if (!isVowel(c) ) {
				ret += c;
			}
		}
		
		return ret;
	}
	
	public static boolean isVowel(Character c) {
		boolean ret = false;
		
		switch(Character.toLowerCase(c)) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				ret = true;
		}
		return ret;
	}
	
	// Print the words in a string one-by-one
	public static void individualWords(String s) {
		String[] words = s.split(" ");
		for(int ii=0;ii<words.length;ii++) {
			System.out.print("[(" + ii + ")" + words[ii] +  "] ");
		}
		System.out.println();
	}
	
}
