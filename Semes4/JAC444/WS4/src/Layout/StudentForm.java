package Layout;

import Student.Student;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.ArrayList;

import static Student.Utils.getInt;

public class StudentForm extends JFrame {
    private JPanel mainPanel;
    private JButton addStudent;
    private JButton showAllStudent;
    private JTextArea textArea;
    private static ArrayList<Student> students = new ArrayList<Student>();


    public StudentForm() {
        super("Student Management");

        addStudent.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    int check = 0;
                    File file = new File("data.bin");
                    FileOutputStream fos = new FileOutputStream(file);
                    ObjectOutputStream oos = new ObjectOutputStream(fos);
                    while (check == 0) { //if user click yes, will return 0. No will return 1.
                        String id = JOptionPane.showInputDialog("Enter Student ID: ", JOptionPane.INFORMATION_MESSAGE);
                        int stdID = 0;
                        if (id != null) { //if it is not a number or negative, user must enter again
                            stdID = getInt(id);
                            while (stdID <= 0 || existsStudent(stdID)) { // student ID must be unique.
                                if (stdID <= 0) {
                                    id = JOptionPane.showInputDialog("ID must be a number and positive. Enter again: ", JOptionPane.WARNING_MESSAGE);
                                    stdID = getInt(id);
                                }
                                if (existsStudent(stdID)) {
                                    id = JOptionPane.showInputDialog("Student ID exists. Please select another: ", JOptionPane.WARNING_MESSAGE);
                                    stdID = getInt(id);
                                }
                            }
                        } else {
                            break;
                        }

                        String firstName = JOptionPane.showInputDialog("Enter First Name: ", JOptionPane.INFORMATION_MESSAGE);
                        if (firstName == null) { //if user click cancel, it will go back to main menu
                            break;
                        }
                        String lastName = JOptionPane.showInputDialog("Enter Last Name: ", JOptionPane.INFORMATION_MESSAGE);
                        if (lastName == null) { //if user click cancel, it will go back to main menu
                            break;
                        }
                        String numOfCourse = JOptionPane.showInputDialog("How Many Courses a student enrolled: ", JOptionPane.INFORMATION_MESSAGE);
                        if (numOfCourse == null) { //if user click cancel, it will go back to main menu
                            break;
                        }
                        int numOfCourseInt = 0;
                        if (numOfCourse != null) {
                            numOfCourseInt = getInt(numOfCourse); //if it is not a number or negative, user must enter again
                            while (numOfCourseInt < 0) {
                                numOfCourse = JOptionPane.showInputDialog("Number of Course must be a number and positive or 0. Enter again: ", JOptionPane.WARNING_MESSAGE);
                                numOfCourseInt = getInt(numOfCourse);
                            }
                        } else {
                            break;
                        }
                        ArrayList<String> courses = new ArrayList<String>();

                        for (int i = 0; i < numOfCourseInt; i++) {
                            String course = JOptionPane.showInputDialog("Enter the course num " + (i + 1) + ": ", JOptionPane.INFORMATION_MESSAGE);
                            courses.add(course);
                        }

                        Student student = new Student(stdID, firstName, lastName, courses);
                        students.add(student);
                        oos.writeObject(student);
                        oos.flush();

                        JOptionPane.showMessageDialog(null, "Added Student!", "Done", JOptionPane.PLAIN_MESSAGE);

                        check = JOptionPane.showConfirmDialog(null, "Do you want to continue?", "Add New Student", JOptionPane.YES_NO_OPTION); //if user click yes, will return 0. No will return 1.
                    }
                    oos.close();
                    fos.close();
                } catch (IOException error) {
                    System.out.println(error.getMessage() + "\n");
                }
            }
        });
        showAllStudent.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    File file = new File("data.bin");
                    FileInputStream fis = new FileInputStream(file);
                    ObjectInputStream ois = new ObjectInputStream(fis);
                    Student student;
                    textArea.setText(null);
                    boolean check = true;
                    while (check) {//infinity loop
                        try {
                            if ((student = (Student) ois.readObject()) != null) {
                                textArea.append(student.toString()+"\n");
                            }
                        } catch (EOFException error) {
                            check = false; //if reach the end of file, we will stop the loop.
                        }
                    }
                    ois.close();
                    fis.close();
                } catch (FileNotFoundException error) {
                    System.out.println("fnfe" + error.getMessage());
                } catch (IOException error) {
                    System.out.println("ioe" + error.getMessage());
                } catch (ClassNotFoundException error) {
                    System.out.println("cnfe" + error.getMessage());
                }
            }
        });

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setContentPane(mainPanel);
        this.pack();
    }

    public static void main(String[] args) {
        JFrame frame = new StudentForm();
        frame.setSize(420, 420);
        frame.setVisible(true);
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
