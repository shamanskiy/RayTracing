#include "Utils/ProgressBar.h"

#include <math.h>

void ProgressBar::displayNext(std::ostream &output)
{
    m_currentStep++;
    
    if (m_currentStep == m_totalSteps)
        output << generateCompleteString() << "\n";
    else if (numberCompleteSegmentsIsSame())
        return;
    else
        output  << generateIncompleteString() << "\r" << std::flush;
}

bool ProgressBar::numberCompleteSegmentsIsSame()
{
    int newCompleteSegments = computeCompleteSegments();
    if (newCompleteSegments > m_completeSegments)
    {
        m_completeSegments = newCompleteSegments;
        return false;
    }
    else
        return true;
}

int ProgressBar::computeCompleteSegments() const
{
    float progress = float(m_currentStep) / m_totalSteps;
    return floor(progress * m_totalSegments);
}

std::string ProgressBar::generateCompleteString() const
{
    return '[' + std::string(m_totalSegments,'=') + ']';
}

std::string ProgressBar::generateIncompleteString() const
{
    int numEqualSigns = m_completeSegments;
    int numSpaces = computeEmptySegments(numEqualSigns);
    
    return '[' + std::string(numEqualSigns,'=') + '>' + std::string(numSpaces,' ') + ']';
}

int ProgressBar::computeEmptySegments(int completeSegments) const
{
    return m_totalSegments - completeSegments - 1;
}


