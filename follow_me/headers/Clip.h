#ifndef CLIP_H_
#define CLIP_H_

/*!
 * @Class_Name: Clip
 * @brief: The class stores details of a single Clip object. Object name, next operations and all Clip object details are stored in this class
 */
namespace follow_me{
class Clip{
public:
	/*! @param: name type: char* stores the name of the Clip object. Which will be used while playing and adding an object*/
	char* name;

	/*! @param: ticks_to_play type: size_t. Stores how many ticks are required to complete Clip*/
	std::size_t ticks_to_play;

	/*! @param: follow_chance_1 type: double. Stores the chance of select action_1*/
	double follow_chance_1;

	/*! @param: follow_chance_2 type: double. Stores the chance of select action_2*/
	double follow_chance_2;

	/*! @param: action_1 type: short. Stores the action name in enumaration form. Value results can b reached from Globals::actions*/
	short action_1;

	/*! @param: action_2 type: short. Stores the action name in enumaration form. Value results can b reached from Globals::actions*/
	short action_2;

	Clip* next = NULL;
	Clip* prev = NULL;

	Clip(char* name_, std::size_t ticks_to_play_, double follow_chance_1_, double follow_chance_2_, short action_1_, short action_2_){
		name = name_;
		ticks_to_play = ticks_to_play_;
		follow_chance_1 = follow_chance_1_;
		follow_chance_2 = follow_chance_2_;
		action_1 = action_1_;
		action_2 = action_2_;
	}

};
}

#endif /* CLIP_H_ */
