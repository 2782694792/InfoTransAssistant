#include "TcpClient.h"


TcpClient::TcpClient()
{

	InitSocket();

	while (1)
	{
		ConectToServer();
	}

	CloseSocket();
}


TcpClient::~TcpClient()
{
}
