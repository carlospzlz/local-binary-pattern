#include <iostream>
#include <string>

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

cv::Mat computeLBP(const cv::Mat& image)
{
    // Followed the web below as resource.
    // http://hanzratech.in/2015/05/30/local-binary-patterns.html

    // These are the deltas to be applied to visit the neighbours.
    // We follow a clockwise order, starting at the top-left neighbour.
    // clang-format off
    constexpr std::array<std::array<int, 2>, 8> deltas{
        {{-1,-1}, { 0,-1}, { 1, -1}, { 1, 0},
         { 1, 1}, { 0, 1}, { -1, 1}, {-1, 0}}
    };
    // clang-format on

    const auto rows = image.rows;
    const auto cols = image.cols;
    cv::Mat result(rows, cols, CV_8UC1);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            const auto pixel = image.at<unsigned char>(i, j);
            unsigned char value{0};
            for (const auto& delta : deltas)
            {
                const int x{((((j + delta[0]) % cols) + cols) % cols)};
                const int y{((((i + delta[1]) % rows) + rows) % rows)};
                value = value << 1;
                value += pixel <= image.at<unsigned char>(y, x);
            }
            result.at<unsigned char>(i, j) = value;
        }
    }
    return result;
}

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        std::cout << "Usage: lbp <input-image> <output-image" << std::endl;
        return -1;
    }

    const std::string input_file{argv[1]};
    const std::string output_file{argv[2]};

    cv::Mat image;
    image = cv::imread(input_file, cv::IMREAD_GRAYSCALE);

    if (!image.data)
    {
        std::cout << "Could not open or find the image: " << input_file
                  << std::endl;
        return -1;
    }

    cv::Mat result{computeLBP(image)};

    cv::imwrite(output_file, result);

    return 0;
}
