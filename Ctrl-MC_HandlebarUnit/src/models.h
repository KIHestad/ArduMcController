/*
 
  Ctrl-MC // An open source Arduino project by KI Hestad: https://github.com/KIHestad/Ctrl-MC
 
*/

// Bike main status
enum BikeStatusIgnition { ignOff, ignPasswordMode, ignOn };
enum BikeStatusEngine { engStopped, engRunning };
enum BikeStatusLights { lightsOff, lightsPark, lightsMain };
class BikeStatus {
    public:

        long displayOffTimestamp; // Timestamp for when display off was initiated
        long displayOffWaitTime; // Number of milliseconds to run shutdown with progressbar befor display is turned off
        bool displayOffProgressRunning; // Flag set to true when progress is running 
        bool communicationOK; // Flag that indicates that communitcation to relay module is OK
        BikeStatusIgnition ignition;
        BikeStatusEngine engine;
        BikeStatusLights lights;

        // Constructor
        void init() {
            displayOffTimestamp = 0;
            displayOffWaitTime = 6000;
            displayOffProgressRunning = false;
            communicationOK = false;
            ignition = ignOff;
            engine = engStopped;
            lights = lightsOff;
        }
};

// Used to define pins allocation for inputs and custom features for button inputs
class Input {
    public:
        bool enabled; // If input is to be used or not
        int pin; // Arduino borad pin
        int activateOnLongPress = 0; // Number of milliseconds, 0 = long not activated
};

// Used tp retrive serial communication data
class SerialCommunicationData {
    public:
        bool retrieved;
        int codeGroup;
        int code;
};
