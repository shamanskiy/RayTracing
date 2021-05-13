#pragma once

#include <string>

using namespace std;

namespace Utils {
    string progressLine(int progress, int total, int width = 25)
    {
        int progressPos = int(float(progress) / total * width);
        return '[' + string(progressPos, '=') + '>' + string(width - progressPos, ' ') + ']';
    }
}


    /*
public:
    /// Constructor. Width is a number of symbols the progress bar spans
    gsProgressBar(index_t width = 25) : m_width(width) {}

    /// display the progress from 0 to 1
    void display(double progress)
    {
        GISMO_ENSURE(progress >= 0. && progress <= 1., "Invalid progress value! Must be between 0 and 1.");
        index_t threshold = (index_t)(progress * m_width);
        gsInfo << "[";
        for (index_t i = 0; i < m_width; i++)
            if (i < threshold)
                gsInfo << "=";
            else if (i == threshold)
                gsInfo << ">";
            else
                gsInfo << " ";
        gsInfo << "] " << (abs(progress - 1.) < 1e-12 ? 100 : (index_t)(progress * 100)) << " %\r";
        gsInfo.flush();

        if (abs(progress - 1.) < 1e-12)
            gsInfo << std::endl;
    }

    /// display the progress from 0 to 1
    void display(index_t progress, index_t total)
    {
        GISMO_ENSURE(progress >= 0 && progress <= total && total >= 0, "Invalid progress value!");
        index_t threshold = (index_t)(1. * progress * m_width / total);
        gsInfo << "[";
        for (index_t i = 0; i < m_width; i++)
            if (i < threshold)
                gsInfo << "=";
            else if (i == threshold)
                gsInfo << ">";
            else
                gsInfo << " ";
        gsInfo << "] " << progress << "/" << total << " \r";
        gsInfo.flush();

        if (progress == total)
            gsInfo << std::endl;
    }

protected:
    index_t m_width;
};*/