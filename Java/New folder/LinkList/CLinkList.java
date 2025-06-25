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
    CircularLinkedList(){
        last=null;
    }
    CircularLinkedList(int data){
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
            System.out.println("Create a list first!!");
            return;
        }    
        System.out.print("Linked List :  ");
        // for(Node top=last.next;top!=last;top=top.next){
        //     System.out.print(top.data+" ");
        // }
        // System.out.println(last.data);
        Node top=last;
        do{
            System.out.print(top.data+" ");
            top=top.next;
        }while(top!=last);
        System.out.println();
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
}
class CLinkList{
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        CircularLinkedList linklist=new CircularLinkedList();
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
                case 9: if(linklist.last==null){
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