/**
 * @file PrecondViolatedExcep.h
 * @brief Exception class thats thrown when a precondition is being violated.
 * @author Isaiah G. (StarID: 16437856)
 * @date Week 4 Sunday 23:59
 * @instructor Jie Meichsner Ph.D
 */

#ifndef PRECOND_VIOLATED_EXCEP_H
#define PRECOND_VIOLATED_EXCEP_H

#include <stdexcept>
#include <string>

class PrecondViolatedExcep : public std::logic_error
{
public:
    PrecondViolatedExcep(const std::string& message = "")
        : std::logic_error("Precondition Violated Exception: " + message)
    {}
}; // end PrecondViolatedExcep

#endif
