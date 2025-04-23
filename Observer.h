//
// Created by Matilde Giuliani on 23/04/25.
//

#ifndef UNTITLED43_OBSERVER_H
#define UNTITLED43_OBSERVER_H
class Observer {
public:
    virtual void update () = 0;
    virtual void attach () = 0;
    virtual void detach () = 0;
    virtual ~Observer ()=default;
};
#endif //UNTITLED43_OBSERVER_H
