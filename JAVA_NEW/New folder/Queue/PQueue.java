import java.util.Scanner;
import java.util.PriorityQueue;

class PQueue{
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        PriorityQueue<Integer> queue=new PriorityQueue<>();
        queue.add(10);
        queue.add(30);
        queue.add(70);
        queue.add(20);
        queue.add(50);
        System.out.println(queue.peek());
        while(!queue.isEmpty()){
            System.out.println(queue.poll());
        }
    }
}