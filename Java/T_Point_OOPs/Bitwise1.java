public class Bitwise1 {
    /**
     * @param args
     */
    public static void main(String[] args) {
        int a=9,b=10,c=9;
        c&=a;
        a&=b;
        System.out.println(a+" "+b+" "+c);
        int x=2;
        x<<=1;
        x>>=1;
        System.out.println(x);
    }
}
