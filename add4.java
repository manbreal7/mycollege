import java.util.Scanner;

// Custom Exception class
class InvalidInputException extends Exception {
    public InvalidInputException(String message) {
        super(message);
    }
}

// Main class
public class add4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int sum = 0;

        try {
            while (true) {
                System.out.print("Enter a number (enter -1 to stop): ");
                String input = scanner.nextLine();

                if (input.equals("-1")) {
                    break;
                } else {
                    try {
                        int num = Integer.parseInt(input);
                        sum += num;
                    } catch (NumberFormatException e) {
                        throw new InvalidInputException("Invalid input: Please enter an integer.");
                    }
                }
            }
            System.out.println("Sum: " + sum);
        } catch (InvalidInputException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}

