#ifndef BELIEN_HEADER_MACRO
#define BELIEN_HEADER_MACRO


#define BELIEN_QT 0



#if BELIEN_QT==0
#define BELIEN_ENUM_QSTRING
#define BELIEN_TCP_CHECK
#define BELIEN_LOG_QDENUG

#elif BELIEN_QT==1
#define BELIEN_ENUM_STRING

#endif // BELIEN_QT==0




#endif