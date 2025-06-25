package com.zosh.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestHeader;
import org.springframework.web.bind.annotation.RestController;

import com.zosh.models.Chat;
import com.zosh.models.User;
import com.zosh.request.CreateChatRequest;
import com.zosh.services.ChatService;
import com.zosh.services.UserService;

@RestController
public class ChatController {

	@Autowired
	ChatService chatService;
	
	@Autowired
	UserService userService;
	
	@PostMapping("/api/chats")
	public Chat createChat(@RequestBody CreateChatRequest chat,@RequestHeader("Authorization") String jwt) throws Exception {
		
		User user=userService.findUserByToken(jwt);
		User user2=userService.findUserById(chat.getUserId());
		
		Chat newChat=chatService.createChat(user,user2);
		
		return newChat;
		
	}
	
	@GetMapping("/api/chats")
	public List<Chat> getUsersChat(@RequestHeader("Authorization") String jwt) {
		
		User user=userService.findUserByToken(jwt);
		
		List<Chat> chats=chatService.findUserChat(user);
		
		return chats;
		
	}
	
}
