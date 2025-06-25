// import my.dsa.Stack_Array;
import java.util.Stack;

class Stack_Class{
    public static void main(String[]args){
        // Stack_Array stack=new Stack_Array(5);
        // System.out.println(stack.isEmpty());
        // stack.push(5);
        // stack.push(6);
        // stack.display();
        // stack.pop();
        // stack.push(7);
        // stack.push(8);
        // stack.top();
        // stack.display();
        // stack.push(10);
        // stack.push(11);
        // stack.display();
        // stack.isEmpty();
        Stack<Integer> stack=new Stack<>();
        stack.push(10);
        stack.push(20);
        stack.push(30);
        System.out.println(stack.peek());
        for(Integer x:stack){
            System.out.print(x+" ");
        }
        System.out.println(stack.search(10));
        System.out.println("Popped value :  "+stack.pop());
        System.out.println(stack.search(10));
    }
}