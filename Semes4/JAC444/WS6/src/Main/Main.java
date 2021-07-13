package Main;

import Shape.*;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        Shape[] shapes = new Shape[50];
        int count = 0;
        String s;
        try (BufferedReader br = new BufferedReader(new FileReader("shapes.txt"))) {
            while ((s = br.readLine()) != null) {
                String[] tokens = s.split(",");
                String name = "";
                double a = 0, b = 0, c = 0;
                boolean flagB = false, flagC = false;
                for (int i = 0; i < tokens.length; i++) {
                    switch (i) { //The string will be slice into array. that will have format array[3]=["name","height","width","length"]. I use switch case to get each element in array!
                        case 0:
                            name = tokens[i];
                            break;
                        case 1:
                            a = Double.parseDouble(tokens[i]);
                            break;
                        case 2:
                            b = Double.parseDouble(tokens[i]);
                            flagB = true; //each flag have each function, If it get any value, the flag will be on.
                            break;
                        case 3:
                            c = Double.parseDouble(tokens[i]);
                            flagC = true;
                            break;
                    }
                }
                try {
                    switch (name) {
                        case "Circle":
                            if (!flagB && !flagC) { //the flag B and C(as known as the second value and third value) should not be here because this Circle just get 1 radius.
                                shapes[count] = new Circle(a);
                                count++;
                            }
                            break;
                        case "Square":
                            if (!flagB && !flagC) { //similar as circle, the square just get only 1 value is the side. This one should not get the second and third value.
                                shapes[count] = new Square(a);
                                count++;
                            }
                            break;
                        case "Rectangle":
                            if (!flagC) { //the retangle should not get the third value (for nothing!)
                                shapes[count] = new Rectangle(a, b);
                                count++;
                            }
                            break;
                        default:
                            break;
                    }
                } catch (CircleException e){
                    System.out.println(e.getMessage());
                } catch (RectangleException e){
                    System.out.println(e.getMessage());
                }
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println();
        System.out.println(count + " shapes were created:\n");
        for (int i = 0; i < count; i++) {
            System.out.println(shapes[i].toString());
        }
    }
}
