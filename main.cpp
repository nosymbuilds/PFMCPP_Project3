/*
Project 3 - Part 1e / 5
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

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  
};

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

struct Song
{
    class Artist
    {
        std::string name = "Moby";
        int Age = 50;
        std::string birthPlace = "America";
        int yearsActive = 25;
        std::string mostPopularSong = "Porcelain";

        void performSongLive(bool tour = true);
        void recordSongInTheStudio(bool recordAlbum);
        void promoteSong(int numberOfInterviews, bool tvAppearances);
    };

    Artist artistA;

    // duration of the song
    int duration = 5;
    // tempo of the song
    int tempo = 125;
    // key of the song
    char key = 'a';
    // number of artists performing on the song
    int numOfPerformingArtists = 4;
    // record label that released the song
    std::string recordLabel = "Virgin";
    
    // play song on the radio
    void playSongOnRadio(int duration, int tempo);
    // perform song live at a concert
    void performSongLiveAtConcert(Artist artistB);
    // remix the song
    void remix(std::string title, Artist artistC, std::string recordLabel);
};

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

struct Sandwich
{
    // type of bread
    std::string bread = "brown";
    // type of fillings
    std::string fillings = "meat";
    // amount of different fillings
    int numOfFillings = 2;
    // condiment used
    std::string condiment = "mayo";
    // number of calories
    int calories = 600;

    // cause foodpoisoning
    void foodPoisoning(std::string fillings = "uncooked chicken");
    // provide a satisfying meal
    void satisfyingMeal(int calories);
    // go moldy if left uneaten
    void moldy(int daysWithoutStorage);
};

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

struct SoccerTeam
{
    class Manager
    {
        std::string name = "Pep Gaurdiola";
        int Age = 48;
        std::string birthPlace = "Spain";
        int yearsActive = 15;
        int numberOfTeamsManaged = 3;

        void trainTeam(std::string nameOfCoach, bool deligateTrainingSession);
        void signNewPlayers(std::string market, int age, std::string playerPosition);
        void speakToThePress(bool attendPressConference = true);
    };

    // number of players in squad
    int squadPlayers = 24;
    // average age of players in squad
    int averageAge = 28;
    // number of total goals scored by the team
    int totalGoalsScored = 60;
    // number of matches in the season
    int numOfMatchesToPlay = 38;
    // league position
    int leaguePosition = 4;

    // train their skills
    void trainingSession(Manager managerA);
    // win a game
    void winMatch(bool motivated);
    // move up the league table
    void changeLeaguePosition(int pointsAccquired);
};

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

struct Synth
{
    // number of oscillators
    int oscillators = 3;
    // amount of presets
    int presets = 150;
    // number of filters
    int filters = 3;
    // number of outputs
    int outputs = 2;
    // type of built-in effect
    std::string effectType = "delay";

    // output midi
    void outputMidi(int outputs);
    // filter out all frequences above 10khz
    void highCut10khz(bool filterSweepDown = true, bool adjustQFactor = true);
    // load different presets
    void loadPresets(bool loadAllPresets = false, std::string presetBankName = "Pads");
};

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

struct Seat
{
    // outer material
    std::string outerMaterial = "leather";
    // inner material
    std::string innerMaterial = "polyster";
    // how many riders it can seat
    int riders = 1;
    // comfort rating
    double comfortRating = 6.5;
    // 5) safety rating 
    double safetyRating = 9.5;

    // seat riders
    void seatRiders(int riders);
    // repel rain with its waterproof material
    void waterproof(bool applyWaterProofCoatToLeatherExterior = true);
    // provide comfort for the rider
    void comfort(int riders, double combinedWeightKG);
};

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

struct Engine
{
    // pistons
    int pistons = 2;
    // valves
    int valves = 16;
    // cyclinder head  manufacturer
    std::string cyclinderHeadManufacturer = "Suzuki";
    // quanity of oil pans
    int oilPans = 2;
    // engine block type
    std::string engineBlockType = "Combustion";

    // produce energy for the motorcycle to move
    void combust(int pistons, int valves, std::string engineBlockType);
    // lubricate itself with oil to keep the parts moving fluidly
    void lubricate(int oilPans, bool lubricateEngine);
    // burn fuel
    void burnFuel(bool burnFuel = true, bool regulateFuelIntake = true);
};

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

struct Exhaust
{
    // length in inches
    double lengthinInches = 15.4;
    // turbocharger power
    double turboChargerPower = 4.5;
    // catalytic converters
    int catalyticConverters = 1;
    // muffler type
    std::string mufflerType = "High Supression";
    // number of pipes
    int pipes = 2;

    // increase the power of the engine using a turbocharger
    void turboChargeOutput(double turboChargerPower);
    // reduce fumes using catalytic converters
    void catalyticConversion(bool performCatalyticConversion = true);
    // reduce or increase the level of noise when reving the engine
    void levelOfNoise(std::string mufflerType);
};

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

struct FuelTank
{
    // capacity in litres
    double capacityL = 8.5;
    // the type of fuel it can hold
    std::string fuel = "unleaded";
    // the min amount of fuel it can hold before it starts to effect performance
    double recommendedMinFuel = 3.5;
    // capacity sensors
    int sensors = 4;
    // material
    std::string material = "steel";

    // notify the rider when it is low on fuel
    std::string lowFuel(double recommendedMinFuel = 3.5, bool fuelIsLowerThanRecommendedAmoutn = true); // return type as std::string is ok?
    // notify the rider when the wrong type of fuel has been used
    std::string wrongFuel(int sensors = 4, std::string fuel = "unleaded", bool wrongFuelInTank = true);
    // hold fuel
    void holdFuel(double capacityL = 8.5, double recommendedMinFuel = 3.5);
};

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

struct Tyre
{
    // type of material // string
    std::string material;
    // hickness of the material // double
    double thickness;
    // average lifespan in km travelled  // double
    double lifespanKM = 2500;
    // the manufacturer // string
    double pressure = 14;
    // the type of terrain the tyre is most suited for // string
    std::string terrain;    

    // puncture
    void puncture(bool tyrePressureDroppedBelow5 = true);
    // provide support for the bike
    void supportVehicle(std::string vehicleType = "Motor Bike", bool numOfTyres = 2);
    // wear out over time
    void wear(double lifespanKM);
};

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
 
struct Motorbike
{
    // seat
    Seat seat;
    // engine 
    Engine engine;
    // exhaust 
    Exhaust exhaust;
    // fuel tank 
    FuelTank fuelTank;
    // tyre 
    Tyre tyre;

    // Move forwards when the throttle is pressed
    void move(std::string direction, int speed);
    // Stand stationary using its stand
    void stand(bool useStand = true, bool tyresMove = false);
    // Hold fuel in the fuel tank
    void holdFuel(FuelTank fuelTank, bool activateFuelSensors = true);
};

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
