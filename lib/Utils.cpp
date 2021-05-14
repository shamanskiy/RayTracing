#include "Utils.h"

#include <math.h>

void ProgressBar::displayNext(std::ostream &output)
{
    currentStep++;
    
    if (currentStep == totalSteps)
        output << generateCompleteString() << "\n";
    else if (numberCompleteSegmentsIsSame())
        return;
    else
        output  << generateIncompleteString() << "\r" << std::flush;
}

bool ProgressBar::numberCompleteSegmentsIsSame()
{
    int newCompleteSegments = computeCompleteSegments();
    if (newCompleteSegments > completeSegments)
    {
        completeSegments = newCompleteSegments;
        return false;
    }
    else
        return true;
}

int ProgressBar::computeCompleteSegments() const
{
    float progress = float(currentStep) / totalSteps;
    return floor(progress * totalSegments);
}

std::string ProgressBar::generateCompleteString() const
{
    return '[' + std::string(totalSegments,'=') + ']';
}

std::string ProgressBar::generateIncompleteString() const
{
    int numEqualSigns = completeSegments;
    int numSpaces = computeEmptySegments(numEqualSigns);
    
    return '[' + std::string(numEqualSigns,'=') + '>' + std::string(numSpaces,' ') + ']';
}

int ProgressBar::computeEmptySegments(int completeSegments) const
{
    return totalSegments - completeSegments - 1;
}


