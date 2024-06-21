class Box1 {

     double width;
    double height;
     double depth;
    Box1(double width, double height, double depth) {
        this.width = width;
        this.height = height;
        this.depth = depth;
    }

     double getVolume() {
        return width * height * depth;
    }

}

public class Box {

    public static void main(String[] args) {
        Box1 b = new Box1(10, 5, 2);

        // Print the volume of the box
        System.out.println("The volume of the box is: " + b.getVolume());
    }

}
