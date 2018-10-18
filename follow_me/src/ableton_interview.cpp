//============================================================================
// Author      : Onur Kececi
// Version     : 1.0
// E-Mail	   : onurkececi@gmail.com
// Phone	   : 0090 532 500 73 28
// Description : "Follow Me" in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>

#include "../headers/Clip_Manager.h"
#include "../headers/Globals.h"
using namespace std;


std::vector<std::string> tokenize(std::string const &in) {
	     char sep = ' ';
	     std::string::size_type b = 0;
	     std::vector<std::string> result;

	     while ((b = in.find_first_not_of(sep, b)) != std::string::npos) {
	         char e = in.find_first_of(sep, b);
	         result.push_back(in.substr(b, e-b));
	         b = e;
	     }
	     return result;
	 };



int main(int argc, char **argv){

	follow_me::Clip_Manager *c_m = new follow_me::Clip_Manager();

	try {

		std::string line;
		 ifstream out(argv[1]);
		    while(getline(out, line)) {

		    	std::vector<std::string> parameters = tokenize(line);

		    	if(parameters.size() > 0){

		    		//check for the first input
		    		if(parameters[0] == "clip" && parameters.size() == 7){

		    			char *name = new char[parameters[1].length() + 1]; // or
		    			std::strcpy(name, parameters[1].c_str());

		    			std::size_t ticks_to_play = stoi(parameters[2]);
		    			double follow_chance_1 = stof(parameters[3]);
		    			double follow_chance_2 = stof(parameters[4]);
		    			int action_1 = stoi(parameters[5]);
		    			int action_2 = stoi(parameters[6]);

		    			c_m->add_new_clip(name, ticks_to_play, follow_chance_1, follow_chance_2, action_1, action_2);

		    		}else if(parameters[0] == "ticks" && parameters.size() > 1){
		    			int ticks = stoi(parameters[1]);
		    			c_m->init_ticks(ticks);

		    			std::vector<double> tick_pair;

		    			std::size_t param_size = parameters.size();
		    			for(std::size_t counter = 2 ; counter < param_size; ++counter){
		    				tick_pair.push_back(stod(parameters[counter]));
		    			}
		    		}

		    		//PLAY THE CLIPS
		    		c_m->play();
		    	}
		    }


	} catch (...) {
		std::cout<<"An Error occured. To reach run instructions check out READ_ME file";
	}

	return 0;
}





