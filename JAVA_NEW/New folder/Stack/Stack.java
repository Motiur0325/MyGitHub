import java.util.Scanner;

class Stack_Array{
    int top=-1;
    int []stack;
    int size;
    Stack_Array(int size){
        this.size=size;
        stack=new int[size];
    }
    public void push(int data){
        top+=1;
        stack[top]=data;
    }
    public int pop(){
        int popped_value=stack[top];
        top-=1;
        return popped_value;
    }
    public void display(){
        System.out.print("Stack :  ");
        for(int i=top;i>=0;i--){
            System.out.print(stack[i]+" ");
        }
        System.out.println();
    }
    public int top(){
        return stack[top];
    }
    public boolean isEmpty(){
        if(top==-1)return true;
        return false;
    }
    public boolean isFull(){
        if(top==size-1)return true;
        return false;
    }
    public void changeTop(int data){
        stack[top]=data;
    }
}
// class Stack_DLinkList{
//     class Node{
//         int data;
//         Node next;
//         Node prev;
//         Node(int data){
//             this.data=data;
//             this.next=null;
//             this.prev=null;
//         }
//     }
//     int size,count;
//     Node head;
//     Stack_LinkList(int size){
//         this.size=size;
//         count=0;
//         head=null;
//     }
//     public void push(int data){
//         Node temp=new Node(data);
//         if(head==null){
//             head=temp;
//         }
//         else{
//             temp.prev=head;
//             head.next=temp;
//             head=temp;
//         }
//         count+=1;
//     }
//     public int pop(){
//         if(head==null){
//             System.out.println("Stack Underflow");
//             return -1;
//         }
//         int popped_value=head.data;
//         if(head.prev==null){
//             head=null;
//         }
//         else{
//             head=head.prev;
//             head.next=null;
//         }
//         count-=1;
//         return popped_value;
//     }
//     public void display(){
//         System.out.print("Stack :  ");
//         for(Node top=head;top!=null;top=top.prev){
//             System.out.print(top.data+" ");
//         }
//         System.out.println();
//     }
//     public int top(){
//         return head.data;
//     }
//     public boolean isEmpty(){
//         if(head==null)return true;
//         return false;
//     }
//     public boolean isFull(){
//         if(count==size)return true;
//         return false;
//     }
//     public void changeTop(int data){
//         head.data=data;
//     }
// }
class Stack_SLinkList{
    class Node{
        int data;
        Node next;
        Node(int data){
            this.data=data;
            this.next=null;
        }
    }
    int size,count;
    Node head;
    Stack_SLinkList(int size){
        this.size=size;
        count=0;
        head=null;
    }
    public void push(int data){
        Node temp=new Node(data);
        if(head==null){
            head=temp;
        }
        else{
            temp.next=head;
            head=temp;
        }
        count+=1;
    }
    public int pop(){
        if(head==null){
            System.out.println("Stack Underflow");
            return -1;
        }
        int popped_value=head.data;
        if(head.next==null){
            head=null;
        }
        else{
            head=head.next;
        }
        count-=1;
        return popped_value;
    }
    public void display(){
        System.out.print("Stack :  ");
        for(Node top=head;top!=null;top=top.next){
            System.out.print(top.data+" ");
        }
        System.out.println();
    }
    public int top(){
        return head.data;
    }
    public boolean isEmpty(){
        if(head==null)return true;
        return false;
    }
    public boolean isFull(){
        if(count==size)return true;
        return false;
    }
    public void changeTop(int data){
        head.data=data;
    }
}
public class Stack{
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the size of Stack :   ");
        // Stack_Array stack=new Stack_Array(sc.nextInt());
        Stack_SLinkList stack=new Stack_SLinkList(sc.nextInt());
        while(true){
            System.out.printf("\nPress any Key to exit....\n1.Push\n2.Pop\n3.Display\n4.Top Element\n5.stackIsEmpty\n6.stackIsFull\n7.changeTop\t\tEnter Choice :  ");
            char choice=sc.next().charAt(0);
            int ch=Character.getNumericValue(choice);
            System.out.println();
            switch(ch){
                case 1: System.out.print("Enter Data :  ");
                        if(!stack.isFull()){
                            stack.push(sc.nextInt());
                        }
                        else{
                            System.out.println("Stack is FUll!!....     Stack Overflow!!");
                        }
                        break;
                case 2: if(!stack.isEmpty()){
                            int data=stack.pop();
                            System.out.println("Popped Value :  "+data);
                        }
                        else{
                            System.out.println("Stack is Empty..  Stack Underflow!!!");
                        }
                        break;
                case 3: stack.display();
                        break;
                case 4: if(stack.isEmpty()){
                            System.out.println("No Top Element found.. Stack Empty!!");
                            break;
                        }
                        System.out.println("Top Element :  "+stack.top());
                        break;
                case 5: System.out.println("Is Stack Empty?  "+stack.isEmpty());
                        break;
                case 6: System.out.println("Is Stack Full?  "+stack.isFull());
                        break;
                case 7: if(!stack.isEmpty()){
                            System.out.print("Enter New Value for Top :  ");
                            stack.changeTop(sc.nextInt());
                        }
                        else{
                            System.out.println("No Top Element Found!!");
                        }
                        break;
                default : System.exit(0);
            }
        }
    }
}