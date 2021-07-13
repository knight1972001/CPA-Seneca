package Shape;

import java.text.DecimalFormat;

public class Rectangle implements Shape {
    private double length;
    private double width;
    private ShapeArea area = () -> getLength() * getWidth();

    public Rectangle(final double width, final double length) throws Exception {
        if (length > 0 && width > 0) {
            this.length = length;
            this.width = width;
        } else {
            throw new RectangleException("Invalid side!");
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
    public String toString() {
        DecimalFormat df = new DecimalFormat("#.0000");
        return "Rectangle {w=" + this.getWidth() + ", l=" + this.getLength() + "} perimeter = " + df.format(perimeter()) + " | area = " + df.format(area.area()) + "\n";
    }
}
