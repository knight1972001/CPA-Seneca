//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NBB
// Day:			    Jun 22th 2020
// Workshop:       	4
//==============================================
package Student;

import java.util.Scanner;

public class Utils {
    public static double getDouble(String in) {
        boolean check = true;
        double number = 0;
        while (check) {

            if (!in.contains("f")) {
                try {
                    number = Double.parseDouble(in);
                    check = false;
                } catch (NumberFormatException e) {
                    return -1;
                } catch (Exception e) {
                    e.printStackTrace();
                }
            } else {
                return -1;
            }
        }
        return number;
    }

    public static int getInt(String in) {
        int result = 0;
        int check = 0;
        do {
            double number = getDouble(in);
            if (((int) number % number) == 0 || (int) number == 0) {
                result = (int) number;
                check = 1;
            } else {
                return -1;
            }
        } while (check == 0);
        return result;
    }

    public static boolean hasOrNot() {
        Scanner input = new Scanner(System.in);
        boolean has = false;
        boolean check = false;
        do {
            String function = input.nextLine();
            if (function.equals("Y") || function.equals("N") || function.equals("y") || function.equals("n")) {
                has = function.equals("Y") || function.equals("y");
                check = true;
            } else {
                System.out.print("The answer must be Y or N. Re-Enter: ");
                check = false;
            }
        } while (!check);
        return has;
    }
}
