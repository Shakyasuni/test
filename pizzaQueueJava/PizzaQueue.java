
public class PizzaQueue
{
    Pizza head, tail;

    public PizzaQueue(Pizza head, Pizza tail)
    {
        this.head = head;
        this.tail = tail;
    }

    public void enqueue(Pizza thispizza)
    {
        if (head == null) 
        {head = thispizza;}
        else 
        {tail.next = thispizza;}
        tail = thispizza;
        return;
    }
    
    public Pizza dequeue()
    {
        Pizza pizzatodeliver = null;
        if (head != null)
        {
        	pizzatodeliver = head;
        	head = head.next;
        }
        if (head == null) 
        	tail = null;
        return pizzatodeliver;
    }
    
    public void deliver()
    {
        Pizza thispizza = this.dequeue();
        if (thispizza == null)
        {
        	System.out.println("No deliveries pending"); 
        	return;
        }
        System.out.println("Deliver a pizza with " + thispizza.toppings + " to " + thispizza.address);
    }
    
    static void onestore() {
    	Pizza first = null, last = null;
    	
        PizzaQueue myQueue = new PizzaQueue(first, last);
        
        myQueue.enqueue(new Pizza("pepperoni", "1234 Bobcat Trail"));
        myQueue.enqueue(new Pizza("sausage", "2345 University Drive"));
        myQueue.deliver();
        myQueue.enqueue(new Pizza("extra cheese", "3456 Rickster Road"));
        myQueue.enqueue(new Pizza("everything", "4567 King Court"));
        myQueue.enqueue(new Pizza("coffee beans", "5678 Java Circle"));
        myQueue.deliver();
        myQueue.deliver();
        myQueue.deliver();
        myQueue.deliver();
        myQueue.deliver();
    }
    
    static void twostores() {
    	Pizza s1f = null, s1l = null;
    	Pizza s2f = null, s2l = null;
    	
        PizzaQueue firstQueue = new PizzaQueue(s1f, s1l);
        PizzaQueue secondQueue = new PizzaQueue(s2f, s2l);
        
        firstQueue.enqueue(new Pizza("111111", "111111111111111"));
        secondQueue.enqueue(new Pizza("AAAAAA", "AAAAAAAAAAAAAAA"));
        firstQueue.enqueue(new Pizza("222222", "222222222222222"));
        secondQueue.enqueue(new Pizza("BBBBBB", "BBBBBBBBBBBBBBB"));
        firstQueue.enqueue(new Pizza("333333", "333333333333333"));
        secondQueue.enqueue(new Pizza("CCCCCC", "CCCCCCCCCCCCCCC"));
        firstQueue.enqueue(new Pizza("444444", "444444444444444"));
        secondQueue.enqueue(new Pizza("DDDDDD", "DDDDDDDDDDDDDDD"));
        firstQueue.enqueue(new Pizza("555555", "555555555555555"));
        secondQueue.enqueue(new Pizza("EEEEEE", "EEEEEEEEEEEEEEE"));
        firstQueue.enqueue(new Pizza("666666", "666666666666666"));
        secondQueue.enqueue(new Pizza("FFFFFF", "FFFFFFFFFFFFFFF"));
        	
        firstQueue.deliver();
        firstQueue.deliver();
        firstQueue.deliver();
        firstQueue.deliver();
        firstQueue.deliver();
        firstQueue.deliver();
        firstQueue.deliver();

        secondQueue.deliver();
        secondQueue.deliver();
        secondQueue.deliver();
        secondQueue.deliver();
        secondQueue.deliver();
        secondQueue.deliver();
        secondQueue.deliver();	
    }
    
    public static void main(String args[])
    {
    	onestore();
    	//twostores();
    }
}
