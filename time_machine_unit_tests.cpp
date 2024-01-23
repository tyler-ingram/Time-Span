#include "time_span.h"
#include <iostream>
/*
Testing Class for the TimeSpan Class. Various unit tests for correctness are performed. 
By Robert Dimpsey
Modified by Tyler Ingram 1/13/2024
*/
using namespace std;

bool CheckValues(TimeSpan time, int hours, int minutes, int seconds)
{
	if ((time.hours() != hours) || (time.minutes() != minutes) || (time.seconds() != seconds))
	{
		return false;
	}
	return true;
}

bool TestZeros()
{
	TimeSpan ts(0, 0, 0);
	return CheckValues(ts, 0, 0, 0);
}

bool TestFloatSeconds()
{
	TimeSpan ts(127.86);
	return CheckValues(ts, 0, 2, 8);
}

bool TestFloatSecondsFloatHours()
{
	TimeSpan ts(1.5,4,127.86);
	return CheckValues(ts, 1, 36, 8);
}

bool TestNegativeMinute()
{
	TimeSpan ts(8, -23, 0);
	return CheckValues(ts, 7, 37, 0);
}

bool TestNegativeHour()
{
	TimeSpan ts(-3, 73, 2);
	return CheckValues(ts, -1, -46, -58);
}

bool TestAdd()
{
	TimeSpan ts1, ts2(5), ts3(7, 0), ts4(4, 0, 0);
	TimeSpan add_it_up = ts1 + ts2 + ts3 + ts4;
	return CheckValues(add_it_up, 4, 7, 5);
}

bool TestSubtract()
{
	TimeSpan ts1, ts2(5), ts3(7, 0), ts4(4, 0, 0);
	TimeSpan sub_ts = ts1 - ts2 - ts3 - ts4;
	return CheckValues(sub_ts, -4, -7, -5);
}

bool TestInStream()
{
	TimeSpan ts;
	cout << "Enter '1 2 3' into the console representing hours min seconds: " << endl;
	cin >> ts; //user enters one two three
	return CheckValues(ts,1,2,3);
}

bool TestOutStream()
{
	TimeSpan ts(1,2,3);
	cout << ts << " ^ does this say 'Hours: 1, Minutes: 2, Seconds: 3'  y/n" << endl;
	string in;
	cin >> in;
	return (in == "y");
}

bool TestFloatMinutes()
{
	TimeSpan ts(0,4.5,0);
	return CheckValues(ts, 0, 4, 30);
}

bool TestTwoParamFloatMinutes()
{
	TimeSpan ts(4.5,0);
	return CheckValues(ts, 0, 4, 30);
}

bool TestFloatHours()
{
	TimeSpan ts(1.25,0,0);
	return CheckValues(ts,1,15,0);
}

bool TestFloatAndNegative()
{
	TimeSpan ts(1.5,-90.5,-15);
	return CheckValues(ts,0,0,-45);
}

bool TestAddInPlace()
{
	TimeSpan ts1(5, 6, 7);
	TimeSpan ts2(1, 1, 1);
	if ((!CheckValues(ts1, 5, 6, 7)) || (!CheckValues(ts2, 1, 1, 1)))
	{
		return false;
	}
	ts1 += ts2;
	if ((!CheckValues(ts1, 6, 7, 8)) || (!CheckValues(ts2, 1, 1, 1)))
	{
		return false;
	}
	return true;
}

bool TestUnary()
{
	TimeSpan ts(1,2,3);
	return CheckValues(-ts,-1,-2,-3);
}

bool TestEquals()
{
	TimeSpan ts1(34.3,40.5,16.7);
	TimeSpan ts2(34.3,40.5,16.7);
	return ts1 == ts2;
}

bool TestNotEquals()
{
	TimeSpan ts1(34.3,40.5,16.7);
	TimeSpan ts2(34.2,40.5,16.7);
	return ts1 != ts2;
}

bool TestGreaterThan()
{
	TimeSpan ts1(34.3,40.5,16.7);
	TimeSpan ts2(34.2,40.5,16.7);
	return ts1 > ts2;
}

bool TestGreaterThanEquals()
{
	TimeSpan ts1(34.3,40.5,16.7);
	TimeSpan ts2(34.3,40.5,16.7);
	if (!(ts1 >= ts2))
		return false;
	ts2.set_time(34,40,16);
	return ts1 >= ts2;
}

bool TestLessThan()
{
	TimeSpan ts1(34.3,40.5,16.7);
	TimeSpan ts2(34.2,40.5,16.7);
	return ts2 < ts1;
}

bool TestLessThanEquals()
{
	TimeSpan ts1(34.3,40.5,16.7);
	TimeSpan ts2(34.3,40.5,16.7);
	if (!(ts2 <= ts1))
		return false;
	ts2.set_time(34,40,16);
	return ts2 <= ts1;
}


bool TestSubtractInPlace()
{
	TimeSpan ts1(5, 6, 7);
	TimeSpan ts2(1, 1, 1);
	if ((!CheckValues(ts1, 5, 6, 7)) || (!CheckValues(ts2, 1, 1, 1)))
	{
		return false;
	}
	ts1 -= ts2;
	if ((!CheckValues(ts1, 4, 5, 6)) || (!CheckValues(ts2, 1, 1, 1)))
	{
		return false;
	}
	return true;
}

int main()
{
	cout << "Testing TimeSpan Class" << endl;
	if (!TestZeros()) cout << "Failed: TestZeros" << endl;
	if (!TestFloatSeconds()) cout << "Failed: TestFloatSeconds" << endl;
	if (!TestNegativeMinute()) cout << "Failed: TestNegativeMinute" << endl;
	if (!TestNegativeHour()) cout << "Failed: TestNegativeHour" << endl;
	if (!TestAdd()) cout << "Failed: TestAdd" << endl;
	if (!TestAddInPlace()) cout << "Failed: TestAddInPlace" << endl;
	//if (!TestInStream()) cout << "Failed: TestInStream" << endl;
	if (!TestFloatMinutes()) cout << "Failed: TestFloatMinutes" << endl;
	if (!TestTwoParamFloatMinutes()) cout << "Failed: TestTwoParamFloatMinutes" << endl;
	if (!TestFloatHours()) cout << "Failed: TestFloatHours" << endl;
	if (!TestSubtract()) cout << "Failed: TestSubtract" << endl;
	//if (!TestOutStream()) cout << "Failed: TestOutStream" << endl;
	if (!TestFloatSecondsFloatHours()) cout << "Failed: TestFloatSecondsFloatHours" << endl;
	if (!TestUnary()) cout << "Failed: TestUnary" << endl;
	if (!TestEquals()) cout << "Failed: TestEquals" << endl;
	if (!TestNotEquals()) cout << "Failed: TestNotEquals" << endl;
	if (!TestGreaterThan()) cout << "Failed: TestGreaterThan" << endl;
	if (!TestGreaterThanEquals()) cout << "Failed: TestGreaterThanEquals" << endl;
	if (!TestLessThan()) cout << "Failed: TestLessThan" << endl;
	if (!TestLessThanEquals()) cout << "Failed: TestLessThanEquals" << endl;
	if (!TestFloatAndNegative()) cout << "Failed: TestFloatAndNegative" << endl;
	cout << "Testing Complete" << endl;
}