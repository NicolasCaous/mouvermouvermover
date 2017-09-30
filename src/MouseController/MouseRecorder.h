#include "../../include/string"
#include "../../include/vector"
#include "../Utils/XY.h"

#ifndef MOUSERECORDER_H
#define MOUSERECORDER_H

class MouseRecorder {
    public:
        MouseRecorder(int threadClock);
        ~MouseRecorder(void);
        void start(void);
        void end(void);
        static void endAll(void);
        std::vector< XY > getTrack(void);
        int getClock(void);
    private:
        static void threadFunction(std::vector< void* >& params);
        static std::vector< MouseRecorder* > recorders;
        static std::string threadGroup;
        static int instances;
        std::string threadName;
        std::vector< void* > params;
        std::vector< XY > track;
        int threadMili;
        int threadClock;
        bool running;
    protected:
};

#endif
