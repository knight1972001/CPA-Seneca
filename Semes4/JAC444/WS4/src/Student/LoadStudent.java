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

public class LoadStudent {
    public static void main(String[] args) {
        try{
            File file=new File("data.bin");
            FileInputStream fis = new FileInputStream(file);
            ObjectInputStream ois = new ObjectInputStream(fis);
            Student student;
            boolean check=true;
            while(check) {//infinity loop
                try{
                    if((student=(Student) ois.readObject()) != null) {
                        System.out.println(student.toString());
                    }
                }catch (EOFException e){
                    check=false; //if reach the end of file, we will stop the loop.
                }
            }
            ois.close();
            fis.close();
        } catch(FileNotFoundException e) {
            System.out.println("fnfe"+e.getMessage());
        } catch(IOException e) {
            System.out.println("ioe"+e.getMessage());
        } catch (ClassNotFoundException e) {
            System.out.println("cnfe"+e.getMessage());
        }

    }
}
