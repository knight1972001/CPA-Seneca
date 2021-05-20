//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    June 19th 2020
// Workshop:       	4 (Part 2)
//==============================================
#ifndef _SAIYAN_H
#define _SAIYAN_H

namespace sdds {
	class Saiyan {
	private:
		char *m_name;
		int m_level;
		int m_dob;
		int m_power;
		bool m_super;
	public:
		Saiyan();
		~Saiyan();
		Saiyan(const char* name, int dob, int power, int level = 0, bool super = false);
		void set(const char* name, int dob, int power, int level=0, bool super = false);
		bool isValid() const;
		void display() const;
		bool fight(Saiyan& other);
	};


}


#endif // !_SAIYAN_H
