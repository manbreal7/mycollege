// Custom EvenNumberException class
class EvenNumberException extends Exception {
    public EvenNumberException(String message) {
        super(message);
    }
}

// Main class
public class add6 {
    public static void main(String[] args) {
        try {
            int number = 4; // Replace this with the input number

            if (number % 2 == 0) {
                throw new EvenNumberException("Number is even. Custom EvenNumberException thrown.");
            } else {
                System.out.println("Number is: " + number + " and it is not even.");
            }
        } catch (EvenNumberException e) {
            System.out.println("Caught EvenNumberException: " + e.getMessage());
        }
    }
}
