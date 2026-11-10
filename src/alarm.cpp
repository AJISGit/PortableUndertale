#include <undertale/alarm.hpp>


void Undertale::Alarm::CallCallback() {

	if (counter != 0) { return; }
	if (callback == nullptr) { return; }
	callback();

}


std::int8_t Undertale::Alarm::CheckNewValue(std::int8_t value) const {
	std::int8_t retVal = value;
	if (value < -1) {
		retVal = -1;
	}
	return retVal;
}


void Undertale::Alarm::SetCallback(Undertale::AlarmCallback callback) {
	this->callback = callback;
}


std::int8_t Undertale::Alarm::GetCounter() const {
	return counter;
}


void Undertale::Alarm::SetCounter(std::int8_t value) {
	counter = CheckNewValue(value);
	CallCallback();
}


void Undertale::Alarm::IncrementCounter() {
	std::int8_t oldCount = GetCounter();
	SetCounter(oldCount + 1);
}


void Undertale::Alarm::DecrementCounter() {
	std::int8_t oldCount = GetCounter();
	SetCounter(oldCount - 1);
}

