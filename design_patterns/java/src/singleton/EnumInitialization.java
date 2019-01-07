package singleton;

public enum EnumInitialization {
	INSTANCE;
	static String test = "";
	public static EnumInitialization getInstance() {
		test = "Hello, world.";
		return INSTANCE;
	}
	
	public void print()
	{
		System.out.println("instance hashCode > " + INSTANCE.test);
	}
	
	public static void main(String args[])
	{
		System.out.println("Start..");
		EnumInitialization.getInstance().print();
		System.out.println("End..");
	}
}
