#include <windows.h> // For Sleep() function, library used for operations in Windows Operating System
#include <cstdlib> // Library used for general purpose functions
#include <ctime> // For time() function, Library used for manipulating date and time functions
#include <string> // Library used for manipulation of strings
#include <iomanip>  // Library used for formatting input and output streams
#include <cctype> // For tolower() Library used for manipulation with individual characters
#include <fstream>
#include <sstream>
#include <vector>

#include "Nova.h"

using namespace std;

// Function to print the message with delay
    void Nova::delay(const string &message)
    {
        for (char c : message)
        {
            cout << "\033[1;36m";
            cout << c;
            Sleep(30);
        }
        cout << "\033[0m";
        cout << endl;
    }

    // Function to calculate components of time
    void Nova::calculatingtime()
    {
        time_t current = time(NULL); // To get the current time in seconds and store in the current variable
        tm *timeinfo = localtime(&current); // To get the componenrs like year, month etc

        day = timeinfo->tm_mday;
        month = 1 + timeinfo->tm_mon;
        year = 1900 + timeinfo->tm_year;
        hour = timeinfo->tm_hour;
        minute = timeinfo->tm_min;
        second = timeinfo->tm_sec;
    }

    // Functions to get the value of the components of time
    int Nova::getday()
    {
        return day;
    }
    int Nova::getmonth()
    {
        return month;
    }
    int Nova::getyear()
    {
        return year;
    }
    int Nova::gethour()
    {
        return hour;
    }
    int Nova::getmin()
    {
        return minute;
    }
    int Nova::getsec()
    {
        return second;
    }

    // Function to greet in the beginning
    void Nova::greetings()
    {
        // Calling to calculate the current time
        calculatingtime();

        if (hour >= 5 && hour < 12)
        {
        delay("Nova: Good Morning!");
        system("espeak -v en+f3 \"Good Morning\"");
        }
        else if (hour >= 12 && hour < 17)
        {
        delay("Nova: Good Afternoon!");
        system("espeak -v en+f3 \"Good Afternoon\"");
        }
        else if (hour >= 17 && hour < 21)
        {
        delay("Nova: Good Evening!");
        system("espeak -v en+f3 \"Good Evening\"");
        }
        else 
        {
        delay("Nova: Good Night!");
        system("espeak -v en+f3 \"Good Night\"");
        }
    }

    // Function to change the characters in the string to lowercase 
    void Nova::lower(string &command)
    {
        string result;
        for (char &c : command)
        {
            if (c != ' ')
            {
                result += tolower(c);
            }
        }
        command = result;
    }

    // Function to talk with Nova
    void Nova::talking(string command)
    {
        if (command == "hi" || command == "hello")
        {
            delay("Nova: Hello my friend! I hope you have a good day");
            system("espeak -v en+f3 \"Hello my friend! I hope you have a good day\"");
        }
        else if (command == "goodmorning" || command == "goodafternoon" || command == "goodevening" || command == "goodnight")
        {
            greetings();
            delay("How may I assist you today?");
            system("espeak -v en+f3 \"How may I assist you today\"");
        }
        else if (command == "howareyou" || command == "howareyoudoing" || command == "howareyoufeeling")
        {
            delay("Nova: I am doing well, thank you! How are you?");
            system("espeak -v en+f3 \"I am doing well, thank you! How are you?\"");
        }
        else if (command == "iamfine" || command == "iamdoingwell" || command == "fine" || command == "great" || command == "good")
        {
            delay("Nova: Glad to hear that! How may I help you today?");
            system("espeak -v en+f3 \"Glad to hear that! How may I help you today?\"");
        }
        else if (command == "ihateyou" || command == "youareboring" || command == "boring")
        {
            delay("Nova: I am sorry that you are feeling this way, is there something I can help you with to make you feel better?");
            system("espeak -v en+f3 \"I am sorry that you are feeling this way, is there something I can help you with to make you feel better\"");
        }
        else if (command == "rude" || command == "yourrude" || command == "youarebeingrude" || command == "youarerude")
        {
            delay("Nova: I apologize if I came across as rude. That was not my intention. How can I assist you better?");
            system("espeak -v en+f3 \"I apologize if I came across as rude. That was not my intention. How can I assist you better\"");
        }
        else if (command == "thankyou" || command == "thankyouforyourtime" || command == "thankyousomuch")
        {
            delay("Nova: You're welcome! If you have any more questions or need assistance with anything, feel free to ask.");
            system("espeak -v en+f3 \"You're welcome! If you have any more questions or need assistance with anything, feel free to ask\"");
        }
    }

    // Function to display date and time
    void dateTime::display_date_time()
    {
        // Calling the function to get all the information
        calculatingtime();

        // formatting date
        string daystr = to_string(getday());
        string monthstr = to_string(getmonth());
        string yearstr = to_string(getyear());
        string Date = daystr + '-' + monthstr + '-' + yearstr;

        delay("Nova: Date: ");
        delay(Date);
        string espeakCommand = "espeak -v en+f3 \"Date is" + Date + "\"";
        system(espeakCommand.c_str());

        // formatting time
        string hourstr = to_string(hour);
        string minstr = to_string(minute);
        string secstr = to_string(second);
        string time = hourstr + ':' + minstr + ':' + secstr;

        delay("Time:");
        delay(time);
        espeakCommand = "espeak -v en+f3 \"Time is" + time + "\"";
        system(espeakCommand.c_str());
    }

// Parametarized constructor
calendar::calendar(int y, int m) : yr(y), mon(m) {}

// Function to calculate number of days in month
int calendar::calculateDaysInMonth(int year, int month)
{
    if (mon == 2) // for february
    {
        if ((yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0)) // and also leap year
            return 29;
        else
            return 28; // if not leap year
    }
    else if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

// Function for calculating the first day
int calendar::calculateStartDay(int year, int month)
{ // Zellers congruence formula to calculate the first day of month
    int m = (mon > 2) ? mon : mon + 12;
    int D = yr % 100; // last two digits of year
    int C = yr / 100; // first two digits of year
    int f = (13 * (m + 1)) / 5 + D + D / 4 + C / 4 - 2 * C;
    return (f + 5 + 9) % 7;
}

// Function to get the name of the month
string calendar::getMonthName(int mon)
{
    static const string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    return months[mon - 1]; // it will return the month on the index month-1
}

// Function to display the calendar
void calendar::displayCalendar()
{
    int numDays = calculateDaysInMonth(yr, mon); // Get number of days from the function
    int startDay = calculateStartDay(yr, mon);   // Get first day from the function
    string styear = to_string(yr);

    // For printing Nova:
    string message = "Nova: ";
    for (char c : message)
    {
        cout << "\033[1;36m";
        cout << c;
        Sleep(30);
    }
    cout << "\033[0m";

    string display = "Calendar for " + getMonthName(mon) + ' ' + styear;

    delay(display);
    string espeakCommand = "espeak -v en+f3 \"" + display + "\"";
    system(espeakCommand.c_str());

    delay("Sun Mon Tue Wed Thu Fri Sat");

    for (int i = 0; i < startDay; ++i) // skip the days before the starting day
        cout << "    ";

    for (int day = 1; day <= numDays; ++day)
    { // loop for printing the calendar
        cout << setw(3) << day << " ";
        if ((startDay + day) % 7 == 0) // if one week is completed then change the line
            cout << endl;
    }

    cout << endl;
    cin.sync();
}

Task::Task(const string _title, const string _description, const string _date)
		: title(_title), description(_description),date(_date), isDone(false) {}

void TaskManager::addTask(const string title, const string description, const string date){
		tasks.emplace_back(title, description,date);
	}

	void TaskManager::deleteTask(int index){
		if (index>= 0 && index<tasks.size()){
			tasks.erase(tasks.begin() + index);
		}
	}

	void TaskManager::markTaskAsDone(int index){
		if (index>= 0 && index<tasks.size()){
			tasks[index].isDone = true;
		}
	}

	void TaskManager::exportTasks() {
		ofstream file(taskfile);
		if (file.is_open()){
			for (const auto& task : tasks){
				file<<task.title<<','<<task.description<<','<<task.date<<','<<task.isDone<<endl;
			}
			file.close();
			delay("Tasks exported successfully");
		}
		else {
			delay("Failed to export tasks");
            system("espeak -v en+f3\"Failed to export tasks\"");
		}
	}

	void TaskManager::importTasks(){
		tasks.clear();
		ifstream file(taskfile);
		if (file.is_open()) {
			string line;
			while (getline(file,line)) {
				stringstream ss(line);
				string title, description, date, isDoneStr;
				getline(ss, title, ',');
				getline(ss, description, ',');
				getline(ss, date, ',');
				getline(ss, isDoneStr, ',');
				bool isDone = (isDoneStr == "1");
				tasks.emplace_back(title, description, date);
				tasks.back().isDone = isDone;
			}
			file.close();
			delay("Tasks imported successfully.");
		}
		else {
			delay("Failed to import tasks.");
            system("espeak -v en+f3\"Failed to import tasks\"");
		}
	}
	void TaskManager::listtodaytask(){
        string current_date;
        calculatingtime();
		string daystr=to_string(day);
		string monthstr=to_string(month);
		string yearstr=to_string(year);
		current_date= monthstr + '/' + daystr + '/' + yearstr;
		bool foundTasks = false;
		int index =0;
		cout<<endl<<endl;
        delay("=======TODAY'S TASKS=======");
		for(int i=0;i<tasks.size();i++){
			if(tasks[i].date==current_date){
			cout<<index << ". ";
			cout<<"Title: "<<tasks[i].title<< ", ";
			cout<<"Description: "<<tasks[i].description<< ", ";
			cout<<"Date: "<<tasks[i].date<< ", ";
			cout<<"Status: "<<(tasks[i].isDone ? "Done" : "Not Done")<<endl;
			foundTasks=true;
			index++;
			}
		}
		 if (!foundTasks) {
        delay("No tasks on today's date");
        system("espeak -v en+f3\" No tasks on today's date\"");
    }
	}

	void TaskManager::listTasks() {
		int index = 0;
		cout<<endl<<endl;
        delay("======TASK LIST======");
		for (const auto& task : tasks) {
			cout<<index<< ". ";
			cout<<"Title: "<<task.title<<", ";
			cout<<"Description: "<<task.description<<", ";
			cout<<"Date: " <<task.date<<", ";
			cout<<"Status: " <<(task.isDone ? "Done" : "Not Done")<<endl;
			index++;
		}
		cout<<endl<<endl;
	}

    // Function to generate single random joke
void RandomJokeGenerator::generateRandom(string command) {
    srand(static_cast<unsigned int>(time(0)));
    if (command == "tellmeajoke" || command == "lightupmymood" || command == "thiswasnotfunny" ||
        command == "notfunny" || command == "thiswasnotfunnyatall" || command == "tellmeanotherjoke" ||
        command == "thisisnotfunny") {
        int index = rand() % 30;
        random = jokes[index];
        cout << "\033[1;36mNova: \033[0m";
        delay(random);
        espeakCommand = "espeak -v en+f3 \"" + random + "\"";
        system(espeakCommand.c_str());
    }
}

// Function to create multiple jokes
void RandomJokeGenerator::generateMultipleRandom(string command) {
    srand(static_cast<unsigned int>(time(0)));
    if (command == "tellmesomejokes" || command == "tellmesomejoke") {
        for (int i = 0; i < 3; i++) {
            cout << "\033[1;36mNova: \033[0m";
            random = jokes[i];
            delay(random);
            espeakCommand = "espeak -v en+f3 \"" + random + "\"";
            system(espeakCommand.c_str());
        }
    }
}

// Function to generate a single random fact or quote
void RandomFactOrQuoteGenerator::generateRandom(string command) {
    srand(static_cast<unsigned int>(time(0)));
    if (command == "tellmeafactorquote" || command == "showmeafactorquote" ||
        command == "displaymeafactorquote" || command == "displayaninterestingfactorquote" ||
        command == "factandquote" || command == "notinterestingshowagain") {
        int index = rand() % 37;
        random = facts[index];
        cout << "\033[1;36mNova: \033[0m";
        delay(random);
        espeakCommand = "espeak -v en+f3 \"" + random + "\"";
        system(espeakCommand.c_str());
    }
}

// Function to generate multiple facts or quotes
void RandomFactOrQuoteGenerator::generateMultipleRandom(string command) {
    srand(static_cast<unsigned int>(time(0)));
    if (command == "tellmemorefactsorquotes" || command == "showmemorefactsorquotes" ||
        command == "displaymemorefactsandquotes" || command == "displaymoreinterestingfactsandquotes") {
        for (int i = 0; i < 3; i++) {
            cout << "\033[1;36mNova: \033[0m";
            random = facts[i];
            delay(random);
            espeakCommand = "espeak -v en+f3 \"" + random + "\"";
            system(espeakCommand.c_str());
        }
    }
}

    // Function to play Surah according to the command
    void Surah::playPeace(const string &mood)
    {
        if (mood == "happy" || mood == "suraerehman")
        {
            delay("Nova: Opening Sura e Rehmaan");
            system("start rehman.mp3");
        }
        else if (mood == "sad" || mood == "suraeduha")
        {
            delay("Nova: Opening Sura e Duha");
            system("start duha.mp3");
        }
        else if (mood == "fear" || mood == "suraefalaq")
        {
            delay("Nova: Opening Sura e Falaq");
            system("start falaq.mp3");
        }
        else if (mood == "anger" || mood == "suraeisra")
        {
            delay("Nova: Opening Sura e Isra");
            system("start isra.mp3");
        }
        else if (mood == "disgust" || mood == "suraemasad")
        {
            delay("Nova: Opening Sura e Masad");
            system("start masad.mp3");
        }
        else if (mood == "guidance" || mood == "suraefatiha")
        {
            delay("Nova: Opening Sura e Fatiha");
            system("start fatiha.mp3");
        }
        else if (mood == "surprise" || mood == "suraetakwir")
        {
            delay("Nova: Opening Sura e Takwir");
            system("start takwir.mp3");
        }
        else if (mood == "gratitude" || mood == "suraeinsan")
        {
            delay("Nova: Opening Sura e Insan");
            system("start insan1.mp3");
        }
        else if (mood == "unity" || mood == "suraehujraat")
        {
            delay("Nova: Opening Sura e Hujraat");
            system("start hujrat.mp3");
        }
        else if (mood == "faith" || mood == "suraetalaq")
        {
            delay("Nova: Opening Sura e Talaq");
            system("start talaq.mp3");
        }
        else if (mood == "protection" || mood == "suraenas")
        {
            delay("Nova: Opening Sura e Nas");
            system("start nas.mp3");
        }
        else if (mood == "protection in travelling" || mood == "suraemulk")
        {
            delay("Nova: Opening Sura e Mulk");
            system("start mulk.mp3");
        }
        else if (mood == "forgiveness" || mood == "suraeikhlaas")
        {
            delay("Nova: Opening Sura e Ikhlaas");
            system("start ikhlas.mp3");
        }
        else if (mood == "spiritual consolation" || mood == "suraekafiroon")
        {
            delay("Nova: Opening Sura e Kafiroon");
            system("start kafiroon.mp3");
        }
        else if (mood == "discipline" || mood == "suraefajar")
        {
            delay("Nova: Opening Sura e Fajar");
            system("start fajar.mp3");
        }
        else if (mood == "enlightenment" || mood == "suraejin")
        {
            delay("Nova: Opening Sura e Jin");
            system("start jin.mp3");
        }
        else if (mood == "forGoodRelation" || mood == "suraekosar")
        {
            delay("Nova: Opening Sura e Kosar");
            system("start kosar.mp3");
        }
        else if (mood == "abundance" || mood == "suraewaqiyah")
        {
            delay("Nova: Opening Surah Waqiyah");
            system("start waqiyah.mp3");
        }
        else if (mood == "devotion" || mood == "suraemuzzammil")
        {
            delay("Nova: Opening Surah Muzzammil");
            system("start muzzammil.mp3");
        }
        else if (mood == "blessing" || mood == "suraeyasin")
        {
            delay("Nova: Opening Surah Yasin");
            system("start yasin.mp3");
        }
        else
        {
            delay("Nova: Sorry, I did not recognize your request.");
            system("espeak -v en+f3 \"Sorry, I did not recognize your request.\"");
        }
    }

    // Function to ask the command again
    bool Surah::askRepeat()
    {
        delay("Nova: Would you like to listen to another Surah? (yes/no)");
        system("espeak -v en+f3 \"Would you like to listen to another Surah?\"");
        cout << "You: ";
        string response;
        getline(cin, response);
        string result;
        for (char &c : response)
        {
            if (c != ' ')
            {
                result += tolower(c);
            }
        }
        return (result == "yes");
    }

    // Function for study tips
    void Tips::studytips()
    {
        delay("Nova: Study Tips");
        system("espeak -v en+f3 \"Study Tips\"");

        delay("1) Plan specific times for studying and stick to them. Consistency is key.");
        system("espeak -v en+f3 \"1 Plan specific times for studying and stick to them. Consistency is key\"");

        delay("2) Define what you want to achieve in each study session.");
        system("espeak -v en+f3 \"2 Define what you want to achieve in each study session.\"");

        delay("3) Study in intervals, such as 25-30 minutes of focused study followed by a 5-minute break.");
        system("espeak -v en+f3 \"3 Study in intervals, such as 25-30 minutes of focused study followed by a 5-minute break.\"");

        delay("4) Choose a quiet, well-lit place free from distractions.");
        system("espeak -v en+f3 \"4 Choose a quiet, well-lit place free from distractions.\"");

        delay("5) Keep your study materials and notes well-organized.");
        system("espeak -v en+f3 \"5 Keep your study materials and notes well-organized.\"");

        delay("6) Keep a positive attitude towards your studies and reward yourself for small achievements.");
        system("espeak -v en+f3 \"6 Keep a positive attitude towards your studies and reward yourself for small achievements.\"");
    }

    // Function for interview tips with choices
    void Tips::InterviewTips(int choice)
    {
        if (choice == 1)
        {
            delay("Nova: Preparation");
            system("espeak -v en+f3 \"Preparation\"");
            cout << endl;
            delay("1) Research the Company:");
            system("espeak -v en+f3 \"Research the Company\"");
            delay("* Understand the company's mission, values, products, and services.");
            system("espeak -v en+f3 \"Understand the company's mission, values, products, and services\"");
            delay("* Know the latest news about the company and its industry.");
            system("espeak -v en+f3 \"Know the latest news about the company and its industry\"");

            delay("2) Understand the Job Description:");
            system("espeak -v en+f3 \"Understand the Job Description\"");
            delay("* Review the job posting thoroughly.");
            system("espeak -v en+f3 \"Review the job posting thoroughly\"");
            delay("* Identify the key skills and experiences required.");
            system("espeak -v en+f3 \"Identify the key skills and experiences required\"");

            delay("3) Prepare Your Answers:");
            system("espeak -v en+f3 \"Prepare Your Answers\"");
            delay("* Practice common interview questions (e.g., Tell me about yourself, Why do you want to work here?).");
            system("espeak -v en+f3 \"Practice common interview questions (e.g., Tell me about yourself, Why do you want to work here?)\"");
            delay("* Use the STAR method (Situation, Task, Action, Result) to structure your answers for behavioral questions.");
            system("espeak -v en+f3 \"Use the STAR method (Situation, Task, Action, Result) to structure your answers for behavioral questions\"");

            delay("4) Know Your Resume:");
            system("espeak -v en+f3 \"Know Your Resume\"");
            delay("* Be ready to discuss everything on your resume in detail.");
            system("espeak -v en+f3 \"Be ready to discuss everything on your resume in detail\"");
            delay("* Highlight your accomplishments and how they relate to the job you're applying for.");
            system("espeak -v en+f3 \"Highlight your accomplishments and how they relate to the job you're applying for\"");

            delay("5) Prepare Questions for the Interviewer:");
            system("espeak -v en+f3 \"Prepare Questions for the Interviewer\"");
            delay("* Ask about the team, company culture, and next steps in the hiring process.");
            system("espeak -v en+f3 \"Ask about the team, company culture, and next steps in the hiring process\"");
            delay("* Avoid questions about salary and benefits in the initial interview.");
            system("espeak -v en+f3 \"Avoid questions about salary and benefits in the initial interview.\"");

            cin.sync();
        }

        else if (choice == 2)
        {
            delay("Nova: During the Interview");
            system("espeak -v en+f3 \"During the Interview\"");
            cout << endl;

            delay("1) First Impressions Matter:");
            system("espeak -v en+f3 \"First Impressions Matter\"");
            delay("* Dress appropriately for the company's culture.");
            system("espeak -v en+f3 \"Dress appropriately for the company's culture.\"");
            delay("* Arrive on time, or join the call promptly if it's a virtual interview.");
            system("espeak -v en+f3 \"Arrive on time, or join the call promptly if it's a virtual interview.\"");

            delay("2) Body Language:");
            system("espeak -v en+f3 \"Body Language\"");
            delay("* Offer a firm handshake (in person).");
            system("espeak -v en+f3 \"Offer a firm handshake (in person)\"");
            delay("* Maintain good eye contact.");
            system("espeak -v en+f3 \"Maintain good eye contact\"");
            delay("* Sit up straight and lean slightly forward to show interest.");
            system("espeak -v en+f3 \"Sit up straight and lean slightly forward to show interest\"");

            delay("3) Communication Skills:");
            system("espeak -v en+f3 \"Communication Skills\"");
            delay("* Speak clearly and confidently.");
            system("espeak -v en+f3 \"Speak clearly and confidently.\"");
            delay("* Listen actively and don't interrupt the interviewer.");
            system("espeak -v en+f3 \"Listen actively and don't interrupt the interviewer\"");
            delay("* Take a moment to think before answering questions if needed.");
            system("espeak -v en+f3 \"Take a moment to think before answering questions if needed.\"");

            delay("4) Show Enthusiasm:");
            system("espeak -v en+f3 \"Show Enthusiasm\"");
            delay("* Be positive and enthusiastic about the role and the company.");
            system("espeak -v en+f3 \"Be positive and enthusiastic about the role and the company\"");
            delay("* Show genuine interest in the job and the company's future.");
            system("espeak -v en+f3 \"Show genuine interest in the job and the company's future.\"");

            delay("5) Be Honest:");
            system("espeak -v en+f3 \"Be Honest\"");
            delay("* If you don't know the answer to a question, it's better to admit it than to make something up.");
            system("espeak -v en+f3 \"If you don't know the answer to a question, it's better to admit it than to make something up.\"");
            delay("* Highlight your willingness to learn and adapt.");
            system("espeak -v en+f3 \"Highlight your willingness to learn and adapt.\"");

            cin.sync();
        }

        else if (choice == 3)
        {
            delay("Nova: After the Interview: ");
            system("espeak -v en+f3 \"After the Interview\"");
            cout << endl;

            delay("1) Thank You Note:");
            system("espeak -v en+f3 \"Thank You Note\"");
            delay("* Send a thank-you email within 24 hours.");
            system("espeak -v en+f3 \"Send a thank-you email within 24 hours.\"");
            delay("* Reiterate your interest in the position and briefly mention a key point from the interview.");
            system("espeak -v en+f3 \"Reiterate your interest in the position and briefly mention a key point from the interview.\"");

            delay("2) Reflect on the Interview:");
            system("espeak -v en+f3 \"Reflect on the Interview\"");
            delay("* Note what went well and what could be improved for future interviews.");
            system("espeak -v en+f3 \"Note what went well and what could be improved for future interviews\"");
            delay("* Prepare for potential follow-up interviews by addressing any areas of weakness.");
            system("espeak -v en+f3 \"Prepare for potential follow-up interviews by addressing any areas of weakness\"");
            cin.sync();
        }

        else if (choice == 4)
        {
            delay("Nova: General Tips");
            system("espeak -v en+f3 \"General Tips\"");
            cout << endl;

            delay("1) Practice, Practice, Practice:");
            system("espeak -v en+f3 \"Practice, Practice, Practice\"");
            delay("* Do mock interviews with friends, family, or mentors.");
            system("espeak -v en+f3 \"Do mock interviews with friends, family, or mentors\"");
            delay("* Record yourself to improve your speaking and body language.");
            system("espeak -v en+f3 \"Record yourself to improve your speaking and body language.\"");

            delay("2) Stay Calm:");
            system("espeak -v en+f3 \"Stay Calm\"");
            delay("* Practice deep breathing or mindfulness techniques to manage anxiety.");
            system("espeak -v en+f3 \"Practice deep breathing or mindfulness techniques to manage anxiety.\"");
            delay("* Remember that it's a two-way street: you are also interviewing the company to see if it's a good fit for you.");
            system("espeak -v en+f3 \"Remember that it's a two-way street: you are also interviewing the company to see if it's a good fit for you.\"");

            delay("3) Know Your Worth:");
            system("espeak -v en+f3 \"Know Your Worth\"");
            delay("* Be prepared to discuss salary expectations if prompted, but do so based on research and your experience.");
            system("espeak -v en+f3 \"Be prepared to discuss salary expectations if prompted, but do so based on research and your experience.\"");

            delay("4) Follow Up:");
            system("espeak -v en+f3 \"Follow Up\"");
            delay("* If you haven't heard back within the expected timeframe, it's okay to follow up with a polite email to inquire about the status of your application.");
            system("espeak -v en+f3 \"If you haven't heard back within the expected timeframe, it's okay to follow up with a polite email to inquire about the status of your application.\"");
            cin.sync();
        }
    }

    // Function for resume tips
    void Tips::ResumeTips()
    {
        delay("Nova: RESUME TIPS:");
        system("espeak -v en+f3 \"RESUME TIPS\"");

        delay("* Header: Include your name, contact information, and LinkedIn profile.");
        system("espeak -v en+f3 \"Header: Include your name, contact information, and LinkedIn profile.\"");

        delay("* Tailor: Customize your resume for each job by highlighting relevant skills and experiences.");
        system("espeak -v en+f3 \"Tailor: Customize your resume for each job by highlighting relevant skills and experiences.\"");

        delay("* Summary Statement: Use a concise, professional summary to grab attention and showcase your key qualifications.");
        system("espeak -v en+f3 \"Summary Statement: Use a concise, professional summary to grab attention and showcase your key qualifications.\"");

        delay("* Work Experience: List in reverse chronological order with focus on achievements rather than just responsibilities.");
        system("espeak -v en+f3 \"Work Experience: List in reverse chronological order with focus on achievements rather than just responsibilities.\"");

        delay("* Use bullet points to quantify accomplishments (e.g., increased sales by 20%).");
        system("espeak -v en+f3 \"Use bullet points to quantify accomplishments (e.g., increased sales by 20%).\"");

        delay("* Skills Section: Include both hard and soft skills relevant to the job.");
        system("espeak -v en+f3 \"Skills Section: Include both hard and soft skills relevant to the job.\"");

        delay("* Education: List degrees and certifications with the most recent first.");
        system("espeak -v en+f3 \"Education: List degrees and certifications with the most recent first.\"");

        delay("* Formatting: Use clean, consistent formatting with easy-to-read fonts and sufficient white space.");
        system("espeak -v en+f3 \"Formatting: Use clean, consistent formatting with easy-to-read fonts and sufficient white space.\"");

        delay("* Language: Write professionally, avoiding jargon and using action verbs.");
        system("espeak -v en+f3 \"Language: Write professionally, avoiding jargon and using action verbs.\"");

        delay("* Proofread: Check thoroughly for typos and grammatical errors.");
        system("espeak -v en+f3 \"Proofread: Check thoroughly for typos and grammatical errors.\"");

        delay("* Length: Keep it to two pages maximum.");
        system("espeak -v en+f3 \" Length: Keep it to two pages maximum.\"");

        delay("* File Format: Save as a PDF for consistent formatting across different devices.");
        system("espeak -v en+f3 \"File Format: Save as a PDF for consistent formatting across different devices.\"");

        delay("* Additional Sections: Consider adding sections for volunteer work, projects, or professional affiliations if relevant to showcase a well-rounded profile.");
        system("espeak -v en+f3 \"Additional Sections: Consider adding sections for volunteer work, projects, or professional affiliations if relevant to showcase a well-rounded profile.\"");
    }

    // Function to print job searching tips
    void Tips::JobSearchingTips()
    {
        delay("Nova: JOB SEARCHING TIPS:");
        system("espeak -v en+f3 \"JOB SEARCHING TIPS.\"");

        delay("* Clarify Your Goals: Understand what type of job you're looking for, including industry, role, and location preferences.");
        system("espeak -v en+f3 \"Clarify Your Goals: Understand what type of job you're looking for, including industry, role, and location preferences\"");

        delay("* Update Your Resume: Tailor your resume to highlight relevant skills and experiences for each job application.");
        system("espeak -v en+f3 \"Update Your Resume: Tailor your resume to highlight relevant skills and experiences for each job application.\"");

        delay("* Utilize Job Search Engines: Use online job boards like Indeed, LinkedIn, Glassdoor, and company websites to find job postings.");
        system("espeak -v en+f3 \"Utilize Job Search Engines: Use online job boards like Indeed, LinkedIn, Glassdoor, and company websites to find job postings.\"");

        delay("* Network: Leverage your professional network through LinkedIn, alumni associations, and industry events. Networking can often lead to hidden job opportunities.");
        system("espeak -v en+f3 \"Network: Leverage your professional network through LinkedIn, alumni associations, and industry events. Networking can often lead to hidden job opportunities.\"");

        delay("* Attend Career Fairs: Attend local or virtual career fairs to connect with recruiters and learn about companies hiring in your field.");
        system("espeak -v en+f3 \"Attend Career Fairs: Attend local or virtual career fairs to connect with recruiters and learn about companies hiring in your field.\"");

        delay("* Follow Companies of Interest: Follow companies you're interested in on social media to stay updated on job openings and company news.");
        system("espeak -v en+f3 \"Follow Companies of Interest: Follow companies you're interested in on social media to stay updated on job openings and company news.\"");

        delay("* Customize Applications: Customize your cover letter and resume for each application to match the job requirements.");
        system("espeak -v en+f3 \"Customize Applications: Customize your cover letter and resume for each application to match the job requirements.\"");

        delay("* Prepare for Interviews: Research companies, practice common interview questions, and be ready to discuss your skills and experiences.");
        system("espeak -v en+f3 \"Prepare for Interviews: Research companies, practice common interview questions, and be ready to discuss your skills and experiences.\"");

        delay("* Stay Organized: Keep track of applications, interviews, and follow-ups using a spreadsheet or job search organizer.");
        system("espeak -v en+f3 \"Stay Organized: Keep track of applications, interviews, and follow-ups using a spreadsheet or job search organizer.\"");

        delay("* Be Persistent and Patient: Job searching can take time, so stay persistent in your efforts while remaining patient throughout the process.");
        system("espeak -v en+f3 \"Be Persistent and Patient: Job searching can take time, so stay persistent in your efforts while remaining patient throughout the process.\"");
    }

    // Function to print Job alert tips
    void Tips::JobAlertTips()
    {
        delay("Nova: TIPS FOR NOTIFYING JOB OPPORTUNITIES:");
        system("espeak -v en+f3 \"TIPS FOR NOTIFYING JOB OPPORTUNITIES\"");

        delay("* Utilize job search engines and company websites to create email alerts for new job postings that match your criteria.");
        system("espeak -v en+f3 \"Utilize job search engines and company websites to create email alerts for new job postings that match your criteria.\"");

        delay("NETWORK ACTIVELY:");
        system("espeak -v en+f3 \"NETWORK ACTIVELY\"");

        delay("* Inform your professional network (including LinkedIn connections, former colleagues, and friends) that you are actively seeking job opportunities. Networking can often lead to referrals and hidden job openings.");
        system("espeak -v en+f3 \"Inform your professional network (including LinkedIn connections, former colleagues, and friends) that you are actively seeking job opportunities. Networking can often lead to referrals and hidden job openings.\"");

        delay("ATTEND NETWORKING EVENTS:");
        system("espeak -v en+f3 \"ATTEND NETWORKING EVENTS\"");

        delay("* Participate in industry-specific events, job fairs, conferences, and seminars where you can meet professionals and recruiters in your field.");
        system("espeak -v en+f3 \"Participate in industry-specific events, job fairs, conferences, and seminars where you can meet professionals and recruiters in your field.\"");

        delay("UTILIZE SOCIAL MEDIA:");
        system("espeak -v en+f3 \"UTILIZE SOCIAL MEDIA\"");

        delay("* Follow companies you're interested in on social media platforms like LinkedIn, Twitter, and Facebook. Many organizations announce job openings on these channels.");
        system("espeak -v en+f3 \"Follow companies you're interested in on social media platforms like LinkedIn, Twitter, and Facebook. Many organizations announce job openings on these channels.\"");

        delay("JOIN PROFESSIONAL ASSOCIATIONS:");
        system("espeak -v en+f3 \"JOIN PROFESSIONAL ASSOCIATIONS\"");

        delay("* Become a member of relevant professional associations or groups in your industry. These organizations often have job boards and networking events.");
        system("espeak -v en+f3 \"Become a member of relevant professional associations or groups in your industry. These organizations often have job boards and networking events.\"");

        delay("REACH OUT TO RECRUITERS:");
        system("espeak -v en+f3 \"REACH OUT TO RECRUITERS\"");

        delay("* Connect with recruiters and staffing agencies specializing in your industry. They often have access to job openings that may not be advertised publicly.");
        system("espeak -v en+f3 \"Connect with recruiters and staffing agencies specializing in your industry. They often have access to job openings that may not be advertised publicly.\"");

        delay("CHECK COMPANY WEBSITES:");
        system("espeak -v en+f3 \"CHECK COMPANY WEBSITES\"");

        delay("* Regularly visit the careers pages of companies you're interested in. Some companies post job openings exclusively on their own websites.");
        system("espeak -v en+f3 \"Regularly visit the careers pages of companies you're interested in. Some companies post job openings exclusively on their own websites.\"");

        delay("STAY INFORMED ABOUT INDUSTRY TRENDS:");
        system("espeak -v en+f3 \"STAY INFORMED ABOUT INDUSTRY TRENDS\"");

        delay("* Follow industry news and trends to identify companies that are growing or expanding, as they may be hiring.");
        system("espeak -v en+f3 \"Follow industry news and trends to identify companies that are growing or expanding, as they may be hiring.\"");

        delay("MAINTAIN A STRONG ONLINE PRESENCE:");
        system("espeak -v en+f3 \"MAINTAIN A STRONG ONLINE PRESENCE\"");

        delay("* Ensure your LinkedIn profile is up to date and showcases your skills and experiences effectively. Recruiters often search for candidates on LinkedIn.");
        system("espeak -v en+f3 \"Ensure your LinkedIn profile is up to date and showcases your skills and experiences effectively. Recruiters often search for candidates on LinkedIn\"");

        delay("BE PROACTIVE:");
        system("espeak -v en+f3 \"BE PROACTIVE\"");

        delay("* Don't wait for job openings to be advertised. Reach out to companies directly with a targeted cover letter and resume, expressing your interest in working for them.");
        system("espeak -v en+f3 \"Don't wait for job openings to be advertised. Reach out to companies directly with a targeted cover letter and resume, expressing your interest in working for them.\"");
    }

    // Constructor to initialize data member
Website::Website() {
    url = "https://";
}

// Destructor to delete objects
Website::~Website() {}

    // Constructor to initialize data member
    UniqueWebsite::UniqueWebsite(){
        url += "www.";
    }

    // Constructot to initialize data member
    Youtube::Youtube()
    {
        url+="youtube.com";
    }

    // Destructor to delete objects
    Youtube::~Youtube(){};

    // Function to resest the link
    void Youtube::reset()
    {
        url="https://www.youtube.com";
    }

    // Function to start the link
    void Youtube::callUrl()
    {
        system(("start " + url).c_str());
    }

    // Function to operate according to the command
    void Youtube::checkingAndProcessing(string reply)
    {
        if (reply == "no")
        {
            delay("Nova: Opening YouTube");
            system("espeak -v en+f3 \"Opening YouTube\"");
            callUrl();
            reset();
        }
        else if (reply == "yes")
        {
            bool b = true;
            while (b)
            {
                string search;
                delay("Nova: What do you want to search?");
                system("espeak -v en+f3 \"What do you want to search?\"");
                cout << "You: ";
                getline(cin, search);
                delay("Nova: Opening YouTube");
                system("espeak -v en+f3 \"Opening YouTube\"");
                
                url += "/results?search_query=";
                for (char c : search)
                {
                    if (c == ' ')
                    {
                        url += '+';
                    }
                    else
                    {
                        url += c;
                    }
                }
                callUrl();
                reset();

                while (1)
                {
                    delay("Nova: Do you want to search anything else?");
                    system("espeak -v en+f3 \"Do you want to search anything else\"");
                    cout << "You: ";
                    string ans;
                    getline(cin, ans);
                    lower(ans);

                    if (ans == "no")
                    {
                        b = false;
                        break;
                    }
                    else if (ans == "yes")
                    {
                        b = true;
                        break;
                    }
                    else
                    {
                        delay("Nova: Sorry I couldn't comprehend.");
                        system("espeak -v en+f3 \"Sorry I couldn't comprehend.\"");
                    }
                }
            }
        }
        else
        {
            delay("Nova: Sorry I couldn't comprehend. Do you want to search on YouTube or not?");
            system("espeak -v en+f3 \"Sorry I couldn't comprehend. Do you want to search on YouTube or not?\"");
            cout << "You: ";
            getline(cin, reply);
            lower(reply);
            checkingAndProcessing(reply);
        }
    }

    // Constructor to initialize data member
    Leetcode::Leetcode()
    {
        url+="leetcode.com";
    }

    // Destructor to delete objects
    Leetcode::~Leetcode(){};

    // Function to start the link
    void Leetcode::callUrl()
    {
        system(("start " + url).c_str());
    }

    // Function reset the link
    void Leetcode::reset()
    {
        url="https://www.leetcode.com";
    }

    // Function to operate according to the command
    void Leetcode::checkingAndProcessing(string reply)
    {
        if (reply == "no")
        {
            delay("Nova: Opening Leetcode");
            system("espeak -v en+f3 \"Opening Leetcode\"");
            callUrl();
            reset();
        }
        else if (reply == "yes")
        {
            bool b = true;
            while (b)
            {
                string search;
                delay("Nova: Enter username = ");
                system("espeak -v en+f3 \"Enter username\"");
                cout << "You: ";
                getline(cin, search);
                delay("Nova: Opening Leetcode");
                system("espeak -v en+f3 \"Opening Leetcode\"");
                
                url += "/u/";
                url += search;
                url += '/';
                callUrl();
                reset();
                while (1)
                {
                    delay("Nova: Do you want to visit another profile?");
                    system("espeak -v en+f3 \"Do you want to visit another profile?\"");
                    string ans;
                    cout << "You: ";
                    getline(cin, ans);
                    lower(ans);
                    if (ans == "no")
                    {
                        b = false;
                        break;
                    }
                    else if (ans == "yes")
                    {
                        b = true;
                        break;
                    }
                    else
                    {
                        delay("Nova: Sorry I couldn't comprehend.");
                        system("espeak -v en+f3 \"Sorry I couldn't comprehend.\"");
                    }
                }
            }
        }
        else
        {
            delay("Nova: Sorry I couldn't comprehend. Do you want to visit leetcode profile or not?");
            system("espeak -v en+f3 \"Sorry I couldn't comprehend. Do you want to visit leetcode profile or not?\"");
            cout << "You: ";
            getline(cin, reply);
            lower(reply);
            checkingAndProcessing(reply);
        }
    }

    // Constructor to initialize data member
    GitHub::GitHub()
    {
        url+="github.com/";
    }

    // Destructor to delete objects
    GitHub::~GitHub(){};

    // Function to start the link
    void GitHub::callUrl()
    {
        system(("start " + url).c_str());
    }
    
    // Function to rest the link
    void GitHub::reset()
    {
        url="https://github.com/";
    }

    // Function to operate according to the command
    void GitHub::checkingAndProcessing(string reply)
    {
        if (reply == "no")
        {
            delay("Nova: Opening GitHub");
            system("espeak -v en+f3 \"Opening GitHub\"");
            callUrl();
            reset();
        }
        else if (reply == "yes")
        {
            int choice;
            delay("Nova: What do you want to search owner profile or repositories?");
            system("espeak -v en+f3 \"What do you want to search owner profile or repositories\"");
            delay("1) Owner profile.");
            system("espeak -v en+f3 \"One     Owner profile.\"");
            delay("2) Repositories.");
            system("espeak -v en+f3 \"Two     repositories.\"");
            delay("Select 1 or 2:");
            system("espeak -v en+f3 \"Select 1 or 2:\"");
            cout<<"You: ";
            cin>>choice;
            cin.sync();

            if(choice==1)
            {   
                bool b = true;
                while (b)
                {
                    string search;
                    delay("Nova: Enter owner name:");
                    system("espeak -v en+f3 \"Enter owner name\"");
                    cout << "You: ";
                    getline(cin, search);
                    delay("Nova: Opening GitHub");
                    system("espeak -v en+f3 \"Opening GitHub\"");
                    
                    for (char c : search)
                    {
                        if (c == ' ')
                        {
                            url += '+';
                        }
                        else
                        {
                            url += c;
                        }
                    }
                    callUrl();
                    reset();
                    while (1)
                    {
                        delay("Nova: Do you want to search another owner profile?");
                        system("espeak -v en+f3 \"Do you want to search another owner profile?\"");
                        string ans;
                        cout << "You: ";
                        getline(cin, ans);
                        lower(ans);
                        if (ans == "no")
                        {
                            b = false;
                            break;
                        }
                        else if (ans == "yes")
                        {
                            b = true;
                            break;
                        }
                        else
                        {
                            delay("Nova: Sorry I couldn't comprehend.");
                            system("espeak -v en+f3 \"Sorry I couldn't comprehend.\"");
                        }
                    }
                }
            }
            else if(choice==2)
            {   
                bool b = true;
                while (b)
                {
                    string search;
                    delay("Nova: What repository do you want to search?");
                    system("espeak -v en+f3 \"What repository do you want to search?\"");
                    cout << "You: ";
                    getline(cin, search);
                    delay("Nova: Opening GitHub");
                    system("espeak -v en+f3 \"Opening GitHub\"");

                    url += "search?q=";
                    
                    for (char c : search)
                    {
                        if (c == ' ')
                        {
                            url += '+';
                        }
                        else
                        {
                            url += c;
                        }
                    }

                    callUrl();
                    reset();
                    while (1)
                    {
                        delay("Nova: Do you want to search another repository?");
                        system("espeak -v en+f3 \"Do you want to search another repository?\"");
                        string ans;
                        cout << "You: ";
                        getline(cin, ans);
                        lower(ans);
                        if (ans == "no")
                        {
                            b = false;
                            break;
                        }
                        else if (ans == "yes")
                        {
                            b = true;
                            break;
                        }
                        else
                        {
                            delay("Nova: Sorry I couldn't comprehend.");
                            system("espeak -v en+f3 \"Sorry I couldn't comprehend.\"");
                        }
                    }
                }
            }
            else
            {
                delay("Inavlid option.");
                system("espeak -v en+f3 \"Inavlid option\"");
                checkingAndProcessing(reply);
            }
        }
        else
        {
            delay("Nova: Sorry I couldn't comprehend. Do you want to search owner profile or repositories?");
            system("espeak -v en+f3 \"Sorry I couldn't comprehend. Do you want to search owner profile or repositories?\"");
            cout << "You: ";
            getline(cin, reply);
            lower(reply);
            checkingAndProcessing(reply);
        }
    }

    // Constructor to initialize data member
    AnimeWeb::AnimeWeb()
    {
        url+="crunchyroll.com/";
    }

    // Destructor to delete objects
    AnimeWeb::~AnimeWeb(){};

    // Function to start the link
    void AnimeWeb::callUrl()
    {
        system(("start " + url).c_str());
    }
    
    // Function to rest the link
    void AnimeWeb::reset()
    {
        url="https://www.crunchyroll.com/";
    }

    // Function to operate according to the command
    void AnimeWeb::checkingAndProcessing(string reply)
    {
        if (reply == "no")
        {
            delay("Nova: Opening Anime Website");
            system("espeak -v en+f3 \"Opening Anime Website\"");
            callUrl();
            reset();
        }
        else if (reply == "yes")
        {
            bool b = true;
            while (b)
            {
                string search;
                delay("Nova: Which anime do you want to watch?");
                system("espeak -v en+f3 \"Which anime do you want to watch?\"");
                cout << "You: ";
                getline(cin, search);
                delay("Nova: Opening Anime Website");
                system("espeak -v en+f3 \"Opening Anime Website\"");
                
                url += "search?q=";
                for (char c : search)
                {
                    if (c == ' ')
                    {
                        url += '+';
                    }
                    else
                    {
                        url += c;
                    }
                }
                callUrl();
                reset();
                while (1)
                {
                    delay("Nova: Do you want to search another anime?");
                    system("espeak -v en+f3 \"Do you want to search another anime?\"");
                    string ans;
                    cout << "You: ";
                    getline(cin, ans);
                    lower(ans);
                    if (ans == "no")
                    {
                        b = false;
                        break;
                    }
                    else if (ans == "yes")
                    {
                        b = true;
                        break;
                    }
                    else
                    {
                        delay("Nova: Sorry I couldn't comprehend.");
                        system("espeak -v en+f3 \"Sorry I couldn't comprehend.\"");
                    }
                }
            }
        }
        else
        {
            delay("Nova: Sorry I couldn't comprehend. Do you want to search anime or not?");
            system("espeak -v en+f3 \"Sorry I couldn't comprehend. Do you want to search anime or not?\"");
            cout << "You: ";
            getline(cin, reply);
            lower(reply);
            checkingAndProcessing(reply);
        }
    }

    // Function to start the link
    void SocialMedia::callUrl()
    {
        system(("start " + url).c_str());
    }

    // Functions to open social media websites
    void SocialMedia::openFacebook()
    {
        delay("Nova: Opening Facebook");
        system("espeak -v en+f3 \"Opening Facebook\"");
        url += "www.facebook.com/";
        callUrl();
    }

    void SocialMedia::openInstagram()
    {
        delay("Nova: Opening Instagram");
        system("espeak -v en+f3 \"Opening Instagram\"");
        url += "www.instagram.com/";
        callUrl();
    }

    void SocialMedia::openX()
    {
        delay("Nova: Opening X");
        system("espeak -v en+f3 \"Opening X\"");
        url += "www.twitter.com/";
        callUrl();
    }

    void SocialMedia::openWhatsappWeb()
    {
        delay("Nova: Opening Whatsapp Web");
        system("espeak -v en+f3 \"Opening Whatsapp Web\"");
        url += "web.whatsapp.com/";
        callUrl();
    }

    void SocialMedia::openLinkedin()
    {
        delay("Nova: Opening Linkedin");
        system("espeak -v en+f3 \"Opening Linkedin\"");
        url += "www.linkedin.com/";
        callUrl();
    }

    // Function to start the link
    void OnlineMeeting::callUrl()
    {
        system(("start " + url).c_str());
    }

    // Functions to open the online meeting websites
    void OnlineMeeting::openMeet()
    {
        delay("Nove: Opening Google Meet");
        system("espeak -v en+f3 \"Opening Google Meet\"");
        url += "meet.google.com/";
        callUrl();
    }

    void OnlineMeeting::openZoom()
    {
        delay("Nove: Opening Zoom");
        system("espeak -v en+f3 \"Opening Zoom\"");
        url += "zoom.us/";
        callUrl();
    }

    // Function to start the link
    void Other::callUrl()
    {
        system(("start " + url).c_str());
    }

    void Other::openGoogleClassroom()
    {
        delay("Nova: Opening GoogleClassroom");
        system("espeak -v en+f3 \"Opening Google Classroom\"");
        url += "classroom.google.com/";
        callUrl();
    }

    void Other::openChatGPT()
    {
        delay("Nova: Opening ChatGPT");
        system("espeak -v en+f3 \"Opening ChatGPT\"");
        url += "chatgpt.com/";
        callUrl();
    }

    void Other::openDawn()
    {
        delay("Nova: Opening Dawn News Website");
        system("espeak -v en+f3 \"Opening Dawn News Website\"");
        url += "www.dawn.com/";
        callUrl();
    }

    void Other::openJang()
    {
        delay("Nova: Opening Jang News Website");
        system("espeak -v en+f3 \"Opening Jang News Website\"");
        url += "e.jang.com.pk/";
        callUrl();
    }

    void Other::openWeather()
    {
        delay("Nova: Opening Weather Update");
        system("espeak -v en+f3 \"Opening Weather Update\"");
        url += "www.google.com/search?q=weather";
        callUrl();
    }

    // Function to start the link
    void Ned::callUrl()
    {
        system(("start " + url).c_str());
    }

    // Functions to open the ned websites
    void Ned::openCsitLeetcodeRankingBoard()
    {
        delay("Nova: Opening CSIT Department Leetcode Ranking Board");
        system("espeak -v en+f3 \"Opening CSIT Department Leetcode Ranking Board\"");
        url += "cct.neduet.edu.pk/leetcodeRanking";
        callUrl();
    }

    void Ned::openNedWebCSIT()
    {
        delay("Nova: Opening NED Webite of CSIT department");
        system("espeak -v en+f3 \"Opening NED Webite of CSIT department\"");
        url+= "cct.neduet.edu.pk/";
        callUrl();
    }

    void Ned::openNedPortal()
    {
        delay("Nova: Opening NEDUET portal");
        system("espeak -v en+f3 \"Opening NEDUET portal\"");
        url += "pl.neduet.edu.pk/";
        callUrl();
    }