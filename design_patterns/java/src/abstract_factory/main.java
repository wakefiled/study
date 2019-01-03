package abstract_factory;
import concretes.Product;

public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Product computer = ProductFactory.getProduct(new ComputerFactory("LG-Gram",200,"i7","8G","256G"));
		Product camera = ProductFactory.getProduct(new CameraFactory("Nikon",70,"16.9m","Single-lens"));
		
		System.out.println(computer.toString());
		System.out.println(camera.toString());
	}
}
