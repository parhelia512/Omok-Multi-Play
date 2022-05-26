#pragma once

#include <queue>
#include <string>

enum class MessageType
{
	CONNECT_CLIENT = 99,
	LOBBY_ENTER_REQUEST = 100,
	LOBBY_ENTER_REPLY	= 101,
	LOBBY_ROOM_DATA_REQUEST	= 110,
	LOBBY_ROOM_DATA_REPLY	= 111,
	MAKE_ROOM_REQUEST		= 120,
	MAKE_ROOM_REPLY			= 121,
	ENTER_ROOM_REQUEST		= 130,
	ENTER_ROOM_REPLY		= 131
};

class Message
{
	typedef std::queue<std::string> MessageQueue;

public:
	Message(MessageType messageType);
	Message(std::string str);

public:
	void			WriteMessage(std::string str);
	void			WriteMessage(int value);
	void			WriteMessage(bool state);
	MessageType		GetMessageType();
	std::string		ReadMessage();
	std::string		ConvertString();

private:
	MessageType		messageType;
	MessageQueue	messageQueue;
};