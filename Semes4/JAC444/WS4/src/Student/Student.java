//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NBB
// Day:			    Jun 22th 2020
// Workshop:       	4
//==============================================
package Student;

import java.io.Serializable;
import java.util.ArrayList;

public class Student implements Serializable {
    private int stdID;
    private String firstName;
    private String lastName;

    @Override
    public String toString() {
        String result = "";
        result+="ID: "+getStdID()+" | Name: "+getFirstName()+" "+getLastName()+" | Courses: ";
        if(getCourses().size()==0){
            result+="[ No course enrolled ]";
        }else{
            result+="[ ";
            for(int i=0;i<getCourses().size();i++){
                result+=getCourses().get(i);
                if((i+1)<getCourses().size()){
                    result+=", ";
                }
            }
            result+=" ]";
        }

        return result;
    }

    ArrayList<String> courses = new ArrayList<String>();

    public Student(int stdID, String firstName, String lastName, ArrayList<String> courses) {
        if(stdID!=0 && firstName!=null && lastName!=null){
            this.stdID = stdID;
            this.firstName = firstName;
            this.lastName = lastName;
            this.courses = courses;
        }
    }

    public int getStdID() {
        return stdID;
    }

    public void setStdID(final int stdID) {
        this.stdID = stdID;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(final String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(final String lastName) {
        this.lastName = lastName;
    }

    public ArrayList<String> getCourses() {
        return courses;
    }

    public void setCourses(final ArrayList<String> courses) {
        this.courses = courses;
    }
}
