#ifndef BELIEN_IPANDPORT_H
#define BELIEN_IPANDPORT_H

#include <string>
#include "Header.h"
#include "singleton.h"
#include <winsock2.h>
#include <ws2tcpip.h> // for inet_pton

#ifdef BELIEN_CHECK_QTCP
#include <QRegularExpression>
#include <QtNetwork\qhostaddress.h>
#endif

#define MAX_PACKET_SIZE		64 * 1024			// 数据包的最大长度,单位是sizeof(char)
#define	MAXFILEDIRLENGTH	256				// 存放文件路径的最大长度

namespace belien {
	namespace tcpcheck {

#define TCPCheck TcpCheck::GetInstance()
		class TcpCheck : public Singleton < TcpCheck > {
			friend Singleton < TcpCheck > ;

		public:
			TcpCheck()	{}

			~TcpCheck() {}

			bool isValidPort(int port) {
				// 首先判断端口号是否在 0 到 65535 之间
				if (port < 0 || port > 65535) {
					return false;
				}
				// 判断是否是保留端口号
				if (port == 0 || port == 20 || port == 21 || port == 22 || port == 23
					|| port == 25 || port == 53 || port == 80 || port == 110 || port == 143
					|| port == 443 || port == 3306) {
					return false;
				}
				// 端口号合法
				return true;
			}

			bool isValidData(const std::string & data){
				return (data.size() > 0 && data.size() < MAX_PACKET_SIZE);
			}

			bool isIPValid(const std::string & ipAddress) {
				struct in_addr addr;
				int retVal = inet_pton(AF_INET, ipAddress.c_str(), &addr);
				return (retVal != 0);
			}

			bool isValidIpAddressAndPort(const std::string& ipAddress, int port) {
				return (isIPValid(ipAddress) && isValidPort(port));
			}

#ifdef BELIEN_CHECK_QTCP
			bool isIPValid(const QString& ip) {
				QRegularExpression regExp("^((([1-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])\\.){1}(([0-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])\\.){2}([1-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5]))$");
				QRegularExpressionMatch match = regExp.match(ip);
				return match.hasMatch();
				/*QHostAddress addr(ip);
				if (addr.isNull() || addr.protocol() != QAbstractSocket::IPv4Protocol) {
					return false;
				}
				else {
					return true;
				}*/
			}

			bool isValidData(const QByteArray & data){
				if (data.size() > MAX_PACKET_SIZE) {
					return false;
				}
				return true;
			}
#endif 
		};
	}
}
#endif
