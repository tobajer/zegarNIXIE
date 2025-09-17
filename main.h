#ifndef __MAXIN_H__
#define __MAXIN_H__
#include <stm32f10x.h>
#include "Biblioteka_Kalendarz.h"

#define SYSCLK_FREQ_56MHz  56000000UL

#define DRV_KROK_PERIOD_VALUE	1	//
#define	PRAWO	Bit_RESET
#define LEWO	Bit_SET

typedef enum eTrybTypeDef
{
	//podstawowe (widoczne) tryby pracy; menu nadrzedne
	ZEGAR = 0,
	USTAW_ZEGAR_GODZINA = 1,
	USTAW_MAX,
	//od tego miejsca zaczynaj¹ siê tzw. podtryby pracy
	USTAW_ZEGAR_MINUTA,
	USTAW_ZEGAR_WDAY,
	USTAW_ALARM_GODZINA,
	USTAW_ALARM_MINUTA,
	USTAW_KALIBRACJA,
//	USTAW_PROGRAM,
	ODCZYT_ALARMU
}TrybTypeDef;

typedef struct
{
	uint16_t 	FREQ;
	uint16_t	PERIOD;
	uint16_t	VOLUME;
}BuzzerTypeDef;


void Buzzer_init(BuzzerTypeDef* buz);
void Buzzer_start(void);

void Wyswietl_czas(BibKal_TimeTypeDef* RTC_TimeStruct);
void Wyswietl_program(uint32_t program);
void Wyswietl_ustaw_zegar_godzina(BibKal_TimeTypeDef* RTC_TimeStruct);
void Wyswietl_ustaw_zegar_minuta(BibKal_TimeTypeDef* RTC_TimeStruct);
void Wyswietl_ustaw_zegar_dzientyg(BibKal_CalendarTypeDef* RTC_CallendarStruct);
void Wyswietl_ustaw_alarm_dzientyg(uint32_t program, BibKal_AlarmTypeDef* RTC_AlarmStruct);
void Wyswietl_ustaw_alarm_godzina(BibKal_AlarmTypeDef* RTC_AlarmStruct);
void Wyswietl_ustaw_alarm_minuta(BibKal_AlarmTypeDef* RTC_AlarmStruct);
void Wyswietl_ustaw_kalibracja(void);
void Wyswietl_odczyt_alarmu(uint32_t wday);
void Wyswietl_nic(void);	//czysci wyswwietlacze

void Drv_kierunek(BitAction kier);
void Drv_krok(void);		//zwraca aktualna pozycje w krokach
int32_t Drv_pozycja(int32_t angle);
void Drv_uspij(void);
void Drv_obodz(void);
void Drv_KrokCount_Reset(void);
void Bazowanie_wskazowki(void);

void Display_value(uint32_t val);
void Display_digit(uint32_t dig, uint32_t val);
uint32_t pierwiastek(uint32_t val, int32_t err);
void GPIO_Configuration(void);

uint32_t pierwiastek(uint32_t val, int32_t err);

#endif //__MAXIN_H__
