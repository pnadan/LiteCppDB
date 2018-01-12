#pragma once

#include "PageAddress.h"

#include <string>
#include <vector>

namespace LiteCppDB
{
	class ByteWriter
	{
	private:
		std::vector<uint8_t> mBuffer;
		int32_t mPosition;

	public:
		std::vector<uint8_t> getBuffer();

		int32_t getPosition() noexcept;

		ByteWriter(int32_t length);

		ByteWriter(std::vector<uint8_t> buffer);

		void Skip(int32_t length) noexcept;

#pragma region Native data types

		void Write(uint8_t value);

		void Write(bool value);

		void Write(uint16_t value);

		void Write(uint32_t value);

		void Write(uint64_t value);

		void Write(int16_t value);

		void Write(int32_t value);

		void Write(int64_t value);

		void Write(double value);

		void Write(std::vector<uint8_t> value);

#pragma endregion Native data types

#pragma region Extended types

		void Write(std::string value);

		void Write(std::string value, int32_t length);

		void Write(std::chrono::time_point<std::chrono::system_clock> value) noexcept;

		void Write(PageAddress value);

		void WriteBsonValue(BsonValue value, uint16_t length);

#pragma endregion Extended types
	};
}