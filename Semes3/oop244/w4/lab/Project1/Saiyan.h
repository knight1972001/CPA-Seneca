//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    June 17th 2020
// Workshop:       	4 (Part 1)
//==============================================
#ifndef _SAIYAN_H
#define _SAIYAN_H

namespace sdds {
	class Saiyan {
	private:
		char m_name[32];
		int m_dob;
		int m_power;
		bool m_super;
	public:
		Saiyan();
		Saiyan(const char* name, int dob,int power);
		void set(const char* name,int dob,int power,bool super=false);
		bool isValid() const;
		void display() const;
		bool fight(const Saiyan& other) const;
	};


}


#endif // !_SAIYAN_H
