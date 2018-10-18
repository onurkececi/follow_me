#include <string>
#include "../headers/Clip.h"
#include "../headers/Ticks.h"

/*!
 * @Class_Name: Clip_Manager
 * @brief: The class manages the clip and tick management. Tick counting clip management and playing are managed from this class.
 */
namespace follow_me{
class Clip_Manager{
private:
	/*! @param: header_node type: Clip object pointer. The header node of clip linked list*/
	Clip *header_node = NULL;

	/*! @param: tail_node type: Clip object pointer. The tail node of clip linked list*/
	Clip *tail_node = NULL;

	/*! @param: ticks type: Ticks object. Tick information is stored*/
	Ticks *ticks = new Ticks();

	/*! @param: clip_action_counter type: integer. Clip skip value  information is stored*/
	int clip_action_counter = 0;

public:
	/*! @param: return_string type: String. Added for testing purposes. Not for production. Gtest uses the variable*/
	std::string return_string = "";

	/*!@func: add_new_clip
	 * @param: name char*
	 * @param: ticks_to_play type: size_t
	 * @param: f_c_1 type: double
	 * @param: f_c_2 type: double
	 * @param: a_1 type: int
	 * @param: a_2 type: int
	 * @brief: adds new clip to clip linked list. If a new clip has same name with the old one, updates the old object
	 * @return: void*/
	void add_new_clip(char* name, std::size_t ticks_to_play, double f_c_1, double f_c_2, int a_1, int a_2);

	/*!@func: init_ticks
	 * @param: tick_count type: int
	 * @brief: sets the initial value of tick count
	 * @return: void*/
	void init_ticks(int tick_count);

	/*!@func: add_tick_pair
	 * @param: tick_pair type: vector<double>
	 * @brief: If tick pairs are supplied, the pair appended
	 * @return: void*/
	void add_tick_pair(std::vector<double> tick_pair);

	/*!@func: play
	 * @brief: Plays the Clips using with clip list and tick object. Appends results to return_string and to terminal
	 * @return: void*/
	void play();

	/*!@func: take_clip_action
	 * @param: curr_clip type: Clip pointer.
	 * @param: remain_tick type: size_t Reference.
	 * @brief: Calculates the remaining tick and clip required ticks. Prints to terminal and appends to return_string the results strings
	 * @return: void*/
	void take_clip_action(Clip *curr_clip, std::size_t &remain_tick);

	/*!@func: decide_next_move
	 * @param: ptr type: Clip reference.
	 * @brief: The tick values is bigger than 0, calculates the next move of clip, action is selected and returned
	 * @return: short*/
	short decide_next_move(Clip &ptr);

	/*!@func: get_percentage_of_action
	 * @param: ptr type: Clip reference.
	 * @brief: Returns the percentage of return value
	 * @return: std::pair<double, double>*/
	std::pair<double, double> get_percentage_of_action(Clip &ptr);

	/*!@func: take_next_move
	 * @param: ptr type: size_t Reference.
	 * @param: next_action type: short.
	 * @brief: Takes action and updates the current object pointer. Accorting to decide_next_move method's return value object is updates
	 * @return: short*/
	Clip * take_next_move(Clip &ptr, short next_action);

};
}


