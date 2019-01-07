package singleton;

public class StaticBlockInitialization {
	private static StaticBlockInitialization instance;
	private StaticBlockInitialization() {}
	
	static {
		try {
			System.out.println("instance create...");
			instance = new StaticBlockInitialization();
		}
		catch(Exception e)
		{
			throw new RuntimeException("Exception creating Static Block Initailization.");
		}
	}
	
	public static StaticBlockInitialization getInstance()
	{
		return instance;
	}
	
	public void print()
	{
		System.out.println("instance hashCode > " + instance.hashCode());
	}
	
	public static void main(String args[])
	{
		System.out.println("Start..");
		StaticBlockInitialization.getInstance().print();
		System.out.println("End..");
	}
}
