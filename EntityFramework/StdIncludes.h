#pragma once
#define WIN32_LEAN_AND_MEAN

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "GLM\GLM.hpp"
#include "GLM\GTC\matrix_transform.hpp"
#include "GLM\GTC\type_ptr.hpp"
#include <GLM\GTC\matrix_transform.hpp>


#include <unordered_map>
#include <algorithm>
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

#include "Stopwatch.h"


namespace KLM_FRAMEWORK
{

	using Vec2i = glm::ivec2;
	using Vec2 = glm::vec2;
	using Vec3 = glm::vec3;
	using Vec4 = glm::vec4;
	using Colour = glm::vec4;
	using Mat4 = glm::mat4;
	using Quat = glm::quat;

	using KLMint = int;
	using KLMuint = unsigned int;
	using KLMfloat = float;
	using KLMdouble = double;
	using KLMchar = char;
	using KLMbyte = char;
	using KLMbool = bool;


	template<class T_KEY, class T_VAL>
	bool QueryMap(T_KEY key, T_VAL& output, const std::unordered_map<T_KEY, T_VAL>& map)
	{
		auto itemPair = map.find(key);
		if (itemPair != std::end(map))
		{
			output = itemPair->second;
			return true;
		}

		return false;
	};

	template<class T>
	void RemoveFromVecByValue(std::vector<T>& vec, const T& value)
	{
		vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
	}


	inline float RandomRange(float low, float high)
	{
		return  low + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (high - low)));
	}


	inline bool IsApproxEqual(const float& a, const float& b, float epsilon)
	{
		return (fabs(b - a) < epsilon);
	};

	inline bool IsApproxEqual(const double& a, const double& b, double epsilon)
	{
		return (fabs(b - a) < epsilon);
	};


	inline void PrintVec(const Vec3& vec)
	{
		std::cout << "x=" << vec.x << "  y=" << vec.y << "  z=" << vec.z << std::endl;
	}


	inline void PrintCol(const Colour& col)
	{
		std::cout << "r=" << col.r << "  g=" << col.g << "  b=" << col.b << "  a=" << col.a << std::endl;
	}


	inline void DEBUG(const std::string& line)
	{
		std::cout << "DEBUG: " << line << std::endl;
	}

	inline void PRINTL(const std::string& line)
	{
		std::cout << line << std::endl;
	}

	inline std::string ToString(int value)
	{
		return std::to_string(value);
	}

	inline std::string ToString(float value)
	{
		return std::to_string(value);
	}

	inline std::string ToString(double value)
	{
		return std::to_string(value);
	}

	inline std::string ToString(const Vec3& vec)
	{

		return   "x=" + std::to_string(vec.x) +
			"  y=" + std::to_string(vec.y) +
			"  z=" + std::to_string(vec.z);
	}

	inline std::string ToString(const Vec4& vec)
	{

		return   "x=" + std::to_string(vec.x) +
			"  y=" + std::to_string(vec.y) +
			"  z=" + std::to_string(vec.z) +
			"  w=" + std::to_string(vec.w);
	}

	inline std::string ColourToString(const Colour& colour)
	{

		return   "r=" + std::to_string(colour.r) +
			"  g=" + std::to_string(colour.g) +
			"  b=" + std::to_string(colour.b) +
			"  a=" + std::to_string(colour.a);
	}

	inline void WaitForKeypress()
	{
		getch();
	}

	inline float ToRadians(const float& degrees)
	{
		return glm::radians(degrees);
	}

	inline float ToDegrees(const float& radinas)
	{
		return glm::degrees(radinas);
	}

	inline Mat4 RotateMatX(const Mat4& matrix, const float& degrees)
	{
		return glm::rotate(matrix, degrees, Vec3(1, 0, 0));
	}

	inline Mat4 RotateMatY(const Mat4& matrix, const float& degrees)
	{
		return glm::rotate(matrix, degrees, Vec3(0, 1, 0));
	}

	inline Mat4 RotateMatZ(const Mat4& matrix, const float& degrees)
	{
		return glm::rotate(matrix, degrees, Vec3(0, 0, 1));
	}

	inline Vec3 LerpVector(const Vec3& a, const Vec3& b, float speed)
	{
		Vec3 vec = (b - a);
		glm::normalize(vec);
		return (a + (vec*speed));
	}


	template<class T>
	class KLMList
	{

	private:
		std::vector<T> m_Data;

	public:
		KLMList(){}
		virtual ~KLMList() {}

		void Add(const T& element) { m_Data.push_back(element); }

		void Remove(const T& element)
		{
			m_Data.erase(std::remove(m_Data.begin(), m_Data.end(), element), m_Data.end());
		}

		void RemoveByIndex(KLMuint index)
		{
			if (index >= m_Data.size())
			{
				throw std::out_of_range("Index is out of range");
				return;
			}
			m_Data.erase(m_Data.begin() + index);
		}

		void RemoveRange(KLMuint fromIndex, KLMuint toIndex)
		{
			if ((fromIndex >= m_Data.size()) || (toIndex >= m_Data.size()))
			{
				throw std::out_of_range("Index is out of range");
				return;
			}
			m_Data.erase(m_Data.begin() + fromIndex, m_Data.begin()+toIndex);
		}

		bool Contains(const T& element)
		{
		if (std::find(m_Data.begin(), m_Data.end(), element) != m_Data.end())
				return true;
			return false;
		}

		std::vector<T>& StdVector() { return m_Data; }

		T& operator[](KLMuint index)
		{
			return m_Data[index];
		}

		void Clear() { m_Data.clear(); }

		KLMuint Count()const { return m_Data.size(); }

	};

}