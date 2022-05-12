package videoexamples.module03.movies;

public class MoviePicker {

	public static void main(String[] args) {

	    Movie movies[] = {
                 new Movie("The Hurt Locker", "Kathryn Bigelow", 2008, "R", 97, 75),	
	             new Movie("In the Heights", "John M. Chu", 2021, "PG-13", 94, 74),	
	    		 new Movie("Aliens", "James Cameron", 1986, "R", 97, 83),
	             new Movie("Shadow of a Doubt", "Alfred Hitchcock", 1943, "PG", 100, 78),	
	             new Movie("Toy Story", "John Lasseter", 1995, "G", 100, 83),	
	             new Movie("Twelve Monkeys", "Terry Gilliam", 1995, "R", 89, 80)
	           };
	    
	    // Print the movies
	    System.out.println("Movie choices:");
	    for (int ii=0;ii<movies.length;ii++) {
	    	System.out.println("   " + movies[ii]);
	    }

	    // Find the best movie in the list 
	    Movie watch = movies[0];
	    for (int jj=1;jj<movies.length;jj++) {
	    	if (movies[jj].compareTo(watch) > 0 ) {
	    		watch = movies[jj];
	    	}
	    }

	    System.out.println();
	    System.out.println("The best of these is " + watch.getTitle());
	}

}
