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

public class Parallelogram extends Rectangle implements Shape {
    private double height;

    public Parallelogram(final double length, final double width, final double height) throws Exception {
        super(length, width);
        if (height > 0) {
            this.height = height;
        } else {
            throw new Exception("Invalid side!");
        }
    }

    public Parallelogram(final double width, final double length) throws Exception {
        super(width, length);
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(final double height) {
        this.height = height;
    }

    @Override
    public double area() throws Exception {
        if (this.height != 0) {
            return super.getLength() * this.height;
        } else {
            throw new Exception("The height must be not 0 to calculate area!");
        }
    }

    @Override
    public String toString() {
        DecimalFormat df = new DecimalFormat("0.0000");
        return "Parallelogram {w=" + this.getWidth() + ", l=" + this.getLength() + "} perimeter = " + df.format(perimeter()) + "\n";
    }
}
