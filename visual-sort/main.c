#include <raylib.h>

const int screen_width = 800;
const int screen_height = 600;
const int bar_width = 5;
const int bar_count = screen_width / bar_width;

void step_sort(int bars[], int *current, int *target);

int main(void) {
	InitWindow(screen_width, screen_height, "Visual Sort");

	int bars[bar_count];

	for(int i = 0; i < bar_count; i++) {
		bars[i] = GetRandomValue(1, screen_height);
	}

	int current = 0;
	int target = 0;

	while(!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(BLACK);

		for(int i = 0; i < bar_count; i++) {
			Color bar_color = WHITE;

			if(i == current) {
				bar_color = GREEN;
			}else if(i == target) {
				bar_color = RED;
			}

			DrawRectangle(
				bar_width * i,
				screen_height - bars[i],
				bar_width,
				bars[i],
				bar_color
			);
		}

		step_sort(bars, &current, &target);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}

void step_sort(int bars[], int *current, int *target) {
	static int i = 0;
	static int j = 1;

	*current = i;
	*target = j;

	if(i >= bar_count - 1) {
		return;
	}

	if(bars[i] > bars[j]) {
		int temp = bars[i];
		bars[i] = bars[j];
		bars[j] = temp;
	}


	if(j >= bar_count) {
		i++;
		j = i + 1;
	}else {
		j++;
	}
}
