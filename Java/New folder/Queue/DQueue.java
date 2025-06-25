import java.util.Scanner;

class Double_Ended_Queue_Array{
    int front,rear,size;
    int[] queue;
    Double_Ended_Queue_Array(int size){
        this.size=size;
        queue=new int[size];
        this.front=-1;
        this.rear=-1;
    }
    public void enqueFront(int data){
        if(front==-1){
            front=0;
            rear=0;
            this.queue[front]=data;
        }
        else if(front==(rear+1)%size){
            System.out.println("Queue is full!!");
        }
        else{
            if(front==0){
                front=size-1;
            }
            else{
                front-=1;
            }
            queue[front]=data;
        }
    }
    public void enqueRear(int data){
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
    public void dequeFront(){
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
    public void dequeRear(){
        if(front==-1){
            System.out.println("Queue is Empty!!");
        }
        else if(front==rear&&front!=-1){
            front=-1;
            rear=-1;
        }
        else{
            if(rear==0){
                rear=size-1;
            }
            else{
                rear-=1;
            }
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
public class DQueue{
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the size of Queue :  ");
        Double_Ended_Queue_Array queue=new Double_Ended_Queue_Array(sc.nextInt());
        while(true){
            System.out.printf("\nPress any key to exit....\n1.EnqueFront\n2.EnqueRear\n3.DequeFront\n4.DequeRear\n5.Display\t\tEnter Choice :  ");
            char ch=sc.next().charAt(0);
            int choice=Character.getNumericValue(ch);
            System.out.println();
            switch(choice){
                case 1: System.out.print("Enter Data to be inserted :  ");
                        queue.enqueFront(sc.nextInt());
                        break;
                case 2: System.out.print("Enter Data to be inserted :  ");
                        queue.enqueRear(sc.nextInt());
                        break;
                case 3: queue.dequeFront();
                        break;
                case 4: queue.dequeRear();
                        break;
                case 5: queue.display();
                        break;
                default:System.exit(0);
            }
        }
    }
}