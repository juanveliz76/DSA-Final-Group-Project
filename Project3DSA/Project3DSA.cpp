// Project3DSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <chrono>
#include "Map.h"

using namespace std;
using namespace std::chrono;

int main()
{
    //Data Structure set up for Adjacency List
    map<string, vector<string>> graph;
    map<string, vector<string>>::iterator it;
    Map map1; 
	
    string choice1; 
    bool rightInput = false;
    vector <string> artistInquiredAbout; 
    vector<string> albumsLookedAt;
    vector<string> genresLookedAt; 

    cout << "Before we get started would you like to work with an Adjacent List or an Ordered Map ?" << endl;
    cout << "Type in AdjacencyList or Map " << endl;
    cin >> choice1; 
    



    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file("data.csv", ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ',')) {
                row.push_back(word);
            }
            content.push_back(row);
        }
    }
    else
        cout << "Could not open the file\n";


    while (rightInput == false) {

        if (choice1 == "AdjacencyList") {
            rightInput = true;
            for (int i = 0;i < content.size();i++)
            {
                for (int j = 0;j < content[i].size();j++)
                {
                    graph[content[i][2]].push_back(content[i][j]);
                }
            }
        }
        else if (choice1 == "Map") {
            rightInput = true;
            for (int i = 0;i < content.size();i++)
            {
                for (int j = 0;j < content[i].size();j++)
                {
                    
                    map1.insert1(content[i][1], content[i]);
                }
            }
        }

        else {
            cout << "Wrong Input please type Map or AdjacencyList to proceed" << endl;
            cin >> choice1;
        }

    }
    
    

    int choice;
    cout << "Hello Welcome back to Audio Library!" << endl;


    cout << "0. Exit" << endl;
    cout << "1. Search by Album Title" << endl;
    cout << "2. Search all albums by an artist" << endl;
    cout << "3. Search critically acclaimed albums in a given year" << endl;
    cout << "4. Search Albums Popular with Audiances in a given year" << endl;
    cout << "5. Search critically acclaimed albums in a genre" << endl;
    cout << "How can we help you ?" << endl;

    cin >> choice;

    while (choice != 0) {



        if (choice == 1) {


            if (choice1 == "AdjacencyList") {
                auto start = high_resolution_clock::now();
                string albumChoice;
                bool check = false;
                cout << "Which Album would you like to search ? " << endl;
                std::getline(std::cin >> std::ws, albumChoice);
                albumsLookedAt.push_back(albumChoice);
                for (it = graph.begin(); it != graph.end(); ++it)
                {
                    for (int i = 0; i < it->second.size();i++) {
                        if (it->second[i] == albumChoice) {
                            check = true;
                            cout << "Rank: " << it->second[i - 1] << endl;
                            cout << "Artist: " << it->second[i + 1] << endl;
                            cout << "Release Date: " << it->second[i + 2] << it->second[i + 3] << endl;
                            cout << "Summary: " << it->second[i + 4] << endl;
                            cout << "MetaScore: " << it->second[i + 5] << endl;
                            cout << "UserScore: " << it->second[i + 6] << endl;
                            cout << "Link: " << it->second[i + 7] << endl;
                            cout << "Img_URL: " << it->second[i + 8] << endl;
                        }
                    }
                }
                if (check == false) {
                    cout << "Sorry we could not find that album " << endl;
                }

                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
            }
            else if (choice1 == "Map") {

                auto start = high_resolution_clock::now();
                string albumChoice;
                cout << "Which Album would you like to search ? " << endl;
                std::getline(std::cin >> std::ws, albumChoice);
                albumsLookedAt.push_back(albumChoice);
                map1.choice1(albumChoice);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
            }

        }

        else if (choice == 2) {

            if (choice1 == "AdjacencyList") {
                auto start = high_resolution_clock::now();
                string choice2;
                bool check = false;
                int rankCheck = 0;
                int TitleCheck = 0;
                int releaseDateCheck = 0;
                int summaryCheck = 0;
                int metaScoreCheck = 0;
                int userScoreCheck = 0;
                int linkCheck = 0;
                int img_urlCheck = 0;
                cout << "What artist would you like to explore ?" << endl;
                std::getline(std::cin >> std::ws, choice2);
                artistInquiredAbout.push_back(choice2);
                for (it = graph.begin(); it != graph.end(); ++it)
                {

                    if (it->first == choice2) {
                        
                        check = true;
                        for (int i = 0; i < it->second.size();i++) {

                            if (rankCheck == 10) {
                                rankCheck = 0;
                            }
                            if (TitleCheck == 10) {
                                TitleCheck = 0;
                            }
                            if (releaseDateCheck == 10) {
                                releaseDateCheck = 0;
                            }

                            if (summaryCheck == 10) {
                                summaryCheck = 0;
                            }

                            if (metaScoreCheck == 10) {
                                metaScoreCheck = 0;
                            }

                            if (userScoreCheck == 10) {
                                userScoreCheck = 0;
                            }

                            if (linkCheck == 10) {
                                linkCheck = 0;
                            }

                            if (img_urlCheck == 10) {
                                img_urlCheck = 0;
                            }

                            if (rankCheck == 0) {
                                cout << endl << "Rank: ";

                            }
                            if (TitleCheck == 1) {
                                cout << "Album Title: ";
                            }
                            if (releaseDateCheck == 4) {
                                cout << "Release Date: ";
                            }
                            if (summaryCheck == 5) {
                                cout << "Summary: ";
                            }
                            if (metaScoreCheck == 6) {
                                cout << "MetaScore: ";
                            }

                            if (userScoreCheck == 7) {
                                cout << "User Score: ";
                            }
                            if (linkCheck == 8) {
                                cout << "Link : ";
                            }
                            if (img_urlCheck == 9) {
                                cout << "Img URL: ";
                            }
                            rankCheck++;
                            TitleCheck++;
                            releaseDateCheck++;
                            summaryCheck++;
                            metaScoreCheck++;
                            userScoreCheck++;
                            linkCheck++;
                            img_urlCheck++;

                            cout << it->second[i] << endl;
                        }
                    }

                }
                if (check == false) {
                    cout << "Sorry we could not find that artists " << endl;
                }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
            }

            else if (choice1 == "Map") {

                auto start = high_resolution_clock::now();
                string artistChoice;
                cout << "Which Artist would you like to search ? " << endl;
                std::getline(std::cin >> std::ws, artistChoice);
                artistInquiredAbout.push_back(artistChoice);
                map1.choice2(artistChoice);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

            }

        }



        else if (choice == 3) {
            if (choice1 == "AdjacencyList") {
                bool check = false;
                auto start = high_resolution_clock::now();
                string yearChoice;
                cout << "Which year would you like to search ?" << endl;
                cout << "Please place a - symbol in front of the year like so -2015 thanks" << endl;
                std::getline(std::cin >> std::ws, yearChoice);
                for (it = graph.begin(); it != graph.end(); ++it)
                {
                    for (int i = 0; i < it->second.size();i++) {
                        if (it->second[i].substr(0, it->second[i].size() - 1) == yearChoice) {
                            string rating = (it->second[i + 2]);
                            if (stoi(rating) > 87) {
                                check = true;
                                cout << "Album Title: " << it->second[i - 3] << endl;
                                cout << "Rank: " << it->second[i - 4] << endl;
                                cout << "Artist: " << it->second[i - 2] << endl;
                                cout << "Release Date: " << it->second[i - 1] << it->second[i] << endl;
                                cout << "Summary: " << it->second[i + 1] << endl;
                                cout << "MetaScore: " << it->second[i + 2] << endl;
                                cout << "UserScore: " << it->second[i + 3] << endl;
                                cout << "Link: " << it->second[i + 4] << endl;
                                cout << "Img_URL: " << it->second[i + 5] << endl;
                                cout << endl;
                            }
                        }
                    }

                }

                if (check == false) {
                    cout << "Sorry, we could not find data on that year please try 1999-2021" << endl;
                }

                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);

                cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

            }
            else if (choice1 == "Map") {
                auto start = high_resolution_clock::now();
                string yearChoice;
                cout << "Which year would you like to search ?" << endl;
                cout << "Please place a - symbol in front of the year like so -2015 thanks" << endl;
                std::getline(std::cin >> std::ws, yearChoice);
                map1.choice3(yearChoice);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
            }
        }
        else if (choice == 4) {

            if (choice1 == "AdjacencyList") {
                bool check = false;
                auto start = high_resolution_clock::now();
                string yearChoice;

                cout << "Which year would you like to search ?" << endl;
                cout << "Please place a - symbol in front of the year like so -2015 thanks" << endl;
                std::getline(std::cin >> std::ws, yearChoice);
                for (it = graph.begin(); it != graph.end(); ++it)
                {
                    for (int i = 0; i < it->second.size();i++) {
                        if (it->second[i].substr(0, it->second[i].size() - 1) == yearChoice) {
                            string rating = it->second[i + 3];
                            if (stof(rating) > 8.7) {
                                check = true;
                                cout << "Album Title: " << it->second[i - 3] << endl;
                                cout << "Rank: " << it->second[i - 4] << endl;
                                cout << "Artist: " << it->second[i - 2] << endl;
                                cout << "Release Date: " << it->second[i - 1] << it->second[i] << endl;
                                cout << "Summary: " << it->second[i + 1] << endl;
                                cout << "MetaScore: " << it->second[i + 2] << endl;
                                cout << "UserScore: " << it->second[i + 3] << endl;
                                cout << "Link: " << it->second[i + 4] << endl;
                                cout << "Img_URL: " << it->second[i + 5] << endl;
                                cout << endl;
                            }
                        }
                    }
                }


                if (check == false) {
                    cout << "Sorry, we could not find data on that year please try 1999-2021" << endl;
                }
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
            }

            else if (choice1 == "Map") {
                auto start = high_resolution_clock::now();
                string yearChoice;
                cout << "Which year would you like to search ?" << endl;
                cout << "Please place a - symbol in front of the year like so -2015 thanks" << endl;
                std::getline(std::cin >> std::ws, yearChoice);
                map1.choice4(yearChoice);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
            }
        }

        else if (choice == 5) {
            if (choice1 == "AdjacencyList") {
                string rating = "0";
                auto start = high_resolution_clock::now();
                string genreChoice;
                int index;
                bool check = false;
                cout << "Which Popular Genre would you like to search ?" << endl;
                cout << "Options are: Rap, Rock, Country, Latin, Indie, Jazz" << endl; 
                cout << "Please type a - before the genre for example -Rock, thank you " << endl;
                std::getline(std::cin >> std::ws, genreChoice);
                cout << "Here are critically acclaimed albums from that genre" << endl;
                genresLookedAt.push_back(genreChoice);
                for (it = graph.begin(); it != graph.end(); ++it)
                {
                    for (int i = 0; i < it->second.size();i++) {

                        int pos = 0;
                        while ((index = it->second[i].find(genreChoice, pos)) != string::npos) {
                            pos = index + 1;
                            if (i + 1 < it->second.size()) {
                                rating = it->second[i + 1];
                            }
                        }
                           
                            if (stoi(rating) > 87) {
                                rating = "0";
                                cout << "Album Title: " << it->second[i - 4] << endl;
                                cout << "Rank: " << it->second[i - 5] << endl;
                                cout << "Artist: " << it->second[i - 3] << endl;
                                cout << "Release Date: " << it->second[i - 2] << it->second[i - 1] << endl;
                                cout << "Summary: " << it->second[i] << endl;
                                cout << "MetaScore: " << it->second[i + 1] << endl;
                                cout << "UserScore: " << it->second[i + 2] << endl;
                                cout << "Link: " << it->second[i + 3] << endl;
                                cout << "Img_URL: " << it->second[i + 4] << endl;
                                cout << endl;
                            }
                        }
                }
                
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
            }

            else if (choice1 == "Map") {
                auto start = high_resolution_clock::now();
                string genreChoice;
                cout << "Which Popular Genre would you like to search ?" << endl;
                cout << "Options are: Rap, Rock, Country, Latin, Indie " << endl;
                cout << "Please type a - before the genre for example -Rock, thank you " << endl;
                std::getline(std::cin >> std::ws, genreChoice);
                genresLookedAt.push_back(genreChoice);
                cout << "Here are critically acclaimed albums from that genre" << endl;
                map1.choice5(genreChoice);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
            }
        }

        else {
            cout << "Non-Valid choice try again" << endl;
        }

        cout << "0. Exit" << endl;
        cout << "1. Search by Album Title" << endl;
        cout << "2. Search all albums by an artist" << endl;
        cout << "3. Search critically acclaimed albums in a given year" << endl;
        cout << "4. Search Albums Popular with Audiances in a given year" << endl;
        cout << "5. Search critically acclaimed albums in a genre" << endl;
        cout << "How can we help you ?" << endl;

        cin >> choice;
    }
    if (artistInquiredAbout.size() > 0 || albumsLookedAt.size() > 0 || genresLookedAt.size() > 0) {
        cout << "Thank you for using our app before you leave here is some info about your latest searches" << endl;
        if (artistInquiredAbout.size() > 0) {
            cout << "Artists you inquired about: " << endl;
            for (int i = 0; i < artistInquiredAbout.size();i++) {
                cout << artistInquiredAbout[i] << endl;
            }
        }
        if (albumsLookedAt.size() > 0) {
            cout << "Albums you inquired about: " << endl;
            for (int j = 0; j < albumsLookedAt.size();j++) {
                cout << albumsLookedAt[j] << endl;
            }
        }
        if (genresLookedAt.size() > 0) {
            cout << "Genres you inquired about:" << endl;
            for (int k = 0; k < genresLookedAt.size();k++) {
                cout << genresLookedAt[k] << endl;
            }
        }
    }
    else if (artistInquiredAbout.size() == 0 && albumsLookedAt.size() == 0 && genresLookedAt.size() == 0) {
        cout << "Thank you for using our app, see you later" << endl;
    }
	return 0;
}
