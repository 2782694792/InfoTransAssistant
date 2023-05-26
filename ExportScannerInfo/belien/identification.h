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
    // 函数操作
    enum class Function : short { SUCCESS, FAILURE };

    class FunctionStr : public Singleton< FunctionStr > {
        friend Singleton< FunctionStr >;

    public:
#ifdef belien_vs
        const char * SUCCESS = "操作成功";
        const char * FAILURE = "操作失败";
#endif
#ifdef belien_qt
        const QString SUCCESS = QString::fromLocal8Bit("操作成功");
        const QString FAILURE = QString::fromLocal8Bit("操作失败");
#endif
    };

    // 数据成员
    enum class Data : short {
        INVALID_ARGUMENT, // 无效的参数
        INVALID_TYPE,     // 无效的类型
        INVALID_SIZE,     // 无效的大小
        INVALID_FORMAT,   // 无效的格式
        INVALID_DATA,     // 无效的数据
        INVALID_STATE     // 无效的状态
    };
	
#define DataStr Data_Str::GetInstance()
    class Data_Str : public Singleton< Data_Str > {
        friend Singleton< Data_Str >;

    public:
#ifdef belien_vs
        const char * INVALID_ARGUMENT = " 无效的参数";
        const char * INVALID_TYPE     = "无效的类型";
        const char * INVALID_SIZE     = "无效的大小";
        const char * INVALID_FORMAT   = "无效的格式";
        const char * INVALID_DATA     = "无效的数据";
        const char * INVALID_STATE    = "无效的状态";
#endif
#ifdef belien_qt
        const QString INVALID_ARGUMENT = QString::fromLocal8Bit("无效的参数");
        const QString INVALID_TYPE = QString::fromLocal8Bit("无效的类型");
        const QString INVALID_SIZE = QString::fromLocal8Bit("无效的大小");
        const QString INVALID_FORMAT = QString::fromLocal8Bit("无效的格式");
        const QString INVALID_DATA  = QString::fromLocal8Bit("无效的数据");
        const QString INVALID_STATE = QString::fromLocal8Bit("无效的状态");
#endif
    };


#pragma region 传输协议

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
        const char * PORT_ILLEGAL             = "非法端口号";
        const char * PORT_ADDED               = "端口号已存在";
        const char * PORT_ADDING_SUCCESS      = "端口号添加成功";
		const char * SOCKET_INIT_FAILURE      = "初始化失败";
		const char * SOCKET_INIT_SUCCESS      = "初始化成功";
        const char * LISTENING                = "监听中...";
        const char * NOT_LISTENED             = "未监听";
        const char * REQUEST_CONNECT          = "请求连接";
        const char * CONNECT                  = "连接成功";
        const char * UNCONNECT                = "未连接";
        const char * DISCONNECT               = "连接断开";
        const char * RECVING_REQUEST_DATA     = "接收请求数据";
        const char * STOP_RECVED_REQUEST_DATA = "已停止数据接收";
        const char * SENDING                  = "发送中...";
        const char * SEND_SUCCESS             = "发送成功";
        const char * SEND_FAILURE             = "发送失败";

#endif
#ifdef belien_qt
        const QString PORT_ILLEGAL = QString::fromLocal8Bit("非法端口号");
        const QString PORT_ADDED = QString::fromLocal8Bit("端口号已存在");
        const QString PORT_ADDING_SUCCESS =
            QString::fromLocal8Bit("端口号添加成功");
		const QString SOCKET_INIT_FAILURE =
            QString::fromLocal8Bit("初始化失败");
		const QString SOCKET_INIT_SUCCESS =
            QString::fromLocal8Bit("初始化成功");
        const QString REQUEST_CONNECT = QString::fromLocal8Bit("请求连接");
        const QString CONNECT         = QString::fromLocal8Bit("连接成功");
        const QString UNCONNECT       = QString::fromLocal8Bit("未连接");
        const QString DISCONNECT      = QString::fromLocal8Bit("连接断开");
        const QString LISTENING       = QString::fromLocal8Bit("监听中...");
        const QString NOT_LISTENED    = QString::fromLocal8Bit("未监听");
        const QString RECVING_REQUEST_DATA =
            QString::fromLocal8Bit("正在接收请求数据");
        const QString STOP_RECVED_REQUEST_DATA =
            QString::fromLocal8Bit("已停止数据接收");
        const QString SENDING      = QString::fromLocal8Bit("发送中...");
        const QString SEND_SUCCESS = QString::fromLocal8Bit("发送成功");
        const QString SEND_FAILURE = QString::fromLocal8Bit("发送失败");
#endif
    };
	
#pragma endregion

} // namespace identification
} // namespace belien

#endif