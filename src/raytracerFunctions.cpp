#include <iostream>
#include <fstream>
#include "raytracer.h"
using namespace std;


void render() {
    // Creating ppm file format
    int imageWidth = 256;
    int imageHeight = 256;

    ofstream imageFile;
    imageFile.open("image.ppm");

    // Define ASCII colours, width, height, and max color
    imageFile << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int j = 0; j < imageHeight; j++) {
        clog << "\rScanlines remaining: " << (imageHeight - j) << flush;
        for (int i = 0; i < imageWidth; i++) {
            /*
            auto r = double(i) / (imageWidth-1);
            auto g = double(j) / (imageHeight-1);
            auto b = 0;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);
            */

            imageFile << i << ' ' << j << ' ' << 0 << '\n';
        }
    }

    imageFile.close();

    clog << "\rDone.                   \n";

    return;

}