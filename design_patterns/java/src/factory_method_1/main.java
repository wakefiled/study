package factory_method_1;
import concretes.*;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Creator factory = new ConcreteCreator();
		Product p1 = factory.createProduct("computer","LG-Gram", 120);
		Product p2 = factory.createProduct("camera", "Nikon", 75);
		
		System.out.println(p1);
		System.out.println(p2);
	}
}
