#include "color.h"
#include "vec3.h"

#include <iostream>

int main() {
	const int image_width = 256;
	const int image_height = 256;

	std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

	for (int j = 0; j < image_height; ++j) {
		std::cerr << "\rScanlines remaining: " << j << " " << std::flush;
		for (int i = 0; i < image_width; ++i) {
			color pixel_color(double(i) / (image_width - 1),
					          double(j) / (image_height - 1),
							  double(std::max(i, j)) /
							  (std::max(image_width, image_height) - 1));

			write_color(std::cout, pixel_color);
		}
	}

	std::cerr << "\nDone.\n";
}
