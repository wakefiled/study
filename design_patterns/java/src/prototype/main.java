package prototype;
import concretes.*;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub		
		ProductFactory pf = new ProductFactory();
		pf.loadData();
		
		for(Product p : pf.getProductList())
		{
			System.out.println(p);
		}
		
		ProductFactory temp = (ProductFactory)pf.clone();
		for(Product p : temp.getProductList())
		{
			System.out.println(p);
		}
	}
}
