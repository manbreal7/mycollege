public class add5 {
    public static void main(String[] args) {
        int negativeSize = -1;
        try {
            if (negativeSize < 0) {
                throw new NegativeArraySizeException("Array size cannot be negative.");
            }
            int[] array = new int[negativeSize]; // This line will not be reached if the size is negative
        } catch (NegativeArraySizeException e) {
            System.out.println("Caught NegativeArraySizeException: " + e.getMessage());
        }
    }
}
