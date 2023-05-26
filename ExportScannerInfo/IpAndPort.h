#include <QString>
#include <QRegularExpression>

inline static bool isValidPort(int port) {
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

inline static bool isIPValid(const QString& ip) {
    QRegularExpression regExp("^((([1-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])\\.){3}([1-9]|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5]))$");
    QRegularExpressionMatch match = regExp.match(ip);
    return match.hasMatch();
}