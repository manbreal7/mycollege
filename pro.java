import java.util.Scanner;

public class pro {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter a five-letter word: ");
        String inputWord = scanner.nextLine();

        if (inputWord.length() != 5) {
            System.out.println("Please enter a five-letter word.");
        } else {
            System.out.println("Three-letter words that can be derived from '" + inputWord + "':");
            generateThreeLetterWords("", inputWord);
        }

        scanner.close();
    }

    public static void generateThreeLetterWords(String prefix, String remaining) {
        if (prefix.length() == 3) {
            System.out.println(prefix);
        } else {
            for (int i = 0; i < remaining.length(); i++) {
                char currentChar = remaining.charAt(i);
                String newPrefix = prefix + currentChar;
                String newRemaining = remaining.substring(0, i) + remaining.substring(i + 1);
                generateThreeLetterWords(newPrefix, newRemaining);
            }
        }
    }
}
