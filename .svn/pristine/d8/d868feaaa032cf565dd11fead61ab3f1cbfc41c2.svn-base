#include "RTC_TimeAndCallendar.h"


RTCRESULT RTC_SetTime(BibKal_TimeTypeDef* RTC_TimeStruct)
{
	uint32_t counter;
	
	if (RTC_TimeStruct->SEC < 60 && RTC_TimeStruct->MIN < 60 && RTC_TimeStruct->HOUR < 24)
	{
		counter = ConvertTimeToSeconds(RTC_TimeStruct);
		PWR_BackupAccessCmd(ENABLE);	//access to BKP registers
		RTC_SetCounter(counter);
		RTC_WaitForLastTask();
		PWR_BackupAccessCmd(DISABLE);	//disable access to BKP registers
		return RTC_OK;
	}else
	{
		return RTC_BAD_TIME;
	}
}

RTCRESULT RTC_SetCalendar(BibKal_CalendarTypeDef* RTC_CalendarStruct)
{
	uint32_t counter, u32time;
	u32time =	RTC_GetSeconds() % 86400;	//store actual day in seconds

	counter = ConvertCalendarToSeconds(RTC_CalendarStruct);
	
	if (counter)
	{
		counter += u32time;	//zamien ilosc dni na sekundy, dodaj aktualny czas w sec.

		PWR_BackupAccessCmd(ENABLE);	//access to BKP registers
		RTC_SetCounter(counter);
		RTC_WaitForLastTask();
		PWR_BackupAccessCmd(DISABLE);	//disable access to BKP registers

		return RTC_OK;
	}
	else
	{
		/*jesli counter==0, to znaczy ze podano nieprawidlowa date i ilosc sekund nie zostala obliczona prawidlowo*/
		return RTC_BAD_DATE;
	}
}

uint32_t RTC_GetSeconds(void)
{
	RTC_WaitForLastTask();
	return RTC_GetCounter();
}

void RTC_GetCalendar(BibKal_CalendarTypeDef* RTC_CalendarStruct, int32_t shift)
{
	uint32_t counter;

//	RTC_WaitForLastTask();
	counter = RTC_GetSeconds();

	counter += shift*86400;

	ConvertSecondsToCalendar(counter, RTC_CalendarStruct);

}


void RTC_GetTime(BibKal_TimeTypeDef* RTC_TimeStruct)
{
	uint32_t counter;
	RTC_WaitForLastTask();
	counter =	RTC_GetCounter();

	ConvertSecondsToTime(counter, RTC_TimeStruct);

}


void RTC_GetDateTimeString(char *string)
{

	BibKal_CalendarTypeDef RTC_CalendarStruct;
	BibKal_TimeTypeDef RTC_TimeStruct;
	char *ptr = string;

	RTC_GetCalendar(&RTC_CalendarStruct, 0);
	RTC_GetTime(&RTC_TimeStruct);
	sprintf(ptr, "20%02d%02d%02d %02d%02d%02d ", RTC_CalendarStruct.YEAR, RTC_CalendarStruct.MONTH, RTC_CalendarStruct.DAY, RTC_TimeStruct.HOUR, RTC_TimeStruct.MIN, RTC_TimeStruct.SEC);

}

