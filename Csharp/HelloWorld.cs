using System;

public class HelloWorld{
    public static void Main(){
        System.Console.WriteLine("Hello World");
        System.Console.WriteLine("My first .EXE");
        System.Console.WriteLine("Passcode: \n>");
	    string line = System.Console.ReadLine();
	    if(line == "Paragon"){
	        System.Console.WriteLine("Correct passcode!");
	    }
        
        //Add args class and playing with it
        args man = new args();
        System.Console.WriteLine(man.getInt());
        
        //Well since the args class worked I want to play with multiple constructors
        //So I built the foo class to play with this
        int[] test = new int[10];
        for(int i = 0; i < test.Length; ++i) test[i] = i;
        foo dave = new foo(test);
        System.Console.WriteLine(dave.getIntArrayAt(3));
    }
}

public class args{                                          //Simple class to test the use of the constructor
    public static int argsInt;
    
    public args(){                                              //Simple constructor named args
        argsInt = 5;                                                //Sets this in to 5
    }

    public int getInt(){                                        //Returns the int to user
        return argsInt;
    }
}

public class foo{                                           //Simple class to test the use of multiple constructors while playing
    public const int CAPACITY = 500;                        //around with int[]
    public int[] intArray;
    public static int length;

    public foo(){
        intArray = new int[CAPACITY];                               //Makes new int[] with a size of CAPACITY
        length = 0;                                                 //Sets the length to be 0 since this array is empty
    }
    public foo(int[] para){                                     //This is the constructor for an int[]
        intArray = new int[CAPACITY];                               //Makes new int[] with a size of CAPACITY
        for(int i = 0; (i < para.Length && i<500) ; ++i){           //For loop for turn para into the foo intArray
//          System.Console.WriteLine(para[i]);                      //Added this for debugging
            intArray[i] = para[i];                                  //para is being put into intArray
        }
        if(para.Length < 500) length = para.Length;                 //Sets the length to para
        else length = 500;                                          //Makes sure to not go over the CAPACITY
    }

    public int getIntArrayAt(int local){                        //Returns intArray[local]
        return intArray[local];                                     //"" ""
    }
}

//=================================================================
//
// NOT SURE WHY I INCLUDED THIS IN THE HW.CS FILE BUT IT WAS ALONG THE LINES
// OF USING THIS TO HELP FURTHER THE UNDERSTANDING OF C#
//
// ================================================================


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
// ALSO WE WILL NOT BE USING XNA FOR THIS PROJECT BUT
// OPENGL SO START TAKING A LOOK INTO THAT AS WELL 
//
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
