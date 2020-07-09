# Database Information

## General Databse Links

- [Things I Wished More Developers Knew About Databases](https://medium.com/@rakyll/things-i-wished-more-developers-knew-about-databases-2d0178464f78)

## SQL Tutorials

- VIDEO [Intro to SQL](https://www.khanacademy.org/computing/computer-programming/sql/sql-basics/v/welcome-to-sql) from Khan Academy

## JDBC

- Jenkov's [JDBC Tutorial](http://tutorials.jenkov.com/jdbc/index.html)

## Setting up SQLite in Eclips

1. Download the [SQLite jar](https://bitbucket.org/xerial/sqlite-jdbc/downloads/) (pick the latest one)
2. Install the JAR file in your project.
3. Left click on your project and select Build Path -> Configure Build Path
4. Click the Libraries tab and click "Add External JAR"
5. Navigate to the directory you downloaded the SQLite JAR file and select it.
6. Click OK
7. If the installation worked, try to execute the class below.  It should state that it made the connection correctly.  

```(Java)
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class SQLiteTest {

    public static void main(String args[]) {
        try {
            Class.forName("org.sqlite.JDBC");
        } catch (ClassNotFoundException e1) {
            e1.printStackTrace();
        }
        Connection conn = null;
        try {
                conn = DriverManager.getConnection("jdbc:sqlite:csc205.db");
                System.out.println("Opened database connection!");
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println(e.getClass().getName() + ": " + e.getMessage());
        }
        finally {
            if (conn != null) {
                try {
                    conn.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                    System.out.println(e.getMessage());
                }
            }
        }
    }
}
```
