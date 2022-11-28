# Database Information

CSC205, CSC220, and CSC240 are not database courses, but we will briefly cover databases if we have time.  We will cover a very small subset of SQL - CREATE TABLE, INSERT, SELECT, and possibly UPDATE - just enough to be able to do something non-trivial in our programs.

## General Database Links

- [Things I Wished More Developers Knew About Databases](https://medium.com/@rakyll/things-i-wished-more-developers-knew-about-databases-2d0178464f78)

## SQL Tutorials

- An non-technical [introduction to SQL](https://blog.hubspot.com/marketing/sql-tutorial-introduction#sm.0014w0gpa13h5f0aqar1fdz1qni3h)
- Another more complete [SQL tutorial](http://www.sqltutorial.org/)
- VIDEO [Intro to SQL](https://www.khanacademy.org/computing/computer-programming/sql/sql-basics/v/welcome-to-sql) from Khan Academy

## Other SQL links

- [SQL Concepts from A to Z](https://www.helenanderson.co.nz/sql-concepts-from-a-to-z/).  That site also has an expaination of [SQL Joins without using Venn Diagrams](https://www.helenanderson.co.nz/sql-joins-venn-diagrams/)
- [SQL queries don't start with SELECT](https://jvns.ca/blog/2019/10/03/sql-queries-don-t-start-with-select/) has some good information about how SQL queries work
- [A Visual Explaination of SQL Joins](https://blog.codinghorror.com/a-visual-explanation-of-sql-joins/)
- A guide to [optimizing queries](https://towardsdatascience.com/learning-sql-201-optimizing-queries-regardless-of-platform-918a3af9c8b1)

## JDBC

- Jenkov's [JDBC Tutorial](http://tutorials.jenkov.com/jdbc/index.html)
- [10 common mistakes Java developers make when writing SQL](https://blog.jooq.org/2013/07/30/10-common-mistakes-java-developers-make-when-writing-sql/)
- [10 *more* common mistakes Java developers make when writing SQL](https://blog.jooq.org/2013/08/12/10-more-common-mistakes-java-developers-make-when-writing-sql/)

## Setting up SQLite in Eclipse

1. Download the [SQLite jar](https://github.com/xerial/sqlite-jdbc/releases)
2. Install the JAR file in your project.
3. Left click on your project and select Build Path -> Configure Build Path
4. Click the Libraries tab and click "Add External JAR"
5. Navigate to the directory you downloaded the SQLite JAR file and select it.
6. Click OK
7. If the installation worked, try to execute the class below.  It should state that it made the connection correctly.  

```(Java)
import java.sql.Connection;
import java.sql.DriverManager; import java.sql.SQLException;

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
