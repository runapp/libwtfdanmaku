#include <Windows.h>
#include <mmsystem.h>
#include "WinmmTimer.hpp"

#pragma comment (lib, "winmm.lib")

namespace WTFDanmaku {

    time_t WinmmTimer::GetGlobalCurrent() {
        return timeGetTime();
    }

    WinmmTimer::WinmmTimer() {
        timeBeginPeriod(1);
    }

    WinmmTimer::~WinmmTimer() {
        timeEndPeriod(1);
    }

    void WinmmTimer::Start() {
        mTimeBase = 0;
        mBeginTime = timeGetTime();
    }

    void WinmmTimer::Pause() {
        mTimeBase += timeGetTime() - mBeginTime;
    }

    void WinmmTimer::Resume() {
        mBeginTime = timeGetTime();
    }

    void WinmmTimer::Update() {
        mCurrent = timeGetTime() - mBeginTime + mTimeBase;
    }

    void WinmmTimer::Stop() {
        mBeginTime = 0;
        mTimeBase = 0;
    }

    void WinmmTimer::AddOffset(int64_t offset) {
        mTimeBase += offset;
    }

    time_t WinmmTimer::GetMilliseconds() {
        return mCurrent;
    }

}