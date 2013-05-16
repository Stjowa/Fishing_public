
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
}

//=========================================================
//
// FOUND THE CODE BELOW IN AN XNA GUIDE TO PROGRAMMING
// FOR US CS MAJORS YOU CAN LITERALLY SKIP TO THE 2D PART
// AND STILL UNDERSTAND THIS CODE, IT IS A LOT LIKE JAVA
// AND C++. BUT TO MAKE THIS WORK WE WILL NEED THE PROPER
// DLL FILES AMOUNG THESE AND I WILL CONT. WORKING ON THAT
//                -STEPHEN
// =======================================================


using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;
using Microsoft.Xna.Framework.Net;
using Microsoft.Xna.Framework.Storage;

namespace HelloWorldXNA{
    public class Game1 : Microsoft.Xna.Framework.Game
    {
	    GraphicsDeviceManager graphics;
	    SpriteBatch spriteBatch;
	
	    public Game1(){
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
        }

        protected override void Initialize(){
            // TODO: Add your initialization logic here
            base.Initialize();
        }

        protected override void LoadContent(){
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);
            // TODO: use this.Content to load your game content here
        }

        protected override void UnloadContent(){
            // TODO: Unload any non ContentManager content here
        }

        protected override void Update(GameTime gameTime)
        {
            // Allows the game to exit
            if (GamePad.GetState(PlayerIndex.One).Buttons.Back ==
            ButtonState.Pressed)
            this.Exit();
            // TODO: Add your update logic here
            base.Update(gameTime);
        }

        protected override void Draw(GameTime gameTime){
            GraphicsDevice.Clear(Color.CornflowerBlue);
            // TODO: Add your drawing code here
            base.Draw(gameTime);
        }
    }
}
*/
