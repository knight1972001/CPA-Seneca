package Shape;

import java.text.DecimalFormat;

public class Square extends Rectangle{
    private double side;
    private ShapeArea area = () -> getSide()*getSide();

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
            DecimalFormat df = new DecimalFormat("0.0000");
        if (Math.round(this.perimeter()) < 1) {
            return "Square {s=" + this.getSide() + "} perimeter = " + perimeter() + " | area = " + df.format(area.area())+ "\n";
        } else {
            return "Square {s=" + this.getSide() + "} perimeter = " + df.format(perimeter()) + " | area = " + area.area() + "\n";
        }
    }
}
