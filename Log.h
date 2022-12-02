#ifndef NGL_LOG_H
#define NGL_LOG_H
#include<iostream>

namespace NGL
{

	class Log
	{
	public:
		template<typename T> static void Info(T msg);
		template<typename T> static void Warning(T msg);
		template<typename T> static void Error(T msg);
		template<typename T> static void Debug(T msg);
	};

	template<typename T>
	void Log::Debug(T msg)
	{
		std::cout << msg << std::endl;
	}

	template<typename T>
	void Log::Info(T msg)
	{

	}

	template<typename T>
	void Log::Warning(T msg)
	{

	}

	template<typename T>
	void Log::Error(T msg)
	{

	}

}



#endif // !NGL_LOG_H

