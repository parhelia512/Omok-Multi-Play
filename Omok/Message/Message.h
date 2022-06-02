#pragma once

#include <queue>
#include <string>

enum class MessageType
{
	CONNECT_CLIENT = 90,
	DISCONNECT_CLIENT = 91,
	LOBBY_ENTER_REQUEST = 100,
	LOBBY_ENTER_REPLY	= 101,
	LOBBY_ROOM_DATA_REQUEST	= 110,
	LOBBY_ROOM_DATA_REPLY	= 111,
	MAKE_ROOM_REQUEST		= 120,
	MAKE_ROOM_REPLY			= 121,
	ENTER_ROOM_REQUEST		= 130,
	ENTER_ROOM_REPLY		= 131,
	GAMEROOM_DATA_REQUEST	= 132,
	GAMEROOM_DATA_REPLY		= 133,
	EXIT_ROOM_REQUEST		= 141,
	EXIT_ROOM_REPLY			= 142
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