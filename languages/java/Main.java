public class Main {
    public static void main(String[] args) {
        int num;  // uninitialized local variable
        System.out.println(num);  // Compilation error: variable num might not have been initialized
    }
}