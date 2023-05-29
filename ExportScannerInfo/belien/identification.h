#ifndef BELIEN_QTNTIFICATION_H
#define BELIEN_QTNTIFICATION_H

#include "Header.h"
#include "singleton.h"

#ifdef BELIEN_ENUM_STRING
#include <string>
#endif
#ifdef BELIEN_ENUM_QSTRING
#include <qstring.h>
#endif

namespace belien {
namespace identification {
    // ��������
    enum class Func : short { SUCCESS, FAILURE };
	
#define FuncStr Function_Str::GetInstance()
    class Function_Str : public Singleton< Function_Str > {
        friend Singleton< Function_Str >;

    public:
#ifdef BELIEN_ENUM_STRING
        const std::string SUCCESS = "�����ɹ�";
        const std::string FAILURE = "����ʧ��";
#endif
#ifdef BELIEN_ENUM_QSTRING
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
#ifdef BELIEN_ENUM_STRING
        const std::string INVALID_ARGUMENT = " ��Ч�Ĳ���";
        const std::string INVALID_TYPE     = "��Ч������";
        const std::string INVALID_SIZE     = "��Ч�Ĵ�С";
        const std::string INVALID_FORMAT   = "��Ч�ĸ�ʽ";
        const std::string INVALID_DATA     = "��Ч������";
        const std::string INVALID_STATE    = "��Ч��״̬";
#endif
#ifdef BELIEN_ENUM_QSTRING
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
		SOCKET_NON_BLOCKING,
		SOCKET_BLOCKING,
		LISTENING,
		NOT_LISTENED,
		REQUEST_CONNECT,
		CONNECT,
		UNCONNECT,
		DISCONNECT,
		RECVING_REQUEST_DATA,
		STOP_RECVED_REQUEST_DATA,
		RESPONSE_CONNECT_REQUEST,
		RECV_SUCCESS,
		RECV_FAILURE,
        SENDING,
        SEND_SUCCESS,
        SEND_FAILURE
    };

#define TPStr TP_Str::GetInstance()
    class TP_Str : public Singleton< TP_Str > {
        friend Singleton< TP_Str >;

    public:
#ifdef BELIEN_ENUM_STRING
        const std::string PORT_ILLEGAL             = "�Ƿ��˿ں�";
        const std::string PORT_ADDED               = "�˿ں��Ѵ���";
        const std::string PORT_ADDING_SUCCESS      = "�˿ں���ӳɹ�";
		const std::string SOCKET_INIT_FAILURE      = "��ʼ��ʧ��";
		const std::string SOCKET_INIT_SUCCESS      = "��ʼ���ɹ�";
		const std::string SOCKET_NON_BLOCKING      = "���ӷ�����";
		const std::string SOCKET_BLOCKING          = "��������";
        const std::string LISTENING                = "������...";
        const std::string NOT_LISTENED             = "δ����";
        const std::string REQUEST_CONNECT          = "��������";
        const std::string CONNECT                  = "���ӳɹ�";
        const std::string UNCONNECT                = "δ����";
        const std::string DISCONNECT               = "���ӶϿ�";
        const std::string RECVING_REQUEST_DATA     = "������������";
        const std::string STOP_RECVED_REQUEST_DATA = "��ֹͣ���ݽ���";
		const std::string RECV_SUCCESS			   = "���ճɹ�";
		const std::string RECV_FAILURE			   = "����ʧ��";
        const std::string SENDING                  = "������...";
        const std::string SEND_SUCCESS             = "���ͳɹ�";
        const std::string SEND_FAILURE             = "����ʧ��"; 
#endif
#ifdef BELIEN_ENUM_QSTRING
        const QString PORT_ILLEGAL = QString::fromLocal8Bit("�Ƿ��˿ں�");
        const QString PORT_ADDED = QString::fromLocal8Bit("�˿ں��Ѵ���");
        const QString PORT_ADDING_SUCCESS =
            QString::fromLocal8Bit("�˿ں���ӳɹ�");
		const QString SOCKET_INIT_FAILURE =
            QString::fromLocal8Bit("��ʼ��ʧ��");
		const QString SOCKET_INIT_SUCCESS =
            QString::fromLocal8Bit("��ʼ���ɹ�");
		const QString SOCKET_NON_BLOCKING      = QString::fromLocal8Bit("���ӷ�����");
		const QString SOCKET_BLOCKING          = QString::fromLocal8Bit("��������");
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
		const QString RECV_SUCCESS			   = "���ճɹ�";
		const QString RECV_FAILURE			   = "����ʧ��";
        const QString SENDING      = QString::fromLocal8Bit("������...");
        const QString SEND_SUCCESS = QString::fromLocal8Bit("���ͳɹ�");
        const QString SEND_FAILURE = QString::fromLocal8Bit("����ʧ��");
#endif
    };
	
#pragma endregion

} // namespace identification
} // namespace belien

#endif