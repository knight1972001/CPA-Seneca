import java.util.ArrayList;

public class main {
    public static void main(String[] args) {
        ArrayList<String> collection = new ArrayList<>();
        collection.add("hi");
        collection.add("1");

        ArrayList<String> collection2= new ArrayList<>();
        collection2.add("AD");
        collection2.add("NEW");
        collection.add(0,"9");

        System.out.println(collection);
    }
}
