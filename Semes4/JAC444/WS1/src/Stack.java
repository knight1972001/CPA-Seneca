//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NBB
// Day:			    May 25th 2020
// Workshop:       	1
//==============================================

public class Stack {
    private int length = 0;
    private char[] array;

    public void push(String input) { //push(String to set the value of array)
        if (input.length() > 0) {
            this.array = input.toCharArray();
            length = input.length();
        } else {
            System.out.println("Error, empty input!");
        }
    }

    public void push(char input) { //push(char input) will be push() function in Stack.
        if (length == 0) { //check if this array is empty, we will create a new array.
            array = new char[1];
            array[0] = input;
        } else {
            char[] temp = new char[length]; //copy of old array.
            for (int i = 0; i < temp.length; i++) {
                temp[i] = array[i];
            }
            array = new char[++length]; //re-size old array to have new size of array
            for (int i = 0; i < length - 1; i++) {
                array[i] = temp[i]; //paste the value of old array
            }
            array[length - 1] = input; //add the new value to the new array
        }
    }

    public boolean empty() {
        return length == 0;
    }

    public char peek() {
        return array[length - 1];
    }

    public char pop() {
        char[] temp = new char[length - 1]; //make a new array that was decreased the size
        char pop = array[length - 1]; //make a copy of the last value in array.
        for (int i = 0, j = 0; i < length; i++) {
            if (!(i == length - 1)) {
                temp[j++] = array[i]; //copy to temp array to re-size
            }
        }
        length--;
        array = new char[length]; //re-size an old array
        for (int i = 0; i < length; i++) {
            array[i] = temp[i]; //paste the old value to the array was popped!
        }
        return pop;
    }

    public int search(char index) {
        for (int i = 0; i < length; i++) {
            if (array[i] == index) {
                return i + 1;
            }
        }
        return -1; //if cannot found, it will return -1!
    }

    public int length() {
        return length; //get size of array!
    }
}
