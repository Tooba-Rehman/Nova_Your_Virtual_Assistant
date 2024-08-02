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

#include "Nova.h"

using namespace std;

int main()
{
    // Variable initialization
    string command;

    // Main class object initialization
    Nova n;

    cout << "\033[1;36m";
    cout << "\t\t##################################### NOVA VIRTUAL ASSISTANT ############################################" << endl
         << endl;
    cout << "\033[0m";

    // For introduction
    n.greetings();
    n.delay("I am Nova, Your Virtual Assistant! How may I help you?");
    system("espeak -v en+f3 \"I am Nova, Your Virtual Assistant! How may I help you?\"");

    // Loop to ask for the command and act accordingly
    while (true)
    {   
        cout << "You: ";
        getline(cin, command);
        n.lower(command);

        if (command == "showdateandtime" || command == "givemedateandtime" || command == "whatisthedateandtime")
        {
            dateTime dt;
            dt.display_date_time();
        }
        else if(command=="showcalendar" || command=="displaycalendar"){
           
            int mon;
            int year=2024;

            string message = "Nova: ";
            for (char c : message)
            {
                cout << "\033[1;36m";
                cout << c;
                Sleep(30);
            }
            cout << "\033[0m";
            n.delay("Enter the month 1-12 = ");
            system("espeak -v en+f3 \"Enter the month\"");
            cin >> mon;
            calendar c(2024,mon);
           c.displayCalendar();
        }
        else if (command == "opentaskmanager")
        {
            TaskManager taskManager;

	// Load existing tasks
	taskManager.importTasks();

	int choice;
	string title, description, date;
	do {
		n.delay("Nova: Task Manager");
        system("espeak -v en+f3 \"Task Manager\"");
		n.delay("1. Add Task");
        system("espeak -v en+f3 \"1. Add Task\"");
		n.delay("2. Delete Task");
        system("espeak -v en+f3 \"2.Dlete Task\"");
		n.delay("3. Mark Task as Done");
        system("espeak -v en+f3 \"3. Mark Task as Done\"");
	    n.delay("4. List Tasks");
        system("espeak -v en+f3 \"4. List Tasks\"");
        n.delay("5. Display today tasks");
        system("espeak -v en+f3 \"5. Display today tasks\"");
		n.delay("6. Exit");
        system("espeak -v en+f3 \"6. Exit\"");
		n.delay("Enter your choice:");
        system("espeak -v en+f3 \"Enter your choice\"");
		cin>>choice;

		switch (choice) {
		case 1:
			{n.delay("Enter task title: ");
            system("espeak -v en+f3 \"Enter task title\"");
			cin.ignore();
			getline(cin, title);
			n.delay("Enter task description: ");
            system("espeak -v en+f3 \"Enter task description\"");
			getline(cin, description);
			n.delay("Enter task date:");
            system("espeak -v en+f3 \"Enter task date\"");
			getline(cin,date);
			taskManager.addTask(title, description , date);
			break;}
		case 2:
			{n.delay("Enter the task index to delete: ");
            system("espeak -v en+f3 \"Enter the task index to delete\"");
			int deleteIndex;
			cin>>deleteIndex;
			taskManager.deleteTask(deleteIndex);
			break;}
		case 3:
			{n.delay("Enter the task index to mark as done: ");
            system("espeak -v en+f3 \"Enter the task index to mark as done\"");
			int doneIndex;
			cin>>doneIndex;
			taskManager.markTaskAsDone(doneIndex);
			break;}
		case 4:
			taskManager.listTasks();
			break;
		case 5:
		      taskManager.listtodaytask();
			  break;	
		case 6:
			// Save tasks before exiting
			taskManager.exportTasks();
			n.delay("Exiting the Task manager");
            system("espeak -v en+f3 \"Exiting the Task manager\"");
			break;
		default:
			n.delay("Invalid choice. Please try again.");
            system("espeak -v en+f3 \"Invalid choice. Please try again\"");
			break;
		}

	} while (choice != 6);
        cin.sync();
            
        }
        else if (command == "hello" || command == "hi" || command == "goodmorning" || command == "goodafternoon" || command == "goodevening" || command == "howareyou" 
            || command == "howareyoudoing" || command == "howareyoufeeling" || command == "iamfine" || command == "iamdoingwell" || command == "fine" 
            || command == "great" || command == "good" || command == "ihateyou" || command == "youareboring" || command == "rude" || command == "yourrude" 
            || command == "youarebeingrude" || command == "youarerude" || command == "thankyou" || command == "thankyouforyourtime" || command == "thankyousomuch" 
            || command == "boring" || command == "goodnight")
        {
            n.talking(command);
        }
        else if (command == "tellmeajoke" || command == "lightupmymood" || command == "tellmeanotherjoke" )
        {
            RandomJokeGenerator jokeGenerator;
            jokeGenerator.generateRandom(command);
        }
        else if(command == "thiswasnotfunny" || command == "notfunny" || command == "thiswasnotfunnyatall" || command == "thisisnotfunny")
        {
            RandomJokeGenerator jokeGenerator;
            n.delay("Nova: My bad, let me know if you like this one");
            system("espeak -v en+f3 \"My bad, let me know if you like this one\"");
            jokeGenerator.generateRandom(command);

        }
        else if (command == "tellmesomejokes" || command == "tellmesomejoke")
        {
            RandomJokeGenerator jokeGenerator;
            jokeGenerator.generateMultipleRandom(command);
        }
        else if (command == "whatisthelatestnews" || command == "newsupdate" || command == "updateaboutnews" || command == "opennewswebsite" || command == "opennews" || command == "whatisthenews")
        {
            Other o;
            string choice;

            while (true)
            {
                n.delay("Nova: Do you want news in English or Urdu? ");
                system("espeak -v en+f3 \"Do you want news in English or Urdu?\"");
                cout << "You: ";
                cin >> choice;
                for (char &c : choice)
                {
                    c = tolower(c);
                }

                if (choice == "english" || choice == "urdu")
                {
                    break;
                }
                else
                {
                    n.delay("Nova: Invalid choice");
                    system("espeak -v en+f3 \"Invalid choice\"");
                }
            }

            if (choice == "english")
            {
                o.openDawn();
            }
            else
            {
                o.openJang();
            }

            cin.sync();
        }
        else if (command == "giveweatherupdates" || command == "whatistheweather" || command == "tellmetheweather" || command == "weatherupdate")
        {
            Other o;
            o.openWeather();
        }
        else if (command == "tellmeafactorquote" || command == "showmeafactorquote" ||
                 command == "displaymeafactorquote" || command == "displayaninterestingfactorquote")
        {
            RandomFactOrQuoteGenerator factOrQuoteGenerator;
            factOrQuoteGenerator.generateRandom(command);
        }
        else if(command == "notinterestingshowagain" || command == "thisiscommonshowanother")
        {
            RandomFactOrQuoteGenerator factOrQuoteGenerator;
            n.delay("Nova: My bad, let me know if you like this one");
            system("espeak -v en+f3 \"My bad, let me know if you like this one\"");
            factOrQuoteGenerator.generateRandom(command);
        }
        else if (command == "tellmemorefactsorquotes" || command == "showmesomefactsorquotes" ||
                 command == "displaymesomefactsorquotes" || command == "displaysomeinterestingfactsorquotes" ||
                 command == "showmesomefactsorquotes")
        {
            RandomFactOrQuoteGenerator factOrQuoteGenerator;
            factOrQuoteGenerator.generateMultipleRandom(command);
        }

        else if (command == "playpeace" || command == "calmmysoul")
        {
            Surah s;
            do
            {
                s.delay("Nova: How is your feeling today? Kindly express your feeling in one word...");
                system("espeak -v en+f3 \"How is your feeling today? Kindly express your feeling in one word...\"");

                cout << "You: ";
                string mood;
                getline(cin, mood);
                s.lower(mood);
                s.playPeace(mood);

            } while (s.askRepeat());
        }
        else if (command == "playsurah")
        {
            Surah s;
            do
            {
                s.delay("Nova: There are the following Surahs in the system. Which Surah do you want to listen to? Kindly enter the name of the Surah...\n"
                        "1. Sura e Rehman\n"
                        "2. Sura e Yasin\n"
                        "3. Sura e Duha\n"
                        "4. Sura e Fajr\n"
                        "5. Sura e Falaq\n"
                        "6. Sura e Fatiha\n"
                        "7. Sura e Hujraat\n"
                        "8. Sura e Ikhlas\n"
                        "9. Sura e Insan\n"
                        "10. Sura e Isra\n"
                        "11. Sura e Jin\n"
                        "12. Sura e Kafiroon\n"
                        "13. Sura e Kosar\n"
                        "14. Sura e Mulk\n"
                        "15. Sura e Nas\n"
                        "16. Sura e Takwir\n"
                        "17. Sura e Talaq\n"
                        "18. Sura e Muzzammil\n"
                        "19. Sura e Waqiyah\n"
                        "20. Sura e Masad");

                cout << "You: ";
                string reply;
                getline(cin, reply);
                s.lower(reply);
                s.playPeace(reply);

            } while (s.askRepeat());
        }
        else if (command == "studytips" || command == "howtostudy" || command == "givemestudytips" || command == "givestudytips" || command == "tellmestudytips" || command == "tellmesomestudytips")
        {
            Tips t;
            t.studytips();
        }
        else if (command == "giveinterviewtips" || command == "givemeinterviewtips" || command == "interviewtips" || command == "tellmeinterviewtips" || command == "giveinterviewtip" || command == "givemeinterviewtip" || command == "interviewtip" || command == "tellmeinterviewtip")
        {
            Tips t;
            n.delay("Nova: Enter 1-4 number according to the below options:");
            system("espeak -v en+f3 \"Enter 1 to 4 number according to the below options\"");
            n.delay("1) Interview Preparation tips");
            system("espeak -v en+f3 \"One    Interview Preparation tips\"");
            n.delay("2) During the Interview tips");
            system("espeak -v en+f3 \"Two    During the Interview tips\"");
            n.delay("3) After the Interview tips");
            system("espeak -v en+f3 \"Three     After the Interview tips\"");
            n.delay("4) General tips");
            system("espeak -v en+f3 \"Four      General tips\"");

            int choice;
            bool b = true;

            while (b)
            {
                cin.sync();
                cout << "You: ";
                cin >> choice;
                if (choice >= 1 && choice <= 4)
                {
                    b = false;
                }
                else
                {
                    n.delay("Nova: Invalid choice. Please enter a number between 1 and 4.");
                    system("espeak -v en+f3 \"Invalid choice. Please enter a number between 1 and 4.\"");
                }
            }
            t.InterviewTips(choice);
        }
        else if (command == "giveresumetips" || command == "givemeresumetips" || command == "resumetips" || command == "tellmeresumetips" 
            || command == "giveresumetip" || command == "givemeresumetip" || command == "resumetip" || command == "tellmeresumetip")
        {
            Tips t;
            t.ResumeTips();
        }
        else if (command == "givejobsearchingtips" || command == "givemetipsforjobsearching" || command == "givemejobsearchingtips" || command == "jobsearchingtips" 
            || command == "tellmejobsearchingtips" || command == "givejobsearchingtip" || command == "givemejobsearchingtip" || command == "jobsearchingtip" 
            || command == "tellmejobsearchingtip")
        {
            Tips t;
            t.JobSearchingTips();
        }
        else if (command == "givetipsfornotifyingjobopportunities" || command == "givetipsforjobalert" || command == "givejobalertingtips" 
            || command == "givenotifyingjobopportunitiestips" || command == "tellmetipsfornotifyingjobopportunities" || command == "tellmetipsforjobalert" 
            || command == "tellmejobalertingtips" | command == "tellmenotifyingjobopportunitiestips")
        {
            Tips t;
            t.JobAlertTips();
        }
        else if (command == "openyoutube" || command == "youtube")
        {
            n.delay("Nova: Do you want to search on YouTube?");
            system("espeak -v en+f3 \"Do you want to search on YouTube?\"");
            cout << "You: ";
            string reply;
            getline(cin, reply);
            Youtube y;
            y.lower(reply);
            y.checkingAndProcessing(reply);
        }
        else if (command == "leetcode" || command == "openleetcode")
        {
            n.delay("Nova: Do you want to visit leetcode profile?");
            system("espeak -v en+f3 \"Do you want to visit leetcode profile?\"");
            cout << "You: ";
            string reply;
            getline(cin, reply);
            Leetcode l;
            l.lower(reply);
            l.checkingAndProcessing(reply);
        }
        else if (command == "opengithub" || command == "github")
        {
            n.delay("Nova: Do you want to search owner profile or repository?");
            system("espeak -v en+f3 \"Do you want to search owner profile or repository?\"");
            cout << "You: ";
            string reply;
            getline(cin, reply);
            GitHub g;
            g.lower(reply);
            g.checkingAndProcessing(reply);
        }
        else if (command == "animewebsite" || command == "openanimewebsite" || command == "iwanttowatchanime" || command == "iwannawatchanime")
        {
            n.delay("Nova: Do you want to search anime?");
            system("espeak -v en+f3 \"Do you want to search anime?\"");
            cout << "You: ";
            string reply;
            getline(cin, reply);
            AnimeWeb a;
            a.lower(reply);
            a.checkingAndProcessing(reply);
        }
        else if (command == "opennedportal" || command == "nedportal")
        {
            Ned ned;
            ned.openNedPortal();
        }
        else if (command == "opencsitleetcoderankingboard" || command == "csitleetcoderankingboard")
        {
            Ned ned;
            ned.openCsitLeetcodeRankingBoard();
        }
        else if (command == "openlinkedin" || command == "linkedin")
        {
            SocialMedia s;
            s.openLinkedin();
        }
        else if (command == "openchatgpt" || command == "chatgpt")
        {
            Other o;
            o.openChatGPT();
        }
        else if (command == "openwhatsappweb" || command == "whatsappweb")
        {
            SocialMedia s;
            s.openWhatsappWeb();
        }
        else if (command == "opengoogleclassroom" || command == "googleclassroom")
        {
            Other o;
            o.openGoogleClassroom();
        }
        else if (command == "openzoom" || command == "zoom")
        {
            OnlineMeeting om;
            om.openZoom();
        }
        else if (command == "opengooglemeet" || command == "googlemeet")
        {
            OnlineMeeting om;
            om.openMeet();
        }
        else if (command == "facebook" || command == "openfacebook")
        {
            SocialMedia s;
            s.openFacebook();
        }
        else if (command == "instagram" || command == "openinstagram")
        {
            SocialMedia s;
            s.openInstagram();
        }
        else if (command == "twitter" || command == "opentwitter" || command == "openx" || command == "x")
        {
            SocialMedia s;
            s.openX();
        }
        else if (command == "opennedwebsite" || command == "nedwebsite" || command == "opennedwebsiteofcsitdepartment" | command == "nedwebsiteofcsitdepartment")
        {
            Ned ned;
            ned.openNedWebCSIT();
        }
        else if (command == "exit" || command == "close" || command == "closetheprogram")
        {
            n.delay("Nova: Closing the program");
            system("espeak -v en+f3 \"Closing the program\"");
            break;
        }
        else
        {
            n.delay("Nova: Sorry, I could not understand your request");
            system("espeak -v en+f3 \"Sorry, I could not understand your request\"");
        }
    }
    return 0;
}