#ifndef BELIEN_IPANDPORT_H
#define BELIEN_IPANDPORT_H

#include <string>
#include <QString>
#include <QRegularExpression>
#include "singleton.h"

#define MAX_PACKET_SIZE		64 * 1024			// ���ݰ�����󳤶�,��λ��sizeof(char)
#define	MAXFILEDIRLENGTH	256				// ����ļ�·������󳤶�

namespace belien {
	namespace ip_port {
		
#define IpPort IpAndPort::GetInstance()
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

			bool isIPValid(const QString& ip) {
				QRegularExpression regExp("^((([1-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])\\.){3}([1-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5]))$");
				QRegularExpressionMatch match = regExp.match(ip);
				return match.hasMatch();
			}
			
			bool isIPValid(const std::string & ip) {
				return isIPValid(QString::fromLocal8Bit(ip.data()));
			}

			bool isValidData(const QByteArray & data){
				if (data.size() > MAX_PACKET_SIZE) {
					return false;
				}
				return true;
			}
			
			bool isValidData(const std::string & data){
				if (data.size() > MAX_PACKET_SIZE) {
					return false;
				}
				return true;
			}

		};
	}
}
#endif
