//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:				March 19th 2020
// Workshop:       	7
//==============================================
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <list>


#include "SongCollection.h"

using namespace std;

namespace sdds {
    void SongCollection::trimSpace(string& value) {
        if (any_of(value.begin(), value.end(), [](char check) {return check != ' '; }))
        {
            while (true) {
                if (value[0] != ' ') {
                    if (value[value.length() - 1] != ' ') {
                        break;
                    }
                    else {
                        value.erase(value.length() - 1, value.find(' ') + 1);
                    }
                }
                else {
                    value.erase(0, value.find(' ') + 1);
                }
            }
        }
        else {
            value = "";
        }
    }

	SongCollection::SongCollection(const std::string filename) {
        listenTime = 0;
        fstream file(filename);
        while (!file.eof()) {
            Song* song = new Song;
            string str, title, artist, album, price, releaseYear, lengthOfSong;
            getline(file, str, '\n');
            title = str.substr(0, 25);
            str.erase(0, 25);

            artist = str.substr(0, 25);
            str.erase(0, 25);

            album = str.substr(0, 25);
            str.erase(0, 25);

            releaseYear = str.substr(0, 5);
            str.erase(0, 5);

            lengthOfSong = str.substr(0, 5);
            str.erase(0, 5);

            price = str.substr(0, 5);
            str.erase(0, 5);

            trimSpace(title);
            trimSpace(artist);
            trimSpace(album);
            trimSpace(releaseYear);
            trimSpace(lengthOfSong);
            trimSpace(price);

            song->title = title;
            song->artist = artist;
            song->album = album;
            song->m_price = stod(price);
            song->releaseYear = releaseYear;
            song->lengthOfSong = timeFormat(stoi(lengthOfSong));
            listenTime += stoi(lengthOfSong);
            

            collections.push_back(*song); 
            delete song;
        }
        totalTime = timeFormat(listenTime);
        file.close();
	}

    std::string SongCollection::timeFormat(const int seconds) {
        if (seconds >= 3600) {
            int h = seconds / 3600;
            int m = seconds / 60 - h * 60;
            int s = seconds % 60;
            stringstream ss;
            ss << h << ":" << std::setfill('0') << std::setw(2) << m << ":" << std::setfill('0') << std::setw(2) << s;
            return ss.str();
        }
        else {
            int min = seconds / 60;
            int second = seconds % 60;
            stringstream ss;
            ss << min << ":" << std::setfill('0') << std::setw(2) << second;
            return ss.str();
        }
    }

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
        out << "| " << left << setw(20) << theSong.title << " |";
        out << " " << left << setw(15) << theSong.artist << " |";
        out << " " << left << setw(20) << theSong.album << " |";
        out << " " << right << setw(6) << theSong.releaseYear << " |";
        out << " " << theSong.lengthOfSong << " |";
        out << " " << std::setprecision(2) << std::fixed << theSong.m_price << " |";
        return out;
	}

    void SongCollection::display(std::ostream& out) const {
        for_each(collections.begin(), collections.end(), [&](const Song theSong) {
            out << theSong << endl;
            });
        out << "----------------------------------------------------------------------------------------" <<std::endl;
        out << "| " << right << setw(77) << "Total Listening Time: " << totalTime << " |" << endl;
    }

    void SongCollection::sort(const std::string field) {
        std::sort(collections.begin(), collections.end(), [field](Song s1, Song s2) {
            if (field == "title") {
                return s1.title < s2.title;
            }
            else {
                if (field == "album") {
                    return s1.album < s2.album;
                }
                else {
                    if (field == "length") {
                        return s1.lengthOfSong < s2.lengthOfSong;
                    }
                    else {
                        throw "Invalid field!";
                    }
                }
            }
        });
    }

    void SongCollection::cleanAlbum() {
        std::transform(collections.begin(), collections.end(), collections.begin(), [](Song& song) {
            if (song.album == "[None]") {
                song.album.clear();
            }
            return song;
            });
    }

    bool SongCollection::inCollection(const std::string artistName) const {
        return std::any_of(collections.begin(), collections.end(), [artistName](const Song& song) {
            return (song.artist == artistName);
            });
    }

    std::list<Song> SongCollection::getSongsForArtist(const std::string artistName) const {
        std::list<Song> filteredSong(collections.size());
        filteredSong.resize(std::distance(filteredSong.begin(), std::copy_if(collections.begin(), collections.end(), filteredSong.begin(), [artistName](const Song& song) {
            return (song.artist == artistName);
            })));
        return filteredSong;
    }
}