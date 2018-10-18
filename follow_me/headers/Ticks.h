#ifndef TICKS_H_
#define TICKS_H_

#include <vector>       // std::vector
#include "Globals.h"	//actions variable is used from Globals class

/*!
 * @Class_Name: Ticks
 * @brief: The class aimed to contain Tick count and the possible value pairs.
 */
namespace follow_me{
class Ticks{
protected:
	/*! @param: tick_count type: size_t (unsigned) stores the remaining tick value for the clips*/
	std::size_t tick_count = 0;

	/*! @param: tick_pairs type: vector<pair>. stores the tick pair values -if given , otherwise, which will be empty*/
	std::vector <std::pair<double,double > > tick_pairs;

	/*! @param: randomize_pairs type: boolean. If tick_pairs is left empty, which means the randomize numbers will be used. Otherwise the value
	 * changed to false, and tick_pairs vector is used*/
	bool randomize_pairs = true;

public:

	/*!@func: set_tick_count
	 * param: tick_count size_t
	 * @brief: updates protected value of tick_count
	 * @return: void*/
	void set_tick_count(std::size_t tick_count_){
		tick_count = tick_count_;
	}

	/*!@func: add_tick_pair
	 * @param: p_1 double
	 * @param: p_2 double
	 * @brief: appends protected value of tick_pairs
	 * @return: void*/
	void add_tick_pair(double p_1, double p_2){
		tick_pairs.push_back(std::make_pair(p_1, p_2));
		randomize_pairs = false;
	}

	/*!
	 * @func: get_tick_count
	 * @brief: returns tick_count
	 * return: tick_count type: size_t*/
	std::size_t get_tick_count(){
		return tick_count;
	}

	/*! @func: get_tick_pairs
	 * @brief: returns address of (reference) tick_pairs
	 * return: tick_pairs type: vector*/
	std::vector <std::pair<double,double > > get_tick_pairs(){
			return tick_pairs;
	}

	/*! @func: is_randomize
	 * @brief: returns randomize_pairs
	 * return: boolean*/
	bool is_randomize(){
		return randomize_pairs;
	}
};
}
#endif /* TICKS_H_ */
