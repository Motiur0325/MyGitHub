package com.zosh.services;

import java.util.List;

import com.zosh.exceptions.UserException;
import com.zosh.models.Messages;
import com.zosh.models.User;

public interface MessageService {

	public Messages createMessage(User user,Integer chatId,Messages msg) throws UserException;
	
	public List<Messages> findChatMessages(Integer chatId) throws UserException;
	
}
