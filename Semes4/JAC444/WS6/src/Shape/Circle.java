package Shape;

import java.text.DecimalFormat;

public class Circle implements Shape {
    private double radius;
    private ShapeArea area = () -> Math.PI * getRadius() * getRadius();

    public Circle(final double radius) throws Exception {
        if (radius > 0) {
            this.radius = radius;
        } else {
            throw new CircleException("Invalid radius!");
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
    public String toString() {
        DecimalFormat df = new DecimalFormat("#.#####");
        return "Circle {r=" + this.radius + "} perimeter = " + df.format(perimeter()) + " | area = " + df.format(area.area()) + "\n";
    }
}

