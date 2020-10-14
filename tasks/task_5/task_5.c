#include <superkarel.h>

void turn();
void turn_back();
void long_step();
bool f_beeper_step();
void find_center();

int main() {
	turn_on("task_5.kw");
	set_step_delay(50);

	long_step();
	turn_left();
	find_center();
	turn();
	find_center();
	turn_back();
	step();

	while (front_is_clear() && beepers_present()) {
		pick_beeper();
		step();
	}

	turn_back();
	step();

	while (!beepers_present())
		step();

	step();

	while (front_is_clear() && beepers_present()) {
		pick_beeper();
		step();
	}

	pick_beeper();
	turn_left();
	find_center();
	turn();
	step();

	while (!beepers_present())
		step();

	turn_left();
	long_step();
	turn_left();
	find_center();
	turn();
	long_step();
	turn_left();
	find_center();
	turn();
	step();

	while (!beepers_present())
		step();

	pick_beeper();

	while (!facing_north())
		turn_left();

	turn_off();
	return 0;
}

void find_center() {
	while (1) {
		while (!f_beeper_step()) {}

		turn_back();
		step();
		if (beepers_present())
			break;
		put_beeper();
	}
}

void turn() {
	turn_left();
	if (!front_is_clear()) {
		turn_left();
		turn_left();
	}
}

void turn_back() {
	turn_left();
	turn_left();
}

void long_step() {
	while (front_is_clear())
		step();
}

bool f_beeper_step() {
	if (!front_is_clear()) {
		put_beeper();
		return 1;
	}

	step();
	if (beepers_present())
		return 1;
	return 0;
}
