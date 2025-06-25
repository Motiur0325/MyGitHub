import my.dsa.CircularLinkedList;

class CLinkList_Class{
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