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
/*
protected override void Draw(GameTime gametime){
    graphics.GraphicsDevice.Clear(Color.CornflowerBlue);

    spriteBatch.Begin(SpriteSortMode.BackToFront, BlendState.AlphaBlend);
    spriteBatch.Draw(myTexture, spritePosition, Color.White);
    spriteBatch.End();

    base.Draw(gametime);
}*/
