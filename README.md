This README file contains "Follow Me" project related information.

////////////////////////////////////////////////////////////////////
//Author: Onur Kececi											///
//Date: 19.09.2018												///
//E-mail: onurkececi@gmail.com									///
//Phone: 0090 532 500 73 28										///
////////////////////////////////////////////////////////////////////

"Follow Me" project implemented because of implementation request.

Project Pre-Requests:
	Make,
	g++ (at least ++ 11),
	Google Test,
	Git (for gtest instllation)
	
OS Compability: 
	Microsoft Windows, 
	Ubuntu 14.6

HOW TO BUILD follow_me:
	go to ableton_interview/
	run this command "make makefile default"
	if compile is succesfully completed "follow_me" executuble is created. 
	to run follow_me a text file needs to be supplied. (see: "INPUT DATA" header for detailed information)
	To run executible (Ex: input.txt) run this command "./follow_me input.txt"
	The results are displayed at the terminal
	
INPUT DATA:
	While working with follow_me executable, an input file needs to be supplied. The file needs to supply format requirements. 
	The input data file needs to contain at least 1 or more clips and 1 tick (There is no protection mechanism added! Beause at the requirement document, it was mentioned that there would not be malformed data.)
	clip object input should be in the same order: 
	clip [clip_name :type: string] [number_of_ticks :type: integer] [follow_chance_1 :type: integer] [follow_chance_2 :type: integer] [action_1 :type: integer] [action_2 :type: integer]
	
	number_of_ticks: quantity of tick is required to complete the clip object
	follow_chance_1 OR follow_chance_2: double value The cahnce of select action
	action_1 OR action_2: the next action name action list is: 
		Action: NONE 	ID: 0
		Action: ANY 	ID: 1
		Action: OTHER 	ID: 2
		Action: NEXT 	ID: 3
		Action: PREVIOUS ID: 4
		
	Tick object is configured with the line started with "ticks". Ticks line has to contain tick count. Tick value  pairs are optional. If the pairs are not suplied, real random values are used. 
	tick object input should be in the same order:
	ticks [total_tick_Count :type: Integer] [OPTIONAL tick_value :type: Integer] [OPTIONAL tick_value :type: Integer] ...
	
	Example inout file: 
clip hello 2 1 0 3 0
clip world 3 1 0 4 0
ticks 10

HOW TO BUILD and RUN GTESTS:	
	go to gUnitTests/
	run this command "make makefile default"
	if compile is succesfully completed "follow_me_g_tests" executuble is created. 
	to run follow_me_g_tests a text file needs to be supplied. (see: "INPUT DATA" header for detailed information)
	To run executible (Ex: input.txt) run this command "./follow_me_g_tests"
	The results are displayed at the terminal
	NOTE: If google test is not downloaded and configurated check out "GTEST CONFIGURATION" section:
	
GTEST CONFIGURATION:
	To download gtest you git needs to be pre-installed.
	To download gtest latest version "git clone https://github.com/google/googletest.git"
	go to "googletest-master/googletest/scripts"
	run "fuse_gtest_files.py /[test_folder_location]/gtest"
	copy gUnitTests/makefile to  /[test_folder_location]/gtest/
	your gtest needs to be ready for "HOW TO BUILD and RUN GTESTS" section
	
NOTES:
	1- Doxygen formatted comments are added
	2- Implementation is tested on Windows 10 (Eclipse -Mingw), and Ubuntu 16.04 (g++ , make)
	3- If you face with any difficultiy, while testing the software, do no hesitate to contact from onurkececi@gmail.com
