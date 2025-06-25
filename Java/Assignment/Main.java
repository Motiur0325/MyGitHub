class Calculate {
    protected int n1, n2;

    // Method to accept integer n1 and n2
    void accept() {
        // You can use Scanner to accept input from the user
        // For simplicity, let's assume the values here
        n1 = 36;
        n2 = 48;
    }

    // Method to display n1 and n2 with suitable messages
    void display() {
        System.out.println("Number 1: " + n1);
        System.out.println("Number 2: " + n2);
    }
}

class Hcf extends Calculate {
    private int h;

    // Method to find and store HCF of n1 and n2 in h
    void findhcf() {
        int min = Math.min(n1, n2);
        h = 1;
        for (int i = 1; i <= min; i++) {
            if (n1 % i == 0 && n2 % i == 0) {
                h = i;
            }
        }
    }

    // Method to display h with a suitable message
    void show() {
        System.out.println("HCF of " + n1 + " and " + n2 + " is: " + h);
    }
}

public class Main {
    public static void main(String[] args) {
        // Create an object of the Hcf class
        Hcf hcfObj = new Hcf();

        // Call the accept method to set values for n1 and n2
        hcfObj.accept();

        // Display the values of n1 and n2
        hcfObj.display();

        // Find and display the HCF
        hcfObj.findhcf();
        hcfObj.show();
    }
}