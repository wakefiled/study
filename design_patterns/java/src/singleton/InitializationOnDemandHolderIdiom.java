package singleton;

public class InitializationOnDemandHolderIdiom {
	
	private InitializationOnDemandHolderIdiom() {}
	private static class Singleton{
		private static final InitializationOnDemandHolderIdiom instance = new InitializationOnDemandHolderIdiom();
	}
	
	public static InitializationOnDemandHolderIdiom getInstance()
	{
		System.out.println("create instance");
		return Singleton.instance;
	}

	public void print()
	{
		System.out.println("instance hashCode > " + Singleton.instance.hashCode());
	}
	
	public static void main(String args[])
	{
		System.out.println("Start..");
		InitializationOnDemandHolderIdiom.getInstance().print();
		System.out.println("End..");
	}
}
