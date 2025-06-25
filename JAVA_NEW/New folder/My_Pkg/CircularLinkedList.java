import java.util.Scanner;

class Node{
    int data;
    Node next;
    Node(int data){
        this.data=data;
        this.next=null;
    }
}
class CircularLinkedList{
    Node last;
    int count=0;
    Scanner sc=new Scanner(System.in);
    public CircularLinkedList(){
        last=null;
    }
    public CircularLinkedList(int data){
        last.data=data;
        last.next=last;
    }
    public void insertAtBeg(int data){
        Node temp=new Node(data);
        if(last==null){
            last=temp;
            last.next=temp;
        }
        else{
            temp.next=last.next;
            last.next=temp;
        }
        count+=1;
    }
    public void insertAtPos(int data){
        if(last==null){
            insertAtBeg(data);
            return;
        }
        System.out.print("Enter the position :  ");
        int pos=sc.nextInt();
        if(pos>count+1||pos<1){
            System.out.println("Invalid Position");
        }
        else if(pos==1){
            insertAtBeg(data);
        }
        else if(pos==count+1){
            insertAtEnd(data);
        }
        else{
            Node first=null;
            Node second=last.next;
            while(pos>1){
                first=second;
                second=second.next;
                pos-=1;
            }
            Node temp=new Node(data);
            first.next=temp;
            temp.next=second;
            count+=1;
        }
    }
    public void insertAtEnd(int data){
        Node temp=new Node(data);
        if(last==null){
            last=temp;
            last.next=temp;
        }
        else{
            temp.next=last.next;
            last.next=temp;
            last=temp;
        }
        count+=1;
    }
    public void display(){
        if(last==null){
            deleteAtBeg();
            return;
        }
        System.out.print("Linked List :  ");
        for(Node top=last.next;top!=last;top=top.next){
            System.out.print(top.data+" ");
        }
        System.out.println(last.data);
    }
    public void count(){
        System.out.println("Number of Nodes :  "+this.count);
    }
    public void deleteAtBeg(){
        if(last==null){
            System.out.println("List is Empty!!");
        }
        else if(last.next==last){
            last=null;
            count=0;
        }
        else{
            last.next=last.next.next;
            count-=1;
        }
    }
    public void deleteAtEnd(){
        if(last==null){
            System.out.println("List is Empty!!");
        }
        else if(last.next==last){
            last=null;
            count=0;
        }
        else{
            Node top=last.next;
            while(top.next!=last)top=top.next;
            top.next=last.next;
            last=top;
            count-=1;
        }
    }
    public void deleteAtPos(int pos){
        if(last==null){
            deleteAtBeg();
            return;
        }
        if(pos>count||pos<1){
            System.out.println("Invalid Position");
        }
        else if(pos==1){
            deleteAtBeg();
        }
        else if(pos==count){
            deleteAtEnd();
        }
        else{
            Node first=null;
            Node second=last.next;
            while(pos>1){
                first=second;
                second=second.next;
                pos-=1;
            }
            first.next=second.next;
            count-=1;
        }
    }
    public int search(int data){
        int loc=1;
        if(last.data==data)return this.count;
        for(Node top=last.next;top!=last;top=top.next){
            if(top.data==data)return loc;
            loc+=1;
        }
        return -1;
    }
    public static void main(String[]args){
        CircularLinkedList linklist=new CircularLinkedList();
        linklist.display();
        linklist.insertAtBeg(1);
        linklist.insertAtEnd(2);
        linklist.display();
        linklist.count();
        linklist.deleteAtBeg();
        linklist.insertAtBeg(0);
        linklist.insertAtPos(1);
        linklist.insertAtEnd(3);
        linklist.display();
        linklist.search(3);
    }
}