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

struct Person
{
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTravelled;

    void run(int howFast, bool startWithLeftFoot);

    struct Foot
    {
        void stepForward()
        {
            std::cout << "One step taken forward" << std::endl;
        }

        int stepSize()
        {
            return 1;
        }
    };

    Foot leftFoot;
    Foot rightFoot;
};

void Person::run(int howFast, bool startWithLeftFoot)
{
    if (startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    } 
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTravelled += leftFoot.stepSize() + rightFoot.stepSize();
    std::cout << "You ran at a speed of " << howFast << " and travelled a distance of " << distanceTravelled << std::endl;
}

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

    int duration = 5;
    float tempo = 125.f;
    char key = 'a';
    int performingArtists = 4;
    std::string recordLabel = "Virgin";
    
    void playSongOnRadio(int songDuration, float songTempo);
    void performSongLiveAtConcert(Artist artistB, std::string concert);
    void remixSong(std::string title, Artist artistC, std::string recordLabelSongIsSignedTo);
};

void Song::playSongOnRadio(int songDuration, float songTempo)
{
    std::cout << "The song is playing on the radio for " << songDuration << " minutes, at the tempo of " << songTempo << " bpm" << std::endl;
}

void Song::performSongLiveAtConcert(Artist artistB, std::string concert)
{
    std::cout << "The song is performed live at " << concert << " by " << artistB.name << std::endl;
}

void Song::remixSong(std::string title, Artist artistC, std::string recordLabelSongIsSignedTo)
{
    std::cout << recordLabelSongIsSignedTo << " have chosen " << artistC.name << " to remix the song " << title << std::endl;
}

void Song::Artist::performSongLive(bool tour)
{
    if (tour == true)
    {
        std::cout << "The artist will perform the song live on tour." << std::endl;
    }
    else
    {
        std::cout << "The artist will NOT perform the song live on tour." << std::endl;
    }
}

void Song::Artist::recordSongInTheStudio(bool recordAlbum)
{
    if (recordAlbum == true)
    {
        std::cout << "The artist is recording a song in the studio for their album." << std::endl; 
    }
    else
    {
        std::cout << "The artist is recording a song in the studio but it is not for their album." << std::endl;
    }
}

void Song::Artist::promoteSong(int numberOfInterviews, bool tvAppearances)
{
    if (tvAppearances == true)
    {
        std::cout << "The artist is promoting their song by doing " << numberOfInterviews << " interviews that include some TV appearances." << std::endl; 
    }
    else
    {
        std::cout << "The artist is promoting their song by doing " << numberOfInterviews << " interviews but has declined all TV appearances." << std::endl; 
    }  
}

struct Sandwich
{
    std::string bread = "Brown";
    int numOfFillings = 1;
    std::string filling = "Salami";
    std::string condiment = "Mayo";
    int calories = 600;

    void causeFoodPoisoning(bool uncookedMeat = true);
    void provideSatisfyingMeal(double levelOfSatisfaction, int calorieCount);
    void goMoldy(int daysWithoutStorage);
};

void Sandwich::causeFoodPoisoning(bool uncookedMeat)
{
    if (uncookedMeat == true)
    {
        std::cout << "The sandwich had uncooked meat as a filling which caused food poisoning." << std::endl;
    }
}

void Sandwich::provideSatisfyingMeal(double levelOfSatisfaction, int calorieCount)
{
    std::cout << "The sandwich has a satisfaction rating of " << levelOfSatisfaction << " with a total calorie content of " << calorieCount  << std::endl; 
}

void Sandwich::goMoldy(int daysWithoutStorage)
{
    std::cout << "After " << daysWithoutStorage << " days with no storage the sandwich has gone moldy." << std::endl;   
}

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
        void celebrateGoal(std::string celebrationType, bool scorerOfGoal);
    };

    Player player1;

    int squadPlayers = 24;
    int averageAge = 28;
    int totalGoalsScoredThisSeason = 60;
    int matchesPlayedThisSeason = 12;
    int currentLeaguePositionThisSeason = 4;

    void trainSkills(Player player2, std::string skill);
    void acquireInjury(Player player3, int daysToRecover);
    void receiveAward(std::string award);
};

void SoccerTeam::trainSkills(Player player2, std::string skill)
{
    std::cout << player2.name << " is training their " << skill << " skills." << std::endl;
}

void SoccerTeam::acquireInjury(Player player3, int daysToRecover)
{
    std::cout << player3.name << " has acquired an injury. It will take them " << daysToRecover << " days to recover." << std::endl;
}

void SoccerTeam::receiveAward(std::string award)
{
    std::cout << "The team has received the " << award << " award!" << std::endl;
}

void SoccerTeam::Player::assistGoal(bool passToStriker)
{
    if (passToStriker == true)
    {
        std::cout << "A pass was made to the striker and a goal was scored!" << std::endl;
    }
    else
    {
        std::cout << "The striker was ready to receive the ball but a pass was not made to them." << std::endl;
    }
    
}

void SoccerTeam::Player::scoreGoal(bool shootAtGoal)
{
    if (shootAtGoal == true)
    {
        std::cout << "GOALLLL!" << std::endl;
    }
    else
    {
        std::cout << "The player had an oppurtunity to score but they did not take a shot at goal." << std::endl;
    }
}

void SoccerTeam::Player::celebrateGoal(std::string celebrationType, bool scorerOfGoal)
{
    if (scorerOfGoal == true)
    {
        std::cout << "The player celebrates scoring a goal with a " << celebrationType << std::endl;
    }
    else
    {
        std::cout << "The player has not scored the goal but is so happy they celebrate the goal with a " << celebrationType << std::endl;
    }
}

struct Synth
{
    int oscillators = 3;
    int presets = 150;
    int filters = 3;
    int outputs = 2;
    std::string effectType = "Delay";

    void outputMidi(int midiOutput);
    void filterAllFrequenciesAbove10k(bool moveHighCutFilterTo10k = true, bool adjustQFactor = true);
    void loadPresets(std::string presetBankName = "All");

};

void Synth::outputMidi(int midiOutput)
{
    std::cout << "Midi data is sent to midi output " << midiOutput << std::endl;
}

void Synth::filterAllFrequenciesAbove10k(bool moveHighCutFilterTo10k, bool adjustQFactor)
{
    if (moveHighCutFilterTo10k == true)
    {   
        if (adjustQFactor == true)
        {   
            std::cout << "All frequencies above 10k have been cut and the Q factor has been adjusted." << std::endl;
        }
        else
        {
            std::cout << "All frequencies above 10k have been cut." << std::endl;
        }   
    } 
    else 
    {
        std::cout << "No filtering of frequencies performed." << std::endl;
    }       
}

void Synth::loadPresets(std::string presetBankName)
{
    std::cout << presetBankName << " presets have been loaded." << std::endl;
}

struct Seat
{
    std::string outerMaterial = "Leather";
    std::string paddingMaterial = "Polyethylene Foam";
    int riders = 1;
    double comfortRating = 6.5;
    double safetyRating = 9.5;

    void seatRiders(int riders);
    void adjustSeatPosition(float moveVertically, float moveHorizontally);
    void heatSeat(float currentSeatTemp, float targetSeatTemp);
};

void Seat::seatRiders(int numOfRiders)
{
    if (numOfRiders == 0)
    {
        std::cout << "The bike has no riders to seat." << std::endl;
    }
    else if (numOfRiders == 1)
    {
        std::cout << numOfRiders << " rider takes a seat on the bike." << std::endl;
    }
    else 
    {
        std::cout << numOfRiders << " riders takes their seat on the bike." << std::endl;
    }
}

void Seat::adjustSeatPosition(float moveVertically, float moveHorizontally)
{
    if (moveVertically == 0.0f && moveHorizontally == 0.0f)
    {
        std::cout << "The seat is not adjusted." << std::endl;
    }
    else 
    {
        std::cout << "The seat is adjusted "  << moveVertically << " degrees vertically and " << moveHorizontally << " degress horizontally." << std::endl;
    }
}

void Seat::heatSeat( float currentSeatTemp, float targetSeatTemp)
{
    float increaseTemp = targetSeatTemp - currentSeatTemp;
    std::cout << "The seat temperature will be increased by " <<  increaseTemp << " to reach the desired temperature set by the rider." << std::endl;    
}

struct Engine
{
    int pistons = 2;
    int valves = 16;
    std::string cyclinderHeadManufacturer = "Suzuki";
    int oilPans = 2;
    std::string engineBlockType = "combustion";

    void produceEnergy(int numOfPistons, int numOfValves, std::string engineType);
    void lubricateEngine(double availableOilInLitres = 0.9);
    void burnFuel(double availableFuelInLitres, double engineRevs);
};

void Engine::produceEnergy(int numOfPistons, int numOfValves, std::string engineType)
{
    int energy = numOfPistons * numOfValves;
    std::cout << "The " << engineType << " engine produces " << energy << "btu of energy." << std::endl;    
}

void Engine::lubricateEngine(double availableOilInLitres)
{
    if (availableOilInLitres <= 0.3)
    {
        std::cout << "There is not enough oil to lubcricate the engine efficiently, please add more oil." << std::endl; 
    }
    else 
    {
        double newOilLevel = availableOilInLitres - 0.1;
        std::cout << "The engine is lubricated with oil. There is " << newOilLevel << " litres of oil available after lubricating the engine." << std::endl;    
    }
}

void Engine::burnFuel(double availableFuelInLitres, double engineRevs)
{
    double amountOfFuelRequired = engineRevs * 2;
    double fuelBurnCalc = availableFuelInLitres - amountOfFuelRequired;

    if (fuelBurnCalc <= 0) 
    {
        std::cout << "There is not enough fuel to burn!" << std::endl; 
    }
    else
    {
        std::cout << "BURN BABY BURN!" << std::endl; 
    }
}

struct Exhaust
{
    double lengthInInches = 15.4;
    double turboChargerPower = 4.5;
    int catalyticConverters = 1;
    std::string mufflerSuppressionType = "low";
    int pipes = 2;

    void turboChargeEngine(double turboCharge);
    void reduceFumes(int numOfCatalyticConverters = 1);
    void controlExhaustNoise(std::string mufflerType, float engineRevs);
};

void Exhaust::turboChargeEngine(double turboCharge)
{
    double charge = turboCharge * 4;
    std::cout << "The engine's output is turbocharged by " << charge << " of power!" << std::endl; 
}

void Exhaust::reduceFumes(int numOfCatalyticConverters)
{
    if (numOfCatalyticConverters > 0)
    {
        std::cout << "The catalytic converter is working to reduce fumes." << std::endl; 
    }
    else
    {
        std::cout << "There is no catalytic converter fitted on this vehicle." << std::endl; 
    }
}

void Exhaust::controlExhaustNoise(std::string mufflerType, float engineRevs)
{
    if (engineRevs <= 9 || engineRevs > 20)
    {
        std::cout << "Please input a rev count between 10 and 20." << std::endl;
    }
    else
    {
        float noiseInDecibels = engineRevs * 10.f;

        if (mufflerType == "high")
        {
            float highNoiseReduction = noiseInDecibels / 5.f;
            std::cout << "The " << mufflerType << " suppression muffler is reducing the noise level at a rate of " << highNoiseReduction << "dbs." << std::endl; 
        }
        else
        {
            float lowNoiseReduction = noiseInDecibels / 15.f;
            std::cout << "The " << mufflerType << " suppression muffler is reducing the noise at a rate of " << lowNoiseReduction << "dbs." << std::endl;
        }
    } 
}

struct FuelTank
{
    double capacityInLitres = 8.5;
    std::string fuelType = "Unleaded";
    double minimumFuelAmountInLitres = 1.0;
    int sensors = 4;
    std::string material = "Steel";

    void notifyFuelAmountIsLow(double fuelAmountInLitres);
    void notifyIncorrectFuelTypeUsed(bool dieselUsed = true);
    double trackFuelUsage(double previousFuelReading, double currentFuelReading);
};

void FuelTank::notifyFuelAmountIsLow(double fuelAmountInLitres)
{
    if (fuelAmountInLitres <= 0.5)
    {
        std::cout << "Fuel is running low! Please add more fuel to the tank." << std::endl;
    }  
    else 
    {
        double fuelLeft  = fuelAmountInLitres - 0.5;
        std::cout << "The fuel tank has "  << fuelLeft << " litres of fuel to burn before the 'Fuel is running low!' notification will appear." << std::endl;
    }
}

void FuelTank::notifyIncorrectFuelTypeUsed(bool dieselUsed)
{
    if (dieselUsed == true)
    {
        std::cout << "The fuel tank has been filled with the wrong fuel type. Please seek immedieate assitance from a professional." << std::endl; 
    }
}

double FuelTank::trackFuelUsage(double previousFuelReading, double currentFuelReading)
{   
    double fuelUsed = previousFuelReading - currentFuelReading;
    std::cout << fuelUsed << " litres of fuel has been used since the last reading." << std::endl; 

    if (currentFuelReading < 0.5)
    {
        notifyFuelAmountIsLow(currentFuelReading);
    }
    return fuelUsed;
}

struct Tyre
{
    std::string material = "Synthetic Rubber";
    double thicknessInInches = 22.5;
    int lifespanInKm = 2500;
    double pressure = 14.2;
    std::string terrain = "Road";    

    void puncture(bool holeInTyre  = true);
    void coverWheel(int tyres = 2);
    void wear(double lifespanInKm, double distanceTravelledInKm, std::string terrain);
};

void Tyre::puncture(bool holeInTyre)
{   
    if (holeInTyre == true)
    {
        std::cout << "You have a puncture!" << std::endl; 
    }  
}

void Tyre::coverWheel(int tyres)
{
    std::cout << "The " << tyres <<  " tyres cover the wheels protect the inner tubes." << std::endl; 
}

void Tyre::wear(double lifespanKm, double distanceTravelledInKm, std::string terrainType)
{
    double tyreLife = lifespanKm - distanceTravelledInKm;

    if (terrainType == "road")
    {
        std::cout << "The tyre has approx. " << tyreLife << "km worth of wear before it needs to be replaced." << std::endl; 
    }
    else if (terrainType == "offroad")
    {
        std::cout << "The tyre has approx. " << tyreLife / 2 << "km worth of wear before it needs to be replaced." << std::endl; 
    }
    else
    {
        std::cout << "The tyre has approx. " << tyreLife / 3 << "km worth of wear before it needs to be replaced." << std::endl; 
    }
}

struct Motorbike
{
    Seat seat;
    Engine engine;
    Exhaust exhaust;
    FuelTank fuelTank;
    Tyre tyre;

    void move(std::string direction, int speed);
    void breakdown(std::string areaOfIssue = "Engine");
    void crash(int injuriesSustained);
};

void Motorbike::move(std::string direction, int speed)
{
    std::cout << "The motorbike moves " << direction << " with a speed of " << speed << "kmph." << std::endl; 
}

void Motorbike::breakdown(std::string areaOfIssue)
{
    std::cout << "The motorbike has broken down! The area of issue is the " << areaOfIssue <<  "." << std::endl; 
}

void Motorbike::crash(int injuriesSustained)
{
    if (injuriesSustained == 0)
    {
        std::cout << "The motorbike crashed! Luckily the rider escaped with no injuries." << std::endl; 
    }
    else if (injuriesSustained >= 1 && injuriesSustained <=3)
    {
        std::cout << "The motorbike crashed! Luckily the rider escaped with only a few injuries." << std::endl;
    } 
    else if (injuriesSustained >= 4)
    {
        std::cout << "The motorbike crashed! The rider sustained a number of injuries and must go to the hospital immediately." << std::endl;
    }
}

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
