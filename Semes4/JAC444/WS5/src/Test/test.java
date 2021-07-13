package Test;

import java.util.ArrayList;

public class test {
    public static void main(String[] args) {
        ArrayList<Integer> array = new ArrayList<Integer>();
        array=getArrayScreen();

        for(int i=0;i<array.size();i++) {
            System.out.println(array.get(i));
        }
    }

    public static int getRandomInt(int min,int max) {
        min = (int) Math.ceil(min);
        max = (int) Math.floor(max);
        return (int) Math.floor(Math.random() * (max - min) + min); //The maximum is exclusive and the minimum is inclusive
    }

    public static boolean checkCheat(ArrayList<Integer> arr){
        if(arr.size() == 0){
            return false;
        }else{
            for(int i=0;i<arr.size(); i++){
                int check= arr.get(i);
                for(int x=i+1;x<arr.size();x++){
                    if(check==arr.get(x)){
                        System.out.println("LAP");
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public static ArrayList<Integer> getArrayScreen(){
        ArrayList<Integer> screenNum = new ArrayList<Integer>();
        while(screenNum.size() != 5){
            int num=getRandomInt(0,9);
            if(!checkCheat(screenNum)){
                System.out.println(num);
                screenNum.add(num);
            }
        }
        return screenNum;
    }
}
