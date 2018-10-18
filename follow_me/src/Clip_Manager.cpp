/*

 * clip.cpp
 *
 *  Created on: Sep 16, 2018
 *      Author: onurke
 */
#include "../headers/Clip_Manager.h" //class header file
#include "../headers/Clip.h" //Clip object is used
#include "../headers/Globals.h" //action enum is used

#include <iostream> //cout is used
#include <cstdlib>
#include <ctime> //random value generator used

using namespace std; //whole std library is loaded

static const double NO_CHANCE = 0; // Zero chance to select an action

namespace follow_me{
void Clip_Manager::add_new_clip(char* name, std::size_t ticks_to_play,
		double f_c_1, double f_c_2, int a_1, int a_2) {

	//if header and tail node is null, which means adding object is initial node
	if (header_node == NULL && tail_node == NULL) {
		//call constructor
		Clip *new_clip = new Clip(name, ticks_to_play, f_c_1, f_c_2, a_1, a_2);

		//set next_prev to itself, because initial node
		new_clip->next = new_clip;
		new_clip->prev = new_clip;

		header_node = new_clip;
		tail_node = new_clip;

		return;

	} else {// if it is not initial node

		Clip *ptr_node = header_node;

		bool loop_completed = false; //used to prevent infinite loop in while loop statement

		while (!loop_completed) {
			//if same name object is found then update the object
			if (ptr_node->name == name) {
				ptr_node->ticks_to_play = ticks_to_play;
				ptr_node->follow_chance_1 = f_c_1;
				ptr_node->follow_chance_2 = f_c_2;
				ptr_node->action_1 = a_1;
				ptr_node->action_2 = a_2;
				//node is updated so, time to return
				return;
			}

			ptr_node = ptr_node->next;

			//it means loop completed and quit from the loop
			if (ptr_node->next == header_node)
				loop_completed = true;
		}

		//if the code statement is reached until here then add the object to end of linked list
		Clip *new_clip = new Clip(name, ticks_to_play, f_c_1, f_c_2, a_1, a_2);

		Clip * temp_last_clip = tail_node;
		temp_last_clip->next = new_clip;
		new_clip->prev = temp_last_clip;
		new_clip->next = header_node;
		header_node->prev = new_clip;
		tail_node = new_clip;

	}

}

void Clip_Manager::init_ticks(int tick_count) {
	ticks->set_tick_count(tick_count);
}

void Clip_Manager::add_tick_pair(std::vector<double> tick_pair) {

	std::size_t tick_pair_size = tick_pair.size();
	for (std::size_t counter = 1; counter < tick_pair_size; counter += 2) {
		ticks->add_tick_pair(tick_pair[counter - 1], tick_pair[counter]);
	}

}

short Clip_Manager::decide_next_move(Clip &ptr) {


	std::pair<double, double>  pair_percentage_val = get_percentage_of_action(ptr);

	//if follow chance 2 is set to 0 then select action 1
	if (pair_percentage_val.second == NO_CHANCE) {
		return ptr.action_1;

	} else if (pair_percentage_val.first == NO_CHANCE) { //if follow chance 1 is set to 0 then select action 2
		return ptr.action_2;

	} else {
		//randomly select the action //try to do with chances

		int random_total = pair_percentage_val.first + pair_percentage_val.second;
		unsigned seed = time(0); //added to get real random value
		srand(seed); //added to get real random value
		int random_chance = rand() % random_total; // get a random value

		//if the random value is smaller than follow_chance_1, select action 1, otherwise select action_2
		if (random_chance < pair_percentage_val.first) {
			return ptr.action_1;
		} else {
			return ptr.action_2;
		}
	}
}


std::pair<double, double> Clip_Manager::get_percentage_of_action(Clip &ptr){

	double first_action;
	double second_action;

	//if randomize option is enabled calculate randomize values then calculate it
	if(ticks->is_randomize()){

		unsigned seed = time(0); //added to get real random value
		srand(seed); //added to get real random value
		first_action = rand() % 100; // get a random value
		seed = time(0); //added to get real random value
		srand(seed); //added to get real random value
		second_action = rand() % 100; // get a random value

		first_action = (first_action /100) * ptr.follow_chance_1;
		second_action = (second_action / 100) * ptr.follow_chance_2;

	}else{
		//if randomize option is disabled checl given values
		std::vector <std::pair<double,double > > value_pairs = ticks->get_tick_pairs();

		//if still the vector boundry then continue
		if(clip_action_counter < value_pairs.size()){

			first_action =  value_pairs[clip_action_counter].first;
			second_action =  value_pairs[clip_action_counter].second;

			first_action = first_action * ptr.follow_chance_1;
			second_action = second_action * ptr.follow_chance_2;

		}else{
			//if the vector is not in the boundry then continue with random values
			unsigned seed = time(0); //added to get real random value
			srand(seed); //added to get real random value
			first_action = rand() % 100; // get a random value
			seed = time(0); //added to get real random value
			srand(seed); //added to get real random value
			second_action = rand() % 100; // get a random value

			first_action = (first_action /100) * ptr.follow_chance_1;
			second_action = (second_action / 100) * ptr.follow_chance_2;

			//increment clip counter
			++clip_action_counter;

		}
	}

	return std::make_pair(first_action, second_action);


}


Clip * Clip_Manager::take_next_move(Clip &ptr, short next_action) {

	if (next_action == Globals::NEXT) {
		return ptr.next;

	} else if (next_action == Globals::PREVIOUS) {
		return ptr.prev;

	} else if (next_action == Globals::NONE) {
		return &ptr;
	}else{
		char * temp_name = ptr.name;
		Clip &local_ptr = ptr; //local pointer to determine

		unsigned seed = time(0); //added to get real random value
		srand(seed); //added to get real random value

		int random_num = rand() % ticks->get_tick_count();

		while (random_num > 0) {
			local_ptr = *local_ptr.next;
			--random_num;
		}

		//if OTHER selected and the current object is the same object go to next object an return
		 if (next_action == Globals::OTHER && ptr.name == temp_name){
			 local_ptr = *local_ptr.next;
		 }

		return &local_ptr;
		//NOTE: there is no need for NONE, it will take no action, and repeat itself

	}
}

void Clip_Manager::take_clip_action(Clip *curr_clip, std::size_t &remain_tick) {

	std::size_t clip_tick_counter = curr_clip->ticks_to_play; //load the ticks to play

	while (clip_tick_counter > 0 && remain_tick > 0) {
		std::cout << curr_clip->name << std::endl;
		return_string += curr_clip->name;
		--remain_tick;
		--clip_tick_counter;
	}

}

void Clip_Manager::play() {
	//start from initial node
	std::size_t tick_counter = ticks->get_tick_count();
	Clip *ptr_node = header_node;
	std::size_t iteration_counter = 0;
	clip_action_counter = 0;

	//while we have tick then continue
	while (tick_counter > 0) {

		take_clip_action(ptr_node, tick_counter);
		//if still have tick action then select for next action
		if (tick_counter > 0) {
			short next_action = decide_next_move(*ptr_node);
			ptr_node = take_next_move(*ptr_node, next_action);
		}
		++iteration_counter;
	}

}
}
