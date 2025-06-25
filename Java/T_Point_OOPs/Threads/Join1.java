public class Join1 extends Thread{    
    public void run(){    
     for(int i=1;i<=5;i++){    
      try{    
       Thread.sleep(500);    
      }catch(Exception e){System.out.println(e);}    
     System.out.println(i);    
     }    
    }    
   public static void main(String args[]){    
    Join1 t1=new Join1();    
    Join1 t2=new Join1();    
    Join1 t3=new Join1();    
    t1.start();    
    try{    
     t1.join(2000);    
    }catch(Exception e){System.out.println(e);}    
       
    t2.start();    
    t3.start();    
    }    
}
