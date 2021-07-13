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

public class Triangle implements Shape {
    private double a;
    private double b;
    private double c;
    private double h;

    public Triangle(final double a, final double b, final double c) throws Exception {
        if ((a > 0 && b > 0 && c > 0) && (a + b > c) && (a + c > b) && b + c > a) {
            this.a = a;
            this.b = b;
            this.c = c;
        } else {
            throw new Exception("Invalid side(s)!");
        }
    }

    public Triangle(final double a, final double b, final double c, final double h) throws Exception {
        if (a > 0 && b > 0 && c > 0 && h > 0) {
            this.a = a;
            this.b = b;
            this.c = c;
            this.h = h;
        } else {
            throw new Exception("The value cannot equal 0 or below 0!");
        }
    }

    public double getA() {
        return a;
    }

    public void setA(final double a) {
        this.a = a;
    }

    public double getB() {
        return b;
    }

    public void setB(final double b) {
        this.b = b;
    }

    public double getC() {
        return c;
    }

    public void setC(final double c) {
        this.c = c;
    }

    public double getH() {
        return h;
    }

    public void setH(final double h) {
        this.h = h;
    }

    @Override
    public double perimeter() {
        return (a + b + c);
    }

    @Override
    public double area() throws Exception {
        if (h != 0) {
            return (b * h) * 0.5;
        } else {
            throw new Exception("The height must be not 0 to calculate area!");
        }
    }

    @Override
    public String toString() {
        DecimalFormat df = new DecimalFormat("#.0000");
        return "Triangle {s1=" + this.getA() + ", s2=" + this.getB() + ", s3=" + this.getC() + "} perimeter = " + df.format(perimeter()) + "\n";
    }
}
