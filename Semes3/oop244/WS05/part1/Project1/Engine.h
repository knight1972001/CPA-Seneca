//==============================================
// Name:           	Long Nguyen
// Student Number: 	155176183
// Email:          	lnguyen97@myseneca.ca
// Section:        	NAA
// Day:			    June 23th 2020
// Workshop:       	5 (Part 1)
//==============================================
#ifndef _ENGINE_H
#define _ENGINE_H
namespace sdds {
	const int TYPE_MAX_SIZE = 30;
	class Engine {
	private:
		double m_size;
		char m_type[TYPE_MAX_SIZE+1];
	public:
		Engine();
		Engine(const char* type, const double size);
		double get() const;
		void display() const;

	};
}


#endif // !_ENGINE_H
