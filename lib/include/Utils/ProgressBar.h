#pragma once

#include <string>
#include <ostream>

class ProgressBar
{
    int m_currentStep;
    int m_totalSteps;
    int m_completeSegments;
    int m_totalSegments;
    
public:
    ProgressBar(int totalSteps, int totalSegments)
    : m_currentStep(0), m_totalSteps(totalSteps), m_completeSegments(-1), m_totalSegments(totalSegments) {}
    
    void displayNext(std::ostream & output);
    void reset();
    
private:
    
    bool numberCompleteSegmentsIsSame();
    std::string generateCompleteString() const;
    std::string generateIncompleteString() const;
    int computeCompleteSegments() const;
    int computeEmptySegments(int completeSegments) const;
};

