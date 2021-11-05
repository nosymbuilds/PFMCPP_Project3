 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
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

struct Song
{
    struct Artist
    {
        std::string name = "Moby";
        int age = 50;
        std::string nationality = "American";
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
    float tempo = 125.f;
    // key of the song
    char key = 'a';
    // number of artists performing on the song
    int performingArtists = 4;
    // record label that released the song
    std::string recordLabel = "Virgin";
    
    // play song on the radio
    void playSongOnRadio(int duration, float tempo);
    // perform song live at a concert
    void performSongLiveAtConcert(Artist artistB, std::string concert);
    // remix the song
    void remixSong(std::string title, Artist artistC, std::string recordLabel);
};

/*
Thing 2) Sandwich
5 properties:
    1) type of bread // string
    2) type of fillings // string
    3) number of fillings // int
    4) condiment // string
    5) number of calories // int
3 things it can do:
    1) cause foodpoisoning
    2) provide a satisfying meal
    3) go moldy if left uneaten
 */

struct Sandwich
{
    // type of bread
    std::string bread = "Brown";
    // number of fillings
    int numOfFillings = 1;
    // fillings
    std::string filling = "Salami";
    // condiment
    std::string condiment = "Mayo";
    // number of calories
    int calories = 600;

    // cause foodpoisoning
    void causeFoodPoisoning(bool uncookedMeat = true);
    // provide a satisfying meal
    void provideSatisfyingMeal(double levelOfSatisfaction, int calories);
    // go moldy if left uneaten
    void goMoldy(int daysWithoutStorage);
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
    1) train skills
    2) acquire injuries
    3) receive awards
 */

struct SoccerTeam
{
    struct Player
    {
        std::string name = "Phil Foden";
        int age = 21;
        std::string nationality = "English";
        std::string position = "Midfield";
        int gamesPlayed = 89;

        void assistGoal(bool passToStriker = true);
        void scoreGoal(bool shootAtGoal = true);
        void celebrateGoal(char celebrationType, bool scorerOfGoal);
    };

    Player player1;

    // number of players in squad
    int squadPlayers = 24;
    // average age of players in squad
    int averageAge = 28;
    // number of total goals scored by the team
    int totalGoalsScoredThisSeason = 60;
    // number of matches in the season
    int matchesPlayedThisSeason = 12;
    // league position
    int currentLeaguePositionThisSeason = 4;

    // train skills
    void trainSkills(Player player2, std::string skill);
    // acquire injuries
    void acquireInjury(Player player3, int daysToRecover);
    // receive awards
    void receiveAward(std::string award);
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
    std::string effectType = "Delay";

    // output midi
    void outputMidi(int output);
    // filter out all frequences above 10khz
    void filterAllFrequenciesAbove10k(bool moveHighCutFilterTo10k = true, bool adjustQFactor = true);
    // load different presets
    void loadPresets(std::string presetBankName = "Pads");
};

/*
Thing 5) Seat
5 properties:
    1) outer material // string
    2) padding material // string
    3) how many riders it can seat // int
    4) comfort rating // double
    5) safety rating // double
3 things it can do:
    1) seat 2 riders at the same time
    2) adjust seat position
    3) automatically heat in low temperatures
 */

struct Seat
{
    // outer material
    std::string outerMaterial = "Leather";
    // inner material
    std::string paddingMaterial = "Polyethylene Foam";
    // how many riders it can seat
    int riders = 1;
    // comfort rating
    double comfortRating = 6.5;
    // 5) safety rating 
    double safetyRating = 9.5;

    // seat riders
    void seatRiders(int riders);
    // adjust seat position
    void adjustSeatPosition(float moveVertically, float moveHorizontally);
    // automatically heat in low temperatures
    void heatSeat(float airTemp, float currentSeatTemp, float targetSeatTemp);
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
    // cyclinder head manufacturer
    std::string cyclinderHeadManufacturer = "Suzuki";
    // quantity of oil pans
    int oilPans = 2;
    // engine block type
    std::string engineBlockType = "Combustion";

    // produce energy for the motorcycle to move
    void produceEnergy(int pistons, int valves, std::string engineBlockType);
    // lubricate itself with oil to keep the parts moving fluidly
    void lubricateEngine(int oilPans = 2, double availableOilInLitres = 0.9);
    // burn fuel
    void burnFuel(double availableFuelInLitres, float engineRevs, float amountOfFuelRequired);
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
    double lengthInInches = 15.4;
    // turbo charger power
    double turboChargerPower = 4.5;
    // catalytic converters
    int catalyticConverters = 1;
    // muffler type
    std::string mufflerType = "High Supression";
    // number of pipes
    int pipes = 2;

    // increase the power of the engine using a turbocharger
    void turboChargeEngine(double turboChargerPower);
    // reduce fumes using catalytic converters
    void reduceFumes(int catalyticConverters = 1, bool performCatalyticConversion = true);
    // reduce or increase the level of noise when reving the engine
    void controlExhaustNoise(std::string mufflerType, float engineRevs, float noiseInDecibels);
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
    double capacityInLitres = 8.5;
    // the type of fuel it can hold
    std::string fuelType = "Unleaded";
    // the min amount of fuel it can hold before it starts to effect performance
    double minimumFuelAmountInLitres = 1.0;
    // capacity sensors
    int sensors = 4;
    // material
    std::string material = "Steel";

    // notify the rider when it is low on fuel
    std::string notifyFuelAmountIsLow(double minimumfuelAmountInLitres = 0.5, bool fuelIsLowerThanMinimumAmount = true);
    // notify the rider when the wrong type of fuel has been used
    std::string notifyIncorrectFuelTypeUsed(std::string fuelType = "diesel", bool wrongFuelInTank = true);
    // hold fuel
    float trackFuelUsage(int sensors, double capacityInLitres, double previousFuelReading, double currentFuelReading);
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
    std::string material = "Synthetic Rubber";
    // thickness of the material // double
    double thicknessInInches = 22.5;
    // average lifespan in km travelled  // double
    int lifespanInKm = 2500;
    // the manufacturer // string
    double pressure = 14.2;
    // the type of terrain the tyre is most suited for // string
    std::string terrain = "Road";    

    // puncture
    void puncture(bool holeInTyre  = true);
    // provide support for the bike
    void supportBike(int tyres = 2);
    // wear out over time
    void wearOut(int lifespanInKm, int distanceTravelledInKm, std::string material, std::string terrain);
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
    1) Move
    2) Breakdown
    3) Crash
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

    // Move
    void move(std::string direction, int speed);
    // Breakdown
    void breakdown(std::string areaOfIssue = "Engine");
    // Crash
    void crash(std::string causeOfCrash, bool isVehicleWrittenOff, int injuriesSustained);
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
