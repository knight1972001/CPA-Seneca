//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NBB
// Day:			    May 31th 2020
// Workshop:       	2&3
//==============================================
package Shapes;

import java.text.DecimalFormat;

public class Circle implements Shape {
    private double radius;

    public Circle(final double radius) throws Exception {
        if (radius > 0) {
            this.radius = radius;
        } else {
            throw new Exception("Invalid radius!");
        }
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    @Override
    public double perimeter() {
        return 2 * Math.PI * radius;
    }

    @Override
    public double area() {
        return Math.pow(radius, 2) * Math.PI;
    }

    @Override
    public String toString() {
        DecimalFormat df = new DecimalFormat("#.#####");
        return "Circle {r=" + this.radius + "} perimeter = " + df.format(perimeter()) + "\n";
    }
}
