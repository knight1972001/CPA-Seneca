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

public class Square extends Rectangle {
    private double side;

    public Square(final double side) throws Exception {
        super(side, side);
        this.side = side;
    }

    public double getSide() {
        return side;
    }

    public void setSide(double side) {
        this.side = side;
    }

    @Override
    public String toString() {
        if (Math.round(this.perimeter()) < 1) {
            return "Square {s=" + this.getSide() + "} perimeter = " + perimeter() + "\n";
        } else {
            DecimalFormat df = new DecimalFormat("0.0000");
            return "Square {s=" + this.getSide() + "} perimeter = " + df.format(perimeter()) + "\n";
        }
    }
}
