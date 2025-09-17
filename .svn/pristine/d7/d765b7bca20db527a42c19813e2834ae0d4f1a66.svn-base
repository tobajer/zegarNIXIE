#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <math.h>
#include <float.h>
#include "stm32f10x.h"
#include "stdio.h"
#include "Biblioteka_Kalendarz.h"

/* defines ------------------------------------------------------------------*/

typedef enum {
	RTC_OK = 0,						/* (0) Succeeded */
	RTC_BAD_DATE = 1,			/* (1) incorrect year value. Should be >= 13*/
	RTC_BAD_TIME = 2			/* (1) incorrect time value */
} RTCRESULT;


/*!
 * \brief Ustawia licznik RTC
 *
 * [detailed description]
 *
 * \param[in] RTC_TimeStruct struktura ze sk³adnikami godziny: HOUR, MIN, SEC
 * \return typ wyliczeniowy RTCRESULT: RTC_OK - jesli poprawne dane wejsciowe oraz RTC_BAD_DATE, gdy dane wejsciowe niepoprawne
 * \sa ConvertTimeToSeconds()
 * \note
 * \warning
 */
RTCRESULT RTC_SetTime(BibKal_TimeTypeDef* RTC_TimeStruct);


/*!
 * \brief Pobiera wartosc licznika RTC i konwertuje do struktura czasowej HOUR,MIN,SEC
 *
 * Konwertuje licznik RTC do postaci struktury czaasu HOUR,MIN,SEC>
 *
 * \param[out] wskaznik do RTC_TimeStruct struktury danych czasu, ktory bedzie uzupelniony
 * \return typ wyliczeniowy RTCRESULT: RTC_OK - jesli poprawne dane wejsciowe oraz RTC_BAD_DATE, gdy dane wejsciowe niepoprawne
 * \sa [see also section]
 * \note
 * \warning
 */
void RTC_GetTime(BibKal_TimeTypeDef* RTC_TimeStruct);


/*!todo uzupelnic dokumentacje funkcji*/
/*!
 * \brief Ustawia licznik RTC zgodnie z danymi wejsciowymi
 *
 * [detailed description]
 *
 * \param[in] RTC_CalendarStruct wskaznik do danych wejsciowych
 * \param[out]
 * \return [information about return value]
 * \sa [see also section]
 * \note [any note about the function you might have]
 * \warning [any warning if necessary]
 */
RTCRESULT RTC_SetCalendar(BibKal_CalendarTypeDef* RTC_CalendarStruct);

/*!todo uzupelnic dokumentacje funkcji*/
  /*!
   * \brief [brief description]
   *
   * [detailed description]
   *
   * \param[in] [name of input parameter] [its description]
   * \param[out] [name of output parameter] [its description]
   * \return typ wyliczeniowy RTCRESULT: RTC_OK - jesli poprawne dane wejsciowe oraz RTC_BAD_DATE, gdy dane wejsciowe niepoprawne
   * \sa [see also section]
   * \note [any note about the function you might have]
   * \warning [any warning if necessary]
   */
  void RTC_GetCalendar(BibKal_CalendarTypeDef* RTC_CalendarStruct, int32_t shift);


  /*!todo uzupelnic dokumentacje funkcji*/
 /*!
   * \brief Konwertuje wartosc licznika RTC i konwertuje do struktury daty
   *
   * \param[out] wskaznik do RTC_CalendarStruct struktury danych daty, ktora bedzie uzupelniony
   * \return typ wyliczeniowy RTCRESULT: RTC_OK - jesli poprawne dane wejsciowe oraz RTC_BAD_DATE, gdy dane wejsciowe niepoprawne
   * \sa [see also section]
   * \note [any note about the function you might have]
   * \warning [any warning if necessary]
   */
   void RTC_GetDateTimeString(char *string);

   /*!todo uzupelnic dokumentacje funkcji*/
   uint32_t RTC_GetSeconds(void);
