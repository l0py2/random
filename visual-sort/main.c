#include <raylib.h>

const int screen_width = 800;
const int screen_height = 600;
const int bar_width = 2;
const int bar_count = screen_width / bar_width;

void step_sort(int bars[]);

int main(void) {
	InitWindow(screen_width, screen_height, "Visual Sort");

	int bars[bar_count];

	for(int i = 0; i < bar_count; i++) {
		bars[i] = GetRandomValue(1, screen_height);
	}

	while(!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(BLACK);

		for(int i = 0; i < bar_count; i++) {
			DrawRectangle(
				bar_width * i,
				screen_height - bars[i],
				bar_width,
				bars[i],
				WHITE
			);
		}

		step_sort(bars);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}

void step_sort(int bars[]) {
	static int i = 0;
	static int j = 1;

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
