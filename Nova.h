#include <iostream> // Library used for input and output functions
#include <windows.h> // For Sleep() function, library used for operations in Windows Operating System
#include <cstdlib> // Library used for general purpose functions
#include <ctime> // For time() function, Library used for manipulating date and time functions
#include <string> // Library used for manipulation of strings
#include <iomanip>  // Library used for formatting input and output streams
#include <cctype> // For tolower() Library used for manipulation with individual characters
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#ifndef _NOVA_
#define _NOVA_

// Base class for general functionalities
class Nova
{
protected:
    // Declaration of data members
    time_t now;
    struct tm *timeinfo;
    int year, month, day, hour, minute, second;

public:
    // Function to print the message with delay
    void delay(const string &message);

    // Function to calculate components of time
    void calculatingtime();

    // Functions to get the value of the components of time
    int getday();
    int getmonth();
    int getyear();
    int gethour();
    int getmin();
    int getsec();

    // Function to greet in the beginning
    void greetings();

    // Function to change the characters in the string to lowercase 
    void lower(string &command);

    // Function to talk with Nova
    void talking(string command);
};

// Class to show the date and time 
class dateTime : public Nova
{
public:
    // Function to display date and time
    void display_date_time();
};

// Class for calendar
class calendar : public Nova
{
protected:
    // Declaration of data members
    int yr, mon, Day;

public:
    // Parametarized constructor
    calendar(int y = 0, int m = 0);

    // Function to calculate number of days in month
    int calculateDaysInMonth(int year, int month);

    // Function for calculating the first day
    int calculateStartDay(int year, int month);

    // Function to get the name of the month
    string getMonthName(int mon);

    // Function to display the calendar
    void displayCalendar();
};

// Class for task menu
class Task {
public:
	string title;
	string description;
	bool isDone;
	string date;
	

	Task(const string _title, const string _description, const string _date);
};

class TaskManager:public Nova {
private:
	vector<Task> tasks;
	const string taskfile="tasks.txt";

public:
	void addTask(const string title, const string description, const string date);

	void deleteTask(int index);

	void markTaskAsDone(int index);

	void exportTasks();

	void importTasks();

	void listtodaytask();

	void listTasks();
};

class RandomGenerator : public Nova {
protected:
    string random;
    string espeakCommand;

public:
    virtual void generateRandom(string command) = 0;
    virtual void generateMultipleRandom(string command) = 0;
};

// Derived class for generating random jokes
class RandomJokeGenerator : public RandomGenerator {
private:
    // Declaration of data members
    string jokes[30] = {
        "Why did the student bring a ladder to the school? Because they wanted to go high school.",
        "Why don't scientists trust atoms? Because they make up everything!",
        "Why don't skeletons fight each other? They don't have the guts!",
        "Why do programmers prefer dark mode? Because light attracts bugs.",
        "What did one ocean say to the other ocean? Nothing, they just waved!",
        "Why was the computer cold? It left its Windows open!",
        "Why was the JavaScript developer sad? Because he didn't 'React' well to criticism.",
        "Why did the programmer go broke? Because he used up all his cache and couldn't afford to buy RAMen noodles.",
        "Why don't programmers like to play hide and seek? Because good players are always encapsulated!",
        "Why did the programmer go to therapy? Because they had too many objects stored in their memory!",
        "Why did the programmer always wear headphones? Because he didn't want to be disturbed while he was coding in his own 'byte'!",
        "Why don't Java developers wear glasses? Because they don't see sharp.",
        "Why did the computer go to the doctor? Because it had a virus!",
        "Why did the hacker break into the bakery? To get the cookies.",
        "Why don't hackers go broke? Because they always cache in.",
        "What's a hacker's favorite season? Phishing season.",
        "How do you know your computer is safe? When you have Norton antivirus and you're running on Windows 95. Nobody's hacking that.",
        "What did the cybercriminal do at the weekend? He went phishing.",
        "What do you call fake spaghetti? An impasta.",
        "Why was the math book sad? Because it had too many problems.",
        "Why couldn't the bicycle stand up by itself? It was two-tired.",
        "Why did the computer go to the beach? To surf the web.",
        "What's the best thing about Switzerland? The flag is a big plus.",
        "I found a book called How to Solve 50% of Your Problems. So I bought 2.",
        "What did the triangle say to the circle? \"You're pointless.\"",
        "I had an argument with a 90° angle. It turns out it was right.",
        "Why doesn't anybody talk to circles? Because there's no point.",
        "Why was six afraid of seven? Because seven, eight, nine!",
        "How do you solve any equation? Multiply both sides by zero.",
        "There are three kinds of people in this world. Those who can count and those who can't."
    };

public:
    // Function to generate single random joke
    void generateRandom(string command) override ;

    // Function to create multiple jokes
    void generateMultipleRandom(string command) override ;
};

// Derived class for generating random facts or quotes
class RandomFactOrQuoteGenerator : public RandomGenerator {
private:
    // Declaration of data member
    string facts[37] = {
        "Success is not the absence of failure; it's the persistence through failure.",
        "Failure is a detour, not a dead-end street - Zig Ziglar",
        "Success is not about avoiding failure, but learning from it and moving forward.",
        "Failure is not falling down but refusing to get up - Chinese Proverb",
        "Success is walking from failure to failure with no loss of enthusiasm - Winston Churchill",
        "Failure is the path of least persistence; success is the road of endless perseverance.",
        "Success is not measured by how many times you fall, but by how many times you rise after each fall.",
        "Failure is a temporary detour, not a dead-end street.",
        "Success is not the absence of failure, but the ability to recover from it quickly.",
        "Failure is the opportunity to begin again more intelligently- Henry Ford",
        "Success is the result of perfection, hard work, learning from failure, loyalty, and persistence - Colin Powell",
        "Failure is the stepping stone to success; it's the lessons learned that pave the way.",
        "Success is not determined by how many times you've failed, but by how you've risen above each setback.",
        "A group of flamingos is called a flamboyance.",
        "Honey never spoils. Archaeologists have found pots of honey in ancient Egyptian tombs that are over 3,000 years old and still perfectly edible.",
        "Success is not final, failure is not fatal: It is the courage to continue that counts. - Winston Churchill",
        "The only way to do great work is to love what you do - Steve Jobs",
        "The only thing necessary for the triumph of evil is for good men to do nothing. - Edmund Burke",
        "In the end, we will remember not the words of our enemies, but the silence of our friends. - Martin Luther King Jr",
        "Be yourself; everyone else is already taken. - Oscar Wilde",
        "The only true wisdom is in knowing you know nothing. - Socrates",
        "Life is what happens when you're busy making other plans. - John Lennon",
        "The greatest glory in living lies not in never falling, but in rising every time we fall. - Nelson Mandela",
        "I have not failed. I've just found 10,000 ways that won't work. - Thomas Edison",
        "The best way to predict the future is to invent it. - Alan Kay",
        "Success is not final, failure is not fatal: It is the courage to continue that counts. - Winston Churchill",
        "The Eiffel Tower can be 15 cm taller during the summer due to thermal expansion",
        "The first computer virus was created in 1983 and was called the Elk Cloner.",
        "Cleopatra VII of Egypt lived closer in time to the moon landing than to the construction of the Great Pyramid of Giza",
        "The original name of Bank of America was Bank of Italy.",
        "The longest time between two twins being born is 87 days.",
        "Bananas are berries, but strawberries aren't",
        "The average person will spend six months of their life waiting for red lights to turn green",
        "Bees can recognize human faces.",
        "The electric chair was invented by a dentist",
        "The longest word in the English language is pneumonoultramicroscopicsilicovolcanoconiosis, which is a lung disease caused by inhaling very fine silicate or quartz dust.",
        "The original name of Google was Backrub."
    };

public:
    // Function to generate a single random fact or quote
    void generateRandom(string command) override ;

    // Function to generate multiple facts or quotes
    void generateMultipleRandom(string command) override;
};

// Derived class for Surah-specific functionalities
class Surah : public Nova
{
public:
    // Function to play Surah according to the command
    void playPeace(const string &mood);

    // Function to ask the command again
    bool askRepeat();
};

// Class to show the tips according to choice
class Tips: public Nova
{
public:
    // Function for study tips
    void studytips();

    // Function for interview tips with choices
    void InterviewTips(int choice);

    // Function for resume tips
    void ResumeTips();

    // Function to print job searching tips
    void JobSearchingTips();

    // Function to print Job alert tips
    void JobAlertTips();
};

class Website : public Nova {
protected:
    string url;

public:
    Website();  // Declaration of constructor
    virtual void callUrl() = 0;
    virtual ~Website();  // Declaration of virtual destructor
};

// Abstract Class derived from Website with unique search options
class UniqueWebsite: public Website
{
public:
    // Constructor to initialize data member
    UniqueWebsite();

    // Declaring an abstract class
    virtual void checkingAndProcessing(string reply)=0;
    virtual void reset()=0;
};

// Class to search in Youtube
class Youtube: public UniqueWebsite
{
public:
    // Constructot to initialize data member
    Youtube();

    // Destructor to delete objects
    ~Youtube();

    // Function to resest the link
    void reset();

    // Function to start the link
    void callUrl();

    // Function to operate according to the command
    void checkingAndProcessing(string reply);
};

// Class to search Leetcode profile
class Leetcode: public UniqueWebsite
{
public:
    // Constructor to initialize data member
    Leetcode();

    // Destructor to delete objects
    ~Leetcode();

    // Function to start the link
    void callUrl();

    // Function reset the link
    void reset();

    // Function to operate according to the command
    void checkingAndProcessing(string reply);
};

// Class to search in GitHub website
class GitHub: public UniqueWebsite
{
public:
    // Constructor to initialize data member
    GitHub();

    // Destructor to delete objects
    ~GitHub();

    // Function to start the link
    void callUrl();
    
    // Function to rest the link
    void reset();

    // Function to operate according to the command
    void checkingAndProcessing(string reply);
};

// Class to search in Anime website
class AnimeWeb: public UniqueWebsite
{
public:
    // Constructor to initialize data member
    AnimeWeb();

    // Destructor to delete objects
    ~AnimeWeb();

    // Function to start the link
    void callUrl();
    
    // Function to rest the link
    void reset();

    // Function to operate according to the command
    void checkingAndProcessing(string reply);
};

// Class for social media websites
class SocialMedia: public Website
{
public:
    // Function to start the link
    void callUrl();

    // Functions to open social media websites
    void openFacebook();

    void openInstagram();

    void openX();

    void openWhatsappWeb();

    void openLinkedin();

};

// Class for online meeting websites
class OnlineMeeting: public Website
{
public:
    // Function to start the link
    void callUrl();

    // Functions to open the online meeting websites
    void openMeet();

    void openZoom();
};

// Class for other miscellaneous websites
class Other: public Website
{
public:
    // Function to start the link
    void callUrl();

    // Functions to open other websites

    void openGoogleClassroom();

    void openChatGPT();

    void openDawn();

    void openJang();

    void openWeather();
};

// Class for ned websites
class Ned: public Website
{
public:
    // Function to start the link
    void callUrl();

    // Functions to open the ned websites
    void openCsitLeetcodeRankingBoard();

    void openNedWebCSIT();

    void openNedPortal();
};

#endif