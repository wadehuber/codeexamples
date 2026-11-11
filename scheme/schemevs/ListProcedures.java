// List procedures - iterative and recursive versions of the Scheme examples
// Compile & run:  javac ListProcedures.java && java ListProcedures

import java.util.ArrayList;
import java.util.List;

public class ListProcedures {

    public static void main(String[] args) {
        List<String> lst = List.of("apple", "banana", "cherry", "banana", "date");

        System.out.println("member? - is an element in the list?");
        System.out.println(memberLoop("cherry", lst) + " " + memberLoop("kiwi", lst));
        System.out.println(memberRec("cherry", lst) + " " + memberRec("kiwi", lst));
        System.out.println(lst.contains("cherry"));     // the library already has it

        System.out.println();
        System.out.println("rember - remove the FIRST occurrence of an element");
        System.out.println(remberLoop("banana", lst));
        System.out.println(remberRec("banana", lst));
        System.out.println(remberRec("kiwi", lst));

        System.out.println();
        System.out.println("countOf - how many times does an element appear?");
        System.out.println(countOfLoop("banana", lst));
        System.out.println(countOfRec("banana", lst));

        System.out.println();
        System.out.println("A mixed list in Java needs the type Object");
        List<Object> mixed = List.of(3, "hello", 7.5, List.of(1, 2));
        System.out.println(mixed.contains(List.of(1, 2)));
    }

    // ---------- Iterative versions: loops and a changing index ----------

    static boolean memberLoop(String ele, List<String> lst) {
        for (String s : lst) {
            if (s.equals(ele)) {
                return true;
            }
        }
        return false;
    }

    static List<String> remberLoop(String ele, List<String> lst) {
        List<String> result = new ArrayList<>(lst);   // copy so the original is unchanged
        result.remove(ele);                           // removes the first occurrence only
        return result;
    }

    static int countOfLoop(String ele, List<String> lst) {
        int count = 0;
        for (String s : lst) {
            if (s.equals(ele)) {
                count++;
            }
        }
        return count;
    }

    // ---------- Recursive versions: the Scheme structure in Java ----------
    // car  -> lst.get(0)
    // cdr  -> lst.subList(1, lst.size())   (a view of the rest - no copying)
    // cons -> build a new list with the element in front

    static boolean memberRec(String ele, List<String> lst) {
        if (lst.isEmpty()) {
            return false;
        }
        if (lst.get(0).equals(ele)) {
            return true;
        }
        return memberRec(ele, lst.subList(1, lst.size()));
    }

    static List<String> remberRec(String ele, List<String> lst) {
        if (lst.isEmpty()) {
            return new ArrayList<>();
        }
        List<String> rest = lst.subList(1, lst.size());
        if (lst.get(0).equals(ele)) {
            return new ArrayList<>(rest);
        }
        return cons(lst.get(0), remberRec(ele, rest));
    }

    static int countOfRec(String ele, List<String> lst) {
        if (lst.isEmpty()) {
            return 0;
        }
        int restCount = countOfRec(ele, lst.subList(1, lst.size()));
        return lst.get(0).equals(ele) ? 1 + restCount : restCount;
    }

    // Java has no cons, so we write one
    static List<String> cons(String first, List<String> rest) {
        List<String> result = new ArrayList<>();
        result.add(first);
        result.addAll(rest);
        return result;
    }
}
