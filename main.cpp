/*
Project 3 - Part 1d / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3. 
Part1 will be broken up into 5 separate steps 
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, 
    until the smallest object is made of up only C++ primitives and std::string. 

    Continuing the previous example:  Cell Phone

    A Cell Phone is made up of the following 5 properties/sub-objects and 3 actions:
        Display
        Memory
        CPU
        Radio
        Applications
    3 actions:
        make a call
        send a text
        run an application.

    These 5 properties can be broken down into their own sub-objects and properties. 

    If we break down the first property 'Display' into its 5 properties we get:
        brightness
        amount of power consumed.
        pixels
        width in cm
        height in cm

    the Display's brightness can be represented with a Primitive, such as a double. 

    The amount of power consumed can also be represented with a Primitive, such as a float or integer (i.e. 250mWa)
    
    The 'pixels' property must be represented with an array of Pixel instances, as the screen has more than 1 row of pixels.
        Arrays have not been discussed and can't be used in this project.
        Instead, we can use an Integer primitive to store the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed (milliwatt-hours)
        Brightness
        width in cm
        height in cm
************************

1) Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10
    example: 
        If #10's first property was 'Engine', then your `Thing 5)` will be `Engine`
        you will need to provide 5 properties and 3 member functions of that Engine object in plain English
        Remember to pick properties that can be represented with 'int float double bool char std::string'
2) write the name of the primitive type you'll be using after each property
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            width in cm (int)
            height in cm (int)

3) move Thing 5-9 to between your Thing 4 and Thing 10.
*/

/*
Thing 1) Song
5 properties:
    1) duration of the song // double
    2) tempo of the song // int 
    3) key of the song // char
    4) number of artists performing on the song // int
    5) record label that released the song // string
3 things it can do:
    1) played on the radio
    2) performed live at a concert
    3) be remixed by another artist
 */

/*
Thing 2) Sandwich
5 properties:
    1) type of bread // string
    2) type of fillings // string
    3) amount of different fillings // int
    4) condiment used // string
    5) number of calories // int
3 things it can do:
    1) cause foodpoisoning
    2) provide a satisfying meal
    3) go moldy if left uneaten
 */

/*
Thing 3) Soccer Team
5 properties:
    1) number of players in squad // int
    2) average age of players in squad // int
    3) number of total goals scored by the team // int
    4) number of matches in the season // int
    5) league position // int
3 things it can do:
    1) train their skills
    2) win a game
    3) move up the league table
 */

/*
Thing 4) Synth
5 properties:
    1) number of oscillators // int
    2) amount of presets // int
    3) number of filters // int
    4) number of outputs // int
    5) type of built-in effect // string
3 things it can do:
    1) output midi
    2) filter out all frequences above 10khz
    3) load different presets
 */

/*
Thing 5) Seat
5 properties:
    1) outer material // string
    2) inner material // string
    3) how many riders it can seat // int
    4) comfort rating // double
    5) safety rating // double
3 things it can do:
    1) seat 2 riders at the same time
    2) repel rain with its waterproof material
    3) provide comfort for the rider
 */

/*
Thing 6) Engine
5 properties:
    1) pistons // int
    2) valves // int
    3) cyclinder head manufacturer // string
    4) quanity of oil pans // int
    5) engine block type // string
3 things it can do:
    1) produce energy for the motorcycle to move
    2) lubricate itself with oil to keep the parts moving fluidly
    3) burn fuel
 */

/*
Thing 7) Exhaust
5 properties:
    1) length in inches // double
    2) turbocharger power // double
    3) catalytic converters // int
    4) muffler type // string
    5) number of pipes // int
3 things it can do:
    1) increase the power of the engine using a turbocharger
    2) reduce fumes using catalytic converters
    3) reduce or increase the level of noise when reving the engine
 */

/*
Thing 8) Fuel Tank
5 properties:
    1) capacity in litres // double
    2) the type of fuel it can hold // string
    3) the min amount of fuel it can hold before it starts to effect performance // double
    4) capacity sensors // int
    5) material // string
3 things it can do:
    1) notify the rider when it is low on fuel
    2) notify the rider when the wrong type of fuel has been used
    3) hold fuel
 */

/*
Thing 9) Tyre
5 properties:
    1) type of material // string
    2) thickness of the material // double
    3) average lifespan in km travelled  // double
    4) the manufacturer // string
    5) the type of terrain the tyre is most suited for // string
3 things it can do:
    1) puncture
    2) provide support for the bike
    3) wear out over time
 */

/*
Thing 10) Motorbike
5 properties:
    1) seat 
    2) engine 
    3) exhaust 
    4) fuel tank 
    5) tyre
3 things it can do:
    1) Move forwards when the throttle is pressed
    2) Stand stationary using its stand
    3) Hold fuel in the fuel tank
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
