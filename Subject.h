//
// Created by Matilde Giuliani on 23/04/25.
//

#ifndef UNTITLED43_SUBJECT_H
#define UNTITLED43_SUBJECT_H
#include "Observer.h"
class Subject {
public:
    virtual void subscribe (Observer * o) = 0;
    virtual void unsubscribe (Observer * o) = 0;
    virtual void notify () = 0;
    virtual ~Subject ()= default;
};

#endif //UNTITLED43_SUBJECT_H
