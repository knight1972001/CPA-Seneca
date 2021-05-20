#pragma once
#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H
namespace sdds {
	class ControlPanel {
	private:
		struct Indicator
		{
			int id;
			char ledColour;
		} *indicators;
		size_t numOfIndicators;
	public:
		ControlPanel();
		ControlPanel(int* ids, char* ledColours, size_t numOfIndicators = 0);
		void changeLED(int ids, char ledColours);
		~ControlPanel();
	};
}
#endif // !1
