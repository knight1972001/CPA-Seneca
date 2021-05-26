import java.util.Locale;
//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NBB
// Day:			    May 25th 2020
// Workshop:       	1
//==============================================
public class Palindrome {
    public static void main(String[] args) {
        for (String input : args) {
            if (isPalindrome(input)) { //call the isPalindrome to check is it a Palindrome or not!
                System.out.println(input + " is a Palindrome!");
            } else {
                System.out.println(input + " is not a Palindrome!");
            }
        }
    }

    public static boolean isPalindrome(String input) {
        if (input.length() > 0) { //check the argument is empty or not!
            Stack object = new Stack();
            object.push(input); //use push(String input) to set the value of array.
            StringBuilder reversedString = new StringBuilder();
            while (!object.empty()) {
                reversedString.append(object.pop()); //StringBuilder will append each character from last to the beginning.
                                                    // We will have a reversed string.
                                                    // Until the original array will be empty, the while loop will be stop followed.
            }

            if (input.equalsIgnoreCase(reversedString.toString())) { //ignore the Case like: "Madam" is Palindrome. Unless "Madam" will be not a Palindrome!
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
}
