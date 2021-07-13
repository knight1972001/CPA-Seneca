@FunctionalInterface
interface CircleProperty {

    double get(double radius);

}



class Circle {

    public double circleValue(double radius, CircleProperty cr) {

        return cr.get(radius);

    }



    public static void main(String[] a) {

        Circle circle = new Circle();

        CircleProperty sr = Math::sqrt;

        double mySR = circle.circleValue(16, sr);

        System.out.println("SquareRootRadius = " + mySR);

    }

}