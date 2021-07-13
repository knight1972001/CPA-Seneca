//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NBB
// Day:			    Jun 22th 2020
// Workshop:       	4
//==============================================
package Student;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

import static Student.Utils.*;

public class AddStudent {
    private static ArrayList<Student> students = new ArrayList<Student>();

    public static void main(String[] args) {
        try{
            File file=new File("data.bin");
            FileOutputStream fos=new FileOutputStream(file);
            ObjectOutputStream oos=new ObjectOutputStream(fos);
            Scanner input = new Scanner(System.in);
            System.out.print("Do you want to add Student (Y/N): ");
            while (hasOrNot()) {
                System.out.print("Enter student ID: ");
                int stdID = getInt("a"); //must be an Integer
                while (stdID <= 0 || existsStudent(stdID)) { // student ID must be unique.
                    if (stdID <= 0) {
                        System.out.print("ID must be a positive number. Enter again: ");
                        stdID = getInt("a");
                    }
                    if (existsStudent(stdID)) {
                        System.out.print("Error: Student ID exists. Please select another: ");
                        stdID = getInt("a");
                    }
                }
                System.out.print("Enter First Name: ");
                String firstName = input.nextLine();
                System.out.print("Enter Last Name: ");
                String lastName = input.nextLine();
                System.out.print("How many courses a student enrolled: ");
                int numOfCourse = getInt("a");
                ArrayList<String> courses = new ArrayList<String>();
                for (int i = 0; i < numOfCourse; i++) {
                    System.out.print("Enter the course num " + (i + 1) + ": ");
                    String course = input.nextLine();
                    courses.add(course);
                }
                Student student = new Student(stdID, firstName, lastName, courses);
                students.add(student);
                oos.writeObject(student);
                oos.flush();
                System.out.println("Added new student!\n");
                System.out.print("Do you want to add Student (Y/N): ");
            }
            input.close();
            oos.close();
            fos.close();
            System.out.println("All data saved! Thank you.");
        } catch(IOException e){
            System.out.println(e.getMessage()+"\n");
        }
    }

    public static boolean existsStudent(int id) {
        if (students.size() == 0) { // if there is no student, we can choose any id.
            return false;
        } else {
            for (Student student : students) {
                if (student.getStdID() == id) {
                    return true;
                }
            }
            return false;
        }
    }
}
