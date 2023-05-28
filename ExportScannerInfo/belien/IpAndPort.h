#ifndef BELIEN_IPANDPORT_H
#define BELIEN_IPANDPORT_H

#include <string>
#include "singleton.h"

#if BELIEN_QT==1
#include <QRegularExpression>
#include <QtNetwork\qhostaddress.h>
#endif

#define MAX_PACKET_SIZE		64 * 1024			// ���ݰ�����󳤶�,��λ��sizeof(char)
#define	MAXFILEDIRLENGTH	256				// ����ļ�·������󳤶�

namespace belien {
	namespace ipport {

#define TCPCheck IpAndPort::GetInstance()
		class IpAndPort : public Singleton < IpAndPort > {
			friend Singleton < IpAndPort > ;

		public:
			IpAndPort()	{}

			~IpAndPort() {}

			bool isValidPort(int port) {
				// �����ж϶˿ں��Ƿ��� 0 �� 65535 ֮��
				if (port < 0 || port > 65535) {
					return false;
				}
				// �ж��Ƿ��Ǳ����˿ں�
				if (port == 0 || port == 20 || port == 21 || port == 22 || port == 23
					|| port == 25 || port == 53 || port == 80 || port == 110 || port == 143
					|| port == 443 || port == 3306) {
					return false;
				}
				// �˿ںźϷ�
				return true;
			}

			bool isValidData(const std::string & data){
				if (data.size() > MAX_PACKET_SIZE) {
					return false;
				}
				return true;
			}			

#if BELIEN_QT==1
			bool isIPValid(const QString& ip) {
				//QRegularExpression regExp("^((([1-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])\\.){3}([1-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5]))$");
				//QRegularExpressionMatch match = regExp.match(ip);
				//return match.hasMatch();
				QHostAddress addr(ip);
				if (addr.isNull() || addr.protocol() != QAbstractSocket::IPv4Protocol) {
					return false;
				}
				else {
					return true;
				}
			}

			bool isValidData(const QByteArray & data){
				if (data.size() > MAX_PACKET_SIZE) {
					return false;
				}
				return true;
			}

			bool isIPValid(const std::string & ip) {
				return isIPValid(QString::fromLocal8Bit(ip.data()));
			}
#endif 
		};
	}
}
#endif
