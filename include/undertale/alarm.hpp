#pragma once
#include <functional>
#include <cstdint>


namespace Undertale {

	using AlarmCallback = std::function<void(void)>;

	class Alarm {

		private:
		AlarmCallback callback = nullptr;
		void CallCallback();
		std::int8_t CheckNewValue(std::int8_t value) const;
		std::int8_t counter = -1;

		public:
		void SetCallback(AlarmCallback callback);

		std::int8_t GetCounter() const;

		void SetCounter(std::int8_t value);
		void IncrementCounter();
		void DecrementCounter();
		

	};

}

