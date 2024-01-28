import java.util.*;

public class Q6 {
    public static String getInput(){
        Scanner sc =new Scanner(System.in);
        System.out.print("Enter the String :  ");
        String str=sc.nextLine();
        sc.close();
        return str;
    }
    public static void getOutput(String str){
        System.out.println(str);
    }
    public static String strprocess(String str){
        StringBuilder result=new StringBuilder();
        for(String w : str.split(" ")){
            char[] ch=w.toCharArray();
            Arrays.sort(ch);
            char min=ch[0];
            char max=ch[w.length()-1];
            result.append(min).append(max).append(" ");
        }
        return result.toString();
    }
    public static void main(String[] args) {
        String str=getInput();
        System.out.print("Given String :  ");
        getOutput(str);
        str=strprocess(str);
        System.out.print("Sorted String :  ");
        getOutput(str);
    }
}
