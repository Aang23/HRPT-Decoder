#include <fstream>
#define cimg_use_png
#define cimg_display 0
#include "CImg.h"

#define NOAA_HRPT_CHANNELS 5

class NOAADecoder
{
private:
    // Our ifstream used... All the time
    std::ifstream &input_file;
    // Total frame count variable to be used later
    int total_frame_count = 0;
    // First frame position in file
    long first_frame_pos = -1;

public:
    // Constructor
    NOAADecoder(std::ifstream &input);
    // Function doing all the pre-frame work, that is, everything you'd need to do before being ready to read an image
    void processHRPT();
    // Function used to decode a choosen channel
    cimg_library::CImg<unsigned short> decodeChannel(int channel);
    // Return total fram count
    int getTotalFrameCount();
};
