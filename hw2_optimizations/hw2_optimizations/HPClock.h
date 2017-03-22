/*******************************************************************************
**
** File: HPClock.h
** Author: Hari Kalva
**
*******************************************************************************/

#ifndef __HPCLOCK_H__
#define __HPCLOCK_H__
/*
* High Performance Clock is based on the high performance counter
* available on Windows OS. The accuracy of the clock depends on the
* actual hardware support.
*/

typedef unsigned long long uint_64;

class HPClock {
public:
	// constructor
	HPClock() :m_bStarted(false), m_nStartTime(0), m_nFrequency(0), m_nCurrentTime(0) {
		QueryPerformanceFrequency(&m_tLargeInt);
		m_nFrequency = m_tLargeInt.QuadPart;
	}

	// destructor
	~HPClock() {};

	// Start measuting the time. Use this in conjunction with Stop
	// to measure the absolute time elapsed (not the thread time)
	void Start() {
		m_bStarted = true;
		QueryPerformanceCounter(&m_tLargeInt);
		m_nStartTime = m_tLargeInt.QuadPart;
	}

	// reset clock
	void Reset() {
		m_bStarted = false;
	}

	// returns the time as a double since last Start was called
	// returns 0 if start was not called earlier;
	double Stop() {
		if (!m_bStarted) return 0.0;
		QueryPerformanceCounter(&m_tLargeInt);
		return (m_tLargeInt.QuadPart - m_nStartTime) / (double)m_nFrequency;
	}

	// get frequency of the clock
	uint_64 GetFrequency() { return m_nFrequency; }

	//get current clock counter value
	uint_64 GetTime() {
		QueryPerformanceCounter(&m_tLargeInt);
		return (m_nCurrentTime = m_tLargeInt.QuadPart);
	}
private:
	uint_64 m_nFrequency;
	uint_64 m_nCurrentTime;
	uint_64 m_nStartTime;
	LARGE_INTEGER m_tLargeInt;
	bool m_bStarted;
};

#endif //__HPCLOCK_H__