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
            value = " ";
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
        out << "| " << setw(20) << left << theSong.title << " |";
        out << " " << setw(15) << left << theSong.artist << " |";
        out << " " << setw(20) << left << theSong.album << " |";
        out << " " << setw(6) << right << theSong.releaseYear << " |";
        out << " " << left << theSong.lengthOfSong << " |";
        out << " " << left << theSong.m_price << " |";
        return out;
	}

    void SongCollection::display(std::ostream& out) const {
        for_each(collections.begin(), collections.end(), [&](const Song theSong) {
            out << theSong << endl;
            });
        out << "----------------------------------------------------------------------------------------" << endl;
        out << "| " << right << "Total Listening Time: " + totalTime << " |" << endl;
        out << "----------------------------------------------------------------------------------------" << endl;
    }

    void SongCollection::sort(const std::string field) {
        std::sort(collections.begin(), collections.end(), [field](Song s1, Song s2) {
            if (field == "title") {
                return s1.title < s2.title;
            }
            if (field == "album") {
                return s1.album < s2.album;
            }
            if (field == "length") {
                return s1.lengthOfSong < s2.lengthOfSong;
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
        std::list<Song> filteredSong;
        auto filter = std::copy_if(collections.begin(), collections.end(), filteredSong.begin(), [artistName](const Song& song) {
            return (song.artist == artistName);
            });
        filteredSong.resize(std::distance(filteredSong.begin(), filter));
        return filteredSong;
    }
}