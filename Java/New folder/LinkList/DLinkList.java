import java.util.Scanner;

class Node{
    int data;
    Node next;
    Node prev;
    Node(int data){
        this.data=data;
        this.prev=null;
        this.next=null;
    }
}
class DoublyLinkedList{
    Node head;
    int count=0;
    Scanner sc=new Scanner(System.in);
    DoublyLinkedList(){
        head=null;
    }
    DoublyLinkedList(int data){
        head.data=data;
        head.next=null;
        head.prev=null;
    }
    public void insertAtBeg(int data){
        Node temp=new Node(data);
        if(head==null){
            head=temp;
        }
        else{
            Node first=head;
            while(first.prev!=null)first=first.prev;
            first.prev=temp;
            temp.next=first;
        }
        count+=1;
    }
    public void insertAtPos(int data){
        if(head==null){
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
            Node second=head;
            while(pos>1){
                first=second;
                second=second.next;
                pos-=1;
            }
            Node temp=new Node(data);
            first.next=temp;
            temp.prev=first;
            temp.next=second;
            second.prev=temp;
            count+=1;
        }
    }
    public void insertAtEnd(int data){
        Node temp=new Node(data);
        if(head==null){
            head=temp;
        }
        else{
            head.next=temp;
            temp.prev=head;
            head=temp;
        }
        count+=1;
    }
    public void display(){
        System.out.print("Linked List :  ");
        for(Node top=head;top!=null;top=top.prev){
            System.out.print(top.data+" ");
        }
        System.out.println();
    }
    public void count(){
        System.out.println("Number of Nodes :  "+this.count);
    }
    public void deleteAtBeg(){
        if(head==null){
            System.out.println("List is Empty!!");
        }
        else if(head.next==null){
            head=null;
            count=0;
        }
        else{
            Node first=head;
            while(first.prev!=null)first=first.prev;
            first.next.prev=null;
            count-=1;
        }
    }
    public void deleteAtEnd(){
        if(head==null){
            System.out.println("List is Empty!!");
        }
        else if(head.next==null){
            head=null;
            count=0;
        }
        else{
            head=head.prev;
            head.next=null;
            count-=1;
        }
    }
    public void deleteAtPos(int pos){
        if(head==null){
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
            Node second=head;
            while(pos>1){
                first=second;
                second=second.next;
                pos-=1;
            }
            first.next=second.next;
            second.next.prev=first;
            count-=1;
        }
    }
    public int search(int data){
        int loc=count;
        for(Node top=head;top!=null;top=top.prev){
            if(top.data==data)return loc;
            loc-=1;
        }
        return -1;
    }
}
class DLinkList{
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        DoublyLinkedList linklist=new DoublyLinkedList();
        while(true){
            System.out.printf("\nPress any Key to exit....\n1.InsertAtBeg\n2.Insert At Position\n3.InsertAtEnd\n4.Display\n5.Count\n6.deleteAtBeg\n7.deleteAtEnd\n8.deleteAtPosition\n9.Search\t\tEnter Choice :  ");
            char choice=sc.next().charAt(0);
            int ch=Character.getNumericValue(choice);
            System.out.println();
            switch(ch){
                case 1: System.out.print("Enter Data :  ");
                        linklist.insertAtBeg(sc.nextInt());
                        break;
                case 2: System.out.print("Enter Data :  ");
                        linklist.insertAtPos(sc.nextInt());
                        break;
                case 3: System.out.print("Enter Data :  ");
                        linklist.insertAtEnd(sc.nextInt());
                        break;
                case 4: linklist.display();
                        break;
                case 5: linklist.count();
                        break;
                case 6: linklist.deleteAtBeg();
                        break;
                case 7: linklist.deleteAtEnd();
                        break;
                case 8: System.out.print("Enter the position :  ");
                        linklist.deleteAtPos(sc.nextInt());
                        break;
                case 9: if(linklist.head==null){
                            System.out.println("List Empty.");
                            break;
                        }
                        System.out.print("Enter the data to be searched :  ");
                        int loc=linklist.search(sc.nextInt());
                        if(loc==-1){
                            System.out.println("Data not found.");
                        }
                        else{
                            System.out.println("Data found at position :  "+loc);
                        }
                        break;
                default: System.exit(0);
            }
        }
    }
}