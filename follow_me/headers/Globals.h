#ifndef GLOBALS_H_
#define GLOBALS_H_

/*!
 * @Class_Name: Globals
 * @brief: Globals class contains the global virables, which can be accessed from everywhere
 */
class Globals{
public:

	/*!
	 * @enum: actions
	 * @brief: the enumaration of the possible clip actions
	 */
	 enum actions{
		NONE,
		ANY,
		OTHER,
		NEXT,
		PREVIOUS
	};

};
#endif /* GLOBALS_H_ */
