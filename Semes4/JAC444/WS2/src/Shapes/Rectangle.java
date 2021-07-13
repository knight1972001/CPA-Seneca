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

public class Rectangle implements Shape {
    private double length;
    private double width;

    public Rectangle(final double width, final double length) throws Exception {
        if (length > 0 && width > 0) {
            this.length = length;
            this.width = width;
        } else {
            throw new Exception("Invalid side!");
        }
    }

    public double getLength() {
        return length;
    }

    public void setLength(final double length) {
        this.length = length;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(final double width) {
        this.width = width;
    }

    @Override
    public double perimeter() {
        return (this.width + this.length) * 2;
    }

    @Override
    public double area() throws Exception {
        return (this.width * this.length);
    }

    @Override
    public String toString() {
        DecimalFormat df = new DecimalFormat("#.0000");
        return "Rectangle {w=" + this.getWidth() + ", l=" + this.getLength() + "} perimeter = " + df.format(perimeter()) + "\n";
    }
}
