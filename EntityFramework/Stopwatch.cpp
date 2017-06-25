
#include "Stopwatch.h"

Stopwatch::Stopwatch() :isRunning(0), isPaused(0),
m_Elapsed_seconds(std::chrono::duration<double>(0)),
m_Paused_seconds(std::chrono::duration<double>(0))
{

}


Stopwatch::~Stopwatch()
{

}

void Stopwatch::Start()
{
	using namespace std::chrono;
	if (!isRunning)
	{
		m_Start = high_resolution_clock::now();
		m_Elapsed_seconds = std::chrono::duration<double>(0);
		m_Paused_seconds = std::chrono::duration<double>(0);
		isPaused = false;
	}
	isRunning = true;
}

void Stopwatch::Stop()
{
	if (!isRunning) return;
	using namespace std::chrono;
	m_End = high_resolution_clock::now();
	this->UnPause();
	isRunning = false;

}

void Stopwatch::UnPause()
{
	if (!isPaused) return;
	if (!isRunning) return;
	using namespace std::chrono;
	isPaused = false;
	m_Paused_seconds += duration<double>(high_resolution_clock::now() - m_PauseStart);

}
void Stopwatch::Pause()
{
	if (isPaused) return;
	if (!isRunning) return;
	using namespace std::chrono;
	isPaused = true;
	m_PauseStart = high_resolution_clock::now();


}


double Stopwatch::ElapsedTime()const
{
	using namespace std::chrono;

	if (isRunning)
	{
		if (isPaused)
		{
			//Calculate and return: duration between start paint and last pause, minus time sum of previous pause periods 
			//paused at -  startedAt  - any residual pause from previous pauses
			return (duration_cast<duration<double>>(m_PauseStart - m_Start) - m_Paused_seconds).count();
		}
		time_point<high_resolution_clock> localEnd = high_resolution_clock::now();
		//std::chrono::duration<double> elapsed_seconds = localEnd - m_Start;
		return (duration_cast<duration<float>>(localEnd - m_Start) - m_Paused_seconds).count();
		//return (duration_cast<duration<milliseconds>>(m_End - m_Start) - m_Paused_seconds).count();
	}
	else
	{
		//std::chrono::duration<int> two_seconds(2);
		return (duration_cast<duration<float>>(m_End - m_Start) - m_Paused_seconds).count();
		//return (duration_cast<duration<milliseconds>>(m_End - m_Start) - m_Paused_seconds).count();
	}
}