import java.lang.Thread;

class Sleep1 extends Thread{    
    Sleep1(String name){
        super(name);
    }
    public void run(){    
    //while(true){
        for(int i=1;i<5;i++){   
  // the thread will sleep for the 500 milli seconds   
        try{Thread.sleep(1000);}catch(InterruptedException e){System.out.println(e);}    
        System.out.print(i+" ");
        }  
        System.out.println();  
    //}
 }    
 public static void main(String args[]){    
  Sleep1 t1=new Sleep1("Hello");    
  Sleep1 t2=new Sleep1("World");    
     
  t1.start(); 
  System.out.println(t1.getName());   
  t2.start();    
  System.out.println(t2.getName());
 }    
}    