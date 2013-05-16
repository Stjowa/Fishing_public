public class HelloWorld{
    public static void Main(){
        System.Console.WriteLine("Hello World");
        System.Console.WriteLine("My first .EXE");
        System.Console.WriteLine("Passcode: \n>");
	string line = System.Console.ReadLine();
	if(line == "Paragon"){
	    System.Console.WriteLine("Good work, it compile sir!");
	}
    }
}
