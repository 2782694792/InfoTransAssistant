#ifndef BELIEN_IDENTIFICATION_H
#define BELIEN_IDENTIFICATION_H

//#define belien_qt
#define belien_vs

#ifdef belien_vs
#include <string>
#endif
#ifdef belien_qt
#include <qstring.h>
#endif

#include "singleton.h"

namespace belien {
namespace identification {
    // ��������
    enum class Function : short { SUCCESS, FAILURE };

    class FunctionStr : public Singleton< FunctionStr > {
        friend Singleton< FunctionStr >;

    public:
#ifdef belien_vs
        const char * SUCCESS = "�����ɹ�";
        const char * FAILURE = "����ʧ��";
#endif
#ifdef belien_qt
        const QString SUCCESS = QString::fromLocal8Bit("�����ɹ�");
        const QString FAILURE = QString::fromLocal8Bit("����ʧ��");
#endif
    };

    // ���ݳ�Ա
    enum class Data : short {
        INVALID_ARGUMENT, // ��Ч�Ĳ���
        INVALID_TYPE,     // ��Ч������
        INVALID_SIZE,     // ��Ч�Ĵ�С
        INVALID_FORMAT,   // ��Ч�ĸ�ʽ
        INVALID_DATA,     // ��Ч������
        INVALID_STATE     // ��Ч��״̬
    };
	
#define DataStr Data_Str::GetInstance()
    class Data_Str : public Singleton< Data_Str > {
        friend Singleton< Data_Str >;

    public:
#ifdef belien_vs
        const char * INVALID_ARGUMENT = " ��Ч�Ĳ���";
        const char * INVALID_TYPE     = "��Ч������";
        const char * INVALID_SIZE     = "��Ч�Ĵ�С";
        const char * INVALID_FORMAT   = "��Ч�ĸ�ʽ";
        const char * INVALID_DATA     = "��Ч������";
        const char * INVALID_STATE    = "��Ч��״̬";
#endif
#ifdef belien_qt
        const QString INVALID_ARGUMENT = QString::fromLocal8Bit("��Ч�Ĳ���");
        const QString INVALID_TYPE = QString::fromLocal8Bit("��Ч������");
        const QString INVALID_SIZE = QString::fromLocal8Bit("��Ч�Ĵ�С");
        const QString INVALID_FORMAT = QString::fromLocal8Bit("��Ч�ĸ�ʽ");
        const QString INVALID_DATA  = QString::fromLocal8Bit("��Ч������");
        const QString INVALID_STATE = QString::fromLocal8Bit("��Ч��״̬");
#endif
    };


#pragma region ����Э��

    enum class TP : short {
		PORT_ILLEGAL,
		PORT_ADDED,
		PORT_ADDING,
		SOCKET_INIT_FAILURE,
		SOCKET_INIT_SUCCESS,
        LISTENING,
        NOT_LISTENED,
        REQUEST_CONNECT,
        CONNECT,
        UNCONNECT,
        DISCONNECT,
        RECVING_REQUEST_DATA,
        STOP_RECVED_REQUEST_DATA,
        RESPONSE_CONNECT_REQUEST,
        SENDING,
        SEND_SUCCESS,
        SEND_FAILURE
    };

#define TPStr TP_Str::GetInstance()
    class TP_Str : public Singleton< TP_Str > {
        friend Singleton< TP_Str >;

    public:
#ifdef belien_vs
        const char * PORT_ILLEGAL             = "�Ƿ��˿ں�";
        const char * PORT_ADDED               = "�˿ں��Ѵ���";
        const char * PORT_ADDING_SUCCESS      = "�˿ں���ӳɹ�";
		const char * SOCKET_INIT_FAILURE      = "��ʼ��ʧ��";
		const char * SOCKET_INIT_SUCCESS      = "��ʼ���ɹ�";
        const char * LISTENING                = "������...";
        const char * NOT_LISTENED             = "δ����";
        const char * REQUEST_CONNECT          = "��������";
        const char * CONNECT                  = "���ӳɹ�";
        const char * UNCONNECT                = "δ����";
        const char * DISCONNECT               = "���ӶϿ�";
        const char * RECVING_REQUEST_DATA     = "������������";
        const char * STOP_RECVED_REQUEST_DATA = "��ֹͣ���ݽ���";
        const char * SENDING                  = "������...";
        const char * SEND_SUCCESS             = "���ͳɹ�";
        const char * SEND_FAILURE             = "����ʧ��";

#endif
#ifdef belien_qt
        const QString PORT_ILLEGAL = QString::fromLocal8Bit("�Ƿ��˿ں�");
        const QString PORT_ADDED = QString::fromLocal8Bit("�˿ں��Ѵ���");
        const QString PORT_ADDING_SUCCESS =
            QString::fromLocal8Bit("�˿ں���ӳɹ�");
		const QString SOCKET_INIT_FAILURE =
            QString::fromLocal8Bit("��ʼ��ʧ��");
		const QString SOCKET_INIT_SUCCESS =
            QString::fromLocal8Bit("��ʼ���ɹ�");
        const QString REQUEST_CONNECT = QString::fromLocal8Bit("��������");
        const QString CONNECT         = QString::fromLocal8Bit("���ӳɹ�");
        const QString UNCONNECT       = QString::fromLocal8Bit("δ����");
        const QString DISCONNECT      = QString::fromLocal8Bit("���ӶϿ�");
        const QString LISTENING       = QString::fromLocal8Bit("������...");
        const QString NOT_LISTENED    = QString::fromLocal8Bit("δ����");
        const QString RECVING_REQUEST_DATA =
            QString::fromLocal8Bit("���ڽ�����������");
        const QString STOP_RECVED_REQUEST_DATA =
            QString::fromLocal8Bit("��ֹͣ���ݽ���");
        const QString SENDING      = QString::fromLocal8Bit("������...");
        const QString SEND_SUCCESS = QString::fromLocal8Bit("���ͳɹ�");
        const QString SEND_FAILURE = QString::fromLocal8Bit("����ʧ��");
#endif
    };
	
#pragma endregion

} // namespace identification
} // namespace belien

#endif