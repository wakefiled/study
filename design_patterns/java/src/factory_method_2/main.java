package factory_method_2;
import concretes.*;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Creator factory = new BrandComputerCreator();
		Product p1 = factory.createProduct("computer","LG-Gram", 120);
		Product p2 = factory.createProduct("computer","Samsung-Ultra", 160);
		Product p3 = factory.createProduct("computer","MAC-Pro", 200);
		Product p4 = factory.createProduct("camera", "Nikon", 75);
		
		System.out.println(p1);
		System.out.println(p2);
		System.out.println(p3);
		System.out.println(p4);
	}
}
