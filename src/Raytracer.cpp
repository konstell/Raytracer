#include <iostream>

int main() {
	const int image_width = 256;
	const int image_height = 256;

	std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

	for (int j = 0; j < image_height; ++j) {
		std::cerr << "\rScanlines remaining: " << j << " " << std::flush;
		for (int i = 0; i < image_width; ++i) {
			auto r = double(i) / (image_width - 1);
			auto g = double(j) / (image_height - 1);
			auto b = double(255 - std::max(i, j)) / (std::max(image_width, image_height) - 1);

			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);

			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}

	std::cerr << "\nDone.\n";
}
