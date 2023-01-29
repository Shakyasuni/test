
public class Pizza
{ 
    String toppings, address;
    Pizza next;

    public Pizza(String toppings, String address)
    {
        this.toppings = toppings;
        this.address = address;
        next = null;
    }   
}
