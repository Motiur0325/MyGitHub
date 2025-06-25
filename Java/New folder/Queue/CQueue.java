import java.util.Scanner;

class Circular_Queue_Array{
    int front,rear,size;
    int[] queue;
    Circular_Queue_Array(int size){
        this.size=size;
        queue=new int[size];
        this.front=-1;
        this.rear=-1;
    }
    public void enque(int data){
        if(front==-1){
            front=0;
            rear=0;
            this.queue[rear]=data;
        }
        else if(front==(rear+1)%size){
            System.out.println("Queue is full!!");
        }
        else{
            rear=(rear+1)%size;
            queue[rear]=data;
        }
    }
    public void deque(){
        if(front==-1){
            System.out.println("Queue is Empty!!");
        }
        else if(front==rear&&front!=-1){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%size;
        }
    }
    public void display(){
        if(front==-1){
            System.out.println("Queue is Empty!!");
            return;
        }
        System.out.print("Queue :  ");
        for(int i=front;i!=rear;i=(i+1)%size){
            System.out.print(this.queue[i]+" ");
        }
        System.out.println(this.queue[rear]);
    }
}
public class CQueue{
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the size of Queue :  ");
        Circular_Queue_Array queue=new Circular_Queue_Array(sc.nextInt());
        while(true){
            System.out.printf("\nPress any key to exit....\n1.Enqueue\n2.Dequeue\n3.Display\t\tEnter Choice :  ");
            char ch=sc.next().charAt(0);
            int choice=Character.getNumericValue(ch);
            System.out.println();
            switch(choice){
                case 1: System.out.print("Enter Data to be inserted :  ");
                        queue.enque(sc.nextInt());
                        break;
                case 2: queue.deque();
                        break;
                case 3: queue.display();
                        break;
                default:System.exit(0);
            }
        }
    }
}