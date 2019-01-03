package builder;

import concretes.Product;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ComputerBuilder builder = new ComputerBuilder();
		Director director = new Director();
		Product com1 = director.createLGGramProduct(builder);
		Product com2 = director.createMACProduct(builder);
		
		System.out.println(com1.toString());
		System.out.println(com2.toString());
	}

}
