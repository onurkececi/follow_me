#ifndef CLIP_MANAGER_TEST_C_
#define CLIP_MANAGER_TEST_C_

#include "gtest/gtest.h"
#include "../../follow_me/headers/Clip_Manager.h"
#include "../../follow_me/headers/Globals.h"
#include <string>
#include <vector>

namespace follow_me{
namespace{
	class ClipManagerTests : public ::testing::Test {
	protected:
//		Clip_Manager clip_manager;
	};

	//sample given in tutorial
	TEST(ClipManagerTests, Clip_Play_1){

		Clip_Manager *c_m = new Clip_Manager();
		c_m->add_new_clip("hello", 2, 1.0, 0.0, Globals::NEXT, Globals::NONE);
		c_m->add_new_clip("world", 3, 1.0, 0.0, Globals::PREVIOUS, Globals::NONE);

		c_m->init_ticks(10);
		c_m->play();

		std::string t_c_1 = "hellohelloworldworldworldhellohelloworldworldworld";
		ASSERT_EQ(t_c_1, c_m->return_string);

	}

	//an object is updated - same name
	TEST(ClipManagerTests, Clip_Play_2){

		Clip_Manager *c_m = new Clip_Manager();
		c_m->add_new_clip("hello", 2, 1.0, 0.0, Globals::NEXT, Globals::NONE);
		c_m->add_new_clip("world", 3, 1.0, 0.0, Globals::PREVIOUS, Globals::NONE);
		c_m->add_new_clip("hello", 1, 1.0, 0.0, Globals::PREVIOUS, Globals::NONE);

		c_m->init_ticks(10);
		c_m->play();

		std::string t_c_2 = "helloworldworldworldhelloworldworldworldhelloworld";
		ASSERT_EQ(t_c_2, c_m->return_string);

	}

	//an object action is always next - same name
	TEST(ClipManagerTests, Clip_Play_3){

		Clip_Manager *c_m = new Clip_Manager();
		c_m->add_new_clip("hello", 1, 1.0, 0.0, Globals::NEXT, Globals::NONE);
		c_m->add_new_clip("world", 1, 1.0, 0.0, Globals::NEXT, Globals::NONE);
		c_m->add_new_clip("able", 1, 1.0, 0.0, Globals::NEXT, Globals::NONE);

		c_m->init_ticks(6);
		c_m->play();

		std::string t_c_3 = "helloworldablehelloworldable";
		ASSERT_EQ(t_c_3, c_m->return_string);

	}

	//an object action is always none - same name
	TEST(ClipManagerTests, Clip_Play_4){

		Clip_Manager *c_m = new Clip_Manager();
		c_m->add_new_clip("hello", 1, 1.0, 0.0, Globals::NONE, Globals::NONE);
		c_m->add_new_clip("world", 1, 1.0, 0.0, Globals::NEXT, Globals::NONE);
		c_m->add_new_clip("able", 1, 1.0, 0.0, Globals::NEXT, Globals::NONE);

		c_m->init_ticks(6);
		c_m->play();

		std::string t_c_4 = "hellohellohellohellohellohello";
		ASSERT_EQ(t_c_4, c_m->return_string);

		}

	//an object action is always previous - same name
	TEST(ClipManagerTests, Clip_Play_5){

		Clip_Manager *c_m = new Clip_Manager();
		c_m->add_new_clip("hello", 1, 1.0, 0.0, Globals::PREVIOUS, Globals::NONE);
		c_m->add_new_clip("world", 1, 1.0, 0.0, Globals::PREVIOUS, Globals::NONE);
		c_m->add_new_clip("able", 1, 1.0, 0.0, Globals::PREVIOUS, Globals::NONE);

		c_m->init_ticks(6);
		c_m->play();

		std::string t_c_5 = "helloableworldhelloableworld";
		ASSERT_EQ(t_c_5, c_m->return_string);

		}

	//sample given in tutorial
		TEST(ClipManagerTests, Clip_Play_6){

			std::vector<double> tick_pairs;

			Clip_Manager *c_m = new Clip_Manager();
			c_m->add_new_clip("hello", 2, 1.0, 0.0, Globals::NEXT, Globals::NONE);
			c_m->add_new_clip("world", 3, 1.0, 0.0, Globals::PREVIOUS, Globals::NONE);

			c_m->init_ticks(10);
			tick_pairs.push_back(1.0);
			tick_pairs.push_back(0);
			tick_pairs.push_back(1.0);
			tick_pairs.push_back(0);
			tick_pairs.push_back(1.0);
			tick_pairs.push_back(0);
			tick_pairs.push_back(1.0);
			tick_pairs.push_back(0);
			tick_pairs.push_back(1.0);
			tick_pairs.push_back(0);
			tick_pairs.push_back(1.0);
			tick_pairs.push_back(0);
			tick_pairs.push_back(1.0);
			tick_pairs.push_back(0);
			tick_pairs.push_back(1.0);
			tick_pairs.push_back(0);
			tick_pairs.push_back(1.0);
			tick_pairs.push_back(0);
			tick_pairs.push_back(1.0);
			tick_pairs.push_back(0);

			c_m->add_tick_pair(tick_pairs);
			c_m->play();

			std::string t_c_1 = "hellohelloworldworldworldhellohelloworldworldworld";
			ASSERT_EQ(t_c_1, c_m->return_string);

		}

}
}

#endif /* CLIP_MANAGER_TEST_C_ */
