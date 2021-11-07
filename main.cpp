/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of each of your user-defined types in the main() function.

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int a; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    a = 0;
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'a' equal to 0? " << (foo.a == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.

struct Song
{
    struct Artist
    {
        std::string name = "Moby";
        int age = 50;
        std::string nationality = "American";
        int yearsActive = 25;
        std::string mostPopularSong = "Porcelain";

        Artist();
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

    Song();
    void playSongOnRadio(int songDuration, float songTempo);
    void performSongLiveAtConcert(Artist artistB, std::string concert);
    void remixSong(std::string title, Artist artistC, std::string recordLabelSongIsSignedTo);
};

Song::Song()
{
    std::cout << "Song constructed" << std::endl;
}

Song::Artist::Artist()
{
    std::cout << "Artist constructed" << std::endl;
}

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

    Sandwich();
    void causeFoodPoisoning(bool uncookedMeat = true);
    void provideSatisfyingMeal(double levelOfSatisfaction, int calorieCount);
    void goMoldy(int daysWithoutStorage);
};

Sandwich::Sandwich()
{
    std::cout << "Sandwich constructed" << std::endl;
}

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

        Player();
        void assistGoal(bool passToStriker = true);
        void scoreGoal(bool shootAtGoal = true);
        void celebrateGoal(std::string celebrationType, bool scorerOfGoal);
    };

    int squadPlayers = 24;
    int averageAge = 28;
    int totalGoalsScoredThisSeason = 60;
    int matchesPlayedThisSeason = 12;
    int currentLeaguePositionThisSeason = 4;

    SoccerTeam();
    void trainSkills(Player player1, std::string skill);
    void acquireInjury(Player player2, int daysToRecover);
    void receiveAward(std::string award);
};

SoccerTeam::SoccerTeam()
{
    std::cout << "SoccerTeam constructed" << std::endl;
}

SoccerTeam::Player::Player()
{
	std::cout << "Player constructed" << std::endl;
}

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

    Synth();
    void outputMidi(int midiOutput);
    void filterAllFrequenciesAbove10k(bool moveHighCutFilterTo10k = true, bool adjustQFactor = true);
    void loadPresets(std::string presetBankName = "All");

};

Synth::Synth()
{
	std::cout << "Synth constructed" << std::endl;
}

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

    Seat();
    void seatRiders(int riders);
    void adjustSeatPosition(float moveVertically, float moveHorizontally);
    void heatSeat(float currentSeatTemp, float targetSeatTemp);
};

Seat::Seat()
{
    std::cout << "Seat constructed" << std::endl;
}

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

    Engine();
    void produceEnergy(int numOfPistons, int numOfValves, std::string engineType);
    void lubricateEngine(double availableOilInLitres = 0.9);
    void burnFuel(double availableFuelInLitres, double engineRevs);
};

Engine::Engine()
{
    std::cout << "Engine constructed" << std::endl;
}

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

    Exhaust();
    void turboChargeEngine(double turboCharge);
    void reduceFumes(int numOfCatalyticConverters = 1);
    void controlExhaustNoise(std::string mufflerType, float engineRevs);
};

Exhaust::Exhaust()
{
    std::cout << "Exhaust constructed" << std::endl;
}

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

    FuelTank();
    void notifyFuelAmountIsLow(double fuelAmountInLitres);
    void notifyIncorrectFuelTypeUsed(bool dieselUsed = true);
    double trackFuelUsage(double previousFuelReading, double currentFuelReading);
};

FuelTank::FuelTank()
{
    std::cout << "FuelTank constructed" << std::endl;
}

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

    Tyre();
    void puncture(bool holeInTyre  = true);
    void coverWheel(int tyres = 2);
    void wear(double lifespanInKm, double distanceTravelledInKm, std::string terrain);
};

Tyre::Tyre()
{
    std::cout << "Tyre constructed" << std::endl;
}

void Tyre::puncture(bool holeInTyre)
{   
    if (holeInTyre == true)
    {
        std::cout << "You have a puncture!" << std::endl; 
    }  
}

void Tyre::coverWheel(int tyres)
{
    std::cout << "The " << tyres <<  " tyres cover the wheels to protect the inner tubes." << std::endl; 
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

    Motorbike();
    void move(std::string direction, int speed);
    void breakdown(std::string areaOfIssue = "Engine");
    void crash(int injuriesSustained);
};

Motorbike::Motorbike()
{
    std::cout << "Motorbike constructed" << std::endl;
}

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
    Example::main();
    
    Song songA;
    Song::Artist artistA;
    songA.playSongOnRadio(5, 125.4f);
    songA.performSongLiveAtConcert(artistA, "Glastonbury");
    songA.remixSong("WAP", artistA, "Atlantic");
    artistA.performSongLive();
    artistA.recordSongInTheStudio(false);
    artistA.promoteSong(20, true);
    std::cout << songA.recordLabel << std::endl;

    Sandwich salamiSandwich;
    salamiSandwich.goMoldy(2);
    salamiSandwich.provideSatisfyingMeal(5.5, 642);
    salamiSandwich.causeFoodPoisoning(true);
    std::cout << salamiSandwich.filling << std::endl;

    SoccerTeam team1;
    SoccerTeam::Player player1;
    team1.trainSkills(player1, "dribbling");
    team1.acquireInjury(player1, 10);
    team1.receiveAward("Team of the Month");
    player1.scoreGoal(true);
    player1.assistGoal(true);
    player1.celebrateGoal("backflip", true);
    std::cout << team1.squadPlayers << std::endl;
    std::cout << player1.gamesPlayed << std::endl;

    Synth juno;
    juno.outputMidi(2);
    juno.filterAllFrequenciesAbove10k();
    juno.filterAllFrequenciesAbove10k(true, true);
    juno.filterAllFrequenciesAbove10k(true, false);
    juno.filterAllFrequenciesAbove10k(false, false);
    juno.loadPresets("Pads");
    std::cout << juno.presets << std::endl;

    Seat seat1;
    seat1.seatRiders(0);
    seat1.adjustSeatPosition(0.2f, 0.0f);
    seat1.heatSeat(20.f, 29.7f);
    std::cout << seat1.outerMaterial << std::endl;

    Engine engine1;
    engine1.produceEnergy(4, 8, "combustion");
    engine1.lubricateEngine(0.9);
    engine1.burnFuel(4.2, 1.4);
    std::cout << engine1.cyclinderHeadManufacturer << std::endl;

    Exhaust exhaust1;
    exhaust1.turboChargeEngine(2.2);
    exhaust1.reduceFumes(3);
    exhaust1.controlExhaustNoise("high", 15);
    std::cout << exhaust1.turboChargerPower<< std::endl;

    FuelTank fuelTank1;
    fuelTank1.notifyFuelAmountIsLow(0.2);
    fuelTank1.notifyIncorrectFuelTypeUsed();
    fuelTank1.trackFuelUsage(8.1, 0.4);
    std::cout << fuelTank1.material << std::endl;

    Tyre tyre1;
    tyre1.puncture();
    tyre1.coverWheel(2);
    tyre1.wear(95.0, 47.5, "jungle");
    std::cout << tyre1.terrain << std::endl;
    
    Motorbike motorbike1;
    motorbike1.move("forwards", 40);
    motorbike1.breakdown("breaks");
    motorbike1.crash(2);
    std::cout << motorbike1.engine.valves << std::endl;
    
    std::cout << "good to go!" << std::endl;
}
