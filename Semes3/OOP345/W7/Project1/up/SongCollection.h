//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NEE
// Day:				March 19th 2020
// Workshop:       	7
//==============================================
#ifndef SONGCOLLECTION_H
#define SONGCOLLECTION_H
#include <iostream>
#include <vector>
#include <list>

namespace sdds {
	struct Song {
		std::string artist;
		std::string title;
		std::string album;
		double m_price;
		std::string releaseYear;
		std::string lengthOfSong;
	};

	class SongCollection {
	private:
		std::vector<Song> collections;
		int listenTime;
		std::string totalTime;
	public:
		void trimSpace(std::string& value);
		std::string timeFormat(const int seconds);
		SongCollection(const std::string filename);
		void display(std::ostream& out) const;
		void sort(const std::string field);
		void cleanAlbum();
		bool inCollection(const std::string artistName) const;
		std::list<Song> getSongsForArtist(const std::string artistName) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);

}
#endif // !SONGCOLLECTION_H
