#pragma once

#include <string>
#include <ostream>

class ProgressBar
{
    int currentStep;
    int totalSteps;
    int completeSegments;
    int totalSegments;
    
    
public:
    ProgressBar(int totalSteps, int totalSegments)
    : currentStep(0), totalSteps(totalSteps), completeSegments(-1), totalSegments(totalSegments) {}
    
    void displayNext(std::ostream & output);
    
private:
    
    bool numberCompleteSegmentsIsSame();
    std::string generateCompleteString() const;
    std::string generateIncompleteString() const;
    int computeCompleteSegments() const;
    int computeEmptySegments(int completeSegments) const;
};

