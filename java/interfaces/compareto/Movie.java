package videoexamples.module03.movies;

public class Movie implements Comparable<Movie> {

	String title;
	String director;
	int releaseDate;
	String rating;
	int rottenTomatoes;
	int imdb;

	public Movie(String title, String director, int releaseDate, String rating, int rottenTomatoes, int imdb) {
		super();
		this.title = title;
		this.director = director;
		this.releaseDate = releaseDate;
		this.rating = rating;
		this.rottenTomatoes = rottenTomatoes;
		this.imdb = imdb;
	}

	public String getTitle() {
		return title;
	}

	public String getDirector() {
		return director;
	}

	public int getReleaseDate() {
		return releaseDate;
	}

	public String getMPAARating() {
		return rating;
	}

	public int getRottenTomatoes() {
		return rottenTomatoes;
	}

	public void setRottenTomatoes(int rottenTomatoes) {
		this.rottenTomatoes = rottenTomatoes;
	}

	public int getImdb() {
		return imdb;
	}

	public void setImdb(int imdb) {
		this.imdb = imdb;
	}

	@Override
	public int compareTo(Movie o) {
	    // Compare movies based on IMDB rating, break ties with RT
		int result = 0;
		
		if (this.imdb < o.getImdb()) {
			result = -1;
		}
		else if (this.imdb > o.getImdb()) {
			result = 1;
		}
		else {
			result = this.rottenTomatoes - o.getRottenTomatoes();
		}
		return result;
	}

	@Override
	public String toString() {
		return title + " (" + releaseDate +"), directed by " + director +  " (rated "
				+ rating + ")";
	}

}
