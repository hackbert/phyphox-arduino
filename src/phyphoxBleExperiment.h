#ifndef PHYPHOX_BLE_EXPERIMENT
#define PHYPHOX_BLE_EXPERIMENT

#define phyphoxBleNViews 5
#define phyphoxBleNElements 5

#include <Arduino.h>

class PhyphoxBleExperiment {

	public:

	PhyphoxBleExperiment() {};                     
	PhyphoxBleExperiment(const PhyphoxBleExperiment&) = delete;         
	PhyphoxBleExperiment &operator=(const PhyphoxBleExperiment &) = delete;
	~PhyphoxBleExperiment() = default;

    class Element {
	    public:

        	Element() {};                     
        	Element(const Element&) = delete;         
        	Element &operator=(const Element &) = delete;
		    ~Element() = default;

		    int typeID = 0;

		    char LABEL[50] = "Graph";

		    void setLabel(const char*);
		    virtual void getBytes(char*);
            virtual bool usesChannel(int);
	    private:


    };

    class Graph : public Element 
    {
	    public:
        	Graph() {};                     
        	Graph(const Graph&) = delete;         
        	Graph &operator=(const Graph &) = delete;
	    ~Graph() = default;

	    char UNITX[50] = "s";
	    char UNITY[50] = "";
	    char LABELX[50] = "time";
	    char LABELY[50] = "value";

	    int INPUTX = 0;
	    int INPUTY = 1;

	    char STYLE[8] = "lines";

	    void setUnitX(const char*);
	    void setUnitY(const char*);
	    void setLabelX(const char*);
	    void setLabelY(const char*);
	    void setChannel(int, int);
	    void setStyle(const char*);

	    void phyphoxTimestamp();
	    void getBytes(char*);
        bool usesChannel(int);
	    private:


    };

    class View
    {
	    public:
        	View() {};                     
        	View(const View&) = delete;         
        	View &operator=(const View &) = delete;
	    ~View() = default;


	    void setLabel(const char*);
	    void getBytes(char*);
	    void addElement(Element&);

        bool usesChannel(int);

	    char LABEL[50] = "Data";
	    Element *ELEMENTS[phyphoxBleNViews]={nullptr};
	    private: 
    };

	void setTitle(const char*);
	void setCategory(const char*);
	void setDescription(const char*);

	void getBytes(char*);
	void addView(View&);

	char TITLE[50] = "Arduino-Experiment";
	char CATEGORY[50] = "Arduino Experiments";
	char DESCRIPTION[500] = "An experiment created with the phyphox BLE library for Arduino-compatible micro controllers.";

	View *VIEWS[phyphoxBleNViews] = {nullptr};

    void setChannelForExport(int, char*);
    void autoDetectExportChannels();
    typedef struct {
        int channel;
        char label[30];
    } ExportChannel;
    ExportChannel *exportConfiguration[6] = {nullptr};
};

#endif
