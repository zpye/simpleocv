#include "simpleocv.h"

#include <iostream>
#include <string>

static const std::string image_path(IMAGE_PATH);

static void SaveImage(const std::string& name, cv::Mat& image) {
    // std::string image_file(image_path);
    // image_file.append("/").append(name);
    cv::imwrite(name, image);
}

int main() {
    std::string image_file(image_path);
    image_file.append("/car.jpg");

    cv::Mat image = cv::imread(image_file);
    std::cout << "image size: " << image.cols << ", " << image.rows << ", "
              << image.channels();

    // resize
    cv::Mat image_small;
    cv::Size small_size(image.cols / 2, image.rows / 2);
    cv::resize(image, image_small, small_size);
    SaveImage("car_small.jpg", image_small);

    // rotate
    cv::Mat image_roate_type_4;
    cv::rotate(image, image_roate_type_4, 4);
    SaveImage("car_rotate_type_4.jpg", image_roate_type_4);

    cv::Mat image_roate_type_8;
    cv::rotate(image, image_roate_type_8, 8);
    SaveImage("car_rotate_type_8.jpg", image_roate_type_8);

    // affine
    float affine[6];
    float invert_affine[6];

    cv::get_rotation_matrix(-45.0f,
                            0.3f,
                            (float)(image.cols / 4),
                            (float)(image.rows / 4),
                            affine);
    cv::invert_affine_transform(affine, invert_affine);
    cv::Mat image_affine_0;
    cv::warpaffine(image, image_affine_0, invert_affine);
    SaveImage("car_affine_0.jpg", image_affine_0);

    cv::get_rotation_matrix(15.0f, 1.2f, 0.0f, (float)(image.rows / 4), affine);
    cv::invert_affine_transform(affine, invert_affine);
    cv::Mat image_affine_1;
    cv::warpaffine(image, image_affine_1, invert_affine);
    SaveImage("car_affine_1.jpg", image_affine_1);

    // white image
    cv::Mat white_image(256, 256, 3);
    cv::rectangle(white_image,
                  cv::Rect(0, 0, white_image.cols, white_image.rows),
                  cv::Scalar(255, 255, 255),
                  -1);
    SaveImage("white_image.jpg", white_image);

    return 0;
}
