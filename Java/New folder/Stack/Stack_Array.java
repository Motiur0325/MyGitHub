package my.dsa;

public class Stack_Array{
    int top=-1;
    int []stack;
    int size;
    public Stack_Array(int size){
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