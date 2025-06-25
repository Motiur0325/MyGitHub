package com.zosh.repository;

import java.util.List;

import org.springframework.data.jpa.repository.JpaRepository;

import com.zosh.models.Messages;

public interface MessageRepository extends JpaRepository<Messages,Integer>{

	public List<Messages> findByChatId(Integer chatId);
	
}
