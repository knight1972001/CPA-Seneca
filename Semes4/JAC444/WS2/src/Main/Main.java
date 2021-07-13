//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NBB
// Day:			    May 31th 2020
// Workshop:       	2&3
//==============================================
package Main;

import Shapes.*;

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
                        case "Triangle":
                            shapes[count] = new Triangle(a, b, c);
                            count++;
                            break;
                        case "Square":
                            if (!flagB && !flagC) { //similar as circle, the square just get only 1 value is the side. This one should not get the second and third value.
                                shapes[count] = new Square(a);
                                count++;
                            }
                            break;
                        case "Parallelogram":
                            if (flagC && c > 0) { //if the parallelogram get the third value, it means the height, So we can possible to calculate the area(However, it did not require in this workshop!
                                shapes[count] = new Parallelogram(a, b, c);
                                count++;
                            }
                            if (!flagC) { //if the parallelogram do not get the third value, it can only calculate the perimeter same as the Rectangle.
                                shapes[count] = new Parallelogram(a, b);
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
                } catch (Exception e) {
                    System.out.println(e);
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

        System.out.println("------->Task 2 ... <-------");
        shapes = task2(shapes, count);
        System.out.println("Shapes length: " + shapes.length + "\n");
        for (int i = 0; i < shapes.length; i++) {
            System.out.println(shapes[i].toString());
        }

        System.out.println("------->Task 3 ... <-------");
        System.out.println("Total perimeter of Parallelogram is: " + getTotalPerimeterParallelogram(shapes));
        System.out.println("Total perimeter of Triangle is: " + getTotalPerimeterTriangle(shapes));

    }

    public static Shape[] task2(final Shape[] shapes, final int count) {
        double miniumPerimeter = 100;
        Shape[] temp = new Shape[50];
        int countTemp = 0;
        for (int i = 0; i < count; i++) { //get the min Triangle perimeter value!
            if (shapes[i] instanceof Triangle) {
                if (shapes[i].perimeter() < miniumPerimeter) {
                    miniumPerimeter = shapes[i].perimeter();
                }
            }
        }
        for (int i = 0; i < count; i++) { //copy old stack to new stack except the Triangle which has the min perimeter value
            if (shapes[i] instanceof Triangle) {
                if (shapes[i].perimeter() != miniumPerimeter) {
                    temp[countTemp] = shapes[i];
                    countTemp++;
                }
            } else {
                temp[countTemp] = shapes[i];
                countTemp++;
            }
        }
        double maxPerimeter = 0;

        for (int i = 0; i < countTemp; i++) { //get the max Circle perimeter value!
            if (temp[i] instanceof Circle) {
                if (temp[i].perimeter() > maxPerimeter) {
                    maxPerimeter = temp[i].perimeter();
                }
            }
        }
        Shape[] result = new Shape[29];
        int countResult = 0;
        for (int i = 0; i < countTemp; i++) { //copy old stack to new stack except the Circle which has the max perimeter value
            if (temp[i] instanceof Circle) {
                if (temp[i].perimeter() != maxPerimeter) {
                    result[countResult] = temp[i];
                    countResult++;
                }
            } else {
                result[countResult] = temp[i];
                countResult++;
            }
        }

        return result;
    }

    public static double getTotalPerimeterParallelogram(final Shape[] shapes) {
        double total = 0;
        for (Shape shape : shapes) {
            if (shape instanceof Parallelogram) {
                total += shape.perimeter();
            }
        }
        return total;
    }

    public static double getTotalPerimeterTriangle(final Shape[] shapes) {
        double total = 0;
        for (Shape shape : shapes) {
            if (shape instanceof Triangle) {
                total += shape.perimeter();
            }
        }
        return total;
    }
}
