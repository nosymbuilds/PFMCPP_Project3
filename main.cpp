/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
#include <array>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





struct Song
{
    struct Artist
    {
        std::string name;
        int age;
        std::string nationality;
        std::string mostPopularSong;
        int salesRecord;

        Artist();
        void performSongLive(bool tour = true);
        void recordSongInTheStudio(bool recordAlbum);
        void promoteSong(int numberOfInterviews, bool tvAppearances);
        void makeAHit(std::string songName, int sales);
    };

    Artist artistA;

    int duration;
    float tempo;
    char key;
    int performingArtists;
    std::string recordLabel;

    Song();
    void playSongOnRadio(int songDuration, float songTempo);
    void performSongLiveAtConcert(Artist artistB, std::string concert);
    void remixSong(std::string title, Artist artistC, std::string recordLabelSongIsSignedTo);
    void syncToAdvert(int offer);
};

Song::Song() : duration(5), tempo(125.f), key('c'), performingArtists(1), recordLabel("Virgin")
{
    std::cout << "Song constructed" << std::endl;
}

Song::Artist::Artist() : name("Moby"), age(50), nationality("American"), mostPopularSong("Porcelain"), salesRecord(20)
{
    std::cout << "Artist constructed" << std::endl;
}

void Song::playSongOnRadio(int songDuration, float songTempo)
{
    std::cout << "The original tempo for this song is " << tempo << "bpm." << std::endl;
    std::cout << "The song is playing on the radio for " << songDuration << " minutes. The original and has been adjusted to play at the tempo of " << songTempo << " bpm." << std::endl;
}

void Song::performSongLiveAtConcert(Artist artistB, std::string concert)
{
    std::cout << "The song is performed live at " << concert << " by " << artistB.name << std::endl;
}

void Song::remixSong(std::string title, Artist artistC, std::string recordLabelSongIsSignedTo)
{
    std::cout << recordLabelSongIsSignedTo << " have chosen " << artistC.name << " to remix the song " << title << std::endl;
}

void Song::syncToAdvert(int offer)
{
    int minimumFee = 50;

    if(offer > minimumFee)
    {
        std::cout << "The offer of £" << offer << " to licence the track for the advert has been accepted." << std::endl;
    }
    else
    {
        for(int i = 0; i + offer <= minimumFee + 1; ++i)
        {  
            if (i + offer > minimumFee)
            {
                std::cout << "The offer of £" << i + offer << " to licence the track for the advert has been accepted!" << std::endl;
            }  
            else 
            {
                std::cout << "The offer of £" << i + offer << " to licence the track for the advert has been rejected." << std::endl;
            }
        } 
    }
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

void Song::Artist::makeAHit(std::string songName, int sales)
{
    int salesCount = 0;

    for(int i = 0; i <= sales ; ++i)
    {   
        ++salesCount;
    }

    if(salesCount > salesRecord)
    {
        mostPopularSong = songName;
        salesRecord = salesCount;
        std::cout << "A new record has been set! " << mostPopularSong << " is now " << name << "'s most popular song with a new high sales record of " << "!" << salesRecord << std::endl;
    }
    else
    {
        std::cout << "No new records were achieved with the release of this song. " << mostPopularSong << " is still " << name << "'s most popular song with a sales record of " << salesRecord << std::endl;
    }
}

struct Sandwich
{
    std::string bread;
    int numOfFillings;
    std::string filling;
    std::string condiment;
    int calories;

    Sandwich();
    void causeFoodPoisoning(bool uncookedMeat = true);
    void provideSatisfyingMeal(double levelOfSatisfaction, int calorieCount);
    void goMoldy(int daysWithoutStorage);
    void eat(int bitesToEat);
};

Sandwich::Sandwich() : bread("white"), numOfFillings(1), filling("egg"), condiment("mayo"), calories(500)
{
    std::cout << "Sandwich constructed using " << bread << " bread." << std::endl;
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

void Sandwich::eat(int bitesToEat)
{
    int caloriesPerBite = calories / bitesToEat;
 
    for(int i = 0; i + 1 <= bitesToEat; ++i)
    {
        if(bitesToEat - (i + 1) == bitesToEat / 2)
            std::cout << "You are halfway through eating your sandwich!" << std::endl;

        std::cout << "You had a bite of the sandwich. There are "  << bitesToEat - (i + 1) << " bites left to eat." << std::endl;

        if(bitesToEat - (i + 1) == 0)
        {
            calories = 0;
            std::cout << "All calories consumed." << std::endl;
        }
        else
        {   
            calories -= caloriesPerBite;
            std::cout << "The remaining calories in the sandwich are: " << calories << std::endl;
        }
    }
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
        void playGames(int numOfGames);
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
    void sellPlayers(int playersSold);
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

void SoccerTeam::sellPlayers(int playersSold)
{
    for(int i = 0; i <= playersSold - 1 ; ++i)
    {   
        --squadPlayers; 
    }

    if(squadPlayers <= 0)
    {
        std::cout << "All players were sold! " << std::endl;
    }
    else 
    {
        std::cout << playersSold << " players were sold. The squad size is now " << squadPlayers << std::endl;
    }     
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

void SoccerTeam::Player::playGames(int numOfGames)
{   
    for(int i = 0; i <= numOfGames ; ++i)
    {   
        ++gamesPlayed;
    }

    std::cout << "The new total number of games played by " << name << " is " << gamesPlayed << std::endl;
}

struct Synth
{
    int oscillators;
    int presets;
    int filters;
    int outputs;
    int effectsLoaded;

    Synth();
    void outputMidi(int midiOutput);
    void filterAllFrequenciesAbove10k(bool moveHighCutFilterTo10k = true, bool adjustQFactor = true);
    void loadPresets(std::string presetBankName = "All");
    void loadEffects(int numOfEffects);

};

Synth::Synth() : oscillators(1), presets(100), filters(3), outputs(2), effectsLoaded(0)
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

void Synth::loadEffects(int numOfEffects)
{   
    for(int i = 0; i <= numOfEffects - 1 ; ++i)
    {
        std::cout << "Effect " << ++i << " loaded and ready to use." << std::endl;
        ++effectsLoaded;
    }
}

struct Seat
{
    std::string outerMaterial = "leather";
    std::string paddingMaterial = "polyethylene foam";
    int riders;
    double comfortRating = 6.5;
    double safetyRating = 9.5;

    Seat();
    void seatRiders(int riders);
    void adjustSeatPosition(float moveVertically, float moveHorizontally);
    void heatSeat(float currentSeatTemp, float targetSeatTemp);
    void changeSeat(double rating);
};

Seat::Seat() : riders(0)
{
    std::cout << "Seat constructed using " << outerMaterial << " and " << paddingMaterial << std::endl;
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

void Seat::changeSeat(double rating)
{
    double previousRating = safetyRating;

    for(double i = 0.0; i <= rating; i += 0.1)
    {
        std::cout << "The mechanic is fitting the safety features of the new seat 1 screw at a time..." << std::endl;
        safetyRating = i;
    }

    std::cout << "Your new seat has been fitted! The safety rating has changed from " << previousRating << " to " << safetyRating << std::endl;
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
    void firePiston();
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

void Engine::firePiston()
{
    int i = 0;
    while(i < pistons)
    {  
        std::cout << "Fire piston " << i + 1 << std::endl;
        ++i;
    }

    std::cout << "All pistons firing!" << std::endl;
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
    void controlTurbo(double kph, double charge);
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

void Exhaust::controlTurbo(double kph, double charge)
{
    turboChargerPower = charge;
    double maxKph = kph * turboChargerPower;

    while(kph < maxKph)
    {
        kph += (maxKph / 10);

        if(kph > maxKph)
        {
            kph = maxKph;
            std::cout << "The onboard computer reduced the kph to the maximum turbo amount. The current kph is: " << kph << std::endl;
        }
        else 
        {
            std::cout << "The current kph is: " << kph << std::endl;
            std::cout << "The turbo increased the kph output by 10% of its maximum output."<< std::endl;
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
    void activateSensor();
};

FuelTank::FuelTank()
{
    std::cout << "FuelTank constructed with a overall capacity of " << capacityInLitres << " litres." << std::endl;
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

void FuelTank::activateSensor()
{
    int i = 0;
    while(i < sensors)
    {  
        std::cout << "Activated sensor " << i + 1 << std::endl;
        ++i; 
    }
   
    std::cout << "All sensors activated!" << std::endl;
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
    void pump(double newPressure);
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

void Tyre::pump(double newPressure)
{
    double previousPressure = pressure;

    if(newPressure - pressure >= 0)
    {
        while(pressure < newPressure)
        {
            pressure += 0.1;
        }
    }
    else
    {   
        while(pressure > newPressure + 0.1)
        {   
            pressure -= 0.1;
        }
    }

    std::cout << "The pressure has been adjusted from " << previousPressure << " to " << pressure << std::endl;
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
    void buy(int bikesPurchased);
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

void Motorbike::buy(int bikesPurchased)
{
    if(bikesPurchased > 5)
    {
        std::cout << "You dont have room to store more than 5 bikes!" << std::endl;
    }
    else
    {
        for(int i = 0; i < bikesPurchased; ++i)
        {
            std::cout << "You stored Motorbike" << i + 1 << " in your garage." << std::endl;
        }
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

    std::cout << std::endl;

    Song songA;
    Song::Artist artistA;
    songA.playSongOnRadio(5, 126.2f);
    songA.performSongLiveAtConcert(artistA, "Glastonbury");
    songA.remixSong("WAP", artistA, "Atlantic");
    artistA.performSongLive();
    artistA.recordSongInTheStudio(false);
    artistA.promoteSong(20, true);
    std::cout << songA.recordLabel << std::endl;
    songA.syncToAdvert(48);
    artistA.makeAHit("Go", 10);
    
    std::cout << std::endl;

    Sandwich salamiSandwich;
    salamiSandwich.goMoldy(2);
    salamiSandwich.provideSatisfyingMeal(5.5, 642);
    salamiSandwich.causeFoodPoisoning(true);
    std::cout << salamiSandwich.filling << std::endl;
    salamiSandwich.eat(3);

    std::cout << std::endl;

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
    player1.playGames(4);
    team1.sellPlayers(26);

    std::cout << std::endl;

    Synth juno;
    juno.outputMidi(2);
    juno.filterAllFrequenciesAbove10k();
    juno.filterAllFrequenciesAbove10k(true, true);
    juno.filterAllFrequenciesAbove10k(true, false);
    juno.filterAllFrequenciesAbove10k(false, false);
    juno.loadPresets("Pads");
    std::cout << juno.presets << std::endl;
    juno.loadEffects(4);

    std::cout << std::endl;

    Seat seat1;
    seat1.seatRiders(0);
    seat1.adjustSeatPosition(0.2f, 0.0f);
    seat1.heatSeat(20.f, 29.7f);
    std::cout << seat1.outerMaterial << std::endl;
    seat1.changeSeat(1.2);

    std::cout << std::endl;

    Engine engine1;
    engine1.produceEnergy(4, 8, "combustion");
    engine1.lubricateEngine(0.9);
    engine1.burnFuel(4.2, 1.4);
    std::cout << engine1.cyclinderHeadManufacturer << std::endl;
    engine1.firePiston();

    std::cout << std::endl;

    Exhaust exhaust1;
    exhaust1.turboChargeEngine(2.2);
    exhaust1.reduceFumes(3);
    exhaust1.controlExhaustNoise("high", 15);
    std::cout << exhaust1.turboChargerPower<< std::endl;
    exhaust1.controlTurbo(10.7, 6.5);

    std::cout << std::endl;

    FuelTank fuelTank1;
    fuelTank1.notifyFuelAmountIsLow(0.2);
    fuelTank1.notifyIncorrectFuelTypeUsed();
    fuelTank1.trackFuelUsage(8.1, 0.4);
    std::cout << fuelTank1.material << std::endl;
    fuelTank1.activateSensor();

    std::cout << std::endl;

    Tyre tyre1;
    tyre1.puncture();
    tyre1.coverWheel(2);
    tyre1.wear(95.0, 47.5, "jungle");
    std::cout << tyre1.terrain << std::endl;
    tyre1.pump(9.2);

    std::cout << std::endl;
    
    Motorbike motorbike1;
    motorbike1.move("forwards", 40);
    motorbike1.breakdown("breaks");
    motorbike1.crash(2);
    motorbike1.buy(4);
    std::cout << motorbike1.engine.valves << std::endl;

    std::cout << std::endl;
    
    std::cout << "good to go!" << std::endl;
    
}
