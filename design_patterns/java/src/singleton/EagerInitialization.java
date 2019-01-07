package singleton;

public class EagerInitialization {
	private static EagerInitialization instance = new EagerInitialization();
	
	private EagerInitialization() {
		System.out.println("Call EagerInitialization constructor.");
	}
	
	public static EagerInitialization getInstance() {
		return instance;
	}
	
	public void print() {
		System.out.println("instance hashCode > " + instance.hashCode());
	}
	
	public static void main(String args[])
	{
		System.out.println("Start..");
		EagerInitialization.getInstance().print();
		System.out.println("End..");
	}
}
